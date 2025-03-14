// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "ActionActor.h"
#include "ActionEnemy.generated.h"

struct FGameplayTagContainer;
class UPathfindingComponent;
class APlayerPawn;

USTRUCT(BlueprintType)
struct FEnemyData : public FTableRowBase, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int attackRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int attackWidth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer damageWeaknesses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int spawnCost;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override { TagContainer = damageWeaknesses; }
};

/**
 * 
 */
UCLASS()
class MAGETOWER_API AActionEnemy : public AActionActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPathfindingComponent> mpPathfindingComponent;

public:
	AActionEnemy();

	virtual void StartTurn() override;

	FEnemyData GetData() const { return data;}
private:
	FEnemyData data;
};