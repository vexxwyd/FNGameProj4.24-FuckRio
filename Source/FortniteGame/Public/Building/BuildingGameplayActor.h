// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingActor.h"
#include "FortniteGame.h"
#include "GameplayEffectTypes.h"
#include "FortWeapon.h"
#include "Math/Color.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "BuildingGameplayActor.generated.h"

USTRUCT(BlueprintType)
struct FMarkedActorDisplayInfo
{
public:

	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FText                                              DisplayName;                                  
	
	UPROPERTY(EditAnywhere)
	class UTexture2D*                                  Icon;                                         
	
	UPROPERTY(EditAnywhere)
	class UClass*                                      CustomIndicatorClass;                         
	
	UPROPERTY(EditAnywhere)
	struct FLinearColor                                PrimaryColor;                                 
	
	UPROPERTY(EditAnywhere)
	class USoundBase*                                  Sound;                                        
	
	UPROPERTY(EditAnywhere)
	EFortMarkedActorScreenClamping                     ScreenClamping;                               
};

USTRUCT(BlueprintType)
struct FFortDeliveryInfoRequirementsFilter
{
public:

	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	struct FGameplayTagRequirements                    SourceTagRequirements;                              
	
	UPROPERTY(EditAnywhere)
	struct FGameplayTagRequirements                    TargetTagRequirements;                              
	
	UPROPERTY(EditAnywhere)
	TEnumAsByte<EFortTeamAffiliation>                  ApplicableTeamAffiliation;                          
	
	UPROPERTY(EditAnywhere)
	uint8                                              bConsiderTeamAffiliationToInstigator : 1;           
	
	UPROPERTY(EditAnywhere)
	TEnumAsByte<EFortTeam>                             ApplicableTeam;                                     
	
	UPROPERTY(EditAnywhere)
	uint8                                              bConsiderTeam : 1;                                  
	
	UPROPERTY(EditAnywhere)
	uint8                                              bApplyToPlayerPawns : 1;                            
	
	UPROPERTY(EditAnywhere)
	uint8                                              bApplyToAIPawns : 1;                                
	
	UPROPERTY(EditAnywhere)
	uint8                                              bApplyToBuildingActors : 1;                         

	UPROPERTY(EditAnywhere)
	EFortDeliveryInfoBuildingActorSpecification        BuildingActorSpecification;                         

	UPROPERTY(EditAnywhere)
	uint8                                              bApplyToGlobalEnvironmentAbilityActor : 1;          
};

USTRUCT(BlueprintType)
struct FFortAbilitySetDeliveryInfo
{
public:

	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		struct FFortDeliveryInfoRequirementsFilter         DeliveryRequirements;
	UPROPERTY(EditAnywhere)
		TArray<TSoftObjectPtr<class UFortAbilitySet>>      AbilitySets;
};


USTRUCT(BlueprintType)
struct FGameplayEffectApplicationInfo
{
public:

	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	class UClass*                                      GameplayEffect;                                     
	UPROPERTY(EditAnywhere)
	float                                              Level;                                              
};

USTRUCT(BlueprintType)
struct FProximityBasedGEDeliveryInfo
{
public:

	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	struct FFortDeliveryInfoRequirementsFilter         DeliveryRequirements;                         
	
	UPROPERTY(EditAnywhere)
	TArray<struct FGameplayEffectApplicationInfo>      EffectsToApply;                       
	
	UPROPERTY(EditAnywhere)
	EFortProximityBasedGEApplicationType               ProximityApplicationType;                 
};

USTRUCT(BlueprintType)
struct FBuildingGameplayActorAbilityDeliveryBucket
{
public:

	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	struct FGameplayTag                                Tag;                                                  
	
	UPROPERTY(EditAnywhere)
	TArray<struct FProximityBasedGEDeliveryInfo>       ProximityBasedEffectBuckets;                          
	
	UPROPERTY(EditAnywhere)
	TArray<struct FFortAbilitySetDeliveryInfo>         PawnPersistentAbilitySetBuckets;                      
	
	UPROPERTY(EditAnywhere, Transient)
	TArray<struct FFortAbilitySetHandle>               PersistentlyAppliedAbilitySets;                       
	
	UPROPERTY(EditAnywhere, Transient)
	uint8                                              bEnabled : 1;                                         
	
	UPROPERTY(EditAnywhere)
	uint8                                              bEnabledByDefault : 1;                             
	
	UPROPERTY(EditAnywhere)
	uint8                                              bHasGEsToApplyOnTouch : 1;                         
	
	UPROPERTY(EditAnywhere)
	uint8                                              bHasGEsToApplyOnPulseTimer : 1;                    
	
	UPROPERTY(EditAnywhere)
	uint8                                              bHasPersistentEffects : 1;                         

};

USTRUCT(BlueprintType)
struct FBuildingGameplayActorAbilityDeliveryInfo
{
public:

	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<struct FBuildingGameplayActorAbilityDeliveryBucket> DeliveryBuckets;                            
	UPROPERTY(EditAnywhere)
	float                                              ProximityPulseInterval;                             
	UPROPERTY(EditAnywhere)
	uint8                                              bHasGEsToApplyOnTouch : 1;                          
	UPROPERTY(EditAnywhere)
	uint8                                              bHasGEsToApplyOnPulseTimer : 1;                     
	UPROPERTY(EditAnywhere)
	uint8                                              bHasPersistentEffects : 1;                          
	UPROPERTY(Transient)
	class ABuildingGameplayActor*                      OwningActor;                                        
	UPROPERTY(Transient)
	TArray<class AActor*>                              DeferredTouchActorsToProcess;                       
};

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API ABuildingGameplayActor : public ABuildingActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY()
	class UFortAbilitySet*                             AbilitySet;                                              
	UPROPERTY(EditAnywhere)
	class UFortAbilitySet*                             InherentAbilitySets[0x5];                                
	//UPROPERTY(Transient)
//	class UFortDamageSet*                              DamageSet;                                               
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	struct FDataTableRowHandle                         DamageStatHandle;                                        
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool                                               bIgnoreInstigatorCollision;                              
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool                                               bAddOwnerVelocity;                                       
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int                                                AbilitySourceLevel;                                      
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	struct FBuildingGameplayActorAbilityDeliveryInfo   DeliverableAbilityInfo;                                  
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	uint8                                              bApplyDefaultEnabledAbilityBucketsOnInit : 1;            
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	uint8                                              bUseSimpleActorTouchSetupForAbilityBuckets : 1;          
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient)
	struct FMarkedActorDisplayInfo                     MarkerDisplay;                                           
	
	UPROPERTY()
	class UPrimitiveComponent*                         RegisteredTouchComponent;                                
	
	UPROPERTY()
	class UProjectileMovementComponent*                ProjectileMovementComponent;
};
