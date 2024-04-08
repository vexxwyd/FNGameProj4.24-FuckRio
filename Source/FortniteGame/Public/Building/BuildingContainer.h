// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingTimeOfDayLights.h"
#include "BuildingContainer.generated.h"

UCLASS()
class FORTNITEGAME_API ABuildingContainer : public ABuildingTimeOfDayLights
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingContainer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
