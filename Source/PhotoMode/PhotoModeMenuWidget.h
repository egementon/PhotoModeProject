// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PhotoModeMenuWidget.generated.h"

class APhotoCamera;
/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPhotoModeMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	APhotoCamera* PhotoCamera;

	UFUNCTION()
	void SetPhotoCamera(APhotoCamera* Camera);	
};
