// Fill out your copyright notice in the Description page of Project Settings.

#include "tankGame.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto tank = GetControlledTank();
	UE_LOG(LogTemp, Warning, TEXT("tank :: %s"), *(tank->GetName()));
}


ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}
