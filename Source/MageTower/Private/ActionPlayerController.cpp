// Fill out your copyright notice in the Description page of Project Settings.


//#include "ActionPlayerController.h"
#include "MageTower/Public/ActionPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "MageTower/Public/PathfindingComponent.h"
#include "SpellCastingComponent.h"

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
	mpPlayerSpellCastingComp = mpActionPlayer->GetComponentByClass<USpellCastingComponent>();
}

void AActionPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if(UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		enhancedInputComponent->BindAction(mpMoveAction, ETriggerEvent::Started, this, &AActionPlayerController::MovePlayer);
		
		enhancedInputComponent->BindAction(mpCastAction, ETriggerEvent::Started, this, &AActionPlayerController::CastSpell);
		enhancedInputComponent->BindAction(mpCancelCastAction, ETriggerEvent::Started, this, &AActionPlayerController::CancelCast);

		enhancedInputComponent->BindAction(mpPickSpell1Action, ETriggerEvent::Started, this, &AActionPlayerController::PickSpell, 0);
		enhancedInputComponent->BindAction(mpPickSpell2Action, ETriggerEvent::Started, this, &AActionPlayerController::PickSpell, 1);
		enhancedInputComponent->BindAction(mpPickSpell3Action, ETriggerEvent::Started, this, &AActionPlayerController::PickSpell, 2);
		enhancedInputComponent->BindAction(mpPickSpell4Action, ETriggerEvent::Started, this, &AActionPlayerController::PickSpell, 3);
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
	if(mpPlayerSpellCastingComp)
	{
		mpPlayerSpellCastingComp->CastSpell();
	}
}

void AActionPlayerController::CancelCast(const FInputActionValue& _Value)
{
	if(mpPlayerSpellCastingComp)
	{
		mpPlayerSpellCastingComp->CancelSpellCast();
	}
}

void AActionPlayerController::PickSpell(const FInputActionValue& _Value, int _HandIndex)
{
	if(mpPlayerSpellCastingComp)
	{
		mpPlayerSpellCastingComp->SelectSpell(_HandIndex);
	}
}
