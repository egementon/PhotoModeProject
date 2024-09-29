// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "PM_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PHOTOMODE_API APM_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	APM_PlayerController();
	
protected:
	virtual void BeginPlay() override;
	
	/** Input and Actions */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* PhotoModeAction;
	
	
private:
	void TogglePhotoMode();
	
	bool bIsPhotoModeActive;
	
	UPROPERTY(EditAnywhere, Category = Camera)
	TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY()
	APawn* PhotoCameraPawn;

	UPROPERTY()
	APawn* PlayerPawn;
	
	UPROPERTY()
	ACharacter* PlayerCharacter;
	
	FTransform PlayerMeshTransform;
};
