// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AGDCharacter.h"
#include "AGDPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
/**
 * 
 */
UCLASS()
class AGD_GAME_API AAGDPlayerCharacter : public AAGDCharacter
{
	GENERATED_BODY()
	
public:
	AAGDPlayerCharacter();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* CameraComponent;

	// Only let the player attack if this is true
	bool bAttackAllowed;

	// Force actor rotation to the camera
	bool bForceRotate;

	// The combo of the attack animation
	int AttackCombo;

public:
	// Gear Meshes
	// Using the default mesh as head
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* UpperBodyComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* LowerBodyComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* HandsComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* FeetComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* WeaponComponent;

	UPROPERTY(EditDefaultsOnly, Category = Weapon)
	FName WeaponSocket;

	/* Set the boolean attack allowed */
	UFUNCTION(BlueprintCallable, Category = Combat)
	void SetAttackAllowed(bool bAllowAttack);

	/* Get the boolean attack allowed */
	UFUNCTION(BlueprintPure, Category = Combat)
	const bool GetAttackAllowed();

	/* Set the boolean force rotate */
	UFUNCTION(BlueprintCallable, Category = Rotation)
	void SetForceRotate(bool bShouldRotate);

	/* Get the boolean force rotate */
	UFUNCTION(BlueprintPure, Category = Rotation)
	const bool GetForceRotate();

	/* Set the integer attack combo */
	UFUNCTION(BlueprintCallable, Category = Combat)
	void SetAttackCombo(int NewAttackCombo);
	
	/* Get the integer attack combo */
	UFUNCTION(BlueprintPure, Category = Combat)
	const int GetAttackCombo();
};
