// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGDLoot.generated.h"

UENUM(BlueprintType)
enum ERarity {
	Common,
	Uncommon,
	Rare,
	Epic,
	Legendary
};

UCLASS()
class AGD_GAME_API AAGDLoot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGDLoot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Loot)
	TEnumAsByte<ERarity> Rarity;

	UPROPERTY(EditDefaultsOnly, Category = Loot)
	int GearScore;

	UPROPERTY(EditDefaultsOnly, Category = Loot)
	FString DisplayName;

	UPROPERTY(EditDefaultsOnly, Category = Loot)
	FString Description;

	UPROPERTY(EditDefaultsOnly, Category = Loot)
	USkeletalMesh* GearMesh;

	virtual void EquipLoot();
};
