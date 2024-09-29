// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhotoMode/MyClasses/Settings/PM_SettingParent.h"
#include "PM_SliderParent.generated.h"

class USlider;
/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPM_SliderParent : public UPM_SettingParent
{
	GENERATED_BODY()

public:
	
	void SetSliderValue(float NewValue);
	virtual void ResetSlider();
	float GetSliderValue();
	
protected:
	
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	UFUNCTION()
	virtual void OnSliderValueChanged(float NewValue);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DefaultValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxValue;

	// Widget Components
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<USlider> Slider;
};
