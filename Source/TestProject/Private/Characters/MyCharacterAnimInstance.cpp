// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MyCharacterAnimInstance.h"
#include "Characters/TestCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UMyCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	myCharacter = Cast<ATestCharacter>(TryGetPawnOwner());

	if (myCharacter)
	{
	myCharacterMovement = myCharacter->GetCharacterMovement();
	}
}

void UMyCharacterAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if (myCharacterMovement) {

		groundSpeed = UKismetMathLibrary::VSizeXY(myCharacterMovement->Velocity);

		isFalling = myCharacterMovement->IsFalling();

		characterState = myCharacter->getCharacterState();
	}

}
