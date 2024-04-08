// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FortPickup.h"

// Sets default values
AFortPickup::AFortPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFortPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFortPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

