// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortPlayerController.h"
#include "GameplayTagContainer.h"
#include "FortPlayerControllerGameplay.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortPlayerControllerGameplay : public AFortPlayerController
{
	GENERATED_BODY()
	
		UFUNCTION(BlueprintCallable)
		void SetHUDElementVisibility(const struct FGameplayTagContainer& HUDElementTags, bool bHideElements);

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);


protected:
	// APawn interface
	virtual void SetupInputComponent() override;
	// End of APawn interface
};
