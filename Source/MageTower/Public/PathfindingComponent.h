// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PathfindingComponent.generated.h"

struct FInputActionValue;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAGETOWER_API UPathfindingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPathfindingComponent();

	virtual void StartMove(const FInputActionValue& _Value);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	
public:	
	// Called every frame
	virtual void TickComponent(float _DeltaTime, ELevelTick _TickType, FActorComponentTickFunction* _ThisTickFunction) override;

	void EnableMovement() { mbCanMove = true; }
	void DisableMovement() { mbCanMove = false; }
	
private:
	UFUNCTION()
	void Move(FVector _StartLocation, FVector _NewLocation);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float mMoveDistance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move Animation", meta = (AllowPrivateAccess = "true"))
	float mMoveRate = 0.02f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move Animation", meta = (AllowPrivateAccess = "true"))
	float mMoveIncrement = 0.1f;
	float mMoveAlpha;
	bool mbCanMove = true;
	FTimerHandle mMoveTimer;
	FTimerDelegate mMoveDelegate;
};
