// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "PM_MenuWidget.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Blueprint/UserWidget.h"
#include "PM_PhotoCamera.generated.h"

class APM_Light;

UCLASS()
class PHOTOMODE_API APhotoCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APhotoCamera();

	UCameraComponent* GetCamera();
	USceneCaptureComponent2D* GetSceneCapture();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called for capture input */
	void Capture();

	/** Called for HideUI input */
	void HideUI();

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;
	
	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;
	
	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	/** Capture Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* CaptureAction;

	/** Capture Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* HideUIAction;

public:
	// Lights
	UPROPERTY()
	APM_Light* SelectedLight;

	UPROPERTY()
	APM_Light* Light1;

	UPROPERTY()
	APM_Light* Light2;

	UPROPERTY()
	APM_Light* Light3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* LightAttachLocation;

	bool bUseLightMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LightMoveSpeed;

	UPROPERTY()
	APawn* PlayerPawn;

	UPROPERTY()
	ACharacter* PlayerCharacter;

	FTransform MeshInitialRelativeTransform;

	FVector GetLightAttachLocation() const;
	
protected:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Camera component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* Camera;

	// Floating Pawn Movement component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	UFloatingPawnMovement* FloatingPawnMovement;

	// Scene Capture component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USceneCaptureComponent2D* SceneCaptureComponent;

	// Limit movement
	void LimitMaxDistance();
	
	// Flash Effect Widget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TSubclassOf<UUserWidget> FlashWidgetClass;

	// Photo Mode Menu Widget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TSubclassOf<UPM_MenuWidget> PhotoModeMenuWidgetClass;

	bool bIsUIHidden;

	UPROPERTY()
	UPM_MenuWidget* PhotoModeMenuWidgetInstance;

	// Render Target Gamma
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjustable")
	float PhotoGamma;

	// Camera Movement Distance Limit
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjustable")
	float MaxDistance = 1500.f;

	void Destroyed() override;
	
	void HideSelectedLightBillboard(bool NewVisibility);

	void DestroyAllLights();
	
};
