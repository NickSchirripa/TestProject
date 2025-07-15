

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "itemClass.generated.h"

class USphereComponent;

UCLASS()
class TESTPROJECT_API AitemClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AitemClass();
virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//Using the Delegate Macro inputs in the function. Also have to add UFUNCTION() for the reflecition system
	UFUNCTION()
	virtual void onSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void onSphereEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* staticMesh;

private:




	UPROPERTY(VisibleAnywhere)
	USphereComponent* sphere;

	float runningTime;
	float amplitude = 0.25f;
	float timeConstant = 5.f;
	
};
