// Fill out your copyright notice in the Description page of Project Settings.

#include "tankGame.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto tank = GetControlledTank();
	if (!tank) {
		UE_LOG(LogTemp, Warning, TEXT("No Tank found"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("tank :: %s"), *(tank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	/// AimTowardsCrosshairs;
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("location : %s"), *HitLocation.ToString());
	}
	// get world location
	auto Tank = GetControlledTank();
	// if hits landsscape
		// tell controlled tannk to aim
}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const {
	HitLocation = FVector(1.0);
	return true;
}


