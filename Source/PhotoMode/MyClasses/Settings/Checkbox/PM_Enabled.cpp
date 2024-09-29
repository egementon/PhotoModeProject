// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_Enabled.h"

#include "Components/PointLightComponent.h"
#include "PhotoMode/MyClasses/PM_Light.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_Enabled::OnCheckStateChanged(bool bIsChecked)
{
	if (!PhotoCamera2->SelectedLight) return;

	PhotoCamera2->SelectedLight->PointLight->SetVisibility(bIsChecked);
	PhotoCamera2->SelectedLight->bEnabled = bIsChecked;
}
