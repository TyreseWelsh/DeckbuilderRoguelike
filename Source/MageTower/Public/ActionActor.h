// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IsActionObject.h"
#include "GameFramework/Actor.h"
#include "ActionActor.generated.h"

UCLASS()
class MAGETOWER_API AActionActor : public AActor, public IIsActionObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void StartTurn() override;
	virtual FOnTurnEnd* GetTurnEndDelegate() override { return &mOnTurnEndDelegate; }

	void SetPlayer(AActor* _NewPlayer) { mpPlayer = _NewPlayer; }
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> mpOrigin;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> mpMesh;

	AActor* mpPlayer;

	FOnTurnEnd mOnTurnEndDelegate;
};
