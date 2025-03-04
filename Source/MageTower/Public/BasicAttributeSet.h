// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#define ATTRIBUTE_ACCESSORS(ClassName,PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

#include "CoreMinimal.h"
#include "Engine.h"
#include "Net/UnrealNetwork.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BasicAttributeSet.generated.h"



/**
 * 
 */
UCLASS()
class MAGETOWER_API UBasicAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UBasicAttributeSet();
	
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute", ReplicatedUsing = OnRep_CurrentHealth)
	FGameplayAttributeData mCurrentHealth;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, mCurrentHealth)
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData mMaxHealth;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, mMaxHealth)

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute", ReplicatedUsing = OnRep_CurrentMana)
	FGameplayAttributeData mCurrentMana;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, mCurrentMana);
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute", ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData mMaxMana;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, mMaxMana);

	
protected:
	virtual void OnRep_CurrentHealth(const FGameplayAttributeData& _OldHealth);
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& _OldMaxHealth);
	virtual void OnRep_CurrentMana(const FGameplayAttributeData& _OldMana);
	virtual void OnRep_MaxMana(const FGameplayAttributeData& _OldMaxMana);
};
