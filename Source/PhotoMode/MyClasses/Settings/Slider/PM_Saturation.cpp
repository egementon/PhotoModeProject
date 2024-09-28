// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_Saturation.h"

#include "PM_Hue.h"
#include "Components/PointLightComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "PhotoMode/MyClasses/PM_Light.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_Saturation::OnSliderValueChanged(float NewValue)
{
	if (!PhotoCamera2->SelectedLight) return;

	const float HueValue = MenuWidget->GetHue()->GetSliderValue();
	const FLinearColor NewColor = UKismetMathLibrary::HSVToRGB(HueValue, NewValue, 1.f, 1.f);
	PhotoCamera2->SelectedLight->PointLight->SetLightColor(NewColor);
}
