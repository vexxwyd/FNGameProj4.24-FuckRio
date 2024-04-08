// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BuildingActor.h"

// Sets default values
ABuildingActor::ABuildingActor()
{
	// Set a new GUID for this BuildingActor.
	MyGuid = FGuid();

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABuildingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuildingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

