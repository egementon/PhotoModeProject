// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PM_MenuWidget.generated.h"

class APhotoCamera;
/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPM_MenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	APhotoCamera* PhotoCamera;

	UFUNCTION()
	void SetPhotoCamera(APhotoCamera* Camera);	
};
