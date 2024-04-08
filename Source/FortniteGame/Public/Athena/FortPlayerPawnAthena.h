// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/FortPlayerPawn.h"
#include "FortPlayerPawnAthena.generated.h"

USTRUCT()
struct FAthenaBatchedDamageGameplayCues_Shared
{
	GENERATED_BODY()

	UPROPERTY()
	struct FVector_NetQuantize10                       Location;                                            
	
	UPROPERTY()
	struct FVector_NetQuantizeNormal                   Normal;                                              
	
	UPROPERTY()
	float                                              Magnitude;                                           
	
	UPROPERTY()
	bool                                               bWeaponActivate;                                     
	
	UPROPERTY()
	bool                                               bIsFatal;                                            
	
	UPROPERTY()
	bool                                               bIsCritical;                                         
	
	UPROPERTY()
	bool                                               bIsShield;                                           
	
	UPROPERTY()
	bool                                               bIsShieldDestroyed;                                  
	
	UPROPERTY()
	bool                                               bIsShieldApplied;                                    
	
	UPROPERTY()
	bool                                               bIsBallistic;                                                                        
	
	UPROPERTY()
	struct FVector_NetQuantize10                       NonPlayerLocation;                                   
	
	UPROPERTY()
	struct FVector_NetQuantizeNormal                   NonPlayerNormal;                                     
	
	UPROPERTY()
	float                                              NonPlayerMagnitude;                                  
	
	UPROPERTY()
	bool                                               NonPlayerbIsFatal;                                   
	
	UPROPERTY()
	bool                                               NonPlayerbIsCritical;                                
	
	UPROPERTY()
	bool                                               bIsValid;                                                                    
};

USTRUCT()
struct FAthenaBatchedDamageGameplayCues_NonShared
{
	GENERATED_BODY()

	UPROPERTY()
	class AActor*                                      HitActor;       
	UPROPERTY()
	class AActor*                                      NonPlayerHitActor;                                   
};

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortPlayerPawnAthena : public AFortPlayerPawn
{
	GENERATED_BODY()
		
public:

	UFUNCTION(Reliable, NetMultiCast)
	void NetMultiCast_Athena_BatchedDamageCue(struct FAthenaBatchedDamageGameplayCues_Shared SharedData, struct FAthenaBatchedDamageGameplayCues_NonShared NonSharedData);
};
