#include "FortAnimNotifyState_EmoteSound.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"


void UFortAnimNotifyState_EmoteSound::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	if (EmoteSound3P != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(MeshComp->GetWorld(), EmoteSound3P, MeshComp->GetComponentLocation(), 0.4f);
	}
}
