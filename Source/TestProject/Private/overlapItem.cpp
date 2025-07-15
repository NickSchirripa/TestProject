


#include "overlapItem.h"
#include "TestProject/debugMacros.h"
#include "Components/SphereComponent.h"


// Sets default values
AoverlapItem::AoverlapItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	RootComponent = staticMesh;

	sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));

	sphere->SetupAttachment(GetRootComponent());


}

// Called when the game starts or when spawned
void AoverlapItem::BeginPlay()
{
	Super::BeginPlay();

	//adding the Delegate OnComponentBeginOverlap to the Subject. and adding a callback
	sphere->OnComponentBeginOverlap.AddDynamic(this, &AoverlapItem::onSphereOverlap);

	sphere->OnComponentEndOverlap.AddDynamic(this, &AoverlapItem::onSphereEnd);
	
}

void AoverlapItem::onSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//getting the name of the actor that overlapped the subject
	const FString OtherActorName = OtherActor->GetName();


	//
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(3, 4.f, FColor::Red, OtherActorName);
	}

}

void AoverlapItem::onSphereEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const FString OtherActorName = FString("Overlap has ended with ") + OtherActor->GetName();

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(4, 4.f, FColor::Yellow, OtherActorName);
	}
}

// Called every frame
void AoverlapItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//making a variable that is equal to DeltaTime
	runningTime += DeltaTime;

	//making a variable that will be a sin wave, on  a specific axis. in this case we will do Z axis
	float deltaZ = amplitude * FMath::Sin(runningTime * timeConstant);

	//add a  world offset function to move the actor with the wave we made
	AddActorWorldOffset(FVector(0.f, 0.f, deltaZ));

}


