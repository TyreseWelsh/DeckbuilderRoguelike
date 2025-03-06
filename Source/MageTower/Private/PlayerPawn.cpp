// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

#include "ManaWidget.h"
#include "Camera/CameraComponent.h"
#include "PathfindingComponent.h"
#include "SpellCastingComponent.h"
#include "PlayerHUDWidget.h"
#include "ManaWidget.h"

APlayerPawn::APlayerPawn()
{
	mpOrigin = CreateDefaultSubobject<USceneComponent>(TEXT("Origin"));
	SetRootComponent(mpOrigin);

	mpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mpMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	mpMesh->SetupAttachment(mpOrigin);

	mpCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	mpCamera->SetupAttachment(mpOrigin);

	mpPathfindingComp = CreateDefaultSubobject<UPathfindingComponent>(TEXT("PathfindingComponent"));
	mpSpellCastingComp = CreateDefaultSubobject<USpellCastingComponent>(TEXT("SpellcastingComponent"));
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	// Player HUD elements such as health and mana points will always be visible.
	// Only upon combat start will we make the hand cards visible and update mana
	if(mpSpellCastingComp)
	{
		mpSpellCastingComp->InitialiseDeck();

		mpPlayerHUD = CreateWidget<UPlayerHUDWidget>(GetWorld(), playerHUDClass);
		if(mpPlayerHUD)
		{
			mpPlayerHUD->manaBar->InitMana();
			mpPlayerHUD->AddToViewport();
		}
	}
}

void APlayerPawn::StartCombat()
{
	if(mpPlayerHUD)
	{
		mpSpellCastingComp->InitaliseCombatDeck(mpPlayerHUD);
		mpPlayerHUD->EnableHand();
	}
}
