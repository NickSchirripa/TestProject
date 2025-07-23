


#include "items/itemClass.h"
#include "Components/SphereComponent.h"
#include "Characters/TestCharacter.h"



// Sets default values
AitemClass::AitemClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	RootComponent = staticMesh;

	sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));

	sphere->SetupAttachment(GetRootComponent());


}

// Called when the game starts or when spawned
void AitemClass::BeginPlay()
{
	Super::BeginPlay();


	//adding the Delegate OnComponentBeginOverlap to the Subject. and adding a callback
	sphere->OnComponentBeginOverlap.AddDynamic(this, &AitemClass::onSphereOverlap);

	sphere->OnComponentEndOverlap.AddDynamic(this, &AitemClass::onSphereEnd);

	
}

void AitemClass::onSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{


	ATestCharacter* testCharacter = Cast<ATestCharacter>(OtherActor);
	if (testCharacter) {
		testCharacter->setOverlappingItem(this);
	}

}

void AitemClass::onSphereEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ATestCharacter* testCharacter = Cast<ATestCharacter>(OtherActor);
	if (testCharacter) {
		testCharacter->setOverlappingItem(nullptr);
	}
}

// Called every frame
void AitemClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//making a variable that is equal to DeltaTime
	runningTime += DeltaTime;

	//making a variable that will be a sin wave, on  a specific axis. in this case we will do Z axis
	float deltaZ = amplitude * FMath::Sin(runningTime * timeConstant);

	//add a  world offset function to move the actor with the wave we made
	if (ItemState == EItemState::EIS_Hovering) {
	AddActorWorldOffset(FVector(0.f, 0.f, deltaZ));
	}


}


