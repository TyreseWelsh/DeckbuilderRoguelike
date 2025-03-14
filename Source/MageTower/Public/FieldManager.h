// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FieldManager.generated.h"

class AActionActor;

USTRUCT(BlueprintType)
struct FFieldObjects
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)	
	TArray<TSubclassOf<AActionActor>> costObjects;
};

/**
 * Handles enemy spawning/managing. May also handle handling of environment objects
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAGETOWER_API UFieldManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void Init(TArray<AActor*> _AvailableTiles);
	UFUNCTION()
	void NewTurn(APawn* _Player);

	void SetPlayerStart();
protected:
	void SpawnEnemies();
	void FindEnemySpawnClass(int _PointsLeft);
	void SpawnEnemy(TSubclassOf<AActionActor> enemyClass);
	AActor* FindEnemySpawnTile();
	
	UPROPERTY()
	TArray<AActor*> mpAvailableTiles;
	UPROPERTY()
	TArray<AActionActor*> mpFieldActors;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TMap<int, FFieldObjects> mpEnemyCosts;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int currentRoomDifficulty = 40;
};
