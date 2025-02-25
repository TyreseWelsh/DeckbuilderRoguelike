// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MapData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, ClassGroup=(Custom))
class TILEMAPGENERATOR_API UMapData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int mapSizeX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int mapSizeY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int tileSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int numBSPSplits;
	
};
