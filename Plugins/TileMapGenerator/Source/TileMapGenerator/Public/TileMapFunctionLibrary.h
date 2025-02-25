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
	static AActor* GetBelowTile(AActor* StartingActor);
	static AActor* GetBelowTile(FVector StartingPos, UWorld* CurrentWorld);
	UFUNCTION(BlueprintCallable)
	static bool OccupyTile(AActor* OccupyingActor);
	UFUNCTION(BlueprintCallable)
	static bool UnOccupyTile(AActor* UnOccupyingActor);
};
