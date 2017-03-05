// Fill out your copyright notice in the Description page of Project Settings.

#include "tankGame.h"
#include "TankTurret.h"




void UTankTurret::Pivot(float RelativeSpeed) {
	UE_LOG(LogTemp, Warning, TEXT("Pivot"));
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, MinSpeed, MaxSpeed);

	auto ElevationChange = RelativeSpeed * PivotSpeed * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Yaw + ElevationChange;
	auto ClampedElevation = FMath::Clamp<float>(RawNewElevation, 150, -150);

	SetRelativeRotation(FRotator(0, ClampedElevation, 0));
}