// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingAutoNav.h"
#include "BuildingTimeOfDayLights.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API ABuildingTimeOfDayLights : public ABuildingAutoNav
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category="TimeOfDayControlledLights")
	TArray<class ULightComponent*>                     TimeOfDayControlledLights;                             
	
	UPROPERTY(EditAnywhere, Category = "TimeOfDayControlledLights")
	TArray<struct FVector>                             TimeOfDayControlledLightsPositions;                    
	
	UPROPERTY(EditAnywhere, Category = "TimeOfDayControlledLights")
	TArray<float>                                      TimeOfDayControlledLightsInitalIntensities;
};
