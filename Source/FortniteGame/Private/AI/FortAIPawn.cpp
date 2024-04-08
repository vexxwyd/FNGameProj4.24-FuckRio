// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FortAIPawn.h"
#include "FortAIController.h"

// Sets default values
AFortAIPawn::AFortAIPawn()
{
	// Set the starting AIController class to FortAIController
	AIControllerClass = AFortAIController::StaticClass();
}