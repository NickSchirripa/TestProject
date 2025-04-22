

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "templateFunctions.generated.h"

UCLASS()
class TESTPROJECT_API AtemplateFunctions : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AtemplateFunctions();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//template function
	template<typename T>
	T avg(T first, T second);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};

template<typename T>
inline T AtemplateFunctions::avg(T first, T second)
{
	return (first + second)/2;
}
