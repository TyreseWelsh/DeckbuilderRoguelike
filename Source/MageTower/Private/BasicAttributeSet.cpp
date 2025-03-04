// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicAttributeSet.h"

UBasicAttributeSet::UBasicAttributeSet()
{
	/*mMaxHealth.SetBaseValue(100.f);
	mMaxHealth.SetCurrentValue(mMaxHealth.GetBaseValue());
	mHealth.SetBaseValue(mMaxHealth.GetBaseValue());
	mHealth.SetCurrentValue(mHealth.GetCurrentValue());*/
	
}

void UBasicAttributeSet::OnRep_CurrentHealth(const FGameplayAttributeData& _OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasicAttributeSet, mCurrentHealth, _OldHealth);
}

void UBasicAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& _OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasicAttributeSet, mMaxHealth, _OldMaxHealth);
}

void UBasicAttributeSet::OnRep_CurrentMana(const FGameplayAttributeData& _OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasicAttributeSet, mCurrentMana, _OldMana);
}

void UBasicAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& _OldMaxMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasicAttributeSet, mMaxMana, _OldMaxMana);
}
