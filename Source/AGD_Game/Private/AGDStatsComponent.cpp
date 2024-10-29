// Fill out your copyright notice in the Description page of Project Settings.


#include "AGDStatsComponent.h"

// Sets default values for this component's properties
UAGDStatsComponent::UAGDStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	bStatsInitialised = false;

	MaxHealth = 100.0f;
	Health = MaxHealth;

	MaxStamina = 100.0f;
	Stamina = MaxStamina;

	MinBaseDamage = 1;
	MaxBaseDamage = 3;

	AttackSpeed = 1.0f;

	CharacterLevel = 0;
	Experience = 0;

	GearAttackSpeed = 0.0f;
	GearHealth = 0.0f;
	GearDamage = 0;
	
	// Set experience per level
	for (int i = 1; i < 10; i++) {
		ExperiencePerLevel.Add(i * 1000);
	}

}


// Called when the game starts
void UAGDStatsComponent::BeginPlay()
{	
	// Set the health and stamina variables to max
	Health = GetMaxHealth();
	Stamina = GetMaxStamina();
	
	Super::BeginPlay();

	UpdateLevel();

	bStatsInitialised = true;
}

int UAGDStatsComponent::GetMaxExperience()
{
	int MaxExperience = 0;

	// Add all experience for each level together
	for (int LevelExperience : ExperiencePerLevel) {
		MaxExperience += LevelExperience;
	}

	return MaxExperience;
}

void UAGDStatsComponent::HandleLevelUp()
{
	SetMaxHealth(MaxHealth * 2);	
	SetHealth(GetMaxHealth());
	
	SetMaxStamina(MaxStamina + 10);
	SetStamina(GetMaxStamina());

	int NewMinDamage = MinBaseDamage + 5;
	int NewMaxDamage = NewMinDamage + (3 + CharacterLevel);

	SetBaseDamage(NewMinDamage, NewMaxDamage);

	SetAttackSpeed(AttackSpeed + 0.1f);
	
	// Run the blueprint event and pass through values
	OnLevelUp(CharacterLevel, bStatsInitialised);
}

void UAGDStatsComponent::UpdateLevel()
{
	// If the character is max level then exit the funtion
	if (CharacterLevel + 1 > ExperiencePerLevel.Num()) {
		return;
	}

	int NewLevel = 0;
	int CollectiveExperience = 0;

	// Increase levels based on experience
	for (int LevelExperience : ExperiencePerLevel) {
		// Increment collective experience by the amount of level experience
		CollectiveExperience += LevelExperience;

		// If our actual experience is less than the collective experience end the loop
		if (Experience < CollectiveExperience) {
			break;
		}

		// Add one level
		NewLevel++;

		// If the level increases then handle level up
		if (NewLevel > CharacterLevel) {
			HandleLevelUp();
		}
	}

	// If the new level is different from the old
	if (NewLevel != CharacterLevel) {
		CharacterLevel = NewLevel;
	}
}

void UAGDStatsComponent::AddExperience(int Amount)
{
	// Adding amount to experience and clamping
	int NewExperience = FMath::Clamp(Experience + Amount, 0, GetMaxExperience());

	// Set the new experience amount
	SetExperience(NewExperience);

	// Call implementable experience function
	OnAddExperience(NewExperience);
}

void UAGDStatsComponent::SetExperience(int NewExperience)
{
	// Clamp experience
	int LocalExperience = FMath::Clamp(NewExperience, 0, GetMaxExperience());

	Experience = LocalExperience;

	UpdateLevel();
}

void UAGDStatsComponent::GetDisplayLevelInfo(int& DisplayLevel, int& DisplayExperience)
{
	// Add 1 to the level for a more readible character level
	DisplayLevel = CharacterLevel + 1;
	DisplayExperience = Experience;

	// If character is level 1, end the function
	if (CharacterLevel <= 0) {
		return;
	}

	// Set experience to 0 if at max level
	if (DisplayExperience >= GetMaxExperience()) {
		DisplayExperience = 0;
		return;
	}

	// Only have experience for current level
	for (int i = 0; i < CharacterLevel; i++) {
		DisplayExperience -= ExperiencePerLevel[i];
	}
}
