// Fill out your copyright notice in the Description page of Project Settings.


#include "items/weapons/weaponClass.h"
#include "Characters/TestCharacter.h"


//function that uses parameters to attach static mesh to a specified component based on the parameters you use. In TestCharacter you can see this used. 
// as the inParent is the Test Character Mesh, and the inSocketName is the name of the socket, on that mesh, that we want to attach the staticMesh to.
void AweaponClass::equip(USceneComponent* inParent, FName inSocketName)
{
	FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, true);
	staticMesh->AttachToComponent(inParent, TransformRules, inSocketName);
	ItemState = EItemState::EIS_Equip;
}

void AweaponClass::onSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::onSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	
}

void AweaponClass::onSphereEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::onSphereEnd(OverlappedComponent, OtherActor,OtherComp, OtherBodyIndex);
}
