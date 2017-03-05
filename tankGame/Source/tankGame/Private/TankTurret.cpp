// Fill out your copyright notice in the Description page of Project Settings.

#include "tankGame.h"
#include "TankTurret.h"




void UTankTurret::Rotate(float RotationSpeed) {
	RotationSpeed = FMath::Clamp<float>(RotationSpeed, -1, 1);

	auto RotateChange = RotationSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotateChange; 
	
	SetRelativeRotation(FRotator(0, Rotation, 0));
}