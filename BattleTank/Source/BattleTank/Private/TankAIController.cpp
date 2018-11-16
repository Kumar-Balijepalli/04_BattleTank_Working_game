// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	// We want to return the tank we are controlling.
	// The cast is needed as GetPawn returns only APawn *, and is not specific to which pawn.
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		// TODO Move Towards the Player

		// Aim Towards the Player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		// TODO Don't Fire every Frame.
		ControlledTank->Fire();
	}
	
}


