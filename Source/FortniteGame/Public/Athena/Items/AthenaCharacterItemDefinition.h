// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Items/AthenaCosmeticItemDefinition.h"
#include "FortniteGame/FortniteGame.h"
#include "Athena/Items/AthenaBackpackItemDefinition.h"
#include "FortniteGame/Public/Heroes/FortHeroType.h"
#include "AthenaCharacterItemDefinition.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UFortFeedbackBank : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

};

UCLASS(BlueprintType)
class FORTNITEGAME_API UAthenaCharacterItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Character")
	TMap<FName, UObject*> RequestedDataStores;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HeroType")
	class UFortHeroType* HeroDefinition;

	UPROPERTY(EditAnywhere, Category = "HeroType")
	class UAthenaBackpackItemDefinition* DefaultBackpack;

	UPROPERTY(EditAnywhere, Category = "Character")
	TArray<UAthenaCosmeticItemDefinition*> RequiredCosmeticItems;

	UPROPERTY(EditAnywhere, Category = "Character")
	EFortCustomGender Gender;

	UPROPERTY(EditAnywhere, Category = "Feedback")
	TSoftObjectPtr<UFortFeedbackBank> FeedbackBank;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaCharacter", GetFName());
	}
};
