// Fill out your copyright notice in the Description page of Project Settings.


#include "FieldGenerator.h"
#include "TileComponent.h"

TArray<AActor*> UFieldGenerator::GenerateField()
{
	FVector startPos = FVector(0, 0, 0);

	if(mpFieldTiles.IsEmpty())
	{
		for(int x = 0; x < mFieldSizeX / mTileSize; x++)
		{
			for(int y = 0; y < mFieldSizeY / mTileSize; y++)
			{
				FVector tileSpawnPos = FVector(0,0, startPos.Z);
				tileSpawnPos.X = startPos.X + x * mTileSize;
				tileSpawnPos.Y = startPos.Y + y * mTileSize;

				if(AActor* tile = SpawnTile(tileSpawnPos))
				{
					mpFieldTiles.Add(tile);
				}
			}
		}
	}

	// Here we will generate the environment on top of the ground tiles
	// Then we will return a new array of "still available" tiles that other things can be spawned on
	for(int i = 0; i < mpFieldTiles.Num(); i++)
	{
		if(UTileComponent* tileComp = mpFieldTiles[i]->GetComponentByClass<UTileComponent>())
		{
			tileComp->Init(100);
		}
	}
	return mpFieldTiles;
}

AActor* UFieldGenerator::SpawnTile(FVector _SpawnPos)
{
	if(GetWorld())
	{
		if(AActor* currentTile = GetWorld()->SpawnActor<AActor>(mpTileClass, _SpawnPos, FRotator(0, 0, 0)))
		{
			return currentTile;
		}

		return nullptr;
	}

	return nullptr;
}
