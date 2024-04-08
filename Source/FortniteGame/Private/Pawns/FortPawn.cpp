// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FortPawn.h"

FFortPawnEquippedWeaponSignature AFortPawn::NotifyWeaponChange;

void AFortPawn::UpdateCullDistance()
{
	// To be implemented
}

// Sets default values
AFortPawn::AFortPawn(const FObjectInitializer& ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFortPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFortPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFortPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

