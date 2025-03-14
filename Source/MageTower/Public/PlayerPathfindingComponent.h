// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PathfindingComponent.h"
#include "PlayerPathfindingComponent.generated.h"

class USpellCastingComponent;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class MAGETOWER_API UPlayerPathfindingComponent : public UPathfindingComponent
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	void StartMove(const FInputActionValue& _Value);
	
protected:
	TObjectPtr<USpellCastingComponent> ownerSpellcastingComp;

};
