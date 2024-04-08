// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTags.h"
#include "UObject/SoftObjectPath.h"
#include "Animation/FortMontageLookupTable.h"
#include "FortniteGame.h"

#include "CustomCharacterPart.generated.h"
/**
 * 
 */
USTRUCT()
struct FCustomPartMaterialOverrideData
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		int MaterialOverrideIndex;

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UMaterialInterface> OverrideMaterial;
};

USTRUCT()
struct FCustomPartScalarParameter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		int MaterialIndexForScalarParameter;

	UPROPERTY(EditAnywhere)
		FName ScalarParameterNameForMaterial;

	UPROPERTY(EditAnywhere)
		float ScalarOverride;
};

USTRUCT()
struct FCustomPartTextureParameter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		int MaterialIndexForTextureParameter;

	UPROPERTY(EditAnywhere)
		FName TextureParameterNameForMaterial;

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UTexture> TextureOverride;
};

USTRUCT()
struct FCustomPartVectorParameter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		int MaterialIndexForVectorParameter;

	UPROPERTY(EditAnywhere)
		FName VectorParameterNameForMaterial;

	UPROPERTY(EditAnywhere)
		FLinearColor VectorOverride;

};




UCLASS()
class FORTNITEGAME_API UCustomCharacterPart : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category = "Character Part")
		EFortCustomGender GenderPermitted;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category = "Character Part")
		EFortCustomBodyType BodyTypesPermitted;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, AssetRegistrySearchable, Category = "Character Part")
		TEnumAsByte<EFortCustomPartType> CharacterPartType;

	UPROPERTY(EditAnywhere, Category = "BoneSetsToHide")
		FGameplayTagContainer BoneSetsToHide;

	UPROPERTY(EditAnywhere, Category = "BoneSetsToHide")
		bool bShouldHideBonesForThisPart;

	UPROPERTY(EditAnywhere, Category = "Character Part")
		FGameplayTagContainer DisallowedCosmeticTags;

	UPROPERTY(EditAnywhere, Category = "Advanced")
		bool bGameplayRelevantCosmeticPart;

	UPROPERTY(EditAnywhere, Category = "Character Part")
		bool bAttachToSocket = true;

	UPROPERTY(EditAnywhere, Category = "Character Part")
		bool bIgnorePart;

	UPROPERTY(EditAnywhere, Category = "Art")
		TSoftClassPtr<UObject> PartModifierBlueprint;

	UPROPERTY(EditAnywhere, Instanced, Category = "Art")
		class UCustomCharacterPartData* AdditionalData;

	UPROPERTY(EditAnywhere, Category = "Animation")
		TSoftObjectPtr<UFortMontageLookupTable> DefaultMontageLookupTable;

	UPROPERTY(EditAnywhere, Category = "Animation")
		TSoftObjectPtr<UFortMontageLookupTable> OverrideMontageLookupTable;

	UPROPERTY(EditAnywhere, Category = "Animation")
		TSoftObjectPtr<UAnimMontage> FrontendAnimMontageIdleOverride;

	UPROPERTY(EditAnywhere, Category = "Animation")
		float FrontEndBackPreviewRotationOffset;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category = "Art", BlueprintReadWrite)
		TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Art")
		TArray<TSoftObjectPtr<USkeletalMesh>> MasterSkeletalMeshes;

	UPROPERTY(EditAnywhere, Category = "Art")
		bool  bSinglePieceMesh;

	UPROPERTY(EditAnywhere, Category = "Art")
		bool  bSupportsColorSwatches;

	UPROPERTY(EditAnywhere, Category = "Animation")
		bool  bAllowStaticRenderPath;

	UPROPERTY(EditAnywhere, Category = "Art")
		TArray<FCustomPartMaterialOverrideData> MaterialOverrides;

	UPROPERTY(EditAnywhere, Category = "Art")
		TArray< FCustomPartTextureParameter> TextureParameters;

	UPROPERTY(EditAnywhere, Category = "Art")
		TArray<FCustomPartScalarParameter> ScalarParameters;

	UPROPERTY(EditAnywhere, Category = "Art")
		TArray<FCustomPartVectorParameter> VectorParameters;

	UPROPERTY(EditAnywhere, Category = "SoundLibary")
		TArray<class UObject*> SoundLibraries;
	
	UPROPERTY(EditAnywhere, Category = "Art")
		int MaterialOverrideFlags;

	UPROPERTY(EditAnywhere, Category = "Effect")
		TSoftObjectPtr<UParticleSystem> IdleEffect;
	
	UPROPERTY(EditAnywhere, Category = "Effect")
		FName IdleFXSocketName;

	UPROPERTY(EditAnywhere, Category = "Effect")
		bool bAutoActivate;

	//UPROPERTY(EditAnywhere)
		//UMarshalledVFX_AuthoredDataConfig* AuthoredData;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("CustomCharacterPart", GetFName());
	}
};
