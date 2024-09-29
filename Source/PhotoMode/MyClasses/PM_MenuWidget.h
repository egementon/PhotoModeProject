// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Settings/Slider/PM_FilterIntensity.h"
#include "PM_MenuWidget.generated.h"

class UPM_Saturation;
class UPM_Hue;
class UPM_LightIntensity;
class UPM_Enabled;
class UPM_AttachToCamera;
class UPM_Movement;
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
	UPM_Enabled* GetEnabled() const;
	UPM_AttachToCamera* GetAttachToCamera() const;
	UPM_Movement* GetMovement() const;
	UPM_LightIntensity* GetLightIntensity() const;
	UPM_Hue* GetHue() const;
	UPM_Saturation* GetSaturation() const;


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
	TObjectPtr<UPM_FilterIntensity> FilterIntensity;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> ShowGrid;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_SettingParent> SelectedLight;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_Enabled> Enabled;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_AttachToCamera> AttachToCamera;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_Movement> Movement;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_LightIntensity> LightIntensity;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_Hue> Hue;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UPM_Saturation> Saturation;

};
