// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FortPlayerController.generated.h"

class AFortInventory;

UCLASS()
class FORTNITEGAME_API AFortPlayerController : public APlayerController
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
		void ServerAttemptInteract(class AActor* ReceivingActor);

	UFUNCTION()
		void HandleWorldInventoryLocalUpdate();

public:

	/** @ Returns World Inventory object */
	AFortInventory* GetWorldInventory() const { return WorldInventory; }

	UPROPERTY(EditAnywhere, ReplicatedUsing=HandleWorldInventoryLocalUpdate)
	class AFortInventory*                              WorldInventory;
};
