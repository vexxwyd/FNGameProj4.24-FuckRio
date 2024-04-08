// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BuildingSMActor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "Net/UnrealNetwork.h"

void ABuildingSMActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABuildingSMActor, TextureData);
	DOREPLIFETIME(ABuildingSMActor, StaticMesh);
	DOREPLIFETIME(ABuildingSMActor, ResourceType);
	DOREPLIFETIME(ABuildingSMActor, ReplicatedMIC);
}

// Sets default values
ABuildingSMActor::ABuildingSMActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/* Static mesh */
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent0"));
	StaticMeshComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	StaticMeshComponent->Mobility = EComponentMobility::Static;
	StaticMeshComponent->SetGenerateOverlapEvents(false);
	StaticMeshComponent->bUseDefaultCollision = true;

	RootComponent = StaticMeshComponent;

	// Only actors that are literally static mesh actors can be placed in clusters, native subclasses or BP subclasses are not safe by default
	bCanBeInCluster = (GetClass() == ABuildingActor::StaticClass());
}

void ABuildingSMActor::OnConstruction(const FTransform & Transform)
{

	/* @ Making sure the providen static mesh is valid to then set the static mesh in the component */
	if (StaticMesh)
	{
		StaticMeshComponent->Mobility = EComponentMobility::Movable;
		StaticMeshComponent->SetStaticMesh(StaticMesh);
	}
	else
	{
		StaticMeshComponent->SetStaticMesh(nullptr);
	}
}