


#include "itemThree.h"
#include "TestProject/debugMacros.h"



// Sets default values
AitemThree::AitemThree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AitemThree::BeginPlay()
{
	Super::BeginPlay();

	FVector location = GetActorLocation();
	FVector forward = GetActorForwardVector();

	SetActorLocation(FVector(0.f, 0.f, 100.f));

	DrawSphere(location, Red);
	DrawVector(location, location + forward * 100.f);
	
}

// Called every frame
void AitemThree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FString time = FString::Printf(TEXT("Delta Time: %f"), DeltaTime);

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Green, time);
	}

}


