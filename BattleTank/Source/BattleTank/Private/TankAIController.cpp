// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/*UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));*/
	ATank *ControlledTank = GetControlledTank();

	if (ControlledTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI does not possess any tank!"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("AI Possessing: %s"), *(ControlledTank->GetName()))
}

ATank* ATankAIController::GetControlledTank() const
{
	// We want to return the tank we are controlling.
	// The cast is needed as GetPawn returns only APawn *, and is not specific to which pawn.
	return Cast<ATank>(GetPawn());
}


