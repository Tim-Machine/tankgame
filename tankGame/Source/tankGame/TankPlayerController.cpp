// Fill out your copyright notice in the Description page of Project Settings.

#include "tankGame.h"
#include "Tank.h"
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
		GetControlledTank()->AimAt(HitLocation);
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
	FVector2D ScreenLocation = FVector2D(
		ViewportSizeX * CrossHairXLocation,
		ViewportSizeY * CrossHairYlocation
	);

	// de-project the screen position of crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	// line-trace along that direction, and see what we hit ( up to max range ) 

	return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		WorldLocation,
		LookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& LookDirection, FVector& HitLocation) const{

	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	FHitResult HitResults;
	if (GetWorld()->LineTraceSingleByChannel(
		HitResults,
		StartLocation, 
		EndLocation, 
		ECollisionChannel::ECC_Visibility)
		) {
		HitLocation = HitResults.Location;
		return true;
	}
	else {
		HitLocation = FVector(0);
		return false;
	}

}