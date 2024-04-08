// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortniteGame.h"
#include "Building/BuildingActor.h"
#include "BuildingSMActor.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API ABuildingSMActor : public ABuildingActor
{
	GENERATED_BODY()
	
		/* Texture data */
public:

	UPROPERTY(EditAnywhere, Category = "Instance", Replicated)
		class UBuildingTextureData* TextureData[NumSlots];


public:

	UPROPERTY(EditAnywhere, Replicated, Category = "Instance")
	class UStaticMesh*                                 StaticMesh;

	UPROPERTY(EditAnywhere, Replicated, Category = "Instance")
	TEnumAsByte<EFortResourceType>                     ResourceType;

	UPROPERTY(EditAnywhere, Replicated, Category = "Instance")
	class UMaterialInstanceConstant*                   ReplicatedMIC;

	UPROPERTY(EditAnywhere, Category = "Instance")
	class UMaterialInterface*                          BaseMaterial;

	// Sets default values for this actor's properties
	ABuildingSMActor();

	// Called on construction
	virtual void OnConstruction(const FTransform& Transform) override;

protected:

	UPROPERTY(BlueprintReadOnly)
		class UStaticMeshComponent* StaticMeshComponent;
};
