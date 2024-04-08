// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortniteGame/FortniteGame.h"
#include "FortAnimNotifyState_EmoteSound.generated.h"

UCLASS(BlueprintType)
class UFortAnimNotifyState_EmoteSound : public UAnimNotifyState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USoundBase* EmoteSound1P;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USoundBase* EmoteSound3P;;

	virtual void NotifyBegin(class USkeletalMeshComponent * MeshComp, class UAnimSequenceBase * Animation, float TotalDuration) override;
};