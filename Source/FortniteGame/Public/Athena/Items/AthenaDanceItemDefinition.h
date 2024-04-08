// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortMontageItemDefinitionBase.h"
#include "FortniteGame/FortniteGame.h"
#include "AthenaDanceItemDefinition.generated.h"

USTRUCT()
struct  FVariantSwapMontageData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FGameplayTag VariantMetaTagRequired;

	UPROPERTY(EditAnywhere)
		FName MontageSectionName;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UAthenaDanceItemDefinition : public UFortMontageItemDefinitionBase
{
	GENERATED_BODY()
		
public:
	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bMovingEmote;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bMovingEmoteSkipLandingFX;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bMoveForwardOnly;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bMoveFollowingOnly;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bGroupEmote;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bUseHighPreviewCamera;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bGroupAnimationSync;

	UPROPERTY(EditAnywhere, Category = "Emote")
		float WalkForwardSpeed = 300;

	UPROPERTY(EditAnywhere, Category = "Emote")
		UAthenaDanceItemDefinition* GroupEmoteToStartLeader;

	UPROPERTY(EditAnywhere, Category = "Emote")
		UAthenaDanceItemDefinition* GroupEmoteToStartFollower;

	UPROPERTY(EditAnywhere, Category = "Emote")
		UAthenaDanceItemDefinition* GroupEmoteToStartLeaderIfBothOwn;

	UPROPERTY(EditAnywhere, Category = "Emote")
		UAthenaDanceItemDefinition* GroupEmoteToStartFollowerIfBothOwn;

	UPROPERTY(EditAnywhere, Category = "Emote")
		TArray<FVariantSwapMontageData> MotageSelectionGroups;

	UPROPERTY(EditAnywhere, Category = "Emote")
		FVector GroupEmotePositionOffset;

	UPROPERTY(EditAnywhere, Category = "Emote")
		float GroupEmotePositionOffsetTolerance = 15;

	UPROPERTY(EditAnywhere, Category = "Emote")
		bool bLockGroupEmoteLeaderRotation;

	UPROPERTY(EditAnywhere, Category = "Emote")
		float GroupEmoteLeaderRotationYawOffset;

	UPROPERTY(EditAnywhere, Category = "Emote")
		float GroupEmoteFollowerRotationYawOffset;

	UPROPERTY(EditAnywhere, meta = (AssetBundles = "AvatarDisplay"), Category = "Emote")
		TSoftObjectPtr<UAnimMontage> FrontEndAnimation;

	UPROPERTY(EditAnywhere, meta = (AssetBundles = "AvatarDisplay"), Category = "Emote")
		TSoftObjectPtr<UAnimMontage> FrontEndAnimationFemaleOverride;

	UPROPERTY(EditAnywhere, Category = "Visuals")
		FSoftClassPath CustomDanceAbility;

	UPROPERTY(EditAnywhere, Category = "Emote")
		FText ChatTriggerCommandName;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaDance", GetFName());
	}
};
