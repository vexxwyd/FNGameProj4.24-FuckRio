// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPawn.h"
#include "GameFramework/Actor.h"
#include "BuildingActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBuildingActorOnInteract, ABuildingActor*, SelfActor, AFortPawn*, InteractingPawn);

UCLASS()
class FORTNITEGAME_API ABuildingActor : public AActor
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGuid                                       MyGuid;  
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText                                       InteractionText;

	UFUNCTION(BlueprintImplementableEvent)
		void BlueprintOnInteract(class AFortPawn* InteractingPawn);

	UFUNCTION(BlueprintImplementableEvent)
		void BlueprintOnBeginInteract();

	UFUNCTION(BlueprintImplementableEvent)
		bool BlueprintCanInteract(class AFortPawn* InteractingPawn);

	UPROPERTY(BlueprintAssignable)
		FBuildingActorOnInteract BuildingActorOnInteract;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                              bAllowInteract;

	// Sets default values for this actor's properties
	ABuildingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
