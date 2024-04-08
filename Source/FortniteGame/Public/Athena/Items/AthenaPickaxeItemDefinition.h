// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Items/AthenaCosmeticItemDefinition.h"
#include "Weapons/Data/FortWeaponMeleeItemDefinition.h"
#include "AthenaPickaxeItemDefinition.generated.h"

/**
 * 
 */
USTRUCT()
struct FFortUICameraFrameTargetBounds
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere)
	 FVector                               Origin;                                            // 0x0(0xC)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

	UPROPERTY(EditAnywhere)
	float                                        CylinderHalfHeight;                                // 0xC(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	
	UPROPERTY(EditAnywhere)
	float                                        CylinderRadius;                                    // 0x10(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

UCLASS()
class FORTNITEGAME_API UAthenaPickaxeItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	class UFortWeaponMeleeItemDefinition*        WeaponDefinition;                                  // 0x430(0x8)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

	UPROPERTY(EditAnywhere,Category = "Frontend Preview")
	 FVector                               PickaxeImpactFXPreviewOffset;                      // 0x438(0xC)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

	UPROPERTY(EditAnywhere,Category = "Bounds")
	 FFortUICameraFrameTargetBounds        CameraFramingBounds;                               // 0x444(0x14)(Edit, BlueprintVisible, BlueprintReadOnly, NoDestructor, NativeAccessSpecifierPublic)

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AthenaPickaxe", GetFName());
	}
};
