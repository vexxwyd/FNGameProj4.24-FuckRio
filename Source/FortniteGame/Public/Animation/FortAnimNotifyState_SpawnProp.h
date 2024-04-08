// Copyright 1998-2023 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortniteGame/FortniteGame.h"
#include "FortAnimNotifyState_SpawnProp.generated.h"

UCLASS()
class UFortAnimNotifyState_SpawnProp : public UAnimNotifyState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName SocketName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector LocationOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator RotationOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Scale= FVector(1.0f, 1.0f, 1.0f);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<AActor> ActorProp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMesh* SkeletalMeshProp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimationAsset* SkeletalMeshPropAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bInheritScale = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAbsoluteScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bPropAnimLooping = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bPrestreamTextures = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PrestreamTextureDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* StaticMeshProp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEmotePropMaterialScalarParam> PropMaterialScalarParams;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 PropId;                                           

	virtual void NotifyBegin(class USkeletalMeshComponent * MeshComp, class UAnimSequenceBase * Animation, float TotalDuration) override;
};