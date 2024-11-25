// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGD_Breakable.generated.h"

class UBoxComponent;

UCLASS()
class AGD_GAME_API AAGD_Breakable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGD_Breakable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* BoxOverlap;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
