// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IsFieldManager.generated.h"

class UFieldManager;
class APawn;
class UDataTable;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIsFieldManager : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MAGETOWER_API IIsFieldManager
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UFieldManager* GetFieldManager();
	virtual APawn* GetPlayer();
	virtual UDataTable* GetEnemyDataTable();
};
