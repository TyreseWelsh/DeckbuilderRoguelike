// Copyright Epic Games, Inc. All Rights Reserved.

#include "MageTowerGameMode.h"

#include "UObject/ConstructorHelpers.h"
#include "FieldGenerator.h"
#include "FieldManager.h"
#include "Kismet/GameplayStatics.h"
#include "IsPlayer.h"

AMageTowerGameMode::AMageTowerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/MageGame/Blueprints/BP_ActionPlayer"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	mpFieldGenerator = CreateDefaultSubobject<UFieldGenerator>(TEXT("FieldGeneratorComponent"));
	mpFieldManager = CreateDefaultSubobject<UFieldManager>(TEXT("FieldManagerComponent"));
}

void AMageTowerGameMode::BeginPlay()
{
	Super::BeginPlay();

	if(APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		mpPlayerPawn = playerController->GetPawn();
		if(mpPlayerPawn)
		{
			mpFieldManager->Init(mpFieldGenerator->GenerateField());

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Default pawn: %s"), *mpPlayerPawn->GetName()));

			if(IIsPlayer* playerInterface = Cast<IIsPlayer>(mpPlayerPawn))
			{
				playerInterface->GetTurnEndDelegate()->AddUObject(mpFieldManager, &UFieldManager::NewTurn);
				if(playerInterface->GetTurnEndDelegate()->IsBound())
				{
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Field manager NewTurn bound to player end turn")));
				}
			}
		}
	}
}
