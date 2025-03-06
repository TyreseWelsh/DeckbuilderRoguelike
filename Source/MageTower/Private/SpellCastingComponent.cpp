// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellCastingComponent.h"

#include "SpellCard.h"
#include "PlayerHUDWidget.h"
#include "HandSpellsWidget.h"
#include "SpellData.h"
#include "Algo/RandomShuffle.h"

// Sets default values for this component's properties
USpellCastingComponent::USpellCastingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpellCastingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

void USpellCastingComponent::InitialiseDeck()
{
	// Initialising owner's deck at start of play
	for(int i = 0; i < mpInitialDeckData.Num(); i++)
	{
		USpellCard* currentSpellCard = NewObject<USpellCard>(this, mpInitialDeckData[i]);
		if(currentSpellCard)
		{
			mpDeckSpells.Add(currentSpellCard);
		}
	}

	Algo::RandomShuffle(mpDeckSpells);
}

void USpellCastingComponent::InitaliseCombatDeck(UPlayerHUDWidget* _PlayerHUD)
{
	mCurrentMana = 5;
	mpCombatDeckSpells = mpDeckSpells;
	Algo::RandomShuffle(mpCombatDeckSpells);
	
	mpPlayerHUD = _PlayerHUD;
	if(mpPlayerHUD)
	{
		mpPlayerHUD->SetMana(mCurrentMana);
		mpPlayerHUD->handSpellCards->Init();
		
		mpHandSpells.SetNum(mMAX_HAND_SIZE);
		for(int i = 0; i < mpHandSpells.Num(); i++)
		{
			DrawTopDeck(i);
			GEngine->AddOnScreenDebugMessage(8195, 1.5f, FColor::Orange, FString::Printf(TEXT("Filling hand...")));
		}
	}
}

void USpellCastingComponent::RotateHand()
{
	mCurrentSpellIndex = -1;
	
	DiscardSpell(0);
	
	for(int i = 0; i < mMAX_HAND_SIZE - 1; i++)
	{
		mpHandSpells[i] = mpHandSpells[i + 1];
		UpdateHandCardUI(mpPlayerHUD, i);
	}
	
	DrawTopDeck(mMAX_HAND_SIZE - 1);
}

void USpellCastingComponent::CycleHand(int _DiscardIndex, int _NewSpellIndex)
{
	DiscardSpell(_DiscardIndex);
	DrawTopDeck(_NewSpellIndex);
}

void USpellCastingComponent::DiscardSpell(int _DiscardIndex)
{
	if(USpellCard* discardedSpell = mpHandSpells[_DiscardIndex])
	{
		mpDiscardSpells.Add(discardedSpell);
		mpHandSpells[_DiscardIndex] = nullptr;
	}
}

void USpellCastingComponent::DrawTopDeck(int _NewSpellIndex)
{
	if(USpellCard* topDeck = GetTopDeck())
	{
		mpHandSpells[_NewSpellIndex] = topDeck;
		UpdateHandCardUI(mpPlayerHUD, _NewSpellIndex);
		mpCombatDeckSpells.RemoveAt(0);

		// After successfully adding from deck to hand, we check if the deck is empty as we will have to refill it
		if(mpCombatDeckSpells.IsEmpty())
		{
			RecycleDiscardPile();
		}
	}
}

USpellCard* USpellCastingComponent::GetTopDeck() const
{
	if (mpCombatDeckSpells.Num() > 0)
	{
		return mpCombatDeckSpells[0];
	}

	return nullptr;
}

void USpellCastingComponent::RecycleDiscardPile()
{
	// Continuously add a random spell from discard pile to deck until there are no discarded spells left
	while (!mpDiscardSpells.IsEmpty())
	{
		int randDiscardIndex = FMath::RandRange(0, mpDiscardSpells.Num() - 1);
		mpCombatDeckSpells.Add(mpDiscardSpells[randDiscardIndex]);
		mpDiscardSpells.RemoveAt(randDiscardIndex);
	}
}

void USpellCastingComponent::SelectSpell(int _HandIndex)
{
	if(_HandIndex >= 0 && _HandIndex < mMAX_HAND_SIZE)
	{
		if(mCurrentMana - mpHandSpells[_HandIndex]->GetSpellData()->mBaseManaCost >= 0)
		{
			GEngine->AddOnScreenDebugMessage(1, 1.5f, FColor::Green, FString::Printf(TEXT("Picked spell %i!"), _HandIndex + 1));
			mCurrentCastingState = ECastingState::Aiming;
			mCurrentSpellIndex = _HandIndex;

			SetCastDirection(FVector2D(1, 0));
		}
	}
}

