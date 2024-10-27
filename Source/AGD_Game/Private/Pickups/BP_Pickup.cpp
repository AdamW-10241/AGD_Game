// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/BP_Pickup.h"
#include "Components/BoxComponent.h"

// Sets default values
ABP_Pickup::ABP_Pickup()
{
 	// Set this actor to call Tick() every frame (do not need).
	PrimaryActorTick.bCanEverTick = false;

	// Add box collision
	BoxOverlap = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxOverlap->SetupAttachment(RootComponent);

	// Enable overlap collision
	BoxOverlap->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxOverlap->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ABP_Pickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_Pickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

