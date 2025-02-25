// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapRoom.generated.h"

USTRUCT(BlueprintType)
struct FRoomData
{
	GENERATED_BODY()

	FRoomData() {}
	FRoomData(FVector _RoomOrigin, int _RoomSizeX, int _RoomSizeY, int _RoomSplitsRemaining, int _RoomMinPadding, int _RoomMaxPadding, int _TileSize, TSubclassOf<AActor> _TileClass)
		: mOrigin(_RoomOrigin), mSizeX(_RoomSizeX), mSizeY(_RoomSizeY), mBSPSplitsRemaining(_RoomSplitsRemaining),
		mMinPadding(_RoomMinPadding), mMaxPadding(_RoomMaxPadding), mTileSize(_TileSize), mTileClass(_TileClass)
		{}

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector mOrigin = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mSizeX = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mSizeY = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mBSPSplitsRemaining = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mMinPadding = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mMaxPadding = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mTileSize = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AActor> mTileClass;

	bool bIsActive = false;
};

UCLASS()
class TILEMAPGENERATOR_API AMapRoom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapRoom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float _DeltaTime) override;
	void Init(FRoomData& _RoomData);
	void GenerateTiles();
	AActor* SpawnTile(FVector _TileSpawnPos);

	FRoomData GetRoomData() const { return mRoomData;}
	TArray<AActor*> GetRoomTiles() const { return mpRoomTiles; } 

private:
	FRoomData mRoomData;
	TArray<AActor*> mpRoomTiles;
};
