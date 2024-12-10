// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BP_Pickup.generated.h"

class UBoxComponent;

UCLASS()
class AGD_GAME_API ABP_Pickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABP_Pickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
	FString PickupIndex;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* BoxOverlap;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
