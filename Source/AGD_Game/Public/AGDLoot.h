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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Loot, meta = (ExposeOnSpawn))
	TEnumAsByte<ERarity> Rarity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Loot, meta = (ExposeOnSpawn))
	int GearScore;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Loot)
	FString DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Loot)
	FString Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Loot)
	FTransform RelativeTransform;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Loot)
	USkeletalMesh* GearMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EquipLoot() {}

	UFUNCTION(BlueprintCallable, Category = Loot)
	virtual void UnEquipLoot() {}
};
