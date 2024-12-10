// Fill out your copyright notice in the Description page of Project Settings.


#include "AGD_Breakable.h"
#include "Components/BoxComponent.h"

// Sets default values
AAGD_Breakable::AAGD_Breakable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Add box collision
	BoxOverlap = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	SetRootComponent(BoxOverlap);

	// Enable overlap collision
	BoxOverlap->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxOverlap->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void AAGD_Breakable::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AAGD_Breakable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

