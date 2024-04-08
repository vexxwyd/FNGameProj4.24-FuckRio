// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "FortGameState.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
	class AFortWorldManager*                           WorldManager;
};
