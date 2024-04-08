// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Color.h"
#include "FortPickupEffect.generated.h"

UCLASS()
class FORTNITEGAME_API AFortPickupEffect : public AActor
{
	GENERATED_BODY()
	
		UFUNCTION(BlueprintCallable)
		class UMaterialInstanceDynamic* ApplyCosmeticOverridesToMaterial(class UMeshComponent* MeshComponent, int MatIndex);

public:                                 
	
	UPROPERTY(EditAnywhere)
		class UStaticMesh*                               StaticMesh;

	UPROPERTY(EditAnywhere)
		class USkeletalMesh*                               SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class UFortAlterationItemDefinition*>       ActiveAlterations;                               
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UFortWorldItemDefinition*                    ItemDefinition;                                  
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bDoNotShowSpawnParticles;                        
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bDoNotTickSkeletalMeshComponents;                                             
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FVector                                     PickupColor;                                     
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FLinearColor                                BackpackWorldPosition;                           
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8                                              bOwnedByALocalPlayer : 1;                        
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8                                              bOwnedByPlayer : 1;                                                      
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool                                               bRandomRotation;                                                            
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class USoundBase>                   PickupByNearbyPawnSound;

	// Sets default values for this actor's properties
	AFortPickupEffect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called on construction
	virtual void OnConstruction(const FTransform& Transform) override;

private:

	// Pickup static mesh component
	UStaticMeshComponent* StaticMeshComponent;

	// Pickup static mesh component
	USkeletalMeshComponent* SkeletalMeshComponent;
};
