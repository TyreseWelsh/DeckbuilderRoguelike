// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "Engine/DataAsset.h"
#include "SpellData.generated.h"

struct FGameplayTag;
struct FGameplayTagContainer;

/**
 * 
 */
UCLASS(Blueprintable)
class MAGETOWER_API USpellData : public UDataAsset, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override { TagContainer = baseDamageTypes; return;}
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mSpellId;	// temp
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString mSpellName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mBaseManaCost;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString mSpellDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mBaseDamage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mBaseRange;
	// Spells by default are one tile wide (0). Additional width is added to both sides of spell
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mBaseWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer baseDamageTypes;
};
