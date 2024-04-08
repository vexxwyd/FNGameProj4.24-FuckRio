// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FortniteGame.h"
#include "FortPawn.generated.h"

class AFortWeapon;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortPawnEquippedWeaponSignature, AFortWeapon*, NewWeapon, AFortWeapon*, PrevWeapon);

UCLASS()
class AFortPawn : public ACharacter
{
	GENERATED_UCLASS_BODY()

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	/** @ Updates the Pawn's cull distance. TODO */
	void UpdateCullDistance();

	/** Global notification when a character equips a weapon. Needed for replication graph. */
    FORTNITEGAME_API static FFortPawnEquippedWeaponSignature NotifyWeaponChange;

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<class AFortWeapon*>                         CurrentWeaponList;
public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
