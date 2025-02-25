// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RoomContentGenerator.generated.h"

class AMapRoom;

/**
 * 
 */
UCLASS()
class TILEMAPGENERATOR_API URoomContentGenerator : public UObject
{
	GENERATED_BODY()

public:
	void Init(TArray<AMapRoom*> _Rooms);

protected:
	void FindStartingRoom();
	
	TArray<AMapRoom*> mpRooms;
};
