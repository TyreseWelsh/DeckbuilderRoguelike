// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "GameplayTagAssetInterface.h"
#include "SpellDataStruct.generated.h"

struct FGameplayTag;
struct FGameplayTagContainer;

/**
 * 
 */
UCLASS(Blueprintable)
class MAGETOWER_API USpellDataStruct : public UUserDefinedStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mSpellId;	// temp
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString mSpellName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mBaseManaCost;
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
