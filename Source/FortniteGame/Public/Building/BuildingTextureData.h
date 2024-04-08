// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortniteGame.h"
#include "BuildingTextureData.generated.h"

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API UBuildingTextureData : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
	class UTexture2D*                                  Diffuse;                                                 
	
	UPROPERTY(EditAnywhere)
	class UTexture2D*                                  Normal;                                                  
	
	UPROPERTY(EditAnywhere)
	class UTexture2D*                                  Specular;                                                
	
	UPROPERTY(EditAnywhere)
	class UMaterialInterface*                          OverrideMaterial;                                        
	
	UPROPERTY(EditAnywhere)
	TEnumAsByte<EFortTextureDataType>                  Type;                                                    
	
	UPROPERTY(EditAnywhere)
	TEnumAsByte<EFortResourceType>                     ResourceType;                                                                         
	
	UPROPERTY(EditAnywhere)
	float                                              ResourceCost[0x4];                                                                      
};
