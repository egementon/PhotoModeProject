// Copyright Epic Games, Inc. All Rights Reserved.

#include "PhotoModeGameMode.h"
#include "PhotoModeCharacter.h"
#include "UObject/ConstructorHelpers.h"

APhotoModeGameMode::APhotoModeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
