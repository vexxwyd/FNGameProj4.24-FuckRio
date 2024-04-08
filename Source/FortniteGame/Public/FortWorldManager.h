// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "FortniteGame.h"
#include "FortWorldManager.generated.h"

USTRUCT(BlueprintType)
struct FFortLevelStreamingInfo
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName                                       PackageName;                                              // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EFortLevelStreamingState>              LevelState;                                               // 0x0008(0x0001) (ZeroConstructor, IsPlainOldData)
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bFailedToLoad;                                            // 0x0009(0x0001) (ZeroConstructor, IsPlainOldData)
};

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortWorldManager : public AInfo
{
	GENERATED_BODY()
	
public:

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<struct FFortLevelStreamingInfo>             StreamedLevels;
};
