// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_Hue.h"

#include "PM_Saturation.h"
#include "Components/PointLightComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "PhotoMode/MyClasses/PM_Light.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_Hue::OnSliderValueChanged(float NewValue)
{
	if (!PhotoCamera2->SelectedLight) return;

	const float SaturationValue = MenuWidget->GetSaturation()->GetSliderValue();
	const FLinearColor NewColor = UKismetMathLibrary::HSVToRGB(NewValue, SaturationValue, 1.f, 1.f);
	PhotoCamera2->SelectedLight->PointLight->SetLightColor(NewColor);
}
