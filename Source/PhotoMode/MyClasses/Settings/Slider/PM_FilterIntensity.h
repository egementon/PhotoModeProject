// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhotoMode/MyClasses/Settings/PM_SliderParent.h"
#include "PM_FilterIntensity.generated.h"

/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPM_FilterIntensity : public UPM_SliderParent
{
	GENERATED_BODY()
	
public:
	virtual void ResetSlider() override;
	
protected:
	virtual void OnSliderValueChanged(float NewValue) override;

	void SetPostProcessBlendWeights(float NewValue);
	
};
