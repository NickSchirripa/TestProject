// Fill out your copyright notice in the Description page of Project Settings.


#include "bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputSubsystems.h"

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

void Abird::moveForward(float value)
{
	UE_LOG(LogTemp, Warning, TEXT("Value %f"), value);
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

	PlayerInputComponent->BindAxis(FName("moveForward"), this, &Abird::moveForward);
}

