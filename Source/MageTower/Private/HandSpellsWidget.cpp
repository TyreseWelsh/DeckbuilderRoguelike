// Fill out your copyright notice in the Description page of Project Settings.


#include "HandSpellsWidget.h"
#include "SpellCardWidget.h"
#include "SpellData.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"

void UHandSpellsWidget::Init()
{
	handSpellCards.Add(spellCard0);
	handSpellCards.Add(spellCard1);
	handSpellCards.Add(spellCard2);
	handSpellCards.Add(spellCard3);
}

void UHandSpellsWidget::UpdateCardUI(int _CardNum, USpellData* _SpellData)
{
	if(handSpellCards.Num() > 0)
	{
		if(USpellCardWidget* spellCardWidget = handSpellCards[_CardNum])
		{
			spellCardWidget->cardName->SetText(FText::FromString(_SpellData->mSpellName));
			//spellCardWidget->cardCost->SetText(FText::FromString(FString::Printf(TEXT("%i"), _SpellData->mBaseManaCost)));
			spellCardWidget->cardCost->SetText(FText::FromString(FString::Printf(TEXT("%i"), _SpellData->mSpellId)));	// TEMP, should be ^^
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("Updated card spell id: %i"), _SpellData->mSpellId));

			spellCardWidget->cardDescription->SetText(FText::FromString(_SpellData->mSpellDescription));
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("HAND SPELL CARD WIDGET INVALID")));
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("NO HAND SPELL CARD UI !")));

	}
}
