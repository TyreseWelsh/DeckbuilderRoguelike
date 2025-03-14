// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IsPlayer.generated.h"

//DECLARE_MULTICAST_DELEGATE_OneParam(FOnPlayerTurnStart, APawn* /*_Player*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnPlayerTurnEnd, APawn* /*_Player*/);


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIsPlayer : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MAGETOWER_API IIsPlayer
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//FOnPlayerTurnStart* GetTurnStartDelegate();
	virtual void StartTurn();
	virtual FOnPlayerTurnEnd* GetTurnEndDelegate();
};
