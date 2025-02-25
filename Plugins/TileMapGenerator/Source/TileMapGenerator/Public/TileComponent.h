// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "TileComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TILEMAPGENERATOR_API UTileComponent : public UBoxComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTileComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float _DeltaTime, ELevelTick _TickType, FActorComponentTickFunction* _ThisTickFunction) override;
	void Init(int _TileSize);

	bool mbIsWalkable = true;
	bool mbIsOccupied = false;

	int mGCost = 0;
	int mHCost = 0;
	int mFCost = 0;
	UPROPERTY()
	TObjectPtr<UTileComponent> mpParentTile;
	UPROPERTY()
	TArray<UTileComponent*> mpNeighbourTiles;

	//TArray<UTileComponent*> GetNeighbourTiles();

	AActor* GetOccupyingObject() { return mpOccupyingObject; }
	void SetOccupyingObject(AActor* _newObject) { mpOccupyingObject = _newObject; }

private:
	void FindNeighbourTiles();

	AActor* mpOccupyingObject;
};
