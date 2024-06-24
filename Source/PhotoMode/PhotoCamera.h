// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "PhotoModeMenuWidget.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Blueprint/UserWidget.h"
#include "PhotoCamera.generated.h"

UCLASS()
class PHOTOMODE_API APhotoCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APhotoCamera();

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Limit movement
	void LimitMaxDistance();

	// Get LightAttachLocation
	UFUNCTION(BlueprintCallable)
	FVector GetLightAttachLocation() const;
	
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
	
	
	// Camera component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* Camera;

	// Floating pawn movement component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	UFloatingPawnMovement* FloatingPawnMovement;

	// Scene Capture component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USceneCaptureComponent2D* SceneCaptureComponent;
	
	
	// Flash Effect Widget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TSubclassOf<UUserWidget> FlashWidgetClass;

	// Photo Mode Menu Widget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TSubclassOf<UPhotoModeMenuWidget> PhotoModeMenuWidgetClass;

	UPROPERTY()
	bool bIsUIHidden;

	UPROPERTY()
	UPhotoModeMenuWidget* PhotoModeMenuWidgetInstance;

	// Render Target Gamma
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjustable")
	float PhotoGamma;

	// Camera Movement Distance Limit
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjustable")
	float MaxDistance = 1500.f;

	void Destroyed() override;

	UPROPERTY(BlueprintReadOnly)
	APawn* PlayerPawn;

	UPROPERTY(BlueprintReadOnly)
	ACharacter* PlayerCharacter;

	UPROPERTY(BlueprintReadOnly)
	FTransform MeshInitialRelativeTransform;

	// Lights
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* SelectedLight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* Light1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* Light2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* Light3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* LightAttachLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool UseLightMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LightMoveSpeed;

	UFUNCTION(BlueprintImplementableEvent, Category = "MyEvents")
	void HideLightBillboard(bool visibility);

	void DestroyAllLights();

	
};
