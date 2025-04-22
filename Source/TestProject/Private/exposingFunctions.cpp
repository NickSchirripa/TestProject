


#include "exposingFunctions.h"
#include "TestProject/debugMacros.h"


// Sets default values
AexposingFunctions::AexposingFunctions()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AexposingFunctions::BeginPlay()
{
	Super::BeginPlay();
	
}

float AexposingFunctions::transformSin(float value)
{
	return amplitude * FMath::Sin(value * timeConstant);
}

float AexposingFunctions::transformSinPure()
{
	 return amplitude * FMath::Sin(runningTime * timeConstant);
}

float AexposingFunctions::transformCosPure()
{
	return amplitude * FMath::Cos(runningTime * timeConstant);
}


// Called every frame
void AexposingFunctions::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//making a variable that is equal to DeltaTime
	runningTime += DeltaTime;

	//making a variable that will be a sin wave, on  a specific axis. in this case we will do Z axis. THIS IS WHAT WE TURNED INTO THE FUNCTION
	//float deltaZ = amplitude * FMath::Sin(runningTime * timeConstant);

	//add a  world offset function to move the actor with the wave we made. THIS IS WHERE WE APPLY THE FUNCTION VALUE 
	//AddActorWorldOffset(FVector(0.f, 0.f, deltaZ));

	UWorld* world = GetWorld();

	if (world) {
		DrawDebugSphere(world, GetActorLocation(), 25.f, 24, FColor::White, false, -1.f);
		DrawVectorSingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

	}

}


