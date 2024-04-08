// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortniteGame.h"
#include "Components/SlateWrapperTypes.h"
#include "Player/FortPlayerControllerGameplay.h"
#include "FortPlayerControllerAthena.generated.h"


USTRUCT(BlueprintType)
struct FSettingsHUDVisibilityAndText
{
	GENERATED_BODY()

public:

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		struct FGameplayTag                                HUDVisibilityGameplayTag;                                 // 0x0000(0x0008) (Edit, DisableEditOnInstance)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESlateVisibility                                 DefaultHUDVisibility;                                     // 0x0008(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText                                       DisplayText;                                              // 0x0010(0x0018) (Edit, DisableEditOnInstance)

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText                                       ToolTipText;                                              // 0x0028(0x0018) (Edit, DisableEditOnInstance)
};


/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortPlayerControllerAthena : public AFortPlayerControllerGameplay
{
	GENERATED_BODY()

		
		UFUNCTION(BlueprintCallable)
			void ServerThankBusDriver();
		
		UFUNCTION(BlueprintCallable)
		void ServerStartMinigame();
		
		UFUNCTION(BlueprintCallable)
		void ServerSpawnCreativeSupplyDrop(struct FVector Position, class UClass* InSupplyDropClass);
		
		UFUNCTION(BlueprintCallable)
		void ServerRestartMinigame();
		
		UFUNCTION(BlueprintCallable)
		void ServerEndMinigame(bool bAbandon);
		
		UFUNCTION(BlueprintCallable)
		void ServerEndLoadingVolume(class AActor* VolumeToLoad);
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FSettingsHUDVisibilityAndText>       HUDVisibilityGameplayTags;
};
