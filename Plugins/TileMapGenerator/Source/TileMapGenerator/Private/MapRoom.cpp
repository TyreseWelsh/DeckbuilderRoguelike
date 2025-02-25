// Fill out your copyright notice in the Description page of Project Settings.


#include "MapRoom.h"
#include "TileComponent.h"

// Sets default values
AMapRoom::AMapRoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMapRoom::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapRoom::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void AMapRoom::Init(FRoomData& _RoomData)
{
	mRoomData = _RoomData;

	GenerateTiles();
}

void AMapRoom::GenerateTiles()
{
	int leftPadding = FMath::RandRange(mRoomData.mMinPadding, mRoomData.mMaxPadding) * mRoomData.mTileSize;
	int topPadding = FMath::RandRange(mRoomData.mMinPadding, mRoomData.mMaxPadding) * mRoomData.mTileSize;
	int rightPadding = FMath::RandRange(mRoomData.mMinPadding, mRoomData.mMaxPadding) * mRoomData.mTileSize;
	int bottomPadding = FMath::RandRange(mRoomData.mMinPadding, mRoomData.mMaxPadding) * mRoomData.mTileSize;

	
	FVector roomStartPos = FVector(mRoomData.mOrigin.X + leftPadding, mRoomData.mOrigin.Y + topPadding, mRoomData.mOrigin.Z);
	FVector roomEndPos = FVector((roomStartPos.X + mRoomData.mSizeX) - rightPadding, (roomStartPos.Y + mRoomData.mSizeY) - bottomPadding, roomStartPos.Z);
	
	int lastIndexX = ((roomEndPos.X - roomStartPos.X) / mRoomData.mTileSize) - 1;
	for(int i = 0; i <= lastIndexX; ++i)
	{
		int lastIndexY = ((roomEndPos.Y - roomStartPos.Y) / mRoomData.mTileSize) - 1;
		for (int j = 0; j <= lastIndexY; ++j)
		{
			FVector TileSpawnPos = FVector::ZeroVector;
			TileSpawnPos.X = roomStartPos.X + i * mRoomData.mTileSize;
			TileSpawnPos.Y = roomStartPos.Y + j * mRoomData.mTileSize;

			mpRoomTiles.Add(SpawnTile(TileSpawnPos));
		}
	}
}

AActor* AMapRoom::SpawnTile(FVector _TileSpawnPos)
{
	//int TileMapArrayIndex = UTileMapFunctionLibrary::CalculateIndexFromTilePos(TileSpawnPos, MapGenerator->MapOrigin, MapGenerator->MapSizeX, TileSize);
	TObjectPtr<AActor> CurrentTile;
	
	// Spawns new tile actor if it does not exist inside the "MapTiles" array
	if(IsValid(GetWorld()))
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		CurrentTile = GetWorld()->SpawnActor<AActor>(mRoomData.mTileClass, _TileSpawnPos, FRotator::ZeroRotator, SpawnParameters);

		if(IsValid(CurrentTile))
		{
			// Initialises the current tile component
			if(UTileComponent* CurrentTileComponent = CurrentTile->GetComponentByClass<UTileComponent>())
			{
				CurrentTileComponent->Init(mRoomData.mTileSize);
			}
			else
			{
				UE_LOG(LogTemp, Display, TEXT("No tile component..."));
			}
		}
	}
	

	return CurrentTile;
}

