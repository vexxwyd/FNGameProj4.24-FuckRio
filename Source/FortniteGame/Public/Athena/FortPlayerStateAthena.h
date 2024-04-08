// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortPlayerStatePvP.h"
#include "FortPlayerStateAthena.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortPlayerStateAthena : public AFortPlayerStatePvP
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	void Server_SetCanEditCreativeIsland(bool bCanEdit, TArray<FString> WhiteList);

	UFUNCTION()
	void OnRep_SquadId();

public:

	UPROPERTY(ReplicatedUsing = OnRep_SquadId)
	uint8                                              SquadId;
};
