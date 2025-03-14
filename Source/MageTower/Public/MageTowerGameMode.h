// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IsFieldManager.h"
#include "GameFramework/GameModeBase.h"
#include "MageTowerGameMode.generated.h"

class UFieldGenerator;
class UFieldManager;

UCLASS(minimalapi)
class AMageTowerGameMode : public AGameModeBase, public IIsFieldManager
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UFieldGenerator> mpFieldGenerator;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UFieldManager> mpFieldManager;
	
public:
	AMageTowerGameMode();

	virtual UFieldManager* GetFieldManager() override { return mpFieldManager; }
	virtual UDataTable* GetEnemyDataTable() override { return mpEnemyDataTable; }
	virtual APawn* GetPlayer() override { return mpPlayerPawn; }
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UDataTable> mpEnemyDataTable;
	UPROPERTY()
	TObjectPtr<APawn> mpPlayerPawn;
};



