// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpellCardWidget.generated.h"

class UImage;
class UTextBlock;

/**
 * 
 */
UCLASS()
class MAGETOWER_API USpellCardWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(BindWidget, AllowPrivateAccess))
	TObjectPtr<UImage> cardBackground;
	UPROPERTY(meta=(BindWidget, AllowPrivateAccess))
	TObjectPtr<UTextBlock> cardName;
	UPROPERTY(meta=(BindWidget, AllowPrivateAccess))
	TObjectPtr<UTextBlock> cardCost;
	UPROPERTY(meta=(BindWidget, AllowPrivateAccess))
	TObjectPtr<UTextBlock> cardDescription;
};
