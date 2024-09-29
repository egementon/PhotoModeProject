// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_PhotoCamera.h"

#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PM_Light.h"
#include "Blueprint/UserWidget.h"
#include "Components/BillboardComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Kismet/KismetSystemLibrary.h"



// Sets default values
APhotoCamera::APhotoCamera()
{
	PrimaryActorTick.bCanEverTick = true;
	
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
	
	SceneCaptureComponent = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCaptureComponent"));
	SceneCaptureComponent->SetupAttachment(Camera);
	SceneCaptureComponent->bCaptureEveryFrame = false;
	SceneCaptureComponent->bCaptureOnMovement = false;
	SceneCaptureComponent->CaptureSource = SCS_FinalColorLDR;
	SceneCaptureComponent->bAlwaysPersistRenderingState = true;

	LightAttachLocation = CreateDefaultSubobject<USceneComponent>(TEXT("LightAttachLocation"));
	LightAttachLocation->SetupAttachment(Camera);
	LightAttachLocation->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));
	bUseLightMovement = false;
	LightMoveSpeed = 1.f;
	
	// Important for moving camera when game paused!
	SetTickableWhenPaused(true);
	Camera->SetTickableWhenPaused(true);
	FloatingPawnMovement->SetTickableWhenPaused(true);

	PhotoGamma = 2.f;
	bIsUIHidden = false;
}

UCameraComponent* APhotoCamera::GetCamera()
{
	return Camera;
}

USceneCaptureComponent2D* APhotoCamera::GetSceneCapture()
{
	return SceneCaptureComponent;
}

void APhotoCamera::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	// Create Widget of Photo Mode Menu
	PhotoModeMenuWidgetInstance = CreateWidget<UPM_MenuWidget>(GetWorld(), PhotoModeMenuWidgetClass);
	if (PhotoModeMenuWidgetInstance)
	{
		PhotoModeMenuWidgetInstance->SetPhotoCamera(this);
		PhotoModeMenuWidgetInstance->AddToViewport();
	}

	// Initialize LightArray with the lights
	LightArray.Add(Light1);
	LightArray.Add(Light2);
	LightArray.Add(Light3);
}

void APhotoCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	LimitMaxDistance();

	UKismetSystemLibrary::PrintString(this, FString::SanitizeFloat(LightArray.Num()));
}

void APhotoCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APhotoCamera::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APhotoCamera::Look);
		EnhancedInputComponent->BindAction(CaptureAction, ETriggerEvent::Started, this, &APhotoCamera::Capture);
		EnhancedInputComponent->BindAction(HideUIAction, ETriggerEvent::Started, this, &APhotoCamera::HideUI);
	}
}

void APhotoCamera::LimitMaxDistance()
{
	const FVector CameraLoc = GetActorLocation();
	const FVector PlayerLoc = PlayerPawn->GetActorLocation();
	const float Distance = FVector::Dist(CameraLoc, PlayerLoc);
	if (Distance > MaxDistance)
	{
		const FVector Direction = (CameraLoc - PlayerLoc).GetSafeNormal();
		const FVector NewLocation = PlayerLoc + Direction * MaxDistance;
		SetActorLocation(NewLocation);
	}
}

APM_Light*& APhotoCamera::GetLightByIndex(int32 LightIndex)
{
	return LightArray[LightIndex - 1];
}

FVector APhotoCamera::GetLightAttachLocation() const
{
	return LightAttachLocation->GetComponentLocation();
}

void APhotoCamera::Move(const FInputActionValue& Value)
{
	// input is a Vector
	const FVector MovementVector = Value.Get<FVector>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();

		// get forward vector
		FVector ForwardDirection = FRotationMatrix(Rotation).GetUnitAxis(EAxis::X);
		
		// get right vector 
		FVector RightDirection = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);

		// ensure movement is only on XY axis
		ForwardDirection.Z = 0.f;
		RightDirection.Z = 0.f;
		
		// create an up direction vector in world space
		const FVector UpVector = FVector::UpVector;

		if (!bUseLightMovement)
		{
			// add camera movement 
			AddMovementInput(ForwardDirection, MovementVector.Y);
			AddMovementInput(RightDirection, MovementVector.X);
			AddMovementInput(UpVector, MovementVector.Z);
		}
		else
		{
			if (SelectedLight)
			{
				SelectedLight->AddActorWorldOffset(ForwardDirection * MovementVector.Y * LightMoveSpeed, true);
				SelectedLight->AddActorWorldOffset(RightDirection * MovementVector.X * LightMoveSpeed, true);
				SelectedLight->AddActorWorldOffset(UpVector * MovementVector.Z * LightMoveSpeed, true);
			}
		}
	}
}

void APhotoCamera::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		float X = LookAxisVector.X;
		float Y = LookAxisVector.Y;

		//Roll angle
		FRotator ActorRotation = GetActorRotation().GetNormalized();
		float Theta = FMath::DegreesToRadians(ActorRotation.Roll);
		
		// Calculate cos and sin of the angle Theta
		float CosTheta = FMath::Cos(Theta);
		float SinTheta = FMath::Sin(Theta);
		
		// Compute the new coordinates
		float NewX = X * CosTheta - Y * SinTheta;
		float NewY = X * SinTheta + Y * CosTheta;
		
		// add yaw and pitch input to controller
		AddControllerYawInput(NewX);
		AddControllerPitchInput(NewY);
	}
}

void APhotoCamera::Capture()
{
	if (Controller != nullptr)
	{
		SceneCaptureComponent->FOVAngle = Camera->FieldOfView;
		
		UTextureRenderTarget2D* RenderTarget = UKismetRenderingLibrary::CreateRenderTarget2D(this,1920,1080, RTF_RGBA8);
		RenderTarget->TargetGamma = PhotoGamma;
		SceneCaptureComponent->TextureTarget = RenderTarget;
		HideSelectedLightBillboard(false);
		SceneCaptureComponent->CaptureScene();
		if (!bIsUIHidden) HideSelectedLightBillboard(true);

		// Play Flash Effect
		if (UUserWidget* FlashWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), FlashWidgetClass))
		{
			FlashWidgetInstance->AddToViewport();
		}

		// Export Image
		FString TimeString = FDateTime::Now().ToString();
		UKismetRenderingLibrary::ExportRenderTarget(this,
			SceneCaptureComponent->TextureTarget,
			UKismetSystemLibrary::GetProjectSavedDirectory(),
			TimeString += TEXT(".png")
			);
	}
}

void APhotoCamera::HideUI()
{
	bIsUIHidden = !bIsUIHidden;

	if (bIsUIHidden)
	{
		PhotoModeMenuWidgetInstance->SetVisibility(ESlateVisibility::Collapsed);
		HideSelectedLightBillboard(false);
	}
	else
	{
		PhotoModeMenuWidgetInstance->SetVisibility(ESlateVisibility::Visible);
		HideSelectedLightBillboard(true);
	}
}

void APhotoCamera::Destroyed()
{
	Super::Destroyed();
	if (PhotoModeMenuWidgetInstance)
	{
		PhotoModeMenuWidgetInstance->RemoveFromParent();
	}
	DestroyAllLights();
}

void APhotoCamera::HideSelectedLightBillboard(bool NewVisibility)
{
	if (SelectedLight)
	{
		SelectedLight->Billboard->SetVisibility(NewVisibility);
	}
}

void APhotoCamera::DestroyAllLights()
{
	for (APM_Light* Light : LightArray)
	{
		if (Light) Light->Destroy();
	}
	SelectedLight = nullptr;
}
