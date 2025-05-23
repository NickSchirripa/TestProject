// Fill out your copyright notice in the Description page of Project Settings.


#include "bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
Abird::Abird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//make components
	capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Comp"));



	//if you want to change size of capsule you can do it in BP or in C++ as shown below:
	capsule->SetCapsuleHalfHeight(20.f);
	capsule->SetCapsuleRadius(20.f);

	//set capsule as Root Comp
	SetRootComponent(capsule);

	skeleMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Fox Mesh"));

	//attach Skeletal Mesh to Root
	skeleMesh->SetupAttachment(GetRootComponent());

	//ATTACH spring arm
	booms = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera  Boom"));

	booms->SetupAttachment(GetRootComponent());
	booms->TargetArmLength = 300.f;

	//Camera Component

	viewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("View Camera"));

	viewCamera->SetupAttachment(booms);


	//AUTO POSSES PLAYER
	//AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void Abird::BeginPlay()
{
	Super::BeginPlay();

	//get a controller cast to a Actor Players Controller pointer variable
	if (APlayerController* playerController = Cast<APlayerController>(GetController()))
	{
		//take the controller cast and apply it to the Enhanced Input System, and attach it to Local Player
		if (UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{
			//take the controller with the Enhanced Input Subsystem and apply the variable we made for the Context Mapping in .h
			subsystem->AddMappingContext(foxMappingContext, 0);
		};
	}
	
}

//THE OLD WAY!!! WE CAN IGNORE THIS
void Abird::moveForward(float value)
{
	UE_LOG(LogTemp, Warning, TEXT("Value %f"), value);
}

//function that sets our value to something  and checks to see if it is true, and if it is, we log to screen.  value is a FInputActionValue so it can be a booleaan or 2d/3d vector.
//we assign it to a boolean and then have a conditional statement to check if it is true
void Abird::move(const FInputActionValue& Value)
{
	const float directionValue = Value.Get<float>();

	if (directionValue) {
		UE_LOG(LogTemp, Warning, TEXT("IA_move triggered!!!!"))
	}

	if (Controller && (directionValue != 0.f)) {
		FVector  forward = GetActorForwardVector();
		AddMovementInput(forward, directionValue);
	}
}

void Abird::look(const FInputActionValue& Value)
{
	const FVector2D lookAxisValue = Value.Get<FVector2D>();

	if (GetController())
	{
		AddControllerYawInput(lookAxisValue.X);
		AddControllerPitchInput(lookAxisValue.Y);
	}
}



// Called every frame
void Abird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input 
void Abird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(moveAction, ETriggerEvent::Triggered, this, &Abird::move);
		EnhancedInputComponent->BindAction(lookAction, ETriggerEvent::Triggered, this, &Abird::look);
	}


	//THIS WAS THE OLD WAY TO BIND!! DO NOT NEED TO DO THIS!
	//PlayerInputComponent->BindAxis(FName("moveForward"), this, &Abird::moveForward);
}

