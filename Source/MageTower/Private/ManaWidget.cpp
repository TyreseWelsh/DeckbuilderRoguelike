// Fill out your copyright notice in the Description page of Project Settings.


#include "ManaWidget.h"

#include "Components/Image.h"

void UManaWidget::InitMana()
{
	// Adding pointers to mana point widgets to array so they can be referenced easily elsewhere
	manaPoints.Add(mana1);
	manaPoints.Add(mana2);
	manaPoints.Add(mana3);
	manaPoints.Add(mana4);
	manaPoints.Add(mana5);
	manaPoints.Add(mana6);
	manaPoints.Add(mana7);
	manaPoints.Add(mana8);
	manaPoints.Add(mana9);
	manaPoints.Add(mana10);
}

void UManaWidget::SetMana(int _CurrentMana)
{
	if (manaPoints.Num() > 0)
	{
		for(int i = 0; i < manaPoints.Num(); i++)
		{
			if(i < _CurrentMana)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("HAND SPELL CARD WIDGET INVALID")));
				manaPoints[i]->SetRenderOpacity(1.f);
			}
			else
			{
				//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("HAND SPELL CARD WIDGET INVALID")));
				manaPoints[i]->SetRenderOpacity(0.5f);
			}
		}
	}
}
