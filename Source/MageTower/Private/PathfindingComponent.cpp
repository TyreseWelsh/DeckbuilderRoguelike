// Fill out your copyright notice in the Description page of Project Settings.


#include "MageTower/Public/PathfindingComponent.h"
#include "InputActionValue.h"
#include "TileComponent.h"
#include "TileMapFunctionLibrary.h"
#include "SpellCastingComponent.h"

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

void UPathfindingComponent::StartMove(const FInputActionValue& _Value)
{
	FVector2D moveDirection = _Value.Get<FVector2D>();

	FVector newLocation = FVector(GetOwner()->GetActorLocation().X + moveDirection.Y * mMoveDistance,GetOwner()->GetActorLocation().Y + moveDirection.X * mMoveDistance, GetOwner()->GetActorLocation().Z);
	if(AActor* tile = UTileMapFunctionLibrary::GetBelowTile(newLocation, GetWorld()))
	{
		if(tile->GetComponentByClass<UTileComponent>()->mbIsWalkable && mbCanMove)
		{
			if(USpellCastingComponent* ownerSpellcastingComp = GetOwner()->GetComponentByClass<USpellCastingComponent>())
			{
				ownerSpellcastingComp->IncreaseMana();
				ownerSpellcastingComp->RotateHand();
			}
			
			DisableMovement();			
			UTileMapFunctionLibrary::UnOccupyTile(GetOwner());
			
			// Start timer until player can move again
			mMoveDelegate.BindUFunction(this, "Move", GetOwner()->GetActorLocation(), newLocation);
			GetWorld()->GetTimerManager().SetTimer(mMoveTimer, mMoveDelegate, mMoveRate, true);
			
			UTileMapFunctionLibrary::OccupyTile(GetOwner());
		}
	}
}


// Called every frame
void UPathfindingComponent::TickComponent(float _DeltaTime, ELevelTick _TickType, FActorComponentTickFunction* _ThisTickFunction)
{
	Super::TickComponent(_DeltaTime, _TickType, _ThisTickFunction);

	// ...
}

void UPathfindingComponent::Move(FVector _StartLocation, FVector _NewLocation)
{
	mMoveAlpha += mMoveIncrement;
	FVector currentLocation = FMath::Lerp(_StartLocation, _NewLocation, mMoveAlpha);
	if(mMoveAlpha >= 1)
	{
		// Reached destination, so clear timer
		GetOwner()->SetActorLocation(_NewLocation);
		mMoveAlpha = 0;
		mbCanMove = true;
		GetWorld()->GetTimerManager().ClearTimer(mMoveTimer);
		return;
	}

	GetOwner()->SetActorLocation(currentLocation);
}

