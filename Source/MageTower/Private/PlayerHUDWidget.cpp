// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUDWidget.h"

#include "HandSpellsWidget.h"
#include "ManaWidget.h"
#include "Components/HorizontalBox.h"

void UPlayerHUDWidget::SetMana(int _CurrentMana)
{
	if(manaBar)
	{
		manaBar->SetMana(_CurrentMana);
	}
}

void UPlayerHUDWidget::UpdateHandUI(int _CardNum, USpellData* _SpellData)
{
	if(handSpellCards)
	{
		handSpellCards->UpdateCardUI(_CardNum, _SpellData);
	}
}

void UPlayerHUDWidget::EnableHand()
{
	cardArea->SetRenderOpacity(1.f);
}