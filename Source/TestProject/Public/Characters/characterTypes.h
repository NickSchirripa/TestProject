#pragma once

//enums
UENUM(BlueprintType)
enum class EcharacterState : uint8
{
	ECS_unequiped UMETA(DisplayName = "Unequip"),
	ECS_equippedOneHandWeapon UMETA(DisplayName = "Equipped One-Hand Weapon"),
	ECS_equippedTwoHandWeapon UMETA(DisplayName = "Equipped Two-Hand Weapon")
};


