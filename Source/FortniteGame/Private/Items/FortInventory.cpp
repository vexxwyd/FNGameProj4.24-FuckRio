// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FortInventory.h"

// Sets default values
AFortInventory::AFortInventory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFortInventory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFortInventory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

