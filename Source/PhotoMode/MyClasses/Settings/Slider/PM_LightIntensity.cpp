// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_LightIntensity.h"

#include "Components/PointLightComponent.h"
#include "PhotoMode/MyClasses/PM_Light.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_LightIntensity::OnSliderValueChanged(float NewValue)
{
	if (!PhotoCamera2->SelectedLight) return;

	PhotoCamera2->SelectedLight->PointLight->SetIntensity(NewValue);
}
