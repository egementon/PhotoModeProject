// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"



void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	APawn* PlayerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent)
	{
		InputComponent->BindAction("PhotoModeAction", IE_Pressed, this, &AMyPlayerController::TogglePhotoMode);
	}
}


void AMyPlayerController::TogglePhotoMode()
{
	bIsPhotoModeActive = !bIsPhotoModeActive;

	if (bIsPhotoModeActive)
	{
		// Logic to enable photo mode
		UE_LOG(LogTemp, Warning, TEXT("Photo Mode Enabled"));
		// Add your custom code to enable photo mode, such as pausing the game, changing the camera, etc.
	}
	else
	{
		// Logic to disable photo mode
		UE_LOG(LogTemp, Warning, TEXT("Photo Mode Disabled"));
		// Add your custom code to disable photo mode, such as resuming the game, reverting camera changes, etc.
	}
}