// Fill out your copyright notice in the Description page of Project Settings.

#include "AGDCharacter.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AAGDCharacter::AAGDCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Face other actor
void AAGDCharacter::FaceOtherActor(AActor* OtherActor)
{
	// Get other actor location
	FVector OtherActorLocation = OtherActor->GetActorLocation();

	// Get new actor rotation
	FRotator NewActorRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), OtherActorLocation);
	// Only change the z axis
	NewActorRotation = { 0.0f, NewActorRotation.Yaw, 0.0f };

	// Set new actor rotation
	SetActorRotation(NewActorRotation);
}

// Called when the game starts or when spawned
void AAGDCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAGDCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
