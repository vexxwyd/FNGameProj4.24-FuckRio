// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Heroes/FortWorkerType.h"
#include "Heroes/FortHeroSpecialization.h"
#include "Animation/FortMontageLookupTable.h"
#include "FortHeroType.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FFortAttributeInitializationKey
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FName AttributeInitCategory;

	UPROPERTY(EditAnywhere)
		FName AttributeInitSubCategory;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortHeroType : public UFortWorkerType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Character Parts")
		bool bForceShowHeadAccessory;

	UPROPERTY(EditAnywhere, Category = "Character Parts")
		bool bForceShowBackpack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AssetBundles = "ItemDetails"), Category = "Specialization")
		TArray<TSoftObjectPtr<UFortHeroSpecialization>> Specializations;

	UPROPERTY(EditAnywhere, Category = "Animation")
		TSoftObjectPtr<UFortMontageLookupTable> DefaultMontageLookupTable;

	UPROPERTY(EditAnywhere, Category = "Animation")
		TSoftObjectPtr<UFortMontageLookupTable> OverrideMontageLookupTable;
	/*
	UPROPERTY(EditAnywhere)
	TArray<FGameplayEffectApplicationInfo> CombinedStatGEs;
	*/
	UPROPERTY(EditAnywhere, Category = "Requirements")
		FGameplayTagContainer RequiredGPTags;
	/*
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortFeedbackBank> MaleOverrideFeedback;
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFortFeedbackBank> FemaleOverrideFeedback;
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pawn")
		TSoftClassPtr<APawn> OverridePawnClass;
	/*
	UPROPERTY(EditAnywhere)
	UFortHeroGameplayDefinition* HeroGameplayDefinition;
	*/
	UPROPERTY(EditAnywhere, Category = "Hero Gameplay")
		class UAthenaCharacterItemDefinition* HeroCosmeticOutfitDefinition;

	UPROPERTY(EditAnywhere, Category = "Hero Gameplay")
		class UAthenaBackpackItemDefinition* HeroCosmeticBackblingDefinition;;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pawn")
		TSoftClassPtr<UAnimInstance> FrontEndAnimClass;

	UPROPERTY(EditAnywhere, Category = "Pawn")
		TSoftObjectPtr<UAnimMontage> FrontendAnimMontageIdleOverride;

	UPROPERTY(EditAnywhere, Category = "Pawn")
		float FrontEndBackPreviewRotationOffset;

	UPROPERTY(EditAnywhere, Category = "Display")
		FText Subtype;

	UPROPERTY(EditAnywhere, Category = "Attributes")
		FFortAttributeInitializationKey AttributeInitKey;

	UPROPERTY(EditAnywhere, Category = "Attributes")
		FDataTableRowHandle LegacyStatHandle;

	UPROPERTY(EditAnywhere, Category = "Preview")
		TSoftObjectPtr<UAnimMontage> ItemPreviewMontage_Male;

	UPROPERTY(EditAnywhere, Category = "Preview")
		TSoftObjectPtr<UAnimMontage> ItemPreviewMontage_Female;
	/*
	UPROPERTY(EditAnywhere)
	FText GetSubType();

	UPROPERTY(EditAnywhere)
	UFortHeroGameplayDefinition* GetHeroGameplayDefinition();

	UPROPERTY(EditAnywhere)
	UAnimMontage* GetFrontendAnimMontageIdleOverride();

	UPROPERTY(EditAnywhere)
	UFrontendAnimInstance* GetFrontendAnimClass();
	*/

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Hero", GetFName());
	}
};
