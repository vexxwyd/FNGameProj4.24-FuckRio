// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAccountItemDefinition.h"
#include "GameplayTags.h"
#include "Customization/FortCosmeticVariant.h"
#include "Particles/ParticleSystem.h"
#include "AthenaCosmeticItemDefinition.generated.h"

class UAthenaCharacterItemDefinition;

USTRUCT(BlueprintType)
struct FFortStatManagerTag : public FGameplayTag
{
	GENERATED_BODY()

public:

};

USTRUCT(BlueprintType)
struct FAthenaCosmeticMaterialOverride
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName ComponentName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int MaterialOverrideIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UMaterialInterface> OverrideMaterial;
};

USTRUCT(BlueprintType)
struct FCosmeticVariantInfo
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FGameplayTag VariantChannelTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FGameplayTag ActiveVariantTag;
};


USTRUCT(BlueprintType)
struct FFortCosmeticAdaptiveStatPair 
{

	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FFortStatManagerTag StatTag;

	UPROPERTY(EditAnywhere)
	int StatValue; 
};

USTRUCT(BlueprintType)
struct FFortCosmeticAdaptiveStatPreview
{

	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FText UnlockCondition;

	UPROPERTY(EditAnywhere)
	TArray<FFortCosmeticAdaptiveStatPair> StatValues; 
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UAthenaCosmeticItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Frontend Preview")
		bool bIsShuffleTile;

	UPROPERTY(EditAnywhere, Category = "Frontend Preview")
		bool bIsOwnedByCampaignHero;

	UPROPERTY(EditAnywhere, Category = "Variants")
		bool bHasMoreThanOneCharacterPartVariant;

	UPROPERTY(EditAnywhere, Category = "Display")
		bool bHideIfNotOwned;
	
	UPROPERTY(EditAnywhere, Category = "Variants")
	    EVariantUnlockType VariantUnlockType;

	UPROPERTY(EditAnywhere, Category = "Frontend Preview")
		FRotator PreviewPawnRotationOffset;
/*
	UPROPERTY(EditAnywhere, Category = "Frontend Preview")
		TArray<UObject*> FoleyLibraries;
	*/
	UPROPERTY(EditAnywhere, Category = "Display")
		FGameplayTagContainer DisallowedCosmeticTags;

	UPROPERTY(EditAnywhere, Category = "Display")
		FGameplayTagContainer MetaTags;

	UPROPERTY(EditAnywhere, Category = "Display")
		TArray<FGameplayTag> VariantChannelsToNeverSendToMCP;

	//UPROPERTY(EditAnywhere)
	//TMap<FCosmeticVariantInfo, FSoftClassPath> ReactivePreviewDrivers;

	UPROPERTY(EditAnywhere, Category = "Visual")
		TArray<FAthenaCosmeticMaterialOverride> MaterialOverrides;

	UPROPERTY(EditAnywhere, Category = "Visual")
		FGameplayTagContainer ObservedPlayerStats;

//	UPROPERTY(EditAnywhere, Category = "Frontend Preview") forward declaration doesn't seem to work for this??
	//	TArray<UFortMontageItemDefinitionBase*> BuiltInEmotes;

	UPROPERTY(EditAnywhere, Instanced, Category = "Variants")
		TArray<UFortCosmeticVariant*> ItemVariants;

	UPROPERTY(EditAnywhere, Category = "Variants")
		FGameplayTag VariantChannelToUseForThumbnails;

	UPROPERTY(EditAnywhere, Category = "Variants")
		TArray<FortCosmeticVariantPreview> ItemVariantPreviews;

	UPROPERTY(EditAnywhere, Category = "Variants")
		FText DirectAquisitionStyleDisclaimerOverride;

	UPROPERTY(EditAnywhere, Category = "Visual")
	TArray<FFortCosmeticAdaptiveStatPreview> ItemObservedStatPreviews;

	UPROPERTY(EditAnywhere, Category = "Display")
		FText UnlockRequirements;

	UPROPERTY(EditAnywhere, Category = "Display")
		TSoftObjectPtr<UFortAccountItemDefinition> UnlockingItemDef;

	UPROPERTY(EditAnywhere, Category = "Preview")
		TSoftClassPtr<UClass> ItemPreviewActorClass;

//	UPROPERTY(EditAnywhere), Category = "Frontend Preview"
	//TSoftObjectPtr<UFXSystemAsset> ItemPreviewParticleSystem;

	UPROPERTY(EditAnywhere, Category = "Preview")
		TSoftObjectPtr<UAnimMontage> ItemPreviewMontage_Male;

	UPROPERTY(EditAnywhere, Category = "Preview")
		TSoftObjectPtr<UAnimMontage> ItemPreviewMontage_Female;

	UPROPERTY(EditAnywhere, Category = "Preview")
		TSoftObjectPtr<UAthenaCharacterItemDefinition> ItemPreviewHero;
/*
	UPROPERTY(EditAnywhere, Category = "Frontend Preview")
		TArray<FName> ConfiguredDynamicInstallBundles;

	UPROPERTY(EditAnywhere, Category = "Frontend Preview")
		TArray<FName> PendingDynamicInstallBundles;
	*/
	UPROPERTY(EditAnywhere, Category = "Exclusive Item")
		FGameplayTagContainer ExclusiveRequiresOutfitTags;

	UPROPERTY(EditAnywhere, Category = "Exclusive Item")
		FText CustomExclusiveCallout;

	UPROPERTY(EditAnywhere, Category = "Exclusive Item")
		FText ExclusiveDescription;

	UPROPERTY(EditAnywhere, Category = "Exclusive Item")
		TSoftObjectPtr<UTexture2D> ExclusiveIcon;
};
