// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AGDStatsComponent.generated.h"


UCLASS( Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AGD_GAME_API UAGDStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAGDStatsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Health)
	float MaxHealth;

	float Health;

	UPROPERTY(EditDefaultsOnly, Category = Stamina)
	float MaxStamina;

	float Stamina;

	UPROPERTY(EditDefaultsOnly, Category = Damage)
	int MinBaseDamage;

	UPROPERTY(EditDefaultsOnly, Category = Damage)
	int MaxBaseDamage;

	UPROPERTY(EditDefaultsOnly, Category = "Additional Stats")
	float AttackSpeed;

	int CharacterLevel;

	UPROPERTY(EditAnywhere, Category = Level)
	int Experience;

	UPROPERTY(EditDefaultsOnly, Category = Level)
	TArray<int> ExperiencePerLevel;

	UPROPERTY(EditDefaultsOnly, Category = Level)
	int CharacterMaxLevel;

	// Gear Variables
	float GearHealth;

	float GearAttackSpeed;

	int GearDamage;

	int GetMaxExperience();

	void HandleLevelUp();

	bool bStatsInitialised;

public:
	UFUNCTION(BlueprintCallable, Category=Initialisation)
	void InitialiseStats(bool bInitialise = true);

	// Gear Functions
	UFUNCTION(BlueprintPure, Category = "Gear Stats")
	float GetGearHealth() const { return GearHealth; }

	UFUNCTION(BlueprintCallable, Category = "Gear Stats")
	void SetGearHealth(float NewHealth) { GearHealth = NewHealth; }
	
	UFUNCTION(BlueprintPure, Category = "Gear Stats")
	float GetGearAttackSpeed() const { return GearAttackSpeed; }

	UFUNCTION(BlueprintCallable, Category = "Gear Stats")
	void SetGearAttackSpeed(float NewAttackSpeed) { GearAttackSpeed = NewAttackSpeed; }
	
	UFUNCTION(BlueprintPure, Category = "Gear Stats")
	int GetGearDamage() const { return GearDamage; }
	
	UFUNCTION(BlueprintCallable, Category = "Gear Stats")
	void SetGearDamage(float NewDamage) { GearDamage = NewDamage; }

	// Stat Functions
	UFUNCTION(BlueprintPure, Category = Health)
	float GetMaxHealth() const { return MaxHealth + GearHealth; }

	UFUNCTION(BlueprintCallable, Category = Health)
	void SetMaxHealth(float NewMax) { MaxHealth = NewMax; }

	UFUNCTION(BlueprintPure, Category = Stamina)
	float GetMaxStamina() const { return MaxStamina; }

	UFUNCTION(BlueprintCallable, Category = Stamina)
	void SetMaxStamina(float NewMax) { MaxStamina = NewMax; }

	UFUNCTION(BlueprintPure, Category = Health)
	float GetHealth() const { return Health; }

	UFUNCTION(BlueprintCallable, Category = Health)
	void SetHealth(float NewHealth) { Health = NewHealth; }

	UFUNCTION(BlueprintPure, Category = Stamina)
	float GetStamina() const { return Stamina; }

	UFUNCTION(BlueprintCallable, Category = Stamina)
	void SetStamina(float NewStamina) { Stamina = NewStamina; }

	UFUNCTION(BlueprintPure, Category = Damage)
	int GetBaseDamage() const { return FMath::RandRange(MinBaseDamage, MaxBaseDamage) + GearDamage; }

	UFUNCTION(BlueprintCallable, Category = Damage)
	void SetBaseDamage(int Min, int Max) { MinBaseDamage = Min; MaxBaseDamage = Max; }

	UFUNCTION(BlueprintPure, Category = "Additional Stats")
	float GetAttackSpeed() const { return AttackSpeed + GearAttackSpeed; }

	UFUNCTION(BlueprintCallable, Category = "Additional Stats")
	void SetAttackSpeed(float newAttackSpeed) { AttackSpeed = newAttackSpeed; }

	// Levelling functions
	UFUNCTION(BlueprintCallable, Category = Level)
	void UpdateLevel();

	UFUNCTION(BlueprintCallable, Category = Level)
	void AddExperience(int Amount);

	UFUNCTION(BlueprintImplementableEvent, Category = Level)
	void OnAddExperience(int Amount);

	UFUNCTION(BlueprintCallable, Category = Level)
	void SetExperience(int NewExperience);
	
	UFUNCTION(BlueprintImplementableEvent, Category = Level)
	void OnLevelUp(int Level, bool bAreStatsInitialised);

	UFUNCTION(BlueprintPure, Category = Level)
	void GetTrueLevelInfo(int& TrueLevel, int& TrueMaxLevel, int& TrueExperience) {
		TrueLevel = CharacterLevel;
		TrueMaxLevel = CharacterMaxLevel;
		TrueExperience = Experience;
	}

	UFUNCTION(BlueprintPure, Category = Level)
	void GetDisplayLevelInfo(int& DisplayLevel, int& DisplayMaxLevel, int& DisplayExperience);

	UFUNCTION(BlueprintPure, Category = Level)
	TArray<int> GetExperiencePerLevel() const { return ExperiencePerLevel; }
};
