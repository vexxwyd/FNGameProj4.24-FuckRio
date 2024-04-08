// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/FortPawn.h"
#include "FortAthenaVehicle.h"
#include "FortPlayerPawn.generated.h"

class AFortPlayerParachute;

/**
 * 
 */
UCLASS()
class FORTNITEGAME_API AFortPlayerPawn : public AFortPawn
{
	GENERATED_BODY()


	UFUNCTION(BlueprintCallable)
	void SetPendingSkydiveLaunch(bool bPending);
	
	UFUNCTION(BlueprintCallable)
	void ServerHandlePickup(class AFortPickup* Pickup, float InFlyTime, const struct FVector& InStartDirection, bool bPlayPickupSound);
	
	UFUNCTION()
	void OnRep_ParachuteAttachment();

	UFUNCTION()
	void OnRep_InVehicle();

public:
	
	/** @ Returns Parachute Attachment */
	AFortPlayerParachute* GetParachuteAttachment() const { return ParachuteAttachment; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	bool                                               bIsSkydiving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing = OnRep_ParachuteAttachment)
	class AFortPlayerParachute*                        ParachuteAttachment;

	UPROPERTY(ReplicatedUsing = OnRep_InVehicle)
		struct FVehiclePawnState                           VehicleStateRep;                                         
	UPROPERTY()
		struct FVehiclePawnState                           VehicleStateLocal;                                       
	UPROPERTY()
		struct FVehiclePawnState                           VehicleStateLastTick;
};
