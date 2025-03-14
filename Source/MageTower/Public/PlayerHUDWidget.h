// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "playerHUDWidget.generated.h"

class UProgressBar;
class UManaWidget;
class UHorizontalBox;
class UHandSpellsWidget;
class UImage;
class USpellData;

/**
 * 
 */
UCLASS()
class MAGETOWER_API UPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMana(int _CurrentMana);
	void UpdateHandUI(int _CardNum, USpellData* _SpellData);
	void EnableHand();
	void DisableHand();
	
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UProgressBar> healthBar;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UManaWidget> manaBar;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UHorizontalBox> cardArea;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UHandSpellsWidget> handSpellCards;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UImage> discardArea;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UImage> deckArea;
};
