// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AGDLoot.h"
#include "AGDArmourLoot.generated.h"

UENUM(BlueprintType)
enum EArmourType {
	Head,
	UpperBody,
	LowerBody,
	Hands,
	Feet
};

/**
 * 
 */
UCLASS()
class AGD_GAME_API AAGDArmourLoot : public AAGDLoot
{
	GENERATED_BODY()
	
public:
	AAGDArmourLoot();

protected:
	UPROPERTY(EditDefaultsOnly, Category = Armour)
	float Health;

	UPROPERTY(EditDefaultsOnly, Category = Armour)
	float AttackSpeed;

	UPROPERTY(EditDefaultsOnly, Category = Armour)
	TEnumAsByte<EArmourType> ArmourType;

	virtual void EquipLoot() override;
};
