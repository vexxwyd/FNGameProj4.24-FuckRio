// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGameModeBase.h"
#include "FortGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortGameMode : public AFortGameModeBase
{
	GENERATED_BODY()
	
public:

	/** Convenience helper to return a cast version of the Game State. */
	template<class T>
	T* GetGameState() const { return Cast<T>(GameState); }
};
