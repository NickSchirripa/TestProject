

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "componentsC__.generated.h"

UCLASS()
class TESTPROJECT_API AcomponentsC__ : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AcomponentsC__();
// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//	UPROPERTY(EditAnywhere, BlueprintReadOnly)  this makes it visible in the details of world instance and BP, but the second specifier makes it so we  can get a BP node in the Event Graph, but not edit it.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine")
	//this makes it visible in the details of world instance and BP, but the second specifier makes it so we  can get a BP node in the Event Graph, and also edit it!
	float amplitude = 5.f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine")
	float timeConstant = 5.f;



	//making a function that is the same as  transformSin, but a Pure Function, and hardcoding runningTime, instead of haveing a parameter that takes a value.
	UFUNCTION(BlueprintPure)
	float transformSinPure();

	UFUNCTION(BlueprintPure)
	float transformCosPure();

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Sine")//makes it visible but not editable on the BP  and Instance World View
		float runningTime;


	//declaring a pointer for a static mesh
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* itemMesh;
	
	
};
