// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpellCastingComponent.generated.h"

class USpellCard;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class MAGETOWER_API USpellCastingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpellCastingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void InitialiseDeck();
	
public:
	void RotateHand();
	void CycleHand(int _DiscardIndex, int _NewSpellIndex);
	void DiscardSpell(int _DiscardIndex);
	void DrawTopDeck(int _NewSpellIndex);
	USpellCard* GetTopDeck() const;
	void RecycleDiscardPile();

	void SelectSpell(int _HandIndex);
	void CastSpell();
	void IncreaseMana();

	int mCurrentSpellIndex = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<USpellCard*> mpHandSpells;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<USpellCard*> mpDeckSpells;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<USpellCard*> mpDiscardSpells;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	int mMAX_MANA = 9;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	int mCurrentMana;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	int mManaPerTurn = 1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	int mMAX_HAND_SIZE = 4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	int mDeckSize = 20;
};
