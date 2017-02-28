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

}

ATank* ATankAIController::GetAITank() {
	return Cast<ATank>(GetPawn());
}
