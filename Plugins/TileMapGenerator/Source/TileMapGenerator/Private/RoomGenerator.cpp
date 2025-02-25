// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomGenerator.h"
#include "MapRoom.h"

void URoomGenerator::Init(FRoomData& _RoomData, UWorld* _World)
{
	mpWorld = _World;
	mTileSize = _RoomData.mTileSize;
	StartSplit(_RoomData);
}

void URoomGenerator::StartSplit(FRoomData& _NewRoomData)
{
	if(_NewRoomData.mBSPSplitsRemaining > 0)
	{
		SplitRoom(_NewRoomData);
		return;
	}
	// Can no longer split room
	SpawnRoom(_NewRoomData);
}

void URoomGenerator::SplitRoom(FRoomData &_RoomData)
{
	float splitPercent = FMath::RandRange(0.35, 0.65);
	/*float num1 = 1 / (MapGenerator->InitialRoomSplitNum * 2);
	int num2 = FMath::RandRange(1, MapGenerator->InitialRoomSplitNum);
	if(num2 % 2 == 0)
	{
		num2 -= 1;
	}
	float SplitPercent = num1 * num2;*/
	
	if(_RoomData.mSizeY >= _RoomData.mSizeX)
	{
		// Check to split horizontally
		// Making sure both rooms produced by the split are larger than the minimum room size
		if(mMinRoomSize < splitPercent * _RoomData.mSizeY && mMinRoomSize < (1 - splitPercent) * _RoomData.mSizeY)
		{
			SplitHorizontally(splitPercent, _RoomData);
			return;
		}
		

		// Trying split again straight down the middle to be sure this room is too small to be split before we move on
		splitPercent = 0.5f;
		if(mMinRoomSize > (splitPercent * _RoomData.mSizeY))
		{
			SpawnRoom(_RoomData);
			return;
		}

		SplitHorizontally(splitPercent, _RoomData);
	}
	else
	{
		// Check to split vertically
		//
		if(mMinRoomSize < splitPercent * _RoomData.mSizeX && mMinRoomSize < (1 - splitPercent) * _RoomData.mSizeX)
		{
			SplitVertically(splitPercent, _RoomData);
			return;
		}

		//
		splitPercent = 0.5f;
		if(mMinRoomSize > (splitPercent * _RoomData.mSizeX))
		{
			SpawnRoom(_RoomData);
			return;
		}

		SplitVertically(splitPercent, _RoomData);
	}
}

void URoomGenerator::SplitHorizontally(const float _SplitPercent, FRoomData& _RoomData)
{
	int roomBottom = _RoomData.mOrigin.Y + _RoomData.mSizeY;

	int splitLocationY = _RoomData.mOrigin.Y + ((roomBottom - _RoomData.mOrigin.Y) * _SplitPercent);
	splitLocationY = (_SplitPercent >= 0.5f) ? RoundToTileSizeMultiple(splitLocationY, false) : RoundToTileSizeMultiple(splitLocationY, true);
	
	// Setup and spawn of Exit actor along split
	int randLocationAlongSplit;
	if(_RoomData.mBSPSplitsRemaining == 1)
	{
		randLocationAlongSplit = _RoomData.mSizeX * FMath::RandRange(0.225, 0.775);
	}
	else
	{
		randLocationAlongSplit = _RoomData.mSizeX *
			(FMath::RandBool() ? FMath::RandRange(mLowerSplitPercentMin, mLowerSplitPercentMax) : FMath::RandRange(mUpperSplitPercentMin, mUpperSplitPercentMax));
	}
	
	int exitSpawnPosX = _RoomData.mOrigin.X + RoundToTileSizeMultiple(randLocationAlongSplit, true);

	FVector exitSpawnPos = FVector(exitSpawnPosX, splitLocationY, _RoomData.mOrigin.Z);
	SpawnExit(exitSpawnPos, FRotator::ZeroRotator);
	
	
	// Creating and initialising child rooms
	FRoomData leftRoomData(FVector(_RoomData.mOrigin.X, _RoomData.mOrigin.Y, _RoomData.mOrigin.Z + mRoomSpawnOffsetZ),
		_RoomData.mSizeX, CalculateLeftRoomSize(splitLocationY, _RoomData.mOrigin.Y), _RoomData.mBSPSplitsRemaining - 1,
		_RoomData.mMinPadding, _RoomData.mMaxPadding, _RoomData.mTileSize, _RoomData.mTileClass);
	StartSplit(leftRoomData);

	int rightRoomOriginY = splitLocationY + mTileSize;
	FRoomData rightRoomData(FVector(_RoomData.mOrigin.X, rightRoomOriginY, _RoomData.mOrigin.Z + mRoomSpawnOffsetZ),
		_RoomData.mSizeX, CalculateRightRoomSize(rightRoomOriginY, roomBottom), _RoomData.mBSPSplitsRemaining - 1,
		_RoomData.mMinPadding, _RoomData.mMaxPadding, _RoomData.mTileSize, _RoomData.mTileClass);
	StartSplit(rightRoomData);
}

