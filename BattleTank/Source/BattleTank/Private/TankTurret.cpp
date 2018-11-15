// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the Turret the right amount this frame
	// Given a max Rotation speed, and the frame time.
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f); // To prevent the barrel from moving too fast.
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	//// We want to prevent the RawNewElevation from going higher/lower than the max and min elevation
	//auto Rotation = FMath::Clamp<float>(RawNewRotation, MinRotationDegrees, MaxRotationDegrees);
	SetRelativeRotation(FRotator(0, Rotation, 0));
}

