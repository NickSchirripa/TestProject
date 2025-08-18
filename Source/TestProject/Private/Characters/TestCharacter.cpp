// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TestCharacter.h"

#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "GameFramework/CharacterMovementComponent.h"

#include "GroomComponent.h"

#include "items/itemClass.h"
#include "items/weapons/weaponClass.h"

#include "Animation/AnimMontage.h"


// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	booms = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera  Boom"));
	booms->SetupAttachment(GetRootComponent());
	booms->TargetArmLength = 300.f;


	viewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("View Camera"));
	viewCamera->SetupAttachment(booms);

	//Grooms

	hair = CreateDefaultSubobject<UGroomComponent>(TEXT("Hair"));
	hair->SetupAttachment(GetMesh());
	hair->AttachmentName = FString("head");

	eyebrows = CreateDefaultSubobject<UGroomComponent>(TEXT("Eyebrows"));
	eyebrows->SetupAttachment(GetMesh());
	eyebrows->AttachmentName = FString("head");

}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();

	//get a controller cast to a Actor Players Controller pointer variable
	if (APlayerController* playerController = Cast<APlayerController>(GetController()))
	{
		//take the controller cast and apply it to the Enhanced Input System, and attach it to Local Player
		if (UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{
			//take the controller with the Enhanced Input Subsystem and apply the variable we made for the Context Mapping in .h
			subsystem->AddMappingContext(testCharContext, 0);
		};
	}

	
}

void ATestCharacter::move(const FInputActionValue& value)
{
	//gets the 2D vector from the Input Action
	const FVector2D movementVector = value.Get<FVector2D>();

	//gets a firward vector for the actor. Then takes that vector and scales it by the 
	// amount in the Y direction from the Input Action 2D Y vector. This will be postive or negative one, depending on what we hit.
	//const FVector forward = GetActorForwardVector();
	//AddMovementInput(forward, movementVector.Y);

	//gets the roation of the controller and saving it to a FRotator
	const FRotator controlRotation = Controller->GetControlRotation();
	//making a FRoator that only has the rotation of the Yaw we get from the controller, which we got above
	const FRotator YawRotation(0.f, controlRotation.Yaw, 0.f);
	//getting a vector that points in  the way the camera is moved, by using the RoationMatrix, from the Rotators we got above. Then having the vector on the X Axis
	const FVector direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	//Stop Moving if attacking. If character is in the Enum attacking state - the code below will not run
	if (actionState == EactionState::EAS_attacking) return;
	
	//moving forward(which is the FVector X we got above) in the direction of the vector we got from the RotationMatrix, by the amount of the Input Action(which is 1 or -1, depending on the Input Action)
	AddMovementInput(direction, movementVector.Y);

	//Same things as above but to the right.
	//const FVector right = GetActorRightVector();
	//AddMovementInput(right, movementVector.X);

	//Getting a vector that is in the right direction, so we changed the EAxis to Y
	const FVector rightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(rightDirection, movementVector.X);

}

void ATestCharacter::look(const FInputActionValue& Value)
{

	const FVector2D lookAxisValue = Value.Get<FVector2D>();

	if (GetController())
	{
		AddControllerYawInput(lookAxisValue.X);
		AddControllerPitchInput(lookAxisValue.Y);
	}
}

void ATestCharacter::fKeyPressed()
{
	AweaponClass* overlappingWeapon = Cast<AweaponClass>(overlappingItem);
	//picks up weapon ig overlapping
	if (overlappingWeapon) 
	{
		overlappingWeapon->equip(GetMesh(), FName("rightHandSocket"));
		characterState = EcharacterState::ECS_equippedOneHandWeapon;
		overlappingItem = nullptr;
		EquippedWeapon = overlappingWeapon;
	
	}
	else{//disarms weapon and animation
		if (CanDisarm()) 
		{
			playEquipMontage(FName("unequip"));
			characterState = EcharacterState::ECS_unequiped;
		}
		//equips weapon and animation
		else if (CanArm())
		{
			playEquipMontage(FName("equip"));
			characterState = EcharacterState::ECS_equippedOneHandWeapon;
		}
	}
}

//attack animation function for when LMB is hit
void ATestCharacter::attackFunction()
{
	if (CanAttack()) {
		playAttackMontage();
		actionState = EactionState::EAS_attacking;
	}
	
}

//function to make attack animations not work if character is already attacking or does not have a weapon
bool ATestCharacter::CanAttack()
{
	return actionState == EactionState::EAS_unoccupied && characterState != EcharacterState::ECS_unequiped;
}

//function that checks if if we should disarm when key hit
bool ATestCharacter::CanDisarm()
{
	return actionState == EactionState::EAS_unoccupied && characterState != EcharacterState::ECS_unequiped;
}

//function that checks if we should equip, when F key hit
bool ATestCharacter::CanArm()
{
	return actionState == EactionState::EAS_unoccupied &&  characterState == EcharacterState::ECS_unequiped && EquippedWeapon;
}

//function we exposed to BP that is attached to a notify and puts weapon on back
void ATestCharacter::Disarm()
{
	if (EquippedWeapon)
	{
		EquippedWeapon->AttachMeshToSocket(GetMesh(), FName("spineSocket"));
	}
}

//Function we exposed to BP and is attached to a Montage Notify that takes weapon off back
void ATestCharacter::Arm()
{
	if (EquippedWeapon)
	{
		EquippedWeapon->AttachMeshToSocket(GetMesh(), FName("spineSocket"));
	}
}


//function that chooses which attack animation to play
void ATestCharacter::playAttackMontage()
{
	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	if (animInstance && attackMontage)
	{
		animInstance->Montage_Play(attackMontage);

		FName sectionName = FName();
		const int32 selection = FMath::RandRange(0, 2);

		switch (selection)
		{
		case 0:
			sectionName = FName("attack1");
			break;

		case 1:
			sectionName = FName("attack2");
			break;

		case 2:
			sectionName = FName("attack3");
			break;

		default:
			break;

		}
		animInstance->Montage_JumpToSection(sectionName, attackMontage);
	}
}

//function that chooses which equip or disarm animation to play
void ATestCharacter::playEquipMontage(FName SectionName)
{
	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	if (animInstance && equipMontage)
	{
		animInstance->Montage_Play(equipMontage);
		animInstance->Montage_JumpToSection(SectionName, equipMontage);

	}
}



void ATestCharacter::attackAnimationEnd()
{
	actionState = EactionState::EAS_unoccupied;
}







// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//if statement to make sure everything is working 
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//bind the input action, choose how the IA is triggered, choose which object it will apply to, and the function that will be launched
		EnhancedInputComponent->BindAction(movementAction, ETriggerEvent::Triggered, this, &ATestCharacter::move);
		EnhancedInputComponent->BindAction(lookAction, ETriggerEvent::Triggered, this, &ATestCharacter::look);
		EnhancedInputComponent->BindAction(jumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(pickupAction, ETriggerEvent::Started, this, &ATestCharacter::fKeyPressed);
		EnhancedInputComponent->BindAction(attack, ETriggerEvent::Triggered, this, &ATestCharacter::attackFunction);

		
	}


}


