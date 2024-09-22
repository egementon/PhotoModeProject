// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Settings/Slider/PM_FilterIntensity.h"
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APhotoCamera* PhotoCamera;

	UFUNCTION()
	void SetPhotoCamera(APhotoCamera* Camera);

	void SetPhotoCameraForSettingWidgets(APhotoCamera* Camera);

	UPM_SettingParent* GetRotation() const;
	UPM_SettingParent* GetUpDown() const;
	UPM_SettingParent* GetNorthSouth() const;
	UPM_SettingParent* GetWestEast() const;
	UPM_SettingParent* GetHidePlayer() const;
	UPM_SettingParent* GetFOV() const;
	UPM_SettingParent* GetCameraRoll() const;
	UPM_SettingParent* GetFilters() const;
	UPM_FilterIntensity* GetFilterIntensity() const;
	UPM_SettingParent* GetShowGrid() const;
	UPM_SettingParent* GetSelectedLight() const;
	UPM_SettingParent* GetEnabled() const;
	UPM_SettingParent* GetAttachToCamera() const;
	UPM_SettingParent* GetMovement() const;
	UPM_SettingParent* GetLightIntensity() const;
	UPM_SettingParent* GetHue() const;
	UPM_SettingParent* GetSaturation() const;


protected:
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
