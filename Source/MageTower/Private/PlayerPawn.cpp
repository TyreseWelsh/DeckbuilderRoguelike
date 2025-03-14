// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

#include "ManaWidget.h"
#include "Camera/CameraComponent.h"
#include "PlayerPathfindingComponent.h"
#include "SpellCastingComponent.h"
#include "PlayerHUDWidget.h"
#include "Kismet/GameplayStatics.h"

APlayerPawn::APlayerPawn()
{
	mpOrigin = CreateDefaultSubobject<USceneComponent>(TEXT("Origin"));
	SetRootComponent(mpOrigin);

	mpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mpMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	mpMesh->SetupAttachment(mpOrigin);

	mpCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	mpCamera->SetupAttachment(mpOrigin);

	mpPlayerPathfindingComp = CreateDefaultSubobject<UPlayerPathfindingComponent>(TEXT("PlayerPathfindingComponent"));
	mpSpellCastingComp = CreateDefaultSubobject<USpellCastingComponent>(TEXT("SpellcastingComponent"));
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	// Player HUD elements such as health and mana points will always be visible.
	// Only upon combat start will we make the hand cards visible and update mana
	if(mpSpellCastingComp)
	{
		mpPlayerHUD = CreateWidget<UPlayerHUDWidget>(GetWorld(), playerHUDClass);
		if(mpPlayerHUD)
		{
			mpSpellCastingComp->InitialiseDeck(mpPlayerHUD);
			
			mpPlayerHUD->manaBar->InitMana();
			mpPlayerHUD->AddToViewport();
		}
	}
}

void APlayerPawn::StartCombat()
{
	if(mpPlayerHUD)
	{
		mpSpellCastingComp->ActivateCombatDeck();
		mpPlayerHUD->EnableHand();
	}
}

void APlayerPawn::EndCombat()
{
	if(mpPlayerHUD)
	{
		mpSpellCastingComp->DeactivateCombatDeck();
		mpPlayerHUD->DisableHand();
	}
}

void APlayerPawn::StartTurn()
{
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}
