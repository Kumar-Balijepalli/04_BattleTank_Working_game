// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/*UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));*/
	ATank *LocatePlayerTank = GetPlayerTank();

	if (LocatePlayerTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI could not locate player tank!"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("AI Found Player tank: %s"), *(LocatePlayerTank->GetName()))
}

ATank* ATankAIController::GetControlledTank() const
{
	// We want to return the tank we are controlling.
	// The cast is needed as GetPawn returns only APawn *, and is not specific to which pawn.
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


