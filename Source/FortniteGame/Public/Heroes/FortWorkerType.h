// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Heroes/FortCharacterType.h"
#include "FortWorkerType.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FORTNITEGAME_API UFortWorkerType : public UFortCharacterType
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cosmetics")
		EFortCustomGender Gender;

	//UPROPERTY(BlueprintReadWrite, EditAnywhere)
	//TSoftObjectPtr<UFortItemIconDefinition> FixedPortrait;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manager")
		bool bIsManager;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manager")
		FGameplayTagContainer ManagerSynergyTag;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manager")
		FGameplayTagContainer FixedPersonalityTag;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Worker")
		FGameplayTagContainer FixedSetBonusTag;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manager")
		int MatchingPersonalityBonus;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manager")
		int MismatchingPersonalityPenalty;
};