// Fill out your copyright notice in the Description page of Project Settings.


#include "TileMapFunctionLibrary.h"

#include "TileComponent.h"

AActor* UTileMapFunctionLibrary::GetBelowTile(AActor* _StartingActor)
{
	FHitResult hitResult;
	FVector traceEnd = FVector(_StartingActor->GetActorLocation().X, _StartingActor->GetActorLocation().Y, _StartingActor->GetActorLocation().Z - 1000);
	FCollisionQueryParams collisionParams;
	collisionParams.AddIgnoredActor(_StartingActor);
	_StartingActor->GetWorld()->LineTraceSingleByChannel(hitResult, _StartingActor->GetActorLocation(), traceEnd, ECC_Visibility, collisionParams);

	if (IsValid(hitResult.GetActor()))
	{
		if (hitResult.GetActor()->GetComponentByClass<UTileComponent>())
		{
			return hitResult.GetActor();
		}

		return nullptr;
	}

	return nullptr;
}

AActor* UTileMapFunctionLibrary::GetBelowTile(FVector _StartingPos, UWorld* _CurrentWorld)
{
	FHitResult hitResult;
	FVector traceEnd = FVector(_StartingPos.X, _StartingPos.Y, _StartingPos.Z - 1000);
	_CurrentWorld->LineTraceSingleByChannel(hitResult, _StartingPos, traceEnd, ECC_Visibility);
	
	if (IsValid(hitResult.GetActor()))
	{
		if (hitResult.GetActor()->GetComponentByClass<UTileComponent>())
		{
			return hitResult.GetActor();
		}

		return nullptr;
	}

	return nullptr;
}

bool UTileMapFunctionLibrary::OccupyTile(AActor* _OccupyingActor)
{
	if (AActor* tile = GetBelowTile(_OccupyingActor))
	{
		if (UTileComponent* tileComponent = tile->GetComponentByClass<UTileComponent>())
		{
			if(!IsValid(tileComponent->GetOccupyingObject()))
			{
				tileComponent->SetOccupyingObject(_OccupyingActor);
				tileComponent->mbIsWalkable = false;
			}
			return true;
		}
	}
	return false;
}

bool UTileMapFunctionLibrary::OccupyTile(AActor* _OccupyingActor, FVector _StartingPos)
{
	if (AActor* tile = GetBelowTile(_StartingPos, _OccupyingActor->GetWorld()))
	{
		if (UTileComponent* tileComponent = tile->GetComponentByClass<UTileComponent>())
		{
			if(!IsValid(tileComponent->GetOccupyingObject()))
			{
				tileComponent->SetOccupyingObject(_OccupyingActor);
				tileComponent->mbIsWalkable = false;
			}
			return true;
		}
	}
	return false;
}

bool UTileMapFunctionLibrary::UnOccupyTile(AActor* _UnOccupyingActor)
{
	if (AActor* tile = GetBelowTile(_UnOccupyingActor))
	{
		if (UTileComponent* tileComponent = tile->GetComponentByClass<UTileComponent>())
		{
			if(IsValid(tileComponent->GetOccupyingObject()))
			{
				tileComponent->SetOccupyingObject(nullptr);
			}
			tileComponent->mbIsWalkable = true;

			return true;
		}
	}
	return false;
}
