// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/NetSerialization.h"
#include "FortniteGame.h"
#include "GameplayAbilitySpec.h"
#include "FortPickup.generated.h"

USTRUCT(BlueprintType)
struct FFortPickupLocationData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AFortPawn*                                   PickupTarget;                                      
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AFortPickup*                                 CombineTarget;                                     
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AFortPawn*                                   ItemOwner;                                         

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FVector_NetQuantize10                       LootInitialPosition;                               
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FVector_NetQuantize10                       LootFinalPosition;                                 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              FlyTime;                                           
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FVector_NetQuantizeNormal                   StartDirection;                                    
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FVector_NetQuantize10                       FinalTossRestLocation;                             
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFortPickupTossState                               TossState;                                       
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bPlayPickupSound;                                                      
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FGuid                                       PickupGuid;                                        
};

USTRUCT(BlueprintType)
struct FFortItemEntryStateValue
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                IntValue;                                             
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName                                       NameValue;                                            
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EFortItemEntryState>                   StateType;                                                                       
};

USTRUCT(BlueprintType)
struct FFortGiftingInfo
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString                                     PlayerName;              
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UFortAccountItemDefinition*                               HeroType;          // UFortHeroType                                                             
};

USTRUCT(BlueprintType)
struct FFortItemEntry : public FFastArraySerializerItem
{

	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                Count;                                               
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                PreviousCount;                                                                   
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UFortItemDefinition*                         ItemDefinition;                                      
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              Durability;                                          
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                Level;                                               
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                LoadedAmmo;                                                                        
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString>                             AlterationDefinitions;                               
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString                                     ItemSource;                                          
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FGuid                                       ItemGuid;                                            
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               inventory_overflow_date;                             
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bWasGifted;                                          
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bIsReplicatedCopy;                                   
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bIsDirty;                                            
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bUpdateStatsOnCollection;                                                          
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FFortGiftingInfo                            GiftingInfo;                                         
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FFortItemEntryStateValue>            StateValues;                                         
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TWeakObjectPtr<class AActor>               ParentInventory;    // Should be AFortInventory                                  
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FGameplayAbilitySpecHandle                  GameplayAbilitySpecHandle;                                                     
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class UFortAccountItemDefinition*>       AlterationInstances;                  // Should be UFortAlterationItemDefinition               
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<float>                                      GenericAttributeValues;                                                     

};
UCLASS()
class FORTNITEGAME_API AFortPickup : public AActor
{
	GENERATED_BODY()
	
/* Delegates */
//TMulticastScriptDelegate<PickupOnPickup>           OnPickup;                                          
//TMulticastScriptDelegate<PickupOnPickup>           OnPickupAttempted;       

public:	

		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bUsePickupWidget;                                  
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bWeaponsCanBeAutoPickups;                          
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bAutoUpgradeWeapons;                                                             
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bRandomRotation;                                                                
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FFortItemEntry                              PrimaryPickupItemEntry;                            
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FFortItemEntry>                      MultiItemPickupEntries;                            
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FFortPickupLocationData                     PickupLocationData;                                
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8                                             PickupSourceTypeFlags;                             
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFortPickupSpawnSource                             PickupSpawnSource;                                                             
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                OptionalOwnerID;                                   
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FGuid                                       OptionalMissionGuid;                                                           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UFortItem*                                   PrimaryPickupDummyItem;                            
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TWeakObjectPtr<class AActor>                       PickupEffectBlueprint;        // Should be AFortPickupEffect                     
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCapsuleComponent*                           TouchCapsule;                                      
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UProjectileMovementComponent*                MovementComponent;                                 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bPickedUp;                                         
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bSplitOnPickup;                                    
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bTossedFromContainer;                              
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bCombinePickupsWhenTossCompletes;                  
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bServerStoppedSimulation;                          
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bClientUseInterpolationOnly;              
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8                                              ServerImpactSoundFlash;                                                       
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              LastLandedSoundPlayTime;                         
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              LandSoundZForceThreshold;                          
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              DefaultFlyTime;                                    
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bForceDefaultFlyTime;                                                          
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAudioComponent*                             DroppedLoopingSoundComp;                           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AFortPawn*                                   PawnWhoDroppedPickup;                              
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                CachedSpecialActorIdx;                             
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName                                              SpecialActorID;                                                                 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UObject*                                     MiniMapIndicator;                       // Should be UFortSimpleMiniMapIndicator           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UObject*                                     HUDLabel;                               // Should be UFortSlateHUDIndicator                     
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              DespawnTime;                                       
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              StormDespawnTime;

	// Sets default values for this actor's properties
	AFortPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
