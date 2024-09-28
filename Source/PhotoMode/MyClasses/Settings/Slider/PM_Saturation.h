// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhotoMode/MyClasses/Settings/PM_SliderParent.h"
#include "PM_Saturation.generated.h"

/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPM_Saturation : public UPM_SliderParent
{
	GENERATED_BODY()

protected:
	virtual void OnSliderValueChanged(float NewValue) override;
};
