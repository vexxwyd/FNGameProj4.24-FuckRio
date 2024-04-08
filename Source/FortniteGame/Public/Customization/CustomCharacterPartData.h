// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortniteGame.h"
#include "Engine/DataAsset.h"
#include "CustomCharacterPartData.generated.h"

USTRUCT()
struct FCustomAccessoryHatReactiveMorphs
{
	GENERATED_BODY(BlueprintType)

public:
	UPROPERTY(EditAnywhere, Category = "Hat Morphs")
		TArray<FName> CapMorphTargets;

	UPROPERTY(EditAnywhere, Category = "Hat Morphs")
		TArray<FName> HelmetMorphTargets;

	UPROPERTY(EditAnywhere, Category = "Hat Morphs")
		TArray<FName> MaskMorphTargets;

	UPROPERTY(EditAnywhere, Category = "Hat Morphs")
		TArray<FName> HatMorphTargets;

};

UCLASS()
class FORTNITEGAME_API UCustomAccessoryAttachmentData : public UDataAsset
{
	GENERATED_BODY(BlueprintType)
public:
	UPROPERTY(EditAnywhere)
		struct FVector                                                        MaleRelativeScale;

	UPROPERTY(EditAnywhere)
		struct FVector                                                        FemaleRelativeScale;

	UPROPERTY(EditAnywhere)
		struct FVector                                                        SmallMaleRelativeScale;

	UPROPERTY(EditAnywhere)
		struct FVector                                                        SmallFemaleRelativeScale;

	UPROPERTY(EditAnywhere)
		struct FVector                                                        LargeMaleRelativeScale;

	UPROPERTY(EditAnywhere)
		struct FVector                                                        LargeFemaleRelativeScale;
};

USTRUCT(BlueprintType)
struct FColorSwatchPair
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName ColorName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FLinearColor ColorValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText ColorDisplayName;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomDynamicColorSwatch : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FColorSwatchPair> ColorPairs;

	//UPROPERTY(BlueprintReadWrite, EditAnywhere)
	 //TArray<FCustomPartTextureParameter> TextureParameters;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TMap<FName, TSoftObjectPtr<UTexture2D>> SpecificIconography;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomHairColorSwatch : public UDataAsset
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomSkinColorSwatch : public UDataAsset
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class  UCustomAccessoryColorSwatch : public UCustomDynamicColorSwatch
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		FLinearColor AccessoryColors;

};

UCLASS(DefaultToInstanced, EditInlineNew)
class FORTNITEGAME_API UCustomCharacterPartData : public UObject
{
	GENERATED_BODY()
};


UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomCharacterAccessoryData : public UCustomCharacterPartData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Accessory")
		FName AttachSocketName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Accessory")
		FVector AttachOffset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Accessory")
		UCustomAccessoryAttachmentData* AttachmentOverrideData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Accessory")
		bool bUseClothCollisionFromOtherParts;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Accessory")
		bool bCollideWithOtherPartsCloth;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Accessory")
		UClass* AnimClass;

	UPROPERTY(EditAnywhere, Category = "Accessory")
		UClass* FrontEndAnimClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Accessory")
		UClass* MannequinAnimClass;

	UPROPERTY(EditAnywhere, Category = "Accessory")
		TSoftObjectPtr<UCustomAccessoryColorSwatch> AccessoryColors;

};

UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomCharacterBackpackData : public UCustomCharacterAccessoryData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FName LootSocketName;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomCharacterBodyPartData : public UCustomCharacterPartData
{
	GENERATED_BODY()

public:


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Body")
		class UClass* AnimClass;

	UPROPERTY(EditAnywhere, Category = "Body")
		class UClass* FrontEndAnimClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Body")
		class UClass* MannequinAnimClass;

	UPROPERTY(EditAnywhere, Category = "Body")
		TSoftObjectPtr<UCustomAccessoryColorSwatch> AccessoryColors;

};

UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomCharacterCharmData : public UCustomCharacterAccessoryData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Charm")
		EFortCustomPartType  PartAttachedToOverride;

};

UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomCharacterFaceData : public UCustomCharacterAccessoryData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Face")
		EFortCustomPartType PartAttachedToOverride;

	UPROPERTY(EditAnywhere, Category = "Hat Morphs")
		FCustomAccessoryHatReactiveMorphs HatMorphData;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomCharacterHeadData : public UCustomCharacterBodyPartData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Material Tweaks")
		TSoftObjectPtr<UCustomSkinColorSwatch> SkinColorSwatch;

	UPROPERTY(EditAnywhere, Category = "Material Tweaks")
		TSoftObjectPtr<UCustomHairColorSwatch>            HairColorSwatch;

	UPROPERTY(EditAnywhere, Category = "Hat Morphs")
		TArray<FName>                               CapMorphTargets;

	UPROPERTY(EditAnywhere, Category = "Hat Morphs")
		TArray<FName>                               HelmetMorphTargets;

	UPROPERTY(EditAnywhere, Category = "Hat Morphs")
		TArray<FName>                               MaskMorphTargets;

	UPROPERTY(EditAnywhere, Category = "Hat Morphs")
		TArray<FName>                               HatMorphTargets;
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UCustomCharacterHatData : public UCustomCharacterAccessoryData
{
	GENERATED_BODY(BlueprintType)
public:


	UPROPERTY(EditAnywhere, Category = "Accessory")
	TEnumAsByte<ECustomHatType> HatType;                                                  
};