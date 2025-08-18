// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "items/itemClass.h"
#include "weaponClass.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API AweaponClass : public AitemClass
{
	GENERATED_BODY()
public:
	void equip(USceneComponent* inParent,FName inSocketName);

	void AttachMeshToSocket(USceneComponent* inParent, const FName& inSocketName);

protected:

	//override functions
	virtual void onSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void onSphereEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	
};
