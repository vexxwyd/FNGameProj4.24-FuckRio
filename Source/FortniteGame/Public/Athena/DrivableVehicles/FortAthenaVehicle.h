// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FortAthenaVehicle.generated.h"

class AFortPawn;
class AFortPlayerControllerZone;
class USoundBase;

USTRUCT()
struct FVehiclePawnState
{
	GENERATED_BODY()

	UPROPERTY()
	class AFortAthenaVehicle*                          Vehicle;                                       
	
	UPROPERTY()
	float                                              VehicleApexZ;                                  
	
	UPROPERTY()
	uint8                                              SeatIndex;                                     
	
	UPROPERTY()
	uint8                                              ExitSocketIndex;                               
	
	UPROPERTY()
	bool                                               bOverrideVehicleExit;                                                  
	
	UPROPERTY()
	struct FVector                                     SeatTransitionVector;                          
	
	UPROPERTY()
	float                                              EntryTime;                                     
};

USTRUCT()
struct FAthenaVehicleShootingCone
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float                                              YawConstraint;
	UPROPERTY(EditAnywhere)
	float                                              PitchConstraint;
};

USTRUCT()
struct FAthenaCarPlayerSlot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FName                                       SeatSocket;                                             
	
	UPROPERTY(EditAnywhere)
	FName                                       SeatChoiceSocket;                                       
	
	UPROPERTY(EditAnywhere)
	FName                                       SeatIndicatorSocket;                                    
	
	UPROPERTY(EditAnywhere)
	FText                                       SeatChoiceDisplayText;                                  
	
	UPROPERTY(EditAnywhere)
	FName                                       SeatCollision;                                          
	
	UPROPERTY(EditAnywhere)
	TArray<FName>                               ExitSockets;                                            
	
	UPROPERTY(EditAnywhere)
	struct FAthenaVehicleShootingCone                  ShootingCone;                                    
	
	UPROPERTY(EditAnywhere)
	class USoundBase*                                  SoundOnEnter;                                    
	
	UPROPERTY(EditAnywhere)
	class USoundBase*                                  SoundOnExit;                                     
	
	UPROPERTY(EditAnywhere)
	uint8                                              bIsSelectable : 1;                               
	
	UPROPERTY(EditAnywhere)
	uint8                                              bUseGroundMotion : 1;                            
	
	UPROPERTY(EditAnywhere)
	uint8                                              bUseVehicleIsOnGround : 1;                       
	
	UPROPERTY(EditAnywhere)
	uint8                                              bCanEmote : 1;                                   
	
	UPROPERTY(EditAnywhere)
	uint8                                              bForceCrouch : 1;                                
	
	UPROPERTY(EditAnywhere)
	struct FVector                                     ActorSpaceCameraOffset;                          
	
	UPROPERTY(EditAnywhere)
	struct FVector                                     VehicleSpaceCameraOffset;                        
	
	UPROPERTY(EditAnywhere)
	float                                              SlopeCompensationCameraOffset;                   
	
	UPROPERTY(EditAnywhere)
	struct FVector                                     StandingFiringOffset;                            
	
	UPROPERTY(EditAnywhere)
	struct FVector                                     CrouchingFiringOffset;                           
	
	UPROPERTY(EditAnywhere)
	struct FVector                                     EmoteOffset;                                     
	
	UPROPERTY(EditAnywhere)
	class AFortPlayerPawn*                             Player;                                          
	
	UPROPERTY(EditAnywhere)
	class AFortPlayerControllerZone*                   Controller;                                      
	
	UPROPERTY(EditAnywhere)
	float                                              PlayerEntryTime;                                 
	
	UPROPERTY(EditAnywhere)
	bool                                               bConstrainPawnToSeatTransform;                   
	
	UPROPERTY(EditAnywhere)
	bool                                               bOffsetPlayerRelativeAttachLocation;             
	
	UPROPERTY(EditAnywhere)
	bool                                               bUseExitTimer;                                   
};

/** @ AFortAthenaVehicle class implementation */
UCLASS()
class FORTNITEGAME_API AFortAthenaVehicle : public APawn
{
	GENERATED_BODY()

	UFUNCTION()
	void OnRep_PlayerSlots();

public:
	
	UFUNCTION()
	bool ContainsPlayers();

	/** @ Returns player slots of the vehicle */
	TArray<struct FAthenaCarPlayerSlot> GetPlayerSlots() const { return PlayerSlots; }

	UPROPERTY(EditAnywhere, ReplicatedUsing = OnRep_PlayerSlots)
		TArray<struct FAthenaCarPlayerSlot>                PlayerSlots;
};
