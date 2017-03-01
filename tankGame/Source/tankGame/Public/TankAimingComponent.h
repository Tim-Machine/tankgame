// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKGAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:	
	UStaticMeshComponent* Barrel = nullptr;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UTankAimingComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AimAt(FVector HitLocation, float LaunchSpeed);
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
};
