// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Data/FortWeaponItemDefinition.h"
#include "FortWeaponMeleeItemDefinition.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API UFortWeaponMeleeItemDefinition : public UFortWeaponItemDefinition
{
	GENERATED_BODY()
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Weapon", GetFName());
	}
};
