// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATank * ATankPlayerController::GetControlledTank() const
{
	// We want to return the tank we are controlling.
	// The cast is needed as GetPawn returns only APawn *, and is not specific to which pawn.
	return Cast<ATank>(GetPawn());
}

