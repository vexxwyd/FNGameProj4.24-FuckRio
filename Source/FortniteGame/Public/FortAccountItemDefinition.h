// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPersistableItemDefinition.h"
#include "FortAccountItemDefinition.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FORTNITEGAME_API UFortAccountItemDefinition : public UFortPersistableItemDefinition
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Account Item")
	FCurveTableRowHandle LevelToXpHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sacrifice")
	FCurveTableRowHandle LevelToSacrificeXpHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sacrifice")
	FDataTableRowHandle SacrificeRecipe;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sacrifice")
	FDataTableRowHandle TransmogSacrificeRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Conversion")
	TArray<FDataTableRowHandle> ConversionRecipes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Conversion")
	FDataTableRowHandle UpgradeRarityRecipeHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	int MinLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	int MaxLevel;
/*
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sacrifice")
	FString GrantToProfileType;*/
};
