// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPlaylist.h"
#include "FortMissionGenerator.h"
#include "Styling/SlateBrush.h"
#include "AttributeSet.h"
#include "FortPlaylistAthena.generated.h"

USTRUCT(BlueprintType)
struct FSupplyDropSubPhaseModifier
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAthenaGamePhase                                   GamePhase;                                   
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                SubPhaseIndex;                               
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              SpawnInPreviousZonePercentChance;            
};

USTRUCT(BlueprintType)
struct FSupplyDropModifierData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName                                       SupplyDropID;                                       
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FSupplyDropSubPhaseModifier>         ModifierList;                                
};

USTRUCT(BlueprintType)
struct FPlaylistUIExtension
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPlaylistUIExtensionSlot                           Slot;                                        
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<class UClass>                       WidgetClass;                                  
};

USTRUCT(BlueprintType)
struct FItemAndCount
{
	GENERATED_BODY()

public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                Count;                                       
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UFortItemDefinition*                         Item;                                        
};

USTRUCT(BlueprintType)
struct FRatingExpansion
{
	GENERATED_BODY()

public:

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                Priority;                                    
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                RatingDelta;                                 
};

USTRUCT(BlueprintType)
struct FAthenaScoreData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAthenaScoringEvent                                ScoringEvent;                                          
				
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                       ScoreNameText;                                         
				
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FGameplayTagContainer                       EventInclusionTags;                                    
				
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                NumOccurrencesForScore;                                
				
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                NumOccurrencesPermitted;                               
				
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FScalableFloat                              ScoreAwarded;                                          
};				
	

USTRUCT(BlueprintType)
struct FWinConditionScoreData
{
	GENERATED_BODY()

public:
			
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FScalableFloat                              GoalScore;                                             
			
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FScalableFloat                              BigScoreThreshold;                                     
			
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FAthenaScoreData>                    ScoreDataList;                                         
};


/**
 * 
 */
