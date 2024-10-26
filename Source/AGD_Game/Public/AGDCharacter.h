// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AGDCharacter.generated.h"

UCLASS()
class AGD_GAME_API AAGDCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAGDCharacter();

	// Face the other actor
	UFUNCTION(BlueprintCallable, Category = Actor)
	void FaceOtherActor(AActor* OtherActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// On Death
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Character)
	void OnCharacterDeath();

	// On Hit
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Character)
	void OnCharacterHurt();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
