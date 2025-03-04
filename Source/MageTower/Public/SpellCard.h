// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "SpellCard.generated.h"

class USpellDamageType;
class USpellData;
struct FGameplayTagContainer;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class MAGETOWER_API USpellCard : public UObject
{
	GENERATED_BODY()

public:
	void Init();
	
	void SetSpellId(int _NewId) { mSpellId = _NewId; }
	int GetSpellId() const { return mSpellId; }
	void SetManaCost(int _NewManaCost) { mManaCost = _NewManaCost; }
	int GetManaCost() const { return mManaCost; }
	void SetDamage(int _NewDamage) { mDamage = _NewDamage; }
	int GetDamage() const { return mDamage; }
	void SetRange(int _NewRange) { mRange = _NewRange; }
	int GetRange() const { return mRange; }
	void SetWidth(int _NewWidth) { mManaCost = _NewWidth; }
	int GetWidth() const { return mWidth; }
	USpellData* GetSpellData() { return mpBaseSpellData; }
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	TObjectPtr<USpellData> mpBaseSpellData;
	
	int mSpellId = 0;
	int mManaCost = 1;
	int mDamage = 10;
	int mRange = 3;
	int mWidth = 0;

	FGameplayTagContainer baseDamageTypes;
};
