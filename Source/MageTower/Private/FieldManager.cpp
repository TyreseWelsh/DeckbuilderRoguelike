// Fill out your copyright notice in the Description page of Project Settings.


#include "FieldManager.h"

#include "TileMapFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "ActionActor.h"
#include "ActionEnemy.h"
#include "IsActionObject.h"
#include "IsFieldManager.h"
#include "TileComponent.h"
#include "GameFramework/GameModeBase.h"

void UFieldManager::Init(TArray<AActor*> _AvailableTiles)
{
	mpAvailableTiles = _AvailableTiles;
	SetPlayerStart();

	SpawnEnemies();

	// Initial turn (player)
	NewTurn();
}

void UFieldManager::NewTurn()
{
	if(fieldActorTurnIndex >= mpFieldActors.Num())
	{
		fieldActorTurnIndex = 0;
	}

	if(IsValid(mpFieldActors[fieldActorTurnIndex]))
	{
		if(IIsActionObject* actionObjInterface = Cast<IIsActionObject>(mpFieldActors[fieldActorTurnIndex]))
		{
			actionObjInterface->StartTurn();
			fieldActorTurnIndex++;
		}
	}
}

void UFieldManager::SetPlayerStart()
{
	int startTileIndex = mpAvailableTiles.Num() / 2;
	if(AActor* startTile = mpAvailableTiles[startTileIndex])
	{
		mpPlayer = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		mpPlayer->SetActorLocation(startTile->GetActorLocation());
		UTileMapFunctionLibrary::OccupyTile(mpPlayer);
		mpFieldActors.Add(mpPlayer);
		mpPlayer->DisableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));
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
		if(IIsActionObject* actionInterface = Cast<IIsActionObject>(currentEnemy))
		{
			actionInterface->GetTurnEndDelegate()->AddUObject(this, &UFieldManager::NewTurn);
		}
		UTileMapFunctionLibrary::OccupyTile(currentEnemy);
		mpFieldActors.Add(currentEnemy);
	}
}

void UFieldManager::FieldActorDeath(AActionActor* _DeadActor)
{
	mpFieldActors.Remove(_DeadActor);
}