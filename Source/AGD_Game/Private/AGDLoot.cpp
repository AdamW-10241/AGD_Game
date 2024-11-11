// Fill out your copyright notice in the Description page of Project Settings.


#include "AGDLoot.h"

// Sets default values
AAGDLoot::AAGDLoot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Rarity = ERarity::Common;
	GearScore = 1;
	DisplayName = TEXT("Loot Name");
	Description = TEXT("Loot Description");
	GearMesh = nullptr;
}

// Called when the game starts or when spawned
void AAGDLoot::BeginPlay()
{
	Super::BeginPlay();
	
	EquipLoot();
}

