// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellCard.h"
#include "SpellData.h"

void USpellCard::Init()
{
	mpBaseSpellData = NewObject<USpellData>();
	if(mpBaseSpellData)
	{
		mSpellId = mpBaseSpellData->mSpellId;
		mManaCost = mpBaseSpellData->mBaseManaCost;
		mDamage = mpBaseSpellData->mBaseDamage;
		mRange = mpBaseSpellData->mBaseRange;
		mWidth = mpBaseSpellData->mBaseWidth;
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("Spell width= %i"), mWidth));
	}
}
