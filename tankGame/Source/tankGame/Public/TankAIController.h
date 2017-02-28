// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:
	void BeginPlay() override;
	ATank* GetAITank() const;
	ATank* GetPlayerTank() const;
	void Tick(float DeltaTime) override;
};
