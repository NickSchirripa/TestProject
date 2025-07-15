// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "characterTypes.h"
#include "TestCharacter.generated.h"

//Forwarde Declare for Controls
class UInputAction;
class UInputMappingContext;

//Forward Decalre for Camerea and Spring
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;

//forward declare other stuff
class AitemClass;




UCLASS()
class TESTPROJECT_API ATestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Make Sure to link this in BP Editor
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = Input)
	UInputMappingContext* testCharContext;

	//Make Sure to link this in BP Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction* movementAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction* lookAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction* jumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction* pickupAction;

	void move(const FInputActionValue& value);

	void look(const FInputActionValue& Value);

	void fKeyPressed();


private:

	EcharacterState characterState = EcharacterState::ECS_unequiped;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* booms;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* viewCamera;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* hair;
	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* eyebrows;

	UPROPERTY(VisibleInstanceOnly)
	AitemClass* overlappingItem;

public:
	//this is a setter function. All this does is set our pointer overlappingItem to the item we put in the arguemnt.
	FORCEINLINE void setOverlappingItem(AitemClass* item) { overlappingItem = item; }

};
