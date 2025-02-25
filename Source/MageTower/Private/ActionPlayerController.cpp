// Fill out your copyright notice in the Description page of Project Settings.


//#include "ActionPlayerController.h"
#include "MageTower/Public/ActionPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "MageTower/Public/PathfindingComponent.h"

// Print to screen ref
//GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Red, FString::Printf(TEXT("NOT A TILE")));

void AActionPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if(UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		subsystem->AddMappingContext(mpPlayerMappingContext, 0);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "ERROR: Cant get Enhanced Input Subsystem");
	}

	mpActionPlayer = GetPawn();
}

void AActionPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if(UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		enhancedInputComponent->BindAction(mpMoveAction, ETriggerEvent::Started, this, &AActionPlayerController::MovePlayer);
		
		enhancedInputComponent->BindAction(mpCastAction, ETriggerEvent::Started, this, &AActionPlayerController::CastSpell);
		enhancedInputComponent->BindAction(mpPickSpell1Action, ETriggerEvent::Started, this, &AActionPlayerController::PickSpell, 1);
		enhancedInputComponent->BindAction(mpPickSpell2Action, ETriggerEvent::Started, this, &AActionPlayerController::PickSpell, 2);
		enhancedInputComponent->BindAction(mpPickSpell3Action, ETriggerEvent::Started, this, &AActionPlayerController::PickSpell, 3);
		enhancedInputComponent->BindAction(mpPickSpell4Action, ETriggerEvent::Started, this, &AActionPlayerController::PickSpell, 4);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("%s: Cast to EIC failed!"), *GetName()));
	}
}

void AActionPlayerController::MovePlayer(const FInputActionValue& _Value)
{
	// Move once in cardinal direction on WASD press
	if(IsValid(mpActionPlayer))
	{
		mpActionPlayer->GetComponentByClass<UPathfindingComponent>()->StartMove(_Value);
	}
}

// TODO: Work on SpellCasting component to cast spells
void AActionPlayerController::CastSpell(const FInputActionValue& _Value)
{
	GEngine->AddOnScreenDebugMessage(0, 1.f, FColor::Cyan, FString::Printf(TEXT("%s: Cast spell!"), *GetName()));
}

void AActionPlayerController::PickSpell(const FInputActionValue& _Value, int _SpellNum)
{
	GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Cyan, FString::Printf(TEXT("%s: Picked spell %i!"), *GetName(), _SpellNum));
}
