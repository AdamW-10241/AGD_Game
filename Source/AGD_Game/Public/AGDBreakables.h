// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class UBoxComponent;

/**
 * 
 */
class AGD_GAME_API AGDBreakables
{
public:
	AGDBreakables();
	~AGDBreakables();

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* BoxOverlap;
};
