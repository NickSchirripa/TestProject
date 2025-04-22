


#include "templateFunctions.h"
#include "TestProject/debugMacros.h"


// Sets default values
AtemplateFunctions::AtemplateFunctions()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AtemplateFunctions::BeginPlay()
{
	Super::BeginPlay();
	
	//template function with an interger
	int tempFunc = avg<int32>(1, 3);

	//log out template int function
	UE_LOG(LogTemp, Warning, TEXT("The average is %d"), tempFunc)


	//template function with float
	float avgFloat = avg<float>(1.5f, 5.5f);

	//log out template fun with float
	UE_LOG(LogTemp, Warning, TEXT("The float average is: %f"), avgFloat)


}

// Called every frame
void AtemplateFunctions::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld* world = GetWorld();

	if (world) {

	DrawDebugSphere(world, GetActorLocation(), 25.f, 24, FColor::Black, false, -1.f);

	//make a vector that is the actors location vector+ 0 then divide by 2. Which will give a vector location that is midway between orgin and actor
	FVector midPoint = avg<FVector>(GetActorLocation(), FVector::ZeroVector);

	DrawDebugPoint(world,midPoint, 20.f, FColor::Emerald,false, -1.f );

	AddActorWorldOffset(FVector(0.f,0.f, 1.f));

	}

	


}


