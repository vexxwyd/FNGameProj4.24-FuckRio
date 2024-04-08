// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Items/AthenaCosmeticItemDefinition.h"
#include "GameplayTags.h"
#include "FortniteGame/FortniteGame.h"
#include "Items/FortItemAccessTokenType.h"
#include "FortMontageItemDefinitionBase.generated.h"

/**
 * 
 */

USTRUCT()
struct  FMontageItemAccessData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FGameplayTag AccessTag;

	UPROPERTY(EditAnywhere)
		UFortItemAccessTokenType* AccessToken;
};

USTRUCT()
struct FSectionNameAndWeight 
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FName SectionName; 

	UPROPERTY(EditAnywhere)
	float SectionWeight;
};


USTRUCT()
struct  FMontageVisibilityData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		EMontageVisibilityRule Rule;

	UPROPERTY(EditAnywhere)
		UFortItemDefinition* Item;
};

USTRUCT(BlueprintType)
struct FFortEmoteMapping
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere)
		EFortCustomBodyType BodyType;

	UPROPERTY(EditAnywhere)
		EFortCustomGender Gender;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortMontageItemDefinitionBase : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Emote")
		TSoftObjectPtr<UAnimMontage> Animation;

	UPROPERTY(EditAnywhere, meta = (AssetBundles = "AvatarDisplay"), Category = "Emote")
		TSoftObjectPtr<UAnimMontage> AnimationFemaleOverride;

	UPROPERTY(EditAnywhere, meta = (AssetBundles = "AvatarDisplay"), Category = "Emote")
		TArray<FFortEmoteMapping> AnimationOverrides;

	UPROPERTY(EditAnywhere, Category = "Emote")
		int PreviewLoops = 1;

	UPROPERTY(EditAnywhere, Category = "Emote")
		float PreviewLength;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bIncludeAudioWithAnimDuration = true;

	UPROPERTY(EditAnywhere, Category = "Emote")
		float EmoteCooldownSecs = 3.0;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bMontageContainsFacialAnimation;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bPlayRandomSection;

	UPROPERTY(EditAnywhere, Category = "Emote")
		TArray<FSectionNameAndWeight> PlayRandomSectionByName;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool  bSwitchToHarvestingToolOnUse;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bHolsterWeapon;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bHolsterWeaponIfDualWieldPickaxe;

	UPROPERTY(EditAnywhere, Category = "Emote")
		TArray<FMontageItemAccessData> AccessData;

	UPROPERTY(EditAnywhere, Category = "Emote")
		TArray<FMontageVisibilityData> VisibilityData;

	UPROPERTY(EditAnywhere, Category = "Emote")
		FGameplayTagContainer EmoteWheelExclusiveTags;

	UPROPERTY(EditAnywhere, Category = "Emote")
		TSoftObjectPtr<UAthenaCosmeticItemDefinition> RequiredEmoteParent;

	UPROPERTY(EditAnywhere, Category = "Emote")
		FGameplayTagContainer TagsWhichIndicateEmoteParent;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Emote", GetFName());
	}
};