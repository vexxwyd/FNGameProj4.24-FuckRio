// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FortAthenaVehicle.h"
#include "Engine/CollisionProfile.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate
	DOREPLIFETIME(AFortAthenaVehicle, PlayerSlots);
}


void AFortAthenaVehicle::OnRep_PlayerSlots()
{
}

bool AFortAthenaVehicle::ContainsPlayers()
{
	return false;
}
