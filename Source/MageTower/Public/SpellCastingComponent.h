// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpellCastingComponent.generated.h"

class USpellCard;

UENUM(BlueprintType)
enum ECastingState : uint8
{
	None		UMETA(DisplayName = "None"),
	Aiming		UMETA(DisplayName = "Aiming"),
	Casting		UMETA(DisplayName = "Casting"),
};

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
	void SetCastDirection(FVector2D _CastDirection);
	void CancelSpellCast();

	ECastingState GetCastState() const { return mCurrentCastingState; }
	
	int mCurrentSpellIndex = -1;
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

	ECastingState mCurrentCastingState = ECastingState::None;
	FVector mCastDirection;
};
