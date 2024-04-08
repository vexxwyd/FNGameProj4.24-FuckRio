// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortItemDefinition.h"
#include "Sound/SoundBase.h"
#include "Engine/SkeletalMesh.h"
#include "FortWorldItemDefinition.generated.h"


USTRUCT(BlueprintType)
struct FFortPickupTagTestContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FGameplayTagContainer Tags;

	UPROPERTY(EditAnywhere)
		FText FailReason;
};

USTRUCT(BlueprintType)
struct FFortPickupRestrictionLists
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FFortPickupTagTestContainer WhiteList;

	UPROPERTY(EditAnywhere)
		FFortPickupTagTestContainer Blacklist;
};

UENUM()
enum class EWorldItemDropBehavior : uint8
{
	DropAsPickup                   = 0,
	DestroyOnDrop                  = 1,
	DropAsPickupDestroyOnEmpty     = 2,
	DropAsPickupEvenWhenEmpty      = 3,
	EWorldItemDropBehavior_MAX     = 4
};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortWorldItemDefinition : public UFortItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Functionality")
		FGameplayTagContainer RequiredEquipTags;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		TArray<FFortPickupRestrictionLists> PickupRestrictionListEntry;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		EWorldItemDropBehavior DropBehavior;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bIgnoreRespawningForDroppingAsPickup;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bCanAutoEquipByClass = true;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bPersistInInventoryWhenFinalStackEmpty;

	UPROPERTY(EditAnywhere, Category = "Display")
		bool bSupportsQuickbarFocus = true;

	UPROPERTY(EditAnywhere, Category = "Display")
		bool bSupportsQuickbarFocusForGamepadOnly;

	UPROPERTY(EditAnywhere, Category = "Display")
		bool bShouldActivateWhenFocused;

	UPROPERTY(EditAnywhere, Category = "Display")
		bool bForceFocusWhenAdded;

	UPROPERTY(EditAnywhere, Category = "Display")
		bool bForceIntoOverflow;

	UPROPERTY(EditAnywhere, Category = "Display")
		bool bForceStayInOverflow;

	UPROPERTY(EditAnywhere, Category = "Display")
		bool bDropCurrentItemOnOverflow = true;

	UPROPERTY(EditAnywhere, Category = "Display")
		bool bShouldShowItemToast = true;

	UPROPERTY(EditAnywhere, Category = "Pickup Visuals")
		bool bShowDirectionalArrowWhenFarOff = true;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bCanBeDropped = true;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bCanBeReplacedByPickup= true;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bItemCanBeStolen = true;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bCanBeDepositedInStorageVault = true;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bItemHasDurability = true;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bAllowedToBeLockedInInventory;

	UPROPERTY(EditAnywhere, Category = "Pickup Visuals")
		bool bOverridePickupMeshTransform;

	UPROPERTY(EditAnywhere, Category = "Special Actor")
		bool bAlwaysCountForCollectionQuest;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bDropOnDeath;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bDropOnLogout;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bDropOnDBNO;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		bool bDoesNotNeedSourceSchematic;

	UPROPERTY(EditAnywhere)
		bool bUsesGoverningTags;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		int DropCount = -1;

	UPROPERTY(EditAnywhere, Category = "Pickup Visuals")
		float MiniMapViewableDistance = 8000;

	UPROPERTY(EditAnywhere, Category = "Pickup Visuals")
		FSlateBrush MiniMapIconBrush;

	UPROPERTY(EditAnywhere, Category = "OwnerPickupText")
		FText OwnerPickupText;

	UPROPERTY(EditAnywhere, Category = "Loot Level")
		FDataTableCategoryHandle LootLevelData;

	UPROPERTY(EditAnywhere, Category = "Pickup Visuals")
		FTransform PickupMeshTransform;

	UPROPERTY(EditAnywhere, Category = "Special Actor")
		bool bIsPickupASpecialActor;

	UPROPERTY(EditAnywhere, Category = "Special Actor")
		FGameplayTag SpecialActorPickupTag;

	//UPROPERTY(EditAnywhere)
	//	TArray<FSpecialActorSingleStatData> SpecialActorPickupStatList;

	UPROPERTY(EditAnywhere, Category = "Special Actor")
		FName PickupSpecialActorUniqueID;

	UPROPERTY(EditAnywhere, Category = "Special Actor")
		FSlateBrush PickupMinimapIconBrush;

	UPROPERTY(EditAnywhere, Category = "Special Actor")
		FVector2D PickupMinimapIconScale;

	UPROPERTY(EditAnywhere, Category = "Special Actor")
		FSlateBrush PickupCompassIconBrush;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		FScalableFloat PickupDespawnTime;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		FScalableFloat InStormPickupDespawnTime;

	UPROPERTY(EditAnywhere, Category = "Functionality")
		FScalableFloat NetworkCullDistanceOverride;

	UPROPERTY(EditAnywhere, Category = "Pickup Visuals")
		TSoftObjectPtr<UStaticMesh> PickupStaticMesh;

	UPROPERTY(EditAnywhere, Category = "Pickup Visuals")
		TSoftObjectPtr<USkeletalMesh> PickupSkeletalMesh;

	UPROPERTY(EditAnywhere, Category = "Pickup Visuals")
		UClass* PickupEffectOverride;

	UPROPERTY(EditAnywhere, Category = "Sounds")
		TSoftObjectPtr<USoundBase> PickupSound;

	UPROPERTY(EditAnywhere, Category = "Sounds")
		TSoftObjectPtr<USoundBase> PickupByNearbyPawnSound;

	UPROPERTY(EditAnywhere, Category = "Sounds")
		TSoftObjectPtr<USoundBase> DropSound;

	UPROPERTY(EditAnywhere, Category = "Sounds")
		TSoftObjectPtr<USoundBase> DroppedLoopSound;

	UPROPERTY(EditAnywhere, Category = "Sounds")
		TSoftObjectPtr<USoundBase> LandedSound;

	UPROPERTY(EditAnywhere, Category = "Disassembly")
		FDataTableRowHandle DisassembleRecipe;

	UPROPERTY(EditAnywhere, Category = "Disassembly")
		float DisassembleDurabilityDegradeMinLootPercent = 0.2;

	UPROPERTY(EditAnywhere, Category = "Disassembly")
		float DisassembleDurabilityDegradeMaxLootPercent = 0.8;

	UPROPERTY(EditAnywhere)
		int PreferredQuickbarSlot = -1;

	UPROPERTY(EditAnywhere, Category = "Level")
		int MinLevel = 1;

	UPROPERTY(EditAnywhere, Category = "Level")
		int MaxLevel = -1;

	UPROPERTY(EditAnywhere, Category = "Inventory")
		uint8 NumberOfSlotsToTake = 1;
};
