// Fill out your copyright notice in the Description page of Project Settings.


#include "MapGeneratorComponent.h"

#include "MapData.h"
#include "MapRoom.h"
#include "RoomContentGenerator.h"
#include "RoomGenerator.h"

// Sets default values for this component's properties
UMapGeneratorComponent::UMapGeneratorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMapGeneratorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	Init();
}


// Called every frame
void UMapGeneratorComponent::TickComponent(float _DeltaTime, ELevelTick _TickType, FActorComponentTickFunction* _ThisTickFunction)
{
	Super::TickComponent(_DeltaTime, _TickType, _ThisTickFunction);

	// ...
}

void UMapGeneratorComponent::Init()
{
	FRoomData initialRoomData(GetOwner()->GetActorLocation(), mpMapData->mapSizeX, mpMapData->mapSizeY, mpMapData->numBSPSplits,
		0, 0, mpMapData->tileSize, mTileClass);
	mpRoomGenerator = NewObject<URoomGenerator>(this, mRoomGeneratorClass);
	if(mpRoomGenerator)
	{
		mpRoomGenerator->Init(initialRoomData, GetWorld());

		if(mpRoomContentGenerator = NewObject<URoomContentGenerator>())
		{
			mpRoomContentGenerator->Init(mpRoomGenerator->mpMapRooms);
		}
	}
}

void UMapGeneratorComponent::GenerateMap()
{
	/*if(mTileClass && mpMapData)
	{
		for(int i = 0; i < mpMapData->mapSizeY / mpMapData->tileSize; i++)
		{
			for(int j = 0; j < mpMapData->mapSizeX / mpMapData->tileSize; j++)
			{
				FVector ownerLocation = GetOwner()->GetActorLocation();
				FVector tileLocation = FVector(ownerLocation.X + i * mpMapData->tileSize, ownerLocation.Y + j * mpMapData->tileSize, ownerLocation.Z);
				AActor* newTile = GetOwner()->GetWorld()->SpawnActor<AActor>(mTileClass, tileLocation, FRotator::ZeroRotator);
			}
		}
	}*/
}
