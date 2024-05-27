// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PHOTOMODE_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMyPlayerController();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	/** Input and Actions */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* PhotoModeAction;
	
	void TogglePhotoMode();
	
	bool bIsPhotoModeActive;

	UPROPERTY(EditAnywhere, Category = Camera)
	TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY()
	APawn* PhotoCameraPawn;

	UPROPERTY()
	APawn* PlayerCharacter;
};
