// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "GameplayTagContainer.h"
#include "FortMissionGenerator.generated.h"

USTRUCT(BlueprintType)
struct FFortMultiSizeBrush
{
	GENERATED_BODY()
public:

		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FSlateBrush                                 Brush_XXS;                                  
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FSlateBrush                                 Brush_XS;                                   
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FSlateBrush                                 Brush_S;                                    
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FSlateBrush                                 Brush_M;                                    
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FSlateBrush                                 Brush_L;                                    
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FSlateBrush                                 Brush_XL;                                   
};

USTRUCT(BlueprintType)
struct FFortPlayerSpawnPadPlacementData
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UDataAsset*                                   PlacementQuery;                             
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<class UClass>                       ActorToPlace;                                
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bSnapToGrid;                                
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bAdjustPlacementForFloors;                  
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FGameplayTagContainer                       TagsToAddToChosenPlacementActor;            
};

USTRUCT(BlueprintType)
struct FZoneLoadingScreenConfig
{
	GENERATED_BODY()
public:
	 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<class UTexture2D>                   BackgroundImage;                             
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                       TitleDescription;                                  
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                       Title;                                             

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class UFortTips*>                           LoadingTips;                                
};

USTRUCT(BlueprintType)
struct FFortAthenaLTMConfig
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<class UTexture2D>                   SplashImage;                                 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                       FrontEndDescription;                               
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                       DisabledMessage;                                   
};

USTRUCT(BlueprintType)
struct FFortPossibleMission
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<class UFortMissionInfo>             MissionInfo;                                
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              Weight;                                     
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int                                                MinAlwaysGenerated;                         
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bIsPrototype;                               
};


/**
 * 
 */
UCLASS()
class FORTNITEGAME_API UFortMissionGenerator : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                       MissionName;                                           
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                       MissionDescription;                                    
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSlateBrush                                 MissionIcon;                                           
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FFortMultiSizeBrush                         MissionIcons;                                          
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FZoneLoadingScreenConfig                    LoadingScreenConfig;                                   
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FFortAthenaLTMConfig                        AthenaLTMConfig;                                       
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<class UFortMissionInfo>             PrimaryMissionInfo;                                    
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bUseNewMissionGeneration;                              
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FGameplayTagQuery                           OptionalRequirementsForAllOtherMissions;               
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<class UFortMissionGenerationList>   MissionGenerationList;                                 
	
	// STATIC ARRAY
	UPROPERTY()
	float                                              MissionGenerationChance;                          
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FFortPossibleMission>                SecondaryMissionList;                                  
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FFortPossibleMission>                TertiaryMissionList;                                   
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FFortPossibleMission>                SurvivorMissionList;                                   
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bUseOverridePlayerSpawnPadPlacementData;               
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FFortPlayerSpawnPadPlacementData            OverridePlayerSpawnPadPlacementData;
};
