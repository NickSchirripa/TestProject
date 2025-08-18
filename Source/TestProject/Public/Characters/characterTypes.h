#pragma once

//enums
UENUM(BlueprintType)
enum class EcharacterState : uint8
{
	ECS_unequiped UMETA(DisplayName = "Unequip"),
	ECS_equippedOneHandWeapon UMETA(DisplayName = "Equipped One-Hand Weapon"),
	ECS_equippedTwoHandWeapon UMETA(DisplayName = "Equipped Two-Hand Weapon")
};

UENUM(BlueprintType)
enum class EactionState : uint8
{
	EAS_unoccupied UMETA(DisplayName = "unoccupied"),
	EAS_attacking UMETA(DisplayName = "attacking"),
	EAS_equipping UMETA(DisplayName = "Equipping"),
	EAS_unequipping UMETA(DisplayName = "Unequipping")
};


