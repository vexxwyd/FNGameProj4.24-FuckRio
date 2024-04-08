// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/FortPawn.h"
#include "FortAIPawn.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortAIPawn : public AFortPawn
{
	GENERATED_BODY()
	
public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBehaviorTree* BehaviorTree;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanShowMinimapIndicator = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bHideHealthBar;

	// Sets default values for this actor's properties
	AFortAIPawn();
};
