// Fill out your copyright notice in the Description page of Project Settings.


#include "TileComponent.h"
#include "TileMapFunctionLibrary.h"

// Sets default values for this component's properties
UTileComponent::UTileComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTileComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTileComponent::TickComponent(float _DeltaTime, ELevelTick _TickType, FActorComponentTickFunction* _ThisTickFunction)
{
	Super::TickComponent(_DeltaTime, _TickType, _ThisTickFunction);

	// ...
}

void UTileComponent::Init(int _TileSize)
{
	FindNeighbourTiles();
}

void UTileComponent::FindNeighbourTiles()
{
	int tileSize = 100;
	for(int x = -1; x <= 1; x++)
    {
    	for(int y = -1; y <= 1; y++)
    	{
    		if(abs(x) != abs(y))
    		{
    			FVector neighbourTileLocation = FVector(GetOwner()->GetActorLocation().X + x * tileSize, GetOwner()->GetActorLocation().Y + y * tileSize, GetOwner()->GetActorLocation().Z);

    			if(AActor* neighbourTile = UTileMapFunctionLibrary::GetBelowTile(neighbourTileLocation, GetWorld()))
    			{
    				if(UTileComponent* neighbourTileComponent = neighbourTile->GetComponentByClass<UTileComponent>())
    				{
    					mpNeighbourTiles.Add(neighbourTileComponent);
    				}
    			}
    		}
    	}
    }
}

