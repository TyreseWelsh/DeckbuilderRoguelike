// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionPawn.h"
#include "PlayerPawn.generated.h"

class UCameraComponent;
class UPathfindingComponent;
class USpellCastingComponent;
class UPlayerHUDWidget;

/**
 * 
 */
UCLASS()
class MAGETOWER_API APlayerPawn : public AActionPawn
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> mpOrigin;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> mpMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> mpCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPathfindingComponent> mpPathfindingComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpellCastingComponent> mpSpellCastingComp;

public:
	APlayerPawn();

	// Temp
	void StartCombat();
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> playerHUDClass;
	TObjectPtr<UPlayerHUDWidget> mpPlayerHUD;
};
