// Copyright Epic Games, Inc. All Rights Reserved.

#include "MageTowerGameMode.h"

#include "UObject/ConstructorHelpers.h"
#include "FieldGenerator.h"
#include "FieldManager.h"
#include "Kismet/GameplayStatics.h"
#include "IsActionObject.h"

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
			
			if(IIsActionObject* playerInterface = Cast<IIsActionObject>(mpPlayerPawn))
			{
				playerInterface->GetTurnEndDelegate()->AddUObject(mpFieldManager, &UFieldManager::NewTurn);
			}
		}
	}
}
