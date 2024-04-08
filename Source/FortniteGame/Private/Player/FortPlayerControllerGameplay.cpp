// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FortPlayerControllerGameplay.h"
#include "FortPawn.h"

void AFortPlayerControllerGameplay::SetHUDElementVisibility(const FGameplayTagContainer & HUDElementTags, bool bHideElements)
{
}


void AFortPlayerControllerGameplay::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		if (K2_GetPawn())
		{
			// find out which way is right
			const FRotator Rotation = GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get right vector 
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
			K2_GetPawn()->AddMovementInput(Direction, Value);
		}
	}
}

void AFortPlayerControllerGameplay::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		if (K2_GetPawn())
		{
			// find out which way is forward
			const FRotator Rotation = GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get forward vector
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			K2_GetPawn()->AddMovementInput(Direction, Value);
		}
	}
}

void AFortPlayerControllerGameplay::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent);

	if (InputComponent != NULL)
	{
		// Basis of movement
		InputComponent->BindAxis("MoveForward", this, &AFortPlayerControllerGameplay::MoveForward);
		InputComponent->BindAxis("MoveRight", this, &AFortPlayerControllerGameplay::MoveRight);

		// Originally, we have 2 versions of the rotation bindings to handle different kinds of devices differently. But in this project we will be using just one for now.
		// "turn" handles devices that provide an absolute delta, such as a mouse.
		InputComponent->BindAxis("Turn", this, &AFortPlayerControllerGameplay::AddYawInput);
		InputComponent->BindAxis("LookUp", this, &AFortPlayerControllerGameplay::AddPitchInput);
	}
}
