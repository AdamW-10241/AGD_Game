// Fill out your copyright notice in the Description page of Project Settings.


#include "Loot/AGDArmourLoot.h"

AAGDArmourLoot::AAGDArmourLoot()
{
	DisplayName = TEXT("Armour Name");
	Description = TEXT("Armour Description");
	Health = 0.0f;
	AttackSpeed = 0.0f;
	ArmourType = EArmourType::Head;
}

void AAGDArmourLoot::EquipLoot()
{
	Super::EquipLoot();

}
