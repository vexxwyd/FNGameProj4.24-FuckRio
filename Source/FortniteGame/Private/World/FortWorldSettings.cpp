// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FortWorldSettings.h"
#include "AI/NavigationSystemConfig.h"
#include "FortniteGame.h"
#include "FortNavSystem.h"

#include <string>

AFortWorldSettings::AFortWorldSettings()
{
	bShowTimeOfDayManager = true;
	bSpawnTimeOfDayManager = true;
}

/* Setting default property values for this class */
void AFortWorldSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (WorldTimeOfDayManager != nullptr)
	{
		if (PropertyChangedEvent.GetPropertyName().Compare(WorldTimeOfDayManager->PropertyLink->GetFName()) > 0 && bSpawnTimeOfDayManager)
		{
			if (TimeOfDayManager != nullptr)
			{
				TimeOfDayManager->K2_DestroyActor();
				UE_LOG(LogFortWorld, VeryVerbose, TEXT("AFortWorldSettings::PostEditChangeProperty: Destroying old Time Of Day Manager"));
			}

			static FActorSpawnParameters SpawnInfo;
			static FRotator spawn_rot(0, 0, 0);
			static FVector spawn_loc(0, 0, 0);

			// Spawn the Time of Day Manager.
			//TimeOfDayManager = static_cast<AFortTimeOfDayManager*>(GetWorld()->SpawnActor<AActor>(WorldTimeOfDayManager, spawn_loc, spawn_rot, SpawnInfo));

			UE_LOG(LogFortWorld, VeryVerbose, TEXT("AFortWorldSettings::PostEditChangeProperty: Changed World Time Of Day Manager"));
		}

		if (TimeOfDayManager != nullptr)
		{
			TimeOfDayManager->bHidden = !bShowTimeOfDayManager;
		}
	}
}