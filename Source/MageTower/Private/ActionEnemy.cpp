// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionEnemy.h"
#include "PathfindingComponent.h"
#include "TileComponent.h"
#include "TileMapFunctionLibrary.h"

AActionEnemy::AActionEnemy()
{
	mpPathfindingComponent = CreateDefaultSubobject<UPathfindingComponent>(TEXT("PathfindingComponent"));
}

void AActionEnemy::StartTurn()
{

	if(mpPlayer)
	{
		UTileComponent* startTile = UTileMapFunctionLibrary::GetBelowTile(this)->GetComponentByClass<UTileComponent>();
		UTileComponent* targetTile = UTileMapFunctionLibrary::GetBelowTile(mpPlayer)->GetComponentByClass<UTileComponent>();

		mpPathfindingComponent->FindPath(startTile, targetTile);
	}
}