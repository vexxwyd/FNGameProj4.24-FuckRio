// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FortPlayerPawn.h"
#include "Net/UnrealNetwork.h"

void AFortPlayerPawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFortPlayerPawn, bIsSkydiving);
	DOREPLIFETIME(AFortPlayerPawn, ParachuteAttachment);
	DOREPLIFETIME(AFortPlayerPawn, VehicleStateRep);
}

void AFortPlayerPawn::SetPendingSkydiveLaunch(bool bPending)
{
}

void AFortPlayerPawn::ServerHandlePickup(AFortPickup * Pickup, float InFlyTime, const FVector & InStartDirection, bool bPlayPickupSound)
{
}

void AFortPlayerPawn::OnRep_ParachuteAttachment()
{
}

void AFortPlayerPawn::OnRep_InVehicle()
{
}
