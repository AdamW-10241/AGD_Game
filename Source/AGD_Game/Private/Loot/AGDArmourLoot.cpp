// Fill out your copyright notice in the Description page of Project Settings.


#include "Loot/AGDArmourLoot.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/AGDPlayerCharacter.h"
#include "AGDStatsComponent.h"

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

	// Get the player
	ACharacter* PCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	// Cast to custom character
	AAGDPlayerCharacter* AGDCharacter = Cast<AAGDPlayerCharacter>(PCharacter);

	// If character is not AAGDPlayerCharacter, end function
	if (!IsValid(AGDCharacter)) {
		return;
	}

	if (IsValid(GearMesh)) {
		// Switch depending on assigned armor type
		switch (ArmourType) {
		case EArmourType::Head :
			AGDCharacter->GetMesh()->SetSkeletalMesh(GearMesh);
			AGDCharacter->GetMesh()->SetRelativeTransform(RelativeTransform);
			break;
		case EArmourType::UpperBody :
			AGDCharacter->UpperBodyComponent->SetSkeletalMesh(GearMesh);
			AGDCharacter->UpperBodyComponent->SetRelativeTransform(RelativeTransform);
			break;
		case EArmourType::LowerBody:
			AGDCharacter->LowerBodyComponent->SetSkeletalMesh(GearMesh);
			AGDCharacter->LowerBodyComponent->SetRelativeTransform(RelativeTransform);
			break;
		case EArmourType::Hands:
			AGDCharacter->HandsComponent->SetSkeletalMesh(GearMesh);
			AGDCharacter->HandsComponent->SetRelativeTransform(RelativeTransform);
			break;
		case EArmourType::Feet:
			AGDCharacter->FeetComponent->SetSkeletalMesh(GearMesh);
			AGDCharacter->FeetComponent->SetRelativeTransform(RelativeTransform);
			break;
		default:
			break;
		}
	}

	// Get the stats component
	UAGDStatsComponent* AGDStats = AGDCharacter->FindComponentByClass<UAGDStatsComponent>();

	// If stats component valid, change stats
	if (IsValid(AGDStats)) {
		// Make suure to add to health and not set it directly
		AGDStats->SetGearHealth(AGDStats->GetGearHealth() + Health);
		AGDStats->SetGearAttackSpeed(AGDStats->GetGearAttackSpeed() + AttackSpeed);
	}
}

void AAGDArmourLoot::UnEquipLoot()
{
	Super::UnEquipLoot();

	// Get the player
	ACharacter* PCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	// Cast to custom character
	AAGDPlayerCharacter* AGDCharacter = Cast<AAGDPlayerCharacter>(PCharacter);

	// If character is not AAGDPlayerCharacter, end function
	if (!IsValid(AGDCharacter)) {
		return;
	}

	if (IsValid(DefaultMesh)) {
		// Switch depending on assigned armor type
		switch (ArmourType) {
		case EArmourType::Head:
			AGDCharacter->GetMesh()->SetSkeletalMesh(DefaultMesh);
			break;
		case EArmourType::UpperBody:
			AGDCharacter->UpperBodyComponent->SetSkeletalMesh(DefaultMesh);
			break;
		case EArmourType::LowerBody:
			AGDCharacter->LowerBodyComponent->SetSkeletalMesh(DefaultMesh);
			break;
		case EArmourType::Hands:
			AGDCharacter->HandsComponent->SetSkeletalMesh(DefaultMesh);
			break;
		case EArmourType::Feet:
			AGDCharacter->FeetComponent->SetSkeletalMesh(DefaultMesh);
			break;
		default:
			break;
		}
	}

	// Get the stats component
	UAGDStatsComponent* AGDStats = AGDCharacter->FindComponentByClass<UAGDStatsComponent>();

	// If stats component valid, change stats
	if (IsValid(AGDStats)) {
		// Make suure to add to health and not set it directly
		AGDStats->SetGearHealth(AGDStats->GetGearHealth() - Health);
		AGDStats->SetGearAttackSpeed(AGDStats->GetGearAttackSpeed() - AttackSpeed);
	}
}
