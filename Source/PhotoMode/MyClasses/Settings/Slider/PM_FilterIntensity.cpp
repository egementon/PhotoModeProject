// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_FilterIntensity.h"

#include "Components/SceneCaptureComponent2D.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_FilterIntensity::OnSliderValueChanged(float NewValue)
{
	SetPostProcessBlendWeights(NewValue);
}

void UPM_FilterIntensity::ResetSlider()
{
	Super::ResetSlider();
	
	SetPostProcessBlendWeights(DefaultValue);
}

void UPM_FilterIntensity::SetPostProcessBlendWeights(float NewValue)
{
	if (!PhotoCamera2) return;
	
	PhotoCamera2->GetCamera()->PostProcessBlendWeight = NewValue;
	PhotoCamera2->GetSceneCapture()->PostProcessBlendWeight = NewValue;
	
}
