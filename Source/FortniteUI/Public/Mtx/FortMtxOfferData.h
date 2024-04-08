// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "FortMtxOfferData.generated.h"

USTRUCT(BlueprintType)
struct FFortMtxDetailsAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText                                       Name;            
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText                                       Value;                                        
};

USTRUCT(BlueprintType)
struct FFortMtxGradient
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	struct FLinearColor                                Start;            
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	struct FLinearColor                                Stop;                                               
};

/**
 * 
 */
UCLASS()
class FORTNITEUI_API UFortMtxOfferData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText                                       DisplayName;                                      
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText                                       ShortDisplayName;                                 
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText                                       ShortDescription;                                 
	
	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	//TArray<struct FFortItemQuantityPair>               GrantOverride;                                    
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	struct FSlateBrush                                 TileImage;                                        
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	struct FSlateBrush                                 BadgeImage;                                       
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	struct FSlateBrush                                 DetailsImage;                                     
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<struct FFortMtxDetailsAttribute>            DetailsAttributes;                                
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	struct FFortMtxGradient                            Gradient;                                         
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	struct FLinearColor                                Background;

};
