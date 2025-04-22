

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "exposingVarEventGrpah.generated.h"

UCLASS()
class TESTPROJECT_API AexposingVarEventGrpah : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AexposingVarEventGrpah();
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

private:

		//makes it possible to allow a private variable accessible with BP and Instance World
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess="true"), Category = "Sine")//makes it visible but not editable on the BP  and Instance World View
		float runningTime;



};
