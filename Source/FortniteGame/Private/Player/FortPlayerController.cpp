// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FortPlayerController.h"
#include "Net/UnrealNetwork.h"

void AFortPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate
	DOREPLIFETIME(AFortPlayerController, WorldInventory);
}

void AFortPlayerController::ServerAttemptInteract(AActor * ReceivingActor)
{
}

void AFortPlayerController::HandleWorldInventoryLocalUpdate()
{
}
