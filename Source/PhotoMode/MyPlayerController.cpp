// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"

AMyPlayerController::AMyPlayerController()
{
	bIsPhotoModeActive = false;
	// needed to move pawn and camera
	bShouldPerformFullTickWhenPaused = true;
}


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

	PlayerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	
	// needed to fix TXAA/MotionBlur glitches
	GetWorld()->bIsCameraMoveableWhenPaused = true;
}


void AMyPlayerController::TogglePhotoMode()
{
	bIsPhotoModeActive = !bIsPhotoModeActive;

	if (bIsPhotoModeActive)
	{
		// Logic to enable photo mode
		const APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0);
		const FVector Location = CameraManager->GetTransform().GetLocation();
		const FRotator Rotation = CameraManager->GetTransform().GetRotation().Rotator();
		FActorSpawnParameters SpawnInfo;
		PhotoModeCamera = Cast<APawn>(GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation));
		UnPossess();
		Possess(PhotoModeCamera);
		UGameplayStatics::SetGamePaused(this, true);
		SetInputMode(FInputModeGameAndUI());
		SetShowMouseCursor(true);
	}
	else
	{
		// Logic to disable photo mode
		UnPossess();
		Possess(PlayerCharacter);
		PhotoModeCamera->Destroy();
		UGameplayStatics::SetGamePaused(this, false);
		SetInputMode(FInputModeGameOnly());
		SetShowMouseCursor(false);
	}
}