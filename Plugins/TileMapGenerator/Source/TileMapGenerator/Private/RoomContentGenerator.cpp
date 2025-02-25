// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomContentGenerator.h"

#include "TileMapFunctionLibrary.h"
#include "MapRoom.h"
#include "TileComponent.h"
#include "Kismet/GameplayStatics.h"

void URoomContentGenerator::Init(TArray<AMapRoom*> _Rooms)
{
	mpRooms = _Rooms;

	FindStartingRoom();
}

void URoomContentGenerator::FindStartingRoom()
{
	// Should be picked randomly
	int startRoomIndex = 0;

	// TODO: Set default player pawn position to a tile in the room as the start position.
	// Then we need to make sure that the players movements make them occupy the correct tile, and not allow them to go outside the bounds of the room
	if(mpRooms.Num() > 0)
	{
		if(AMapRoom* startingRoom = mpRooms[startRoomIndex])
		{
			int startTileIndex = startingRoom->GetRoomTiles().Num() / 2;
			if(AActor* startTile = startingRoom->GetRoomTiles()[startTileIndex])
			{
				APawn* playerPawn = UGameplayStatics::GetPlayerPawn(startingRoom->GetWorld(), 0);
				playerPawn->SetActorLocation(startTile->GetActorLocation());
				UTileMapFunctionLibrary::OccupyTile(playerPawn);
			}
		}
	}
}
