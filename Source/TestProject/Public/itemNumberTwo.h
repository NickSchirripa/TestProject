

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "itemNumberTwo.generated.h"

UCLASS()
class TESTPROJECT_API AitemNumberTwo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AitemNumberTwo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
