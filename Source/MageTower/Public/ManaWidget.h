// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ManaWidget.generated.h"

class UImage;

/**
 * 
 */
UCLASS()
class MAGETOWER_API UManaWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void Init();
	void SetMana(int _CurrentMana);
	
protected:
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UImage> mana1;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UImage> mana2;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UImage> mana3;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UImage> mana4;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
    TObjectPtr<UImage> mana5;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UImage> mana6;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UImage> mana7;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UImage> mana8;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UImage> mana9;
	UPROPERTY(meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UImage> mana10;

	UPROPERTY()
	TArray<UImage*> manaPoints;
};
