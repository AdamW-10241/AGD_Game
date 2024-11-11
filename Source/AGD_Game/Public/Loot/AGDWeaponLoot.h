// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AGDLoot.h"
#include "AGDWeaponLoot.generated.h"

/**
 * 
 */
UCLASS()
class AGD_GAME_API AAGDWeaponLoot : public AAGDLoot
{
	GENERATED_BODY()
	
public:
	AAGDWeaponLoot();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon, meta = (ExposeOnSpawn))
	int Damage;

protected:
	virtual void EquipLoot() override;

	virtual void UnEquipLoot() override;
};
