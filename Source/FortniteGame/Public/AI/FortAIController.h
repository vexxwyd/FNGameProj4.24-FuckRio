// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FortAIController.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortAIController : public AAIController
{
	GENERATED_BODY()
	
		UFUNCTION(BlueprintCallable)
		void SetGoalActor(class AActor* InActor, bool bLocationAlwaysKnown);

public:

	UPROPERTY()
	class AActor* GoalActor;
};
