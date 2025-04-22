

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "componentsBP.generated.h"

UCLASS()
class TESTPROJECT_API AcomponentsBP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AcomponentsBP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
