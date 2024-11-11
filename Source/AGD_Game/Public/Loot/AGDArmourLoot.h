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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Armour, meta = (ExposeOnSpawn))
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Armour, meta = (ExposeOnSpawn))
	float AttackSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Armour)
	TEnumAsByte<EArmourType> ArmourType;

protected:
	virtual void EquipLoot() override;
};
