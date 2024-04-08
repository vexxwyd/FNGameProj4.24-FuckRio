// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FortPickupEffect.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "Items/FortWorldItemDefinition.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/SkeletalMeshComponent.h"

UMaterialInstanceDynamic * AFortPickupEffect::ApplyCosmeticOverridesToMaterial(UMeshComponent * MeshComponent, int MatIndex)
{
	/* Return the created dynamic material instance */
	return 	MeshComponent->CreateDynamicMaterialInstance(MatIndex, MeshComponent->GetMaterial(MatIndex));
}

// Sets default values
AFortPickupEffect::AFortPickupEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/* ------------------COMPONENTS-----------------------*/
	/* @ Creating basic components for this pickup effect */
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemStaticMesh0"));
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ItemSkeletalMesh0"));

	/* @ Attachment */
	StaticMeshComponent->AttachTo(RootComponent);
	SkeletalMeshComponent->AttachTo(RootComponent);

	bDoNotTickSkeletalMeshComponents ? SkeletalMeshComponent->bTickInEditor = false : SkeletalMeshComponent->bTickInEditor = true;
}

// Called when the game starts or when spawned
void AFortPickupEffect::BeginPlay()
{
	Super::BeginPlay();
}

void AFortPickupEffect::OnConstruction(const FTransform & Transform)
{
	/* ---- Item definition support ----*/
    /* @ Setting the skeletal mesh      */
	/*if (ItemDefinition)
	{
		if (TSoftObjectPtr<USkeletalMesh>* PickupSkeletalMesh = ItemDefinition->PickupSkeletalMesh)
		{
			SkeletalMesh = PickupSkeletalMesh;
		}
	}

	/* @ Making sure one of them is valid, we are using 'else if' because we don't want both, skeletal mesh and static mesh to show up */
	if (StaticMesh)
	{
		StaticMeshComponent->SetStaticMesh(StaticMesh);
		SkeletalMeshComponent->SetSkeletalMesh(nullptr);
	}
	else if (SkeletalMesh)
	{
		SkeletalMeshComponent->SetSkeletalMesh(SkeletalMesh);
		StaticMeshComponent->SetStaticMesh(nullptr);
	}
	else
	{
		SkeletalMeshComponent->SetSkeletalMesh(nullptr);
		StaticMeshComponent->SetStaticMesh(nullptr);
	}
}

// Called every frame
void AFortPickupEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

