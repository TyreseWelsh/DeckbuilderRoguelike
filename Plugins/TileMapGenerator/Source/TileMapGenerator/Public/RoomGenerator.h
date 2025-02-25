// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RoomGenerator.generated.h"

class AMapRoom;
struct FRoomData;

/**
 * 
 */
UCLASS(Blueprintable)
class TILEMAPGENERATOR_API URoomGenerator : public UObject
{
	GENERATED_BODY()

public:
	void Init(FRoomData& _RoomData, UWorld* _World);
	void StartSplit(FRoomData& _RoomData);
	UFUNCTION()
	void SplitRoom(FRoomData& _RoomData);
	void SplitHorizontally(const float _SplitPercent, FRoomData& _RoomData);
	void SplitVertically(const float _SplitPercent, FRoomData& _RoomData);

	void SpawnExit(FVector& _SpawnPos, FRotator _SpawnRot);
	void SpawnRoom(FRoomData& _RoomData);

	float RoundToTileSizeMultiple(const float _OldValue, const bool _bRoundUp);
	int CalculateLeftRoomSize(const int _SplitLocation, const int _Origin);
	int CalculateRightRoomSize(const int _SplitLocation, const int _RoomEnd);
	
	TArray<AMapRoom*> mpMapRooms;

private:
	UWorld* mpWorld;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess = true))
	TSubclassOf<AMapRoom> mRoomClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = true))
	int mMinRoomSize = 0;

	int mTileSize = 0;
	float mLowerSplitPercentMin = 0.2;
	float mLowerSplitPercentMax = 0.3;
	float mUpperSplitPercentMin = 0.7;
	float mUpperSplitPercentMax = 0.8;

	// Debug properties
	float mRoomSpawnOffsetZ = 0.f;
};
