// Fill out your copyright notice in the Description page of Project Settings.


#include "MageTower/Public/PathfindingComponent.h"

#include "IsActionObject.h"
#include "TileMapFunctionLibrary.h"
#include "TileComponent.h"


// Sets default values for this component's properties
UPathfindingComponent::UPathfindingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}

// Called when the game starts
void UPathfindingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

void UPathfindingComponent::FindPath(UTileComponent* _StartTile, UTileComponent* _TargetTile)
{
	mpOpenSet.Empty();
	mpClosedSet.Empty();
	
	_StartTile->mGCost = 0;
	mpOpenSet.Add(_StartTile);

	while(mpOpenSet.Num() > 0)
	{
		// Find path
		UTileComponent* currentTile = mpOpenSet[0];
		for(int i = 1; i < mpOpenSet.Num(); i++)
		{
			if(mpOpenSet[i]->mFCost < currentTile->mFCost or
				(mpOpenSet[i]->mFCost == currentTile->mFCost && mpOpenSet[i]->mHCost < currentTile->mHCost))
			{
				currentTile = mpOpenSet[i];
			}
		}
		mpOpenSet.Remove(currentTile);
		mpClosedSet.Add(currentTile);
		
		float distToTarget = FVector::Distance(currentTile->GetOwner()->GetActorLocation(), _TargetTile->GetOwner()->GetActorLocation());
		if(distToTarget == 100)
		{
			// End pathfinding and calculate path
			RetracePath(_StartTile, currentTile);
			return;
		}
		
		// Add valid neighbour tiles to open set
		for(UTileComponent* NeighbourTileComponent : currentTile->mpNeighbourTiles)
		{
			if(!NeighbourTileComponent->mbIsWalkable or mpClosedSet.Contains(NeighbourTileComponent))
			{
				continue;
			}
	
			int NewNeighbourGCost = abs(currentTile->mGCost + GetDistance(currentTile, NeighbourTileComponent));
			if(NewNeighbourGCost < NeighbourTileComponent->mGCost or !mpOpenSet.Contains(NeighbourTileComponent))
			{
				NeighbourTileComponent->mGCost = NewNeighbourGCost;
				NeighbourTileComponent->mHCost = abs(GetDistance(NeighbourTileComponent, _TargetTile));
				
				NeighbourTileComponent->mFCost = NeighbourTileComponent->mGCost + NeighbourTileComponent->mHCost;
				NeighbourTileComponent->mpParentTile = currentTile;

				if(!mpOpenSet.Contains(NeighbourTileComponent))
				{
					mpOpenSet.Add(NeighbourTileComponent);
				}
			}
		}
	}
}

void UPathfindingComponent::EndMove()
{
}

void UPathfindingComponent::ClearMoveTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(mMoveTimer);
}

void UPathfindingComponent::RetracePath(UTileComponent* _StartTile, UTileComponent* _TargetTile)
{
	UTileComponent* currentTile = _TargetTile;
	if(currentTile != _StartTile)
	{
		while(currentTile->mpParentTile != _StartTile)
		{
			if(!currentTile->mpParentTile)
			{
				break;
			}
			currentTile = currentTile->mpParentTile;
		}
	}
	
	if(currentTile->mbIsWalkable)
	{
		DisableMovement();			
		UTileMapFunctionLibrary::UnOccupyTile(GetOwner());
		
		MoveOverTime(currentTile->GetOwner()->GetActorLocation());
	}
}

int UPathfindingComponent::GetDistance(UTileComponent* _TileA, UTileComponent* _TileB)
{
	int tileSize = 100;
	int DistanceX = abs(_TileA->GetOwner()->GetActorLocation().X - _TileB->GetOwner()->GetActorLocation().X);
	int DistanceY = abs(_TileA->GetOwner()->GetActorLocation().Y - _TileB->GetOwner()->GetActorLocation().Y);

	if(DistanceX > DistanceY)
	{
		return (14.f * tileSize) * DistanceY + (10.f * tileSize) * (DistanceX - DistanceY);
	}

	return (14.f * tileSize) * DistanceX + (10.f * tileSize) * (DistanceY - DistanceX);
}

// Called every frame
void UPathfindingComponent::TickComponent(float _DeltaTime, ELevelTick _TickType, FActorComponentTickFunction* _ThisTickFunction)
{
	Super::TickComponent(_DeltaTime, _TickType, _ThisTickFunction);

	// ...
}

void UPathfindingComponent::MoveOverTime(FVector _NewLocation)
{
	// Start timer until player can move again
	mMoveDelegate.BindUFunction(this, "Move", GetOwner()->GetActorLocation(), _NewLocation);
	GetWorld()->GetTimerManager().SetTimer(mMoveTimer, mMoveDelegate, mMoveRate, true);
}

void UPathfindingComponent::Move(FVector _StartLocation, FVector _NewLocation)
{
	mMoveAlpha += mMoveIncrement;
	FVector currentLocation = FMath::Lerp(_StartLocation, _NewLocation, mMoveAlpha);
	if(mMoveAlpha >= 1)
	{
		// Reached move destination
		GetOwner()->SetActorLocation(_NewLocation);
		mMoveAlpha = 0;
		UTileMapFunctionLibrary::OccupyTile(GetOwner());
		EnableMovement();
		
		if(IIsActionObject* actionActorInterface = Cast<IIsActionObject>(GetOwner()))
		{
			actionActorInterface->GetTurnEndDelegate()->Broadcast();
		}
		ClearMoveTimer();
		return;
	}
	
	GetOwner()->SetActorLocation(currentLocation);
}

