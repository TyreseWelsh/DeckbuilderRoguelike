// Copyright Epic Games, Inc. All Rights Reserved.

#include "MageTowerGameMode.h"
#include "MageTowerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMageTowerGameMode::AMageTowerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/MageGame/Blueprints/BP_ActionPlayer"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