void URoomGenerator::SplitVertically(const float _SplitPercent, FRoomData& _RoomData)
{
	int roomRight = _RoomData.mOrigin.X + _RoomData.mSizeX;
	
	int splitLocationX = _RoomData.mOrigin.X + ((roomRight - _RoomData.mOrigin.X) * _SplitPercent);
	splitLocationX = (_SplitPercent >= 0.5f) ? RoundToTileSizeMultiple(splitLocationX, false) : RoundToTileSizeMultiple(splitLocationX, true);
	
	int randLocationAlongSplit;
	if(_RoomData.mBSPSplitsRemaining == 1)
	{
		randLocationAlongSplit = _RoomData.mSizeY * FMath::RandRange(0.225, 0.775);
	}
	else
	{
		randLocationAlongSplit = _RoomData.mSizeY *
			(FMath::RandBool() ? FMath::RandRange(mLowerSplitPercentMin, mLowerSplitPercentMax) : FMath::RandRange(mUpperSplitPercentMin, mUpperSplitPercentMax));
	}
	
	int exitSpawnPosY = _RoomData.mOrigin.Y + RoundToTileSizeMultiple(randLocationAlongSplit, true);
	
	FVector exitSpawnPos = FVector(splitLocationX, exitSpawnPosY, _RoomData.mOrigin.Z);
	SpawnExit(exitSpawnPos, FRotator(0, 90, 0));
	
	// Creating and initialising child rooms
	FRoomData leftRoomData(FVector(_RoomData.mOrigin.X, _RoomData.mOrigin.Y, _RoomData.mOrigin.Z + mRoomSpawnOffsetZ),
	CalculateLeftRoomSize(splitLocationX, _RoomData.mOrigin.X), _RoomData.mSizeY, _RoomData.mBSPSplitsRemaining - 1,
	_RoomData.mMinPadding, _RoomData.mMaxPadding, _RoomData.mTileSize, _RoomData.mTileClass);
	StartSplit(leftRoomData);
	
	int rightRoomOriginX = splitLocationX + mTileSize;
	FRoomData rightRoomData(FVector(rightRoomOriginX, _RoomData.mOrigin.Y, _RoomData.mOrigin.Z + mRoomSpawnOffsetZ),
	CalculateRightRoomSize(rightRoomOriginX, roomRight), _RoomData.mSizeY, _RoomData.mBSPSplitsRemaining - 1,
	_RoomData.mMinPadding, _RoomData.mMaxPadding, _RoomData.mTileSize, _RoomData.mTileClass);
	StartSplit(rightRoomData);
}

void URoomGenerator::SpawnExit(FVector& _SpawnPos, FRotator _SpawnRot)
{
	
}

void URoomGenerator::SpawnRoom(FRoomData& _RoomData)
{
	AMapRoom* NewRoom = mpWorld->SpawnActor<AMapRoom>(mRoomClass, _RoomData.mOrigin, FRotator::ZeroRotator);
	// TODO: UNCOMMENT AND FIX vvv
	if(IsValid(NewRoom))
	{
		NewRoom->Init(_RoomData);
		mpMapRooms.Add(NewRoom);
	}
}

float URoomGenerator::RoundToTileSizeMultiple(const float _OldValue, const bool _bRoundUp)
{
	float CurrentValue = _OldValue / mTileSize;
	CurrentValue = (_bRoundUp) ? ceil(CurrentValue) : floor(CurrentValue);
	
	return CurrentValue * mTileSize;
}

int URoomGenerator::CalculateLeftRoomSize(const int _SplitLocation, const int _Origin)
{
	return _SplitLocation - _Origin;
}

int URoomGenerator::CalculateRightRoomSize(const int _SplitLocation, const int _RoomEnd)
{
	return _RoomEnd - _SplitLocation;
}
