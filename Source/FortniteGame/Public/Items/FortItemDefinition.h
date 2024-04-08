// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once
/* FortItemDefinition */
/* * Base Definition class for items in Fortnite */
#include "CoreMinimal.h"
#include "McpItemDefinitionBase.h"
#include "FortniteGame/Public/Items/FortItem.h"
#include "Engine/Texture2D.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "FortniteGame.h"
#include "Engine/CurveTable.h"
#include "FortItemSeriesDefinition.h"
#include "FortItemDefinition.generated.h"

/* Weapon statistics structures */
USTRUCT(BlueprintType)
struct FFortBaseWeaponStats : public FTableRowBase
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                BaseLevel;                                

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName                                       NamedWeightRow;                                  

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              DmgPB;                                    

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              DmgMid;                                   

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              DmgLong;                                  

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              DmgMaxRange;                              

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              EnvDmgPB;                                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              EnvDmgMid;                                

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              EnvDmgLong;                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              EnvDmgMaxRange;                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              ImpactDmgPB;                              

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              ImpactDmgMid;                             

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              ImpactDmgLong;                            

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              ImpactDmgMaxRange;                        

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool                                               bForceControl;                            

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RngPB;                                    

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RngMid;                                   

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RngLong;                                  

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RngMax;                                   

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UCurveTable*                                 DmgScaleTable;                            

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName                                       DmgScaleTableRow;                                

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              DmgScale;                                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UCurveTable*                                 EnvDmgScaleTable;                         

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName                                       EnvDmgScaleTableRow;                             

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              EnvDmgScale;                              

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UCurveTable*                                 ImpactDmgScaleTable;                      

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName                                       ImpactDmgScaleTableRow;                          

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              ImpactDmgScale;                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName                                       SurfaceRatioRowName;                             

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              DamageZone_Light;                         

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              DamageZone_Normal;                        

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              DamageZone_Critical;                      

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              DamageZone_Vulnerability;                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              KnockbackMagnitude;                       

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MidRangeKnockbackMagnitude;               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              LongRangeKnockbackMagnitude;              

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              KnockbackZAngle;                          

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              StunTime;                                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              StunScale;                                

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UDataTable*                                  Durability;                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName                                       DurabilityRowName;                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              DurabilityScale;                          

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              DurabilityPerUse;                         

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              DiceCritChance;                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              DiceCritDamageMultiplier;                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              ReloadTime;                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              ReloadScale;                              

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		EFortWeaponReloadType                              ReloadType;                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool                                               bReloadInterruptIsImmediate;              

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                ClipSize;                                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              ClipScale;                                

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                InitialClips;                             

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                CartridgePerFire;                         

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                AmmoCostPerFire;                          

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                MaxAmmoCostPerFire;                       

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MinChargeTime;                            

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MaxChargeTime;                            

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              ChargeDownTime;                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MinChargeDamageMultiplier;                

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MaxChargeDamageMultiplier;                

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              EquipAnimRate;                            

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              QuickBarSlotCooldownDuration;             
};

USTRUCT(BlueprintType)
struct FFortMeleeWeaponStats : public FFortBaseWeaponStats
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RangeVSEnemies;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              ConeYawAngle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              ConePitchAngle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              SwingPlaySpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              SwingTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              BuildingConeAngle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              BuildingConeAnglePitch;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RangeVSBuildings2D;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RangeVSBuildingsZ;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RangeVSWeakSpots;
};

USTRUCT(BlueprintType)
struct FFortRangedWeaponStats : public FFortBaseWeaponStats
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              Spread;                                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              SpreadDownsights;                                     

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              StandingStillSpreadMultiplier;                        

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaCrouchingSpreadMultiplier;                      

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaJumpingFallingSpreadMultiplier;                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaSprintingSpreadMultiplier;                      

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MinSpeedForSpreadMultiplier;                          

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MaxSpeedForSpreadMultiplier;                          

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              SpreadDownsightsAdditionalCooldownTime;               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              HeatX1;                                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              HeatY1;                                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              HeatX2;                                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              HeatY2;                                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              HeatX3;                                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              HeatY3;                                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              HeatXScale;                                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              HeatYScale;                                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              CoolX1;                                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              CoolY1;                                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              CoolX2;                                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              CoolY2;                                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              CoolX3;                                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              CoolY3;                                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              CoolXScale;                                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              CoolYScale;                                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                BulletsPerCartridge;                                  

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              FiringRate;                                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              ROFScale;                                             

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              BurstFiringRate;                                      

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RecoilVert;                                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RecoilVertScale;                                      

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RecoilVertScaleGamepad;                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              VertRecoilDownChance;                                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RecoilHoriz;                                          

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RecoilHorizScale;                                     

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RecoilHorizScaleGamepad;                              

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RecoilInterpSpeed;                                    

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RecoilRecoveryInterpSpeed;                            

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RecoilRecoveryDelay;                                  

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RecoilRecoveryFraction;                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              RecoilDownsightsMultiplier;                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaRecoilMagnitudeMin;                             

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaRecoilMagnitudeMax;                             

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaRecoilMagnitudeScale;                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaRecoilAngleMin;                                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaRecoilAngleMax;                                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaRecoilRollMagnitudeMin;                         

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaRecoilRollMagnitudeMax;                         

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaRecoilInterpSpeed;                              

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaRecoilRecoveryInterpSpeed;                      

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaRecoilDownsightsMultiplier;                     

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaRecoilHipFireMultiplier;                        

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AthenaAimAssistRange;                                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              ADSTransitionInTime;                                  

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              ADSTransitionOutTime;                                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                MaxSpareAmmo;                                         

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int                                                BulletsPerTracer;                                     

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AIDelayBeforeFiringMin;                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AIDelayBeforeFiringMax;                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AIFireDurationMin;                                    

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AIFireDurationMax;                                    

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AIMinSpreadDuration;                                  

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AIMaxSpreadDuration;                                  

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AIDurationSpreadMultiplier;                     

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AIAdditionalSpreadForTargetMovingLaterally;     

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              EQSDensity;                                     

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MinApproachRange;                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MinActualRange;                                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MinPreferredRange;                              

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MinPreferredRangeEQS;                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MaxPreferredRangeEQS;                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MaxPreferredRange;                              

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MaxActualRange;                                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              MaxApproachRange;                               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              SweepRadius;                                    

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float                                              AutoReloadDelayOverride;                        
};

