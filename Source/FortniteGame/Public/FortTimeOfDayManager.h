// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Math/Color.h"
#include "FortTimeOfDayManager.generated.h"

USTRUCT(BlueprintType)
struct FCloudColorState
{

	GENERATED_BODY()
			
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FLinearColor                                BottomEmissive;                                       
			
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FLinearColor                                TopEmissive;                                          
			
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FLinearColor                                BottomLightning;                                      
			
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FLinearColor                                TopLightning;                                         
			
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FLinearColor                                InternalColor;                                        
};

USTRUCT(BlueprintType)
struct FSkyLightValues
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FLinearColor                                SkyLightColor;                                       
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FLinearColor                                SkyLightOcclusionTint;                               
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              SkyLightMinOcclusion;                                
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              VolumetricScatteringIntensity;                       
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTextureCube*                                Cubemap;                                             
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTextureCube*                                DestinationCubemap;                                  
};

USTRUCT(BlueprintType)
struct FThreatCloudValues
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FCloudColorState                            CloudActivated;                                      
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FCloudColorState                            CloudDeactivated;                                    
};

USTRUCT(BlueprintType)
struct FElementalCharValues
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FLinearColor                                FireCharColor;                                       
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              ElectricalCharEmissive;                              
};

USTRUCT(BlueprintType)
struct FDirectionalLightValues
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FColor                                      LightColor;                                          
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              Brightness;                                          
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              VolumetricScatteringIntensity;                       
};

USTRUCT(BlueprintType)
struct FExponentialHeightFogValues
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              FogDensity;                                           
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              FogHeightFalloff;                                     
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              FogMaxOpacity;                                        
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              StartDistance;                                        
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              DirectionalInscatteringExponent;                      
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              DirectionalInscatteringStartDistance;                 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FLinearColor                                DirectionalInscatteringColor;                         
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FLinearColor                                FogInscatteringColor;                                 
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              VolumetricFogScatteringDistribution;                  
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              VolumetricFogExtinctionScale;                         
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              VolumetricFogDistance;                                
	//struct FExponentialHeightFogData                   SecondFogData;                                        
};

USTRUCT(BlueprintType)
struct FDayPhaseInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString                                            PhaseStartAnnouncement;                           
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              TimePhaseBegins;                                  
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              PhaseLengthInHours;                               
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              PercentageTransitionIn;                           
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              TransitionInTimeInMinutes;                        
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              PercentageTransitionOut;                          
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float                                              TransitionOutTimeInMinutes;                       
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FSkyLightValues                             SkyLightValues;                                   
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FThreatCloudValues                          ThreatCloudValues;                                
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FElementalCharValues                        ElementalCharValues;                              
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FDirectionalLightValues                     DirectionalLightValues;                           
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FExponentialHeightFogValues                 ExpHeightFogValues;                               
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPostProcessComponent*                       LowPriPostProcessComponent;                       
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMaterialInstance*                           SkyMaterialInstance;                              
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMaterialInstance*                           StarMapMaterialInstance;                          
};

/**
 * 
 */
UCLASS(notplaceable)
class FORTNITEGAME_API AFortTimeOfDayManager : public AInfo
{
	GENERATED_BODY()

	AFortTimeOfDayManager();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite /*Replicated*/)
	float                                              TimeOfDay;                
	UPROPERTY(EditAnywhere, BlueprintReadWrite /*Replicated*/)
	float                                              TimeOfDayReplicated;

	UPROPERTY(EditAnywhere)
	struct FDayPhaseInfo                               LightAndFogPhaseSettings[0x4];

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent*                        SkyDomeMeshComp;
};
