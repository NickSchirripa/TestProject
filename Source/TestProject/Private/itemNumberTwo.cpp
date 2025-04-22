


#include "itemNumberTwo.h"
#include "TestProject/debugMacros.h"



// Sets default values
AitemNumberTwo::AitemNumberTwo()
{
 
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AitemNumberTwo::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AitemNumberTwo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld* world = GetWorld();

	//movement rate in units cm per second
	float movementRate = 50.f;

	//rotation per second
	float rotationRate = 45.f;

	//movementRate * DeltaTime is (cm/seconds) * (seconds/frames)  = (centermeters/Frame) or cms per frame
	AddActorWorldOffset(FVector(0.f, 0.f,movementRate * DeltaTime));

	//rotationRate * DeltaTime creates the desired roation every frame 
	AddActorWorldRotation(FRotator(0.f, rotationRate * DeltaTime, 0.f));

	if (world) {
		DrawDebugSphere(world, GetActorLocation(), 25.f, 24, FColor::Black, false, -1.f);
		DrawVectorSingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

	}
}


