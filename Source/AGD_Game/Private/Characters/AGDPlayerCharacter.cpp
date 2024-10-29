// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AGDPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AAGDPlayerCharacter::AAGDPlayerCharacter()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	UpperBodyComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Upper Body"));
	UpperBodyComponent->SetupAttachment(GetMesh());
	UpperBodyComponent->SetMasterPoseComponent(GetMesh());
	
	LowerBodyComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Lower Body"));
	LowerBodyComponent->SetupAttachment(GetMesh());
	LowerBodyComponent->SetMasterPoseComponent(GetMesh());
	
	HandsComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hands"));
	HandsComponent->SetupAttachment(GetMesh());
	HandsComponent->SetMasterPoseComponent(GetMesh());
	
	FeetComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Feet"));
	FeetComponent->SetupAttachment(GetMesh());
	FeetComponent->SetMasterPoseComponent(GetMesh());

	WeaponSocket = FName("Hand_R");
	WeaponComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	WeaponComponent->SetupAttachment(GetMesh(), WeaponSocket);

	bAttackAllowed = true;
	bForceRotate = false;

	AttackCombo = 0;
}

void AAGDPlayerCharacter::SetAttackAllowed(bool bAllowAttack)
{
	bAttackAllowed = bAllowAttack;
}

const bool AAGDPlayerCharacter::GetAttackAllowed()
{
	return bAttackAllowed;
}

void AAGDPlayerCharacter::SetForceRotate(bool bShouldRotate)
{
	bForceRotate = bShouldRotate;
}

const bool AAGDPlayerCharacter::GetForceRotate()
{
	return bForceRotate;
}

void AAGDPlayerCharacter::SetAttackCombo(int NewAttackCombo)
{
	AttackCombo = NewAttackCombo;
}

const int AAGDPlayerCharacter::GetAttackCombo()
{
	return AttackCombo;
}
