// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPathfindingComponent.h"

#include "InputActionValue.h"
#include "TileComponent.h"
#include "TileMapFunctionLibrary.h"
#include "SpellCastingComponent.h"
#include "IsActionObject.h"
#include "Kismet/GameplayStatics.h"

void UPlayerPathfindingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	ownerSpellcastingComp = GetOwner()->GetComponentByClass<USpellCastingComponent>();
}

void UPlayerPathfindingComponent::StartMove(const FInputActionValue& _Value)
{
	FVector2D moveDirection = _Value.Get<FVector2D>();
	FVector newLocation;

	if(ownerSpellcastingComp)
	{
		switch(ownerSpellcastingComp->GetCastState())
		{
		case(ECastingState::None):
			newLocation = FVector(GetOwner()->GetActorLocation().X + moveDirection.Y * mMoveDistance,GetOwner()->GetActorLocation().Y + moveDirection.X * mMoveDistance, GetOwner()->GetActorLocation().Z);
			if(AActor* tile = UTileMapFunctionLibrary::GetBelowTile(newLocation, GetWorld()))
			{
				if(tile->GetComponentByClass<UTileComponent>()->mbIsWalkable && mbCanMove)
				{
					if(ownerSpellcastingComp)
					{
						ownerSpellcastingComp->IncreaseMana(ownerSpellcastingComp->GetManaPerTurn());
						ownerSpellcastingComp->RotateHand();
					}
					
					UTileMapFunctionLibrary::UnOccupyTile(GetOwner());
					MoveOverTime(newLocation);
				}
			}
			break;
		case(ECastingState::Aiming):
			ownerSpellcastingComp->SetCastDirection(moveDirection);
			break;
		case(ECastingState::Casting):
			break;
		default:
			break;
		}
	}
}

void UPlayerPathfindingComponent::EndMove()
{
	
}
