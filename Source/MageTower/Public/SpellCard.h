// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpellCard.generated.h"

/**
 * 
 */
UCLASS()
class MAGETOWER_API USpellCard : public UObject
{
	GENERATED_BODY()

public:
	void SetSpellId(int _NewId) { mSpellId = _NewId; }
	int GetSpellId() const { return mSpellId; }
	void SetManaCost(int _NewManaCost) { mManaCost = _NewManaCost; }
	int GetManaCost() const { return mManaCost; }
private:
	int mSpellId;
	int mManaCost = 2;
};
