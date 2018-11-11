// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATank * ATankPlayerController::GetControlledTank() const
{
	// We want to return the tank we are controlling.
	// The cast is needed as GetPawn returns only APawn *, and is not specific to which pawn.
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	// Always call this before anything else, so that the parent class's BeginPlay is called.
	Super::BeginPlay();
	/*UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));*/
	ATank *ControlledTank = GetControlledTank();

	if (ControlledTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player does not possess any tank!"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Player Possessing: %s"),*(ControlledTank->GetName()))

}
