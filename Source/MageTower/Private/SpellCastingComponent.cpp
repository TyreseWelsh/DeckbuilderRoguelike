// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellCastingComponent.h"

#include "SpellCard.h"

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
	InitialiseDeck();
}

void USpellCastingComponent::InitialiseDeck()
{
	for(int i = 0; i < mDeckSize; i++)
	{
		if(USpellCard* spellCard = NewObject<USpellCard>())
		{
			spellCard->SetSpellId(i);
			mpDeckSpells.Add(spellCard);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Adding SpellCard %i to deck"), spellCard->GetSpellId()));
		}
	}

	mpHandSpells.SetNum(mMAX_HAND_SIZE);
	for(int i = 0; i < mpHandSpells.Num(); i++)
	{
		DrawTopDeck(i);
		GEngine->AddOnScreenDebugMessage(8195, 1.5f, FColor::Orange, FString::Printf(TEXT("Filling hand...")));
	}

	mCurrentMana = mMAX_MANA;
}

void USpellCastingComponent::RotateHand()
{
	mCurrentSpellIndex = -1;
	UE_LOG(LogTemp, Display, TEXT("Start rotating hand..."));
	
	UE_LOG(LogTemp, Display, TEXT("Discarding spell %i"), mpHandSpells[0]->GetSpellId());
	DiscardSpell(0);
	for(int i = 0; i < mMAX_HAND_SIZE - 1; i++)
	{
		mpHandSpells[i] = mpHandSpells[i + 1];
	}
	UE_LOG(LogTemp, Display, TEXT("Drawing spell %i"), mpDeckSpells[0]->GetSpellId());
	DrawTopDeck(mMAX_HAND_SIZE - 1);
	
	UE_LOG(LogTemp, Display, TEXT("Stop rotating hand..."));
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
		mpDeckSpells.RemoveAt(0);

		// After successfully adding from deck to hand, we check if the deck is empty as we will have to refill it
		if(mpDeckSpells.IsEmpty())
		{
			RecycleDiscardPile();
		}
	}
}

USpellCard* USpellCastingComponent::GetTopDeck() const
{
	if (mpDeckSpells.Num() > 0)
	{
		return mpDeckSpells[0];
	}

	return nullptr;
}

void USpellCastingComponent::RecycleDiscardPile()
{
	// Continuously add a random spell from discard pile to deck until there are no discarded spells left
	while (!mpDiscardSpells.IsEmpty())
	{
		int randDiscardIndex = FMath::RandRange(0, mpDiscardSpells.Num() - 1);
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Magenta, FString::Printf(TEXT("Recycling spell%i into deck!"), mpDiscardSpells[randDiscardIndex]->GetSpellId()));

		mpDeckSpells.Add(mpDiscardSpells[randDiscardIndex]);
		mpDiscardSpells.RemoveAt(randDiscardIndex);
	}
}

void USpellCastingComponent::SelectSpell(int _HandIndex)
{
	if(_HandIndex >= 0 && _HandIndex < mMAX_HAND_SIZE)
	{
		GEngine->AddOnScreenDebugMessage(1, 1.5f, FColor::Green, FString::Printf(TEXT("Picked spell %i!"), _HandIndex + 1));
		mCurrentCastingState = ECastingState::Aiming;
		mCurrentSpellIndex = _HandIndex;
	}
}

void USpellCastingComponent::CastSpell()
{
	if(mCurrentSpellIndex >= 0 && mCurrentSpellIndex < mMAX_HAND_SIZE && mpHandSpells[mCurrentSpellIndex]->GetManaCost() <= mCurrentMana)
	{
		if(mpHandSpells[mCurrentSpellIndex])
		{
			GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Cyan, FString::Printf(TEXT("%s: Casting spell %i!"), *GetOwner()->GetName(), mpHandSpells[mCurrentSpellIndex]->GetSpellId()));
			mCurrentMana -= mpHandSpells[mCurrentSpellIndex]->GetManaCost();
			CycleHand(mCurrentSpellIndex, mCurrentSpellIndex);
			mCurrentSpellIndex = -1;
		}
	}
}

void USpellCastingComponent::IncreaseMana()
{
	mCurrentMana += mManaPerTurn;
	if(mCurrentMana > mMAX_MANA)
	{
		mCurrentMana = mMAX_MANA;
	}
}

void USpellCastingComponent::SetCastDirection(FVector2D _CastDirection)
{
	mCastDirection = FVector(_CastDirection.Y, _CastDirection.X, 0);
	
	FHitResult hitResult;
	FVector traceStart = GetOwner()->GetActorLocation();
	traceStart.Z += 50.f;
	FVector traceEnd = traceStart + mCastDirection * 300.f;
	GEngine->AddOnScreenDebugMessage(2831, 2.0f, FColor::Green, FString::Printf(TEXT("TraceEnd: x=%f , y=%f , z=%f"), traceEnd.X, traceEnd.Y, traceEnd.Z));
	
	GetWorld()->LineTraceSingleByChannel(hitResult, traceStart, traceEnd, ECC_Visibility);
	DrawDebugLine(GetWorld(), traceEnd, FVector(traceEnd.X, traceEnd.Y, traceEnd.Z + 1000), FColor::Red, false, 15.f, 0, 2.f);
	// We need to somehow get all tiles along this path (jump in cast direction in intervals of the tile size until we reach the required distance
	// Then at each point we GetBelowTile() and store these somewhere so that the spells "pathfinding" can access them
	// For each point along the path, the spell can choose what to do, either just move to the next or do something on this tile
	// In the spell, for each tile in the path, we will also be checking if its occupied to apply damage if damageable
	// and choosing if we want to stop the spell there or keep going depending on its interaction with the occupying object.
}

void USpellCastingComponent::CancelSpellCast()
{
	mCurrentSpellIndex = -1;
	mCurrentCastingState = ECastingState::None;
}

