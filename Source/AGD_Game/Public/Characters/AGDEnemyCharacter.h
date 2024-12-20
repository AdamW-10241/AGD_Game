// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AGDCharacter.h"
#include "AGDEnemyCharacter.generated.h"

UCLASS()
class AGD_GAME_API AAGDEnemyCharacter : public AAGDCharacter
{
	GENERATED_BODY()

public:
	AAGDEnemyCharacter() { AttackRange = 200.0f; }

protected:
	UPROPERTY(EditAnywhere, Category = "Alternate Stats")
	float AttackRange;

public:
	UFUNCTION(BlueprintPure, Category = "Alternate Stats")
	float GetAttackRange() { return AttackRange; }

	UFUNCTION(BlueprintCallable, Category = "Alternate Stats")
	void SetAttackRange(float NewRange) { AttackRange = NewRange; }

};
