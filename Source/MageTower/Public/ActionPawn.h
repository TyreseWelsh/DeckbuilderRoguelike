// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AbilitySystemInterface.h"
#include "ActionPawn.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);


class UAbilitySystemComponent;

UCLASS()
class MAGETOWER_API AActionPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AActionPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	
};
