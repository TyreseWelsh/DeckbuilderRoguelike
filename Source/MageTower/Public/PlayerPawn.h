// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionPawn.h"
#include "IsPlayer.h"
#include "PlayerPawn.generated.h"


class UCameraComponent;
class UPlayerPathfindingComponent;
class USpellCastingComponent;
class UPlayerHUDWidget;

/**
 * 
 */
UCLASS()
class MAGETOWER_API APlayerPawn : public AActionPawn, public IIsPlayer
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> mpOrigin;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> mpMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> mpCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPlayerPathfindingComponent> mpPlayerPathfindingComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpellCastingComponent> mpSpellCastingComp;

public:
	APlayerPawn();

	// Temp
	void StartCombat();
	void EndCombat();

	// "IsPlayer" interface functions
	virtual void StartTurn() override;
	virtual FOnPlayerTurnEnd* GetTurnEndDelegate() override { return &mOnTurnEndDelegate; }
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> playerHUDClass;
	TObjectPtr<UPlayerHUDWidget> mpPlayerHUD;

	//FOnPlayerTurnStart mOnTurnStartDelegate;
	FOnPlayerTurnEnd mOnTurnEndDelegate;
};
