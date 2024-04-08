// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "FortPlayerPawn.h"
#include "FortPlayerState.generated.h"

class AFortPlayerPawn;

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	
	/** @ Return current FortPlayerPawn used by this player state. */
	/** @ Potentially should be moved to FortPlayerStateAthena.    */
	AFortPlayerPawn* GetCurrentPawn() const { return CastChecked<AFortPlayerPawn>(GetPawn()); }
};
