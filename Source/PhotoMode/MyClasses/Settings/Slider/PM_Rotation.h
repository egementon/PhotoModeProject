// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhotoMode/MyClasses/Settings/PM_SliderParent.h"
#include "PM_Rotation.generated.h"

/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPM_Rotation : public UPM_SliderParent
{
	GENERATED_BODY()

	virtual void OnSliderValueChanged(float NewValue) override;
};
