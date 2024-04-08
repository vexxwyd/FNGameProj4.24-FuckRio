// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FortTimeOfDayManager.h"
#include "Components/StaticMeshComponent.h"

AFortTimeOfDayManager::AFortTimeOfDayManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(L"DefaultSceneRoot");

	/* Creating the default weapon mesh */
	SkyDomeMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(L"SkyDomeMeshComp");
	SkyDomeMeshComp->AttachTo(RootComponent);
}
