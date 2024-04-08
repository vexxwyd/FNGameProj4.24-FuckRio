// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPtr.h"
#include "Items/FortWorldItemDefinition.h"
#include "Items/FortAlterationItemDefinition.h"
#include "FortWeaponItemDefinition.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API UFortWeaponItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data Effects")
		TSoftClassPtr<UObject> WeaponActorClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
		TSoftObjectPtr<USkeletalMesh> WeaponMeshOverride;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
		 FDataTableRowHandle WeaponStatHandle;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
		TSoftObjectPtr<UFortAlterationItemDefinition> BaseAlteration;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
		TSoftObjectPtr<UFortAlterationItemDefinition> BaseCosmeticAlteration;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
		TSoftClassPtr<UObject> PrimaryFireAbility;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
		TSoftClassPtr<UObject> SecondaryFireAbility;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
		TSoftClassPtr<UObject> ReloadAbility;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
		TSoftObjectPtr<UFortWorldItemDefinition> AmmoData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	float LowAmmoPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	float DegradedPercentage;  
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Firing")
		EFortWeaponTriggerType TriggerType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Firing")
	bool bAllowTargetingDuringReload = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display")
		uint8 DisplayTier;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reticle")
		TSoftObjectPtr<UTexture2D> ReticleImage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reticle")
	TArray<float> ReticleCornerAngles;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reticle")
		TSoftObjectPtr<UTexture2D> HitNotifyImage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reticle")
		TSoftObjectPtr<UTexture2D> MuzzleBlockedImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reticle")
	TArray<float> HitNotifyCornerAngles;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reticle")
		TSoftObjectPtr<UTexture2D> ReticleCenterImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reticle")
	FVector2D ReticleCenterImageOffset; 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reticle")
		TSoftObjectPtr<UTexture2D> ReticleCenterPerfectAimImage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reticle")
		bool bReticleCornerOutsideSpreadRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reticle")
	float HitNotifyDuration;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reticle")
	TAssetPtr<UCurveFloat> HitNotifyOpacityCurve;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
	bool bValidForLastEquipped = true;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("Weapon", GetFName());
	}
};
