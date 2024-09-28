// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_SliderParent.h"

#include "Components/Slider.h"

void UPM_SliderParent::NativePreConstruct()
{
	Super::NativePreConstruct();
	
	Slider->SetValue(DefaultValue);
	Slider->SetMinValue(MinValue);
	Slider->SetMaxValue(MaxValue);
	
}

void UPM_SliderParent::NativeConstruct()
{
	Super::NativeConstruct();
	
	Slider->OnValueChanged.AddDynamic(this, &UPM_SliderParent::OnSliderValueChanged);
}

void UPM_SliderParent::OnSliderValueChanged(float NewValue)
{
	// Logic will be implemented in subclasses
}

void UPM_SliderParent::SetSliderValue(float NewValue)
{
	Slider->SetValue(NewValue);
}

void UPM_SliderParent::ResetSlider()
{
	Slider->SetValue(DefaultValue);
}

float UPM_SliderParent::GetSliderValue()
{
	return Slider->GetValue();
}
