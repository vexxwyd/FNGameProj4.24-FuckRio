// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAccountItemDefinition.h"
#include "Abilities/FortAbilitySet.h"
#include "FortAlterationItemDefinition.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FFortCosmeticModification
{
	GENERATED_BODY()

public: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UMaterialInterface> CosmeticMaterial;                                      

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UParticleSystem> AmbientParticleSystem;                                

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UParticleSystem> MuzzleParticleSystem;                                    

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UParticleSystem> ReloadParticleSystem;                                     

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UParticleSystem> BeamParticleSystem;                                       

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UParticleSystem> ImpactPhysicalSurfaceEffects;               

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<UClass> TracerTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bModifyColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 FLinearColor                                ColorAlteration;                                        

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName                                       ColorParameterName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                    bModifyDecalColour;                                   // 0x08C0(0x0001) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 FLinearColor                                DecalColourAlterationStart;                               // 0x08C4(0x0010) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_IsPlainOldData)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 FLinearColor                                DecalColourAlterationEnd;                                 // 0x08D4(0x0010) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_IsPlainOldData)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                     bModifyShellColour;                                   // 0x08E4(0x0001) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_ZeroConstructor, CPF_IsPlainOldData)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 FLinearColor                                ShellColourAlteration;                                    // 0x08E8(0x0010) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly, CPF_IsPlainOldData)
};

USTRUCT(BlueprintType)
struct FFortConditionalCosmeticModification
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 FFortCosmeticModification                   CosmeticModification;                                     // 0x0000(0x08F8) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer                       ConditionalTags;                                          // 0x08F8(0x0020) (CPF_Edit, CPF_BlueprintVisible, CPF_BlueprintReadOnly)
};

USTRUCT(BlueprintType)
struct FFortConditionalIncludeTags
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 FGameplayTagContainer                       ConditionTags;                                            // 0x0000(0x0020) (CPF_Edit)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 FGameplayTagContainer                       IncludeTags;                                              // 0x0020(0x0020) (CPF_Edit)
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortAlterationItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EFortAlteration> AlterationType;                                          

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 FFortCosmeticModification                   DefaultCosmetic;                                          // 0x0278(0x08F8) (CPF_Edit)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FFortConditionalCosmeticModification> ConditionalCosmetics;                                     // 0x0B70(0x0010) (CPF_Edit, CPF_ZeroConstructor)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FFortConditionalIncludeTags>         AdditionalGameplayTags;                                   // 0x0B80(0x0010) (CPF_Edit, CPF_ZeroConstructor)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UFortAbilitySet> AlterationAbilitySet;                                     // 0x0B90(0x0020) (CPF_Edit)
	
};
