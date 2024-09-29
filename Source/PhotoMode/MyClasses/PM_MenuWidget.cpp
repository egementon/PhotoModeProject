// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_MenuWidget.h"
#include "Settings/PM_SettingParent.h"

void UPM_MenuWidget::SetPhotoCamera(APhotoCamera* Camera)
{
	PhotoCamera = Camera;
	SetPhotoCameraForSettingWidgets(Camera);
}

void UPM_MenuWidget::SetPhotoCameraForSettingWidgets(APhotoCamera* Camera)
{
	// Array to hold all UPM_SettingParent variables
	TArray<UPM_SettingParent*> SettingParents;

	// Iterate over all UPROPERTY variables of the current class
	for (TFieldIterator<FProperty> PropIt(GetClass()); PropIt; ++PropIt)
	{
		FProperty* Property = *PropIt;

		// Check if the property is a subclass of UPM_SettingParent
		FObjectProperty* ObjectProp = CastField<FObjectProperty>(Property);
		if (ObjectProp && ObjectProp->PropertyClass->IsChildOf(UPM_SettingParent::StaticClass()))
		{
			// Get the UObject* and cast it to UPM_SettingParent* or its subclass
			UObject* Obj = ObjectProp->GetObjectPropertyValue_InContainer(this);
			UPM_SettingParent* SettingParent = Cast<UPM_SettingParent>(Obj); 

			if (SettingParent)
			{
				// Add the setting parent or subclass to the array
				SettingParents.Add(SettingParent);
			}
		}
	}

	// for-each loop over SettingParents to set PhotoCamera variables
	for (UPM_SettingParent* SettingParent : SettingParents)
	{
		if (SettingParent)
		{
			SettingParent->SetPhotoCamera(Camera);
			SettingParent->SetMenuWidget(this);
		}
	}
}


UPM_SettingParent* UPM_MenuWidget::GetRotation() const { return Rotation; }
UPM_SettingParent* UPM_MenuWidget::GetUpDown() const { return UpDown; }
UPM_SettingParent* UPM_MenuWidget::GetNorthSouth() const { return NorthSouth; }
UPM_SettingParent* UPM_MenuWidget::GetWestEast() const { return WestEast; }
UPM_SettingParent* UPM_MenuWidget::GetHidePlayer() const { return HidePlayer; }
UPM_SettingParent* UPM_MenuWidget::GetFOV() const { return FOV; }
UPM_SettingParent* UPM_MenuWidget::GetCameraRoll() const { return CameraRoll; }
UPM_SettingParent* UPM_MenuWidget::GetFilters() const { return Filters; }
UPM_FilterIntensity* UPM_MenuWidget::GetFilterIntensity() const { return FilterIntensity; }
UPM_SettingParent* UPM_MenuWidget::GetShowGrid() const { return ShowGrid; }
UPM_SettingParent* UPM_MenuWidget::GetSelectedLight() const { return SelectedLight; }
UPM_Enabled* UPM_MenuWidget::GetEnabled() const { return Enabled; }
UPM_AttachToCamera* UPM_MenuWidget::GetAttachToCamera() const { return AttachToCamera; }
UPM_Movement* UPM_MenuWidget::GetMovement() const { return Movement; }
UPM_LightIntensity* UPM_MenuWidget::GetLightIntensity() const { return LightIntensity; }
UPM_Hue* UPM_MenuWidget::GetHue() const { return Hue; }
UPM_Saturation* UPM_MenuWidget::GetSaturation() const { return Saturation; }
