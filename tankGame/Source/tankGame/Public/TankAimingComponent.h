// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankBarrel.h"
#include "TankAimingComponent.generated.h"


// Forward Declaration
//class UTankBarrel;

//
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TANKGAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:	
	UTankBarrel* Barrel = nullptr;

protected:


public:	
	UTankAimingComponent();
	void AimAt(FVector HitLocation, float LaunchSpeed);
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void MoveBarrelTowards(FVector AimDirection);
};
