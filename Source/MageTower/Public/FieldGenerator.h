// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FieldGenerator.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAGETOWER_API UFieldGenerator : public UActorComponent
{
	GENERATED_BODY()

public:
	TArray<AActor*> GenerateField();

protected:
	AActor* SpawnTile(FVector _SpawnPos);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AActor> mpTileClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mTileSize;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mFieldSizeX;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int mFieldSizeY;

	UPROPERTY(BlueprintReadOnly)
	TArray<AActor*> mpFieldTiles;
};
