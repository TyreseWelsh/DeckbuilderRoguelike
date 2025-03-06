// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DamageTypeWidget.generated.h"

class UImage;
class USpacer;

/**
 * 
 */
UCLASS()
class MAGETOWER_API UDamageTypeWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget, AllowPrivateAccess))
	TObjectPtr<UImage> icon;
};
