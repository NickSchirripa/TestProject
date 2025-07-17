// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "characterTypes.h"
#include "MyCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API UMyCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime)override;

	UPROPERTY(BlueprintReadWrite)
	class ATestCharacter* myCharacter;

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
	class UCharacterMovementComponent* myCharacterMovement;

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
	float groundSpeed;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool isFalling;

	UPROPERTY(BlueprintReadOnly, Category = "Movement | Character State")
	EcharacterState characterState;
};
