// Fill out your copyright notice in the Description page of Project Settings.


#include "Loot/AGDWeaponLoot.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/AGDPlayerCharacter.h"
#include "AGDStatsComponent.h"

AAGDWeaponLoot::AAGDWeaponLoot()
{
	DisplayName = TEXT("Weapon Name");
	Description = TEXT("Weapon Description");
	Damage = 1;
}

void AAGDWeaponLoot::EquipLoot()
{
	Super::EquipLoot();

	// Gets the player as a default character class
	ACharacter* PCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	// Casts to our AGD player character class
	AAGDPlayerCharacter* AGDCharacter = Cast<AAGDPlayerCharacter>(PCharacter);

	// Make sure the player character is of the AGD class
	if (IsValid(AGDCharacter)) {
		// Check that we have a mesh assigned
		if (IsValid(GearMesh)) {
			AGDCharacter->WeaponComponent->SetSkeletalMesh(GearMesh);
			AGDCharacter->WeaponComponent->SetRelativeTransform(RelativeTransform);
		}

		// Find the stats component
		UAGDStatsComponent* AGDStats = AGDCharacter->FindComponentByClass<UAGDStatsComponent>();
		// Check if we found it
		if (IsValid(AGDStats)) {
			// Change the damage
			AGDStats->SetGearDamage(Damage);
		}
	}
}

void AAGDWeaponLoot::UnEquipLoot()
{
	Super::UnEquipLoot();

	// Gets the player as a default character class
	ACharacter* PCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	// Casts to our AGD player character class
	AAGDPlayerCharacter* AGDCharacter = Cast<AAGDPlayerCharacter>(PCharacter);

	// Make sure the player character is of the AGD class
	if (IsValid(AGDCharacter)) {
		// Check if skeletal mesh is assigned
		if (AGDCharacter->WeaponComponent->SkeletalMesh != nullptr) {
			// Remove mesh if assigned
			AGDCharacter->WeaponComponent->SetSkeletalMesh(nullptr);
		}
	}
}
