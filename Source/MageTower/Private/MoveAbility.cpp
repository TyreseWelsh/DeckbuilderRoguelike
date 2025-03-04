// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveAbility.h"
#include "GameFramework/Pawn.h"
#include "AbilitySystemComponent.h"

void UMoveAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if(APawn* pawn = Cast<APawn>(ActorInfo->AvatarActor.Get()))
	{
		
	}
}