UCLASS()
class FORTNITEGAME_API UFortPlaylistAthena : public UFortPlaylist
{
	GENERATED_BODY()
	
public:

		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bRewardsTrackPlacement = true;                                
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bRewardsAllowXPProgression = true;                            
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bRewardForRevivingTeammates;                           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERewardPlacementBonusType                          RewardPlacementBonusType;                              
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                RewardsPlacementThreshold;                             
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERewardTimePlayedType                              RewardTimePlayedType;                                                                   
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                RewardTimePlayedXPPerMinute;                           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                RewardTimePlayedXPFlatValue;                           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bAllowSinglePartyMatches;                              
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bRequeueAfterFailedSessionAssignment = 1;                  
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bIsTournament;                                         
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bEnableAdvancedLogic;                                  
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bUpdateMMR;                                                                            
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString                                            RatingType;                                            
    	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString                                            Strategy;                                              
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString                                            SessionAssignmentChannel;                              
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                MaxBucketCapacity;                                     
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                MaxPendingMatches;                                     
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FRatingExpansion>                    PriorityRatingExpansion;                               
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bUseInputRules = 1;                                        
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bRequireCrossplayEnabled;                              
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bLimitedPoolMatchmakingEnabled;                                                     
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                CompetitivePointClamp;                                 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bUseMultidivisionQueues;                               
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAthenaWinCondition                                WinConditionType;                                                                       
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FScalableFloat                              TimedWinConditionTime;                                 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FScalableFloat                              FinalWinConditionTime;                                 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FWinConditionScoreData                      ScoringData;                                           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FScalableFloat                              TimedSafeZonePhaseTime;                                
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                WinConditionPlayersRemaining;                          
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bIsLargeTeamGame;                                      
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bShouldSpreadTeams = 1;                                    
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bIgnoreDefaultQuests;                                  
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bDisallowMultipleWeaponsOfType;                        
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bAllowEditingEnemyWalls;                                                           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                LootDropRounds;                                        
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              ForceKickAfterDeathTime;                               
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EForceKickAfterDeathMode                           ForceKickAfterDeathMode;                               
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWeaponSelectionPreservationType                   QuickbarSelectionPreservationMode;                                                   
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FGameplayTagContainer                       AlwaysAllowedNativeActions;                            
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FItemAndCount>                       InventoryItemsToGrant;                                 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              DestructedBuildingInGridTimeout;                       
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bTeamFilterDestructedBuildingsInGrid;                  
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bOwnerFilterDestructedBuildingsInGrid;                                                   
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              MaximumAspectRatio;                                    
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bVehiclesDestroyAllBuildingSMActorsOnContact;          
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bForceCameraFadeOnRespawn = 1;                                                            
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              MinTimeBeforeRespawnCameraFade;                        
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAthenaRespawnType                                 RespawnType;                                                                           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FScalableFloat                              RespawnHeight;                                         
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FScalableFloat                              MaxRespawnHeight;                                      
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FScalableFloat                              RespawnTime;                                           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bRespawnInAir;                                                                       
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FScalableFloat                              RespawnLevelStreamDistanceToForceSceenFade;            
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bSkipWarmup;                                           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bSkipAircraft;                                         
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAirCraftBehavior                                  AirCraftBehavior;                                      
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bUseCustomAircraftPathSelection;                       
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bUseSameDirectionForOpposingAircraft;                                                    
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              AircraftPathOffsetFromMapCenterMin;                    
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              AircraftPathOffsetFromMapCenterMax;                    
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              AircraftPathMidpointSelectionRadiusMin;                
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              AircraftPathMidpointSelectionRadiusMax;                
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UFortMissionGenerator*                                     PlaylistMissionGen;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bForceLTMLoadingScreenBackground;                                                       
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<class UClass>                       LoadingScreenWidget;                                   
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FPlaylistUIExtension>                UIExtensions;                                          
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UClass*                                      UIExtenderClass;                                       
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<class UFortPlaylistUIInfo>          PlaylistUIData;                                        
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTexture2D*                                  MissionIcon;                                           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                       UIDisplaySubName;                                      
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FScalableFloat                              OnlyRespectsGlobalSettingForReplayRecording;           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bLimitedTimeMode = 1;                                      
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bDisplayScoreInHUD;                                    
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bDisplayRespawnWidget;                                 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bEnforceFullSquadInUI;                                                               
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FSlateBrush                                 MapImageOverride;                                      
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              MapScaleOverride;                                      
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bDrawCreativeDynamicIslands;                           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESafeZoneStartUp                                   SafeZoneStartUp;                                       
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bWarmUpInStorm;                                                                        
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              StormEffectDelay;                                      
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bDisplayFinalStormPosition;                            
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bDrawLineToStormCircleIfOutside = 1;                                                       
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                LastSafeZoneIndex;                                     
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bUseDefaultSupplyDrops = 1;                                                                 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FSupplyDropModifierData>             SupplyDropModifierList;                                
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSoftClassPtr<class UFortSupplyDropInfo>>  SupplyDropInfoList;                                    
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSoftClassPtr<class UDataTable>>           QueryNameToLootChanceScaleTables;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSoftClassPtr<class UDataTable>>           QueryNameToLootCountScaleTables;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<class UFortAthenaExitCraftInfo>     ExitCraftInfo;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bPlaylistUsesCustomCharacterParts;                                                     
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSoftClassPtr<class UFortSpawnActorInfo>>  SpawnActorInfoList;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                NetActorDiscoveryBudgetInKBytesPerSec;                 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                              bEnableCreativeMode;                               
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                              bAllowTeamSwitching;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                              bAllowLayoutRequirementsFeature;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool                                              bUseCreativeStarterIsland;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bUsesAnimationSharing;                                                          
		
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TSoftObjectPtr<class UAnimationSharingSetup>       AnimationSharingSetup;                                 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                PlaylistStatId;                                        
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bAccumulateToProfileStats;                             
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bSaveToRecentGameList;                                 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bEnableStatsV2Stats;                                                                      
//	class UAthenaAISettings*                           AISettings;
};
