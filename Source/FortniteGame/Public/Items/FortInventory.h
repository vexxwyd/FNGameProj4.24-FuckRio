// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortInventory.generated.h"

UCLASS()
class FORTNITEGAME_API AFortInventory : public AActor
{
	GENERATED_BODY()

	// Sets default values for this actor's properties
	AFortInventory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
