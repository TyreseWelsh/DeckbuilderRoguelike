// Fill out your copyright notice in the Description page of Project Settings.


#include "FieldManager.h"

#include "TileMapFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "ActionActor.h"
#include "ActionEnemy.h"
#include "IsPlayer.h"
#include "IsFieldManager.h"
#include "TileComponent.h"
#include "GameFramework/GameModeBase.h"

void UFieldManager::Init(TArray<AActor*> _AvailableTiles)
{
	mpAvailableTiles = _AvailableTiles;
	SetPlayerStart();

	SpawnEnemies();
}

void UFieldManager::NewTurn(APawn* _Player)
{

	for(AActionActor* fieldActor : mpFieldActors)
	{
		// Move enemies, tick dot's, do environment stuff, etc
		//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Orange, FString::Printf(TEXT("FieldManager: Loop through fieldActors...")));
		fieldActor->StartTurn();
	}

	// After field actors have finished, player can take actions
	if(IIsPlayer* playerInterface = Cast<IIsPlayer>(_Player))
	{
		playerInterface->StartTurn();
	}
}

void UFieldManager::SetPlayerStart()
{
	int startTileIndex = mpAvailableTiles.Num() / 2;
	if(AActor* startTile = mpAvailableTiles[startTileIndex])
	{
		APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		playerPawn->SetActorLocation(startTile->GetActorLocation());
		UTileMapFunctionLibrary::OccupyTile(playerPawn);
	}
}

void UFieldManager::SpawnEnemies()
{
	// Sorts by key in ascending order
	mpEnemyCosts.KeySort([](int32 _A, int32 _B)
	{
		return _A < _B; 
	});
	FindEnemySpawnClass(currentRoomDifficulty);
}

void UFieldManager::FindEnemySpawnClass(int _PointsLeft)
{
	TArray<int> costKeys;
	mpEnemyCosts.GenerateKeyArray(costKeys);
	int maxCostIndex = 0;
	for(int i = 0; i < costKeys.Num(); i++)
	{
		if(costKeys[i] <= _PointsLeft)
		{
			maxCostIndex = i;
			continue;
		}

		break;
	}

	int randCostIndex = FMath::RandRange(0, maxCostIndex);
	int randCostKey = costKeys[randCostIndex];
	_PointsLeft -= randCostKey;
	int randCostValueIndex = FMath::RandRange(0, mpEnemyCosts[randCostKey].costObjects.Num() - 1);
	
	SpawnEnemy(mpEnemyCosts[randCostKey].costObjects[randCostValueIndex]);

	if(_PointsLeft > 0)
	{
		// Call this function again with remaining _PointsLeft
		FindEnemySpawnClass(_PointsLeft);
	}
}

void UFieldManager::SpawnEnemy(TSubclassOf<AActionActor> enemyClass)
{
	if(AActor* spawnTile = FindEnemySpawnTile())
	{
		float enemyRotationYaw = FMath::RandRange(0, 4) * 90;
		FRotator enemyRotation = FRotator(0, enemyRotationYaw, 0);
		AActionEnemy* currentEnemy = GetWorld()->SpawnActor<AActionEnemy>(enemyClass, spawnTile->GetActorLocation(), enemyRotation);
		if(IIsFieldManager* fieldManagerInterface = Cast<IIsFieldManager>(GetWorld()->GetAuthGameMode()))
		{
			currentEnemy->SetPlayer(fieldManagerInterface->GetPlayer());
		}
		UTileMapFunctionLibrary::OccupyTile(currentEnemy);
		mpFieldActors.Add(currentEnemy);
	}
}

AActor* UFieldManager::FindEnemySpawnTile()
{
	int randTileIndex = FMath::RandRange(0, mpAvailableTiles.Num() - 1);
	AActor* currentTile = mpAvailableTiles[randTileIndex];
	while(!currentTile->GetComponentByClass<UTileComponent>()->mbIsWalkable)
	{
		randTileIndex = FMath::RandRange(0, mpAvailableTiles.Num() - 1);
		currentTile = mpAvailableTiles[randTileIndex];
	}

	return currentTile;
}