void USpellCastingComponent::CastSpell()
{
	if(mCurrentSpellIndex >= 0 && mCurrentSpellIndex < mMAX_HAND_SIZE && mpHandSpells[mCurrentSpellIndex]->GetSpellData()->mBaseManaCost <= mCurrentMana)
	{
		if(mpHandSpells[mCurrentSpellIndex])
		{
			DecreaseMana(mpHandSpells[mCurrentSpellIndex]->GetSpellData()->mBaseManaCost);
			CycleHand(mCurrentSpellIndex, mCurrentSpellIndex);
			CancelSpellCast();
		}
	}
}

void USpellCastingComponent::IncreaseMana(int _IncreaseAmount)
{
	SetCurrentMana(mCurrentMana + _IncreaseAmount);
}

void USpellCastingComponent::DecreaseMana(int _DecreaseAmount)
{
	SetCurrentMana(mCurrentMana - _DecreaseAmount);
}

void USpellCastingComponent::SetCastDirection(FVector2D _CastDirection)
{
	if(_CastDirection == FVector2D::ZeroVector or _CastDirection == FVector2D::One()/* or (mCurrentSpellIndex < 0 && mCurrentSpellIndex > mMAX_HAND_SIZE)*/)
	{
		return;
	}
	
	mCastDirection = FVector(_CastDirection.Y, _CastDirection.X, 0);
	int tileSize = 100;
	if(IsValid(mpHandSpells[mCurrentSpellIndex]))
	{
		int spellRange = mpHandSpells[mCurrentSpellIndex]->GetSpellData()->mBaseRange;
		int spellWidth = mpHandSpells[mCurrentSpellIndex]->GetSpellData()->mBaseWidth;
	
		FVector startPos = GetOwner()->GetActorLocation();
		for(int cRange = 1; cRange <= spellRange; cRange++)
		{
			for (int cWidth = -spellWidth; cWidth <= spellWidth; cWidth++)
			{
				FVector affectedTilePos;
				if(mCastDirection.X != 0 && mCastDirection.Y == 0) 
				{
					affectedTilePos.X = startPos.X + mCastDirection.X * (cRange * tileSize);
					affectedTilePos.Y = startPos.Y + cWidth * tileSize;
				}
				else if(mCastDirection.X == 0 && mCastDirection.Y != 0)
				{
					affectedTilePos.X = startPos.X + cWidth * tileSize;
					affectedTilePos.Y = startPos.Y + mCastDirection.Y * (cRange * tileSize);
				}

				GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::Printf(TEXT("x: %f , y: %f"), affectedTilePos.X, affectedTilePos.Y));
				DrawDebugLine(GetWorld(), affectedTilePos, FVector(affectedTilePos.X, affectedTilePos.Y, affectedTilePos.Z + 1000), FColor::Red, false, 1.f, 0, 2.f);
			}
		}	
	}
}

void USpellCastingComponent::CancelSpellCast()
{
	mCurrentSpellIndex = -1;
	mCurrentCastingState = ECastingState::None;
}

void USpellCastingComponent::UpdateHandCardUI(UPlayerHUDWidget* _PlayerHUD, int _CardNum)
{
	if(mpHandSpells.Num() > 0)
	{
		_PlayerHUD->handSpellCards->UpdateCardUI(_CardNum, mpHandSpells[_CardNum]->GetSpellData());
	}
}

void USpellCastingComponent::SetCurrentMana(int _CurrentMana)
{
	GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Cyan, FString::Printf(TEXT("new mana cost = %i"), _CurrentMana));

	mCurrentMana = _CurrentMana;
	if(mCurrentMana > mMAX_MANA)
    {
    	mCurrentMana = mMAX_MANA;
    }
	if(mpPlayerHUD)
	{
		mpPlayerHUD->SetMana(mCurrentMana);
	}
	GEngine->AddOnScreenDebugMessage(8195, 1.5f, FColor::Cyan, FString::Printf(TEXT("Current mana = %i"), mCurrentMana));
}
