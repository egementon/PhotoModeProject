// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PM_MenuWidget.generated.h"

class UPM_SettingParent;
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

	void SetPhotoCameraForSettingWidgets(APhotoCamera* Camera);

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> Rotation;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> UpDown;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> NorthSouth;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> WestEast;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> HidePlayer;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> FOV;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> CameraRoll;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> Filters;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> FilterIntensity;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> ShowGrid;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> SelectedLight;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> Enabled;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> AttachToCamera;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> Movement;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> LightIntensity;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> Hue;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> Saturation;

};
