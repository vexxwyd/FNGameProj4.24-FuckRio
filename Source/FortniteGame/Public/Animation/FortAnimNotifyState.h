// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortniteGame/FortniteGame.h"
#include "FortAnimNotifyState.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FORTNITEGAME_API UFortAnimNotifyState : public UAnimNotify
{
	GENERATED_BODY()
	
public:
};

USTRUCT(BlueprintType)
struct FEmoteRetargetingNotifyParameters 
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	  EFortPlayerAnimBodyType BodyTypeToAffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	  EFortHandIKOverrideType LeftHandIK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	  EFortHandIKOverrideType RightHandIK; 
};

UCLASS(BlueprintType)
class UFortAnimNotifyState_EmoteRetargeting : public UAnimNotifyState 
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 TArray<FEmoteRetargetingNotifyParameters> EmoteParameters;

};

USTRUCT(BlueprintType)
struct FEmotePropMaterialScalarParam
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere)
	FName ParamName; // 0x00(0x08)

	UPROPERTY(EditAnywhere)
	float ParamValue; // 0x08(0x04)
};	