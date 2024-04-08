// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGameStatePvP.h"
#include "FortGameStateAthena.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortGameStateAthena : public AFortGameStatePvP
{
	GENERATED_BODY()
	
public:

	UPROPERTY(Replicated)
		bool                                               bIsLargeTeamGame;
};
