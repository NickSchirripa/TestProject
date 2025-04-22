

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "itemThree.generated.h"

UCLASS()
class TESTPROJECT_API AitemThree : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AitemThree();
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
};
