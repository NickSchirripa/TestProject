// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "GameFramework/SpringArmComponent.h"
#include "bird.generated.h"





//FORWARD DECLARE
class UCapsuleComponent;
class USkeletalMeshComponent;
class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;


UCLASS()
class TESTPROJECT_API Abird : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	Abird();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//callback function for moveing forward. THIS IS FOR THE OLD WAY OF CONTROLS _ YYOU CAN IGNORE THIS
	void moveForward(float value);


	

	//make variable for mapping context  so you can use it in BP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "INPUT")
	UInputMappingContext* foxMappingContext;

	//make a varaible  for the Input Action
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "INPUT")
	UInputAction* moveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "INPUT")
	UInputAction* lookAction;

	//function that we will link  to the Input Action variable  "move action" we made above. That moves forward and back 
	void move(const FInputActionValue& Value);

	void look(const FInputActionValue& Value);



private:
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* capsule;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* skeleMesh;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* booms;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* viewCamera;




};
