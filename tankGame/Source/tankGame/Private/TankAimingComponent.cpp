// Fill out your copyright notice in the Description page of Project Settings.

#include "tankGame.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {

	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile")); // we want to shoot from the socket
	
	bool HaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	auto Time = GetWorld()->GetTimeSeconds();

	if(HaveAimSolution){
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}

}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet) {
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}
void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet) {
	if (!Turret) { return; }
	Turret = TurretToSet;
}
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection){

	//where are we going to aim at?
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimRotator = AimDirection.Rotation();
	auto DeltaRotator = AimRotator - BarrelRotator;
	// rotate turret
	Barrel->Elevate(DeltaRotator.Pitch);
	//Turret->Pivot(DeltaRotator.Yaw);
}
