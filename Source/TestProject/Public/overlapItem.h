

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "overlapItem.generated.h"

class USphereComponent;

UCLASS()
class TESTPROJECT_API AoverlapItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AoverlapItem();
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Using the Delegate Macro inputs in the function. Also have to add UFUNCTION() for the reflecition system
	UFUNCTION()
	void onSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void onSphereEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	UPROPERTY(VisibleAnywhere)
	USphereComponent* sphere;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* staticMesh;

	float runningTime;
	float amplitude = 0.25f;
	float timeConstant = 5.f;
	
	
};
