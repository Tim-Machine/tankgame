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
		UE_LOG(LogTemp, Warning, TEXT("Look Direction : %s"), *HitLocation.ToString());
	}
	// get world location
	auto Tank = GetControlledTank();
	// if hits landsscape
		// tell controlled tannk to aim
}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const {

	// Find crosshair direction
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	
	
	// Get Location in 2d space
	FVector2D ScreenPosition = FVector2D(
		ViewportSizeX * CrossHairXLocation,
		ViewportSizeY * CrossHairYlocation
	);

	UE_LOG(LogTemp, Warning, TEXT("ScreenData : %s"), *ScreenPosition.ToString());


	// de-project the screen position of crosshair to a world direction
	// line-trace along that direction, and see what we hit ( up to max range ) 

	return true;
}


