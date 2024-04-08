// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BuildingContainer.h"

// Sets default values
ABuildingContainer::ABuildingContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuildingContainer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuildingContainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

