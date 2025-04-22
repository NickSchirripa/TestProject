

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "exposingItems.generated.h"

UCLASS()
class TESTPROJECT_API AexposingItems : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AexposingItems();
	virtual void Tick(float DeltaTime) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	//UPROPERTY(VisibleDefaultsOnly) makes the variable visible in BP,  but not instance  world view
	//UPROPERTY(VisibleInstanceOnly)-this would make it visible in Instance World View but  not BP
	UPROPERTY(VisibleAnywhere)//makes it visible but not editable on the BP  and Instance World View
	float runningTime;



	UPROPERTY(EditDefaultsOnly)
	//this makes it visible and able to edit in BP, but not Instance World View
	float amplitude = 0.25f;


	
	//UPROPERTY(EditAnywhere)-  this makes it visible and editable in both World Instance and BP. If you have this active and make an edit in World View it will override the BP value.
	UPROPERTY(EditInstanceOnly)//This makes it visible and editable in World View, but not BP.
	float timeConstant = 5.f;
	
};
