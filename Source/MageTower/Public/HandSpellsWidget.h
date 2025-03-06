// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HandSpellsWidget.generated.h"

class UHorizontalBox;
class USpellCardWidget;
class USpellData;

/**
 * 
 */
UCLASS()
class MAGETOWER_API UHandSpellsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void Init();
	void UpdateCardUI(int _CardNum, USpellData* _SpellData);
	
protected:
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<USpellCardWidget> spellCard0;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<USpellCardWidget> spellCard1;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<USpellCardWidget> spellCard2;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<USpellCardWidget> spellCard3;

	TArray<USpellCardWidget*> handSpellCards;
};
