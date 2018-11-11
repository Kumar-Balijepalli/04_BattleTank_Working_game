// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Public/CollisionQueryParams.h"
#include "Math/Vector2D.h"

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

void ATankPlayerController::Tick(float DeltaTime)
{
	// Always do the super/parent classes function first.
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Called TankPlayerController's tick function"));
	AimTowardsCrossHair();
}


ATank * ATankPlayerController::GetControlledTank() const
{
	// We want to return the tank we are controlling.
	// The cast is needed as GetPawn returns only APawn *, and is not specific to which pawn.
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank())
		return;
	
	FVector HitLocation{ 0 }; // out parameter

	if (GetSightRayHitLocation(HitLocation))
	{
		// If it hits the landscape 
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation %s"), *HitLocation.ToString());
			// Tell the control tank to aim at this point.
	}
}

// Get World Location if Line trace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{

	// Find the cross hair position
	int32 ViewPortSizeX, ViewPortSizeY;

	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	FVector2D ScreenLocation(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY*CrossHairYLocation);

		// "De-Project" the screen position of the crosshair to a world direction
		// LineTrace along that look direction, and see what we hit (up to a max range).

		return true;
}