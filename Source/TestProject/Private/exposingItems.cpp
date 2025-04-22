


#include "exposingItems.h"
#include "TestProject/debugMacros.h"


// Sets default values
AexposingItems::AexposingItems()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AexposingItems::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AexposingItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	//making a variable that is equal to DeltaTime
	runningTime += DeltaTime;

	//making a variable that will be a sin wave, on  a specific axis. in this case we will do Z axis
	float deltaZ = amplitude * FMath::Sin(runningTime * timeConstant);

	//add a  world offset function to move the actor with the wave we made
	AddActorWorldOffset(FVector(0.f, 0.f, deltaZ));

	UWorld* world = GetWorld();

	if (world) {
		DrawDebugSphere(world, GetActorLocation(), 25.f, 24, FColor::Purple, false, -1.f);
		DrawVectorSingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

	}
}


