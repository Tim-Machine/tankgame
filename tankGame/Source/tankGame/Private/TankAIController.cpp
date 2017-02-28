// Fill out your copyright notice in the Description page of Project Settings.

#include "tankGame.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		/// aim at player
		GetAITank()->AimAt(GetPlayerTank()->GetActorLocation());
		// fire at player tank
	}
}

// AI Tank instance
ATank* ATankAIController::GetAITank() const {
	return Cast<ATank>(GetPawn());
}

// Get the player tank
ATank* ATankAIController::GetPlayerTank() const {

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerTank);
}

