// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Kismet/GameplayStatics.h"


void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//////////////////////////////////////////////////////////////////////////
	// Input
	// Ensure the Input Subsystem is set up for the player
	if (APlayerController* PC = Cast<APlayerController>(this))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			// Create and add the input mapping context
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(PhotoModeAction, ETriggerEvent::Started, this, &AMyPlayerController::TogglePhotoMode);
	}
	//////////////////////////////////////////////////////////////////////////

	APawn* PlayerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
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