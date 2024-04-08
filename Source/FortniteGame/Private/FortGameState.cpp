// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FortGameState.h"
#include "Net/UnrealNetwork.h"

void AFortGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFortGameState, WorldManager);
}
