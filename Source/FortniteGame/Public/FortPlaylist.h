// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortniteGame.h"
#include "GameplayTagContainer.h"
#include "FortPlaylist.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API UFortPlaylist : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                PlaylistId;                             
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName                                       PlaylistName;                                  
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                MinPlayers;                             
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                MaxPlayers;                             
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                MaxTeamCount;                           
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                MaxTeamSize;                            
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                MaxSocialPartySize;                     
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                MaxSquadSize;                           
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                MaxSquads;                              
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               EnforceSquadFill;                       
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bAllowSquadFillOption = 1;                  
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bAllowJoinInProgress;                               
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                       JoinInProgressMatchType;                
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bAllowBroadcasting;                           
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPlaylistUserOptions*                        UserOptions;                            
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSoftObjectPtr<class UWorld>>               AdditionalLevels;                       
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8                                              DefaultFirstTeam;                       
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8                                              DefaultLastTeam;                                 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FGameplayTagContainer                       GameplayTagContainer;                   
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFriendlyFireType                                  FriendlyFireType;                       
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bUseFriendlyFireAimAssist;                         
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                LootLevel;                              
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FGameplayTagQuery                           LootTagQuery;                           
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                BuildingLevelOverride;                  
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDBNOType                                          DBNOType;                                                   
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              SpawnImmunityTime;                                       
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSoftObjectPtr<class UFortGameplayModifierItemDefinition>> ModifierList;            
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<class UClass>                       TimeOfDayManager;                       
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class UFortWorldItemDefinition*>            ItemsToFullyLoad;                       
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bIsDefaultPlaylist;                     
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                       UIDisplayName;                                 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                       UIDescription;                                 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FGameplayTagContainer                       HUDElementsToHide;                      
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<class UDataTable>                   LootTierData;                           
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<class UDataTable>                   LootPackages;                           
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<class UDataTable>                   RangedWeapons;                          
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<class UCurveTable>                  GameData;                               
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<class UCurveTable>                  ResourceRates;                          
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              GarbageCollectionFrequency;             
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              ServerPerformanceEventFrequency;        
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              ServerMetricsEventFrequency;           

};
