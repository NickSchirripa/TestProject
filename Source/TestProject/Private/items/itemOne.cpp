// Fill out your copyright notice in the Description page of Project Settings.


#include "items/itemOne.h"
#include "TestProject/debugMacros.h"


// Sets default values
AitemOne::AitemOne()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AitemOne::BeginPlay()
{
	Super::BeginPlay();

	FVector location = GetActorLocation();
	
	DrawSphere(location, Blue)
	
}

// Called every frame
void AitemOne::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GEngine) {

		FString deltaTimeLog = FString::Printf(TEXT("DeltaTime: %f"), DeltaTime);
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, deltaTimeLog);

		FString name = GetName();
		FString getNameMessage = FString::Printf(TEXT("Name of Item: %s"), *name);

		GEngine->AddOnScreenDebugMessage(2, 30.f, FColor::Magenta, getNameMessage);
	}
	

}