USTRUCT(BlueprintType)
struct FFortLootLevelData : public FTableRowBase
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName                                       Category;                                              
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                LootLevel;                                      
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                MinItemLevel;                                   
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int                                                MaxItemLevel;                                   
};

UCLASS()
class FORTNITEGAME_API UFortItemDefinition : public UMcpItemDefinitionBase
{
	//UFUNCTION(BlueprintCallable)
		//class UFortItem* CreateTemporaryItemInstanceBP(int Count, int Level);

	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		TSoftClassPtr<UObject> OnItemCountChanged;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable)
		EFortItemType ItemType;

	UPROPERTY(EditAnywhere)
		EFortItemType PrimaryAssetIdItemTypeOverride;

	UPROPERTY(EditAnywhere, Category = "Display")
		EFortInventoryFilter FilterOverride;

	UPROPERTY(EditAnywhere, Category = "Display")
		EFortItemTier Tier;

	UPROPERTY(EditAnywhere, Category = "Display")
		EFortItemTier MaxTier;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		EFortTemplateAccess Access;

	UPROPERTY(EditAnywhere)
		bool bIsAccountItem;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category = "Release Version")
		bool bNeverPersisted;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bAllowMultipleStacks = true;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bAutoBalanceStacks = true;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bAllowSwapSingleStack;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bForceAutoPickup;

	UPROPERTY(EditAnywhere, Category = "Inventory Limit")
		bool bInventorySizeLimited = true;

	UPROPERTY(EditAnywhere, Category = "Display")
		FText ItemTypeNameOverride;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category = "Display")
		FText DisplayName;

	UPROPERTY(EditAnywhere, Category = "Display")
	   FText QuantityDisplayName;

	UPROPERTY(EditAnywhere, Category = "Display")
		FText ShortDescription;

	UPROPERTY(EditAnywhere, Category = "Display")
		FText Description;

	UPROPERTY(EditAnywhere)
		FText DisplayNamePrefix;

	UPROPERTY(EditAnywhere, Category = "Display")
		FText SearchTags;

	UPROPERTY(EditAnywhere, Category = "Display")
	    FName GiftBoxGroupName;

	UPROPERTY(EditAnywhere, Category = "Frontend Preview")
	    float FrontendPreviewScale;
	
	UPROPERTY(EditAnywhere, Category = "Owned Tags")
		FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, Category = "Owned Tags")
		FGameplayTagContainer AutomationTags;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		FGameplayTagContainer SecondaryCategoryOverrideTags;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		FGameplayTagContainer TertiaryCategoryOverrideTags;
		
	UPROPERTY(EditAnywhere, Category = "Functionality")
		FScalableFloat MaxStackSize;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		FScalableFloat PurchaseItemLimit;

	UPROPERTY(EditAnywhere, Category = "Tooltips")
		TSoftClassPtr<UObject> TooltipClass;

	/*UPROPERTY(EditAnywhere, Category = "Tooltips")
	TSoftObjectPtr<UFortTooltipDisplayStatsList> StatList;*/
	
	UPROPERTY(EditAnywhere, Category = "Rating")
		FCurveTableRowHandle RatingLookup;

	UPROPERTY(EditAnywhere, Category = "Display")
		TSoftObjectPtr<UTexture2D> WidePreviewImage;

	UPROPERTY(EditAnywhere, Category = "Display")
		TSoftObjectPtr<UTexture2D> SmallPreviewImage;

	UPROPERTY(EditAnywhere, Category = "Display")
		UTexture2D* LargePreviewImage;

	UPROPERTY(EditAnywhere , Category = "Display")
		FSoftObjectPath DisplayAssetPath;

	UPROPERTY(EditAnywhere, Category = "Display")
		EFortRarity Rarity;
	
	UPROPERTY(EditAnywhere, Category = "Display")
	  FDataTableRowHandle PopupDetailsTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Series")
	UFortItemSeriesDefinition* Series;

	/*UPROPERTY(EditAnywhere, Category = "Preview Image")
	    UItemPreviewImageOverride* ItemPreviewImageOverride;*/
	
	UPROPERTY(EditAnywhere, Category = "Prm")
	   FString PrmParameterName;

	UPROPERTY(EditAnywhere, Category = "Frontend Preview")
		FVector FrontendPreviewPivotOffset;

	UPROPERTY(EditAnywhere, Category = "Frontend Preview")
		FRotator FrontendPreviewInitialRotation;

	UPROPERTY(EditAnywhere, Category = "Frontend Preview")
		TSoftObjectPtr<UStaticMesh> FrontendPreviewMeshOverride;

	UPROPERTY(EditAnywhere, Category = "Frontend Preview")
		TSoftObjectPtr<USkeletalMesh> FrontendPreviewSkeletalMeshOverride;

};
