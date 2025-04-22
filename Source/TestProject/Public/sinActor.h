

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "sinActor.generated.h"

UCLASS()
class TESTPROJECT_API AsinActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AsinActor();
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	float runningTime;
	float amplitude = 0.25f;
	float timeConstant = 5.f;
	
};
