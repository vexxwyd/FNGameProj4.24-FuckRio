// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FortPlayerStateAthena.h"
#include "Net/UnrealNetwork.h"

void AFortPlayerStateAthena::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate
	DOREPLIFETIME(AFortPlayerStateAthena, SquadId);
}

void AFortPlayerStateAthena::Server_SetCanEditCreativeIsland(bool bCanEdit, TArray<FString> WhiteList)
{
}

void AFortPlayerStateAthena::OnRep_SquadId()
{
}
