// Fill out your copyright notice in the Description page of Project Settings.

#include "tankGame.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	auto AITank = GetAITank();
	if (!AITank) {
		UE_LOG(LogTemp, Warning, TEXT("no ai tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AItank :: %s"), *(AITank->GetName()));
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("No Player tank found"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank  :: %s"), *(PlayerTank->GetName()));
	}

}

ATank* ATankAIController::GetAITank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerTank);
}