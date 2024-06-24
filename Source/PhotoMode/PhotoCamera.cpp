// Fill out your copyright notice in the Description page of Project Settings.


#include "PhotoCamera.h"

#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Kismet/KismetSystemLibrary.h"



// Sets default values
APhotoCamera::APhotoCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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
	UseLightMovement = false;
	LightMoveSpeed = 1.f;
	
	// Important for moving camera when game paused!
	SetTickableWhenPaused(true);
	Camera->SetTickableWhenPaused(true);
	FloatingPawnMovement->SetTickableWhenPaused(true);

	PhotoGamma = 2.f;
	bIsUIHidden = false;
}

// Called when the game starts or when spawned
void APhotoCamera::BeginPlay()
{
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	// Create Widget of Photo Mode Menu
	PhotoModeMenuWidgetInstance = CreateWidget<UPhotoModeMenuWidget>(GetWorld(), PhotoModeMenuWidgetClass);
	if (PhotoModeMenuWidgetInstance)
	{
		PhotoModeMenuWidgetInstance->SetPhotoCamera(this);
		PhotoModeMenuWidgetInstance->AddToViewport();
	}
}

// Called every frame
void APhotoCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	LimitMaxDistance();
}

// Called to bind functionality to input
void APhotoCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APhotoCamera::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APhotoCamera::Look);

		//Capturing
		EnhancedInputComponent->BindAction(CaptureAction, ETriggerEvent::Started, this, &APhotoCamera::Capture);

		//Hiding UI
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

		if (!UseLightMovement)
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
		HideLightBillboard(false);
		SceneCaptureComponent->CaptureScene();
		if (!bIsUIHidden) HideLightBillboard(true);

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
		HideLightBillboard(false);
	}
	else
	{
		PhotoModeMenuWidgetInstance->SetVisibility(ESlateVisibility::Visible);
		HideLightBillboard(true);
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

void APhotoCamera::DestroyAllLights()
{
	if (IsValid(Light1)) Light1->Destroy();
	if (IsValid(Light2)) Light2->Destroy();
	if (IsValid(Light3)) Light3->Destroy();
	SelectedLight = nullptr;
}
