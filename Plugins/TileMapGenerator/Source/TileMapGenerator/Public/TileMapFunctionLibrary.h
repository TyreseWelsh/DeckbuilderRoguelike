// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TileMapFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class TILEMAPGENERATOR_API UTileMapFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static AActor* GetBelowTile(AActor* _StartingActor);
	static AActor* GetBelowTile(FVector _StartingPos, UWorld* _CurrentWorld);
	UFUNCTION(BlueprintCallable)
	static bool OccupyTile(AActor* _OccupyingActor);
	static bool OccupyTile(AActor* _OccupyingActor, FVector _StartingPos);
	UFUNCTION(BlueprintCallable)
	static bool UnOccupyTile(AActor* _UnOccupyingActor);
};
