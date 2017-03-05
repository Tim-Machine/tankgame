// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKGAME_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Pivot(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float PivotSpeed = 10.0f;

	float MinSpeed = -10.0f;
	float MaxSpeed = 10.0f;
};
