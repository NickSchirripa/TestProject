


#include "componentsC__.h"
#include "TestProject/debugMacros.h"


// Sets default values
AcomponentsC__::AcomponentsC__()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//took the itemMesh pointer we made, and assigned it to a StaticMesh Component.
	itemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));

	//Assigned the mesh we made as the RootComponent of the Actor
	RootComponent = itemMesh;

}

// Called when the game starts or when spawned
void AcomponentsC__::BeginPlay()
{
	Super::BeginPlay();
	
}

float AcomponentsC__::transformSinPure()
{
	return  amplitude * FMath::Sin(runningTime * timeConstant);;
}

float AcomponentsC__::transformCosPure()
{
	return amplitude * FMath::Cos(runningTime * timeConstant);
}




// Called every frame
void AcomponentsC__::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	runningTime += DeltaTime;

}


