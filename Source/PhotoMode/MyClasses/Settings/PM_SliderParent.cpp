// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_SliderParent.h"

#include "Components/Slider.h"
#include "Kismet/KismetSystemLibrary.h"

void UPM_SliderParent::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (Slider)
	{
		Slider->SetValue(DefaultValue);
		Slider->SetMinValue(MinValue);
		Slider->SetMaxValue(MaxValue);
	}
}

void UPM_SliderParent::NativeConstruct()
{
	Super::NativeConstruct();

	Slider->OnValueChanged.AddDynamic(this, &UPM_SliderParent::OnSliderValueChanged);
}

void UPM_SliderParent::OnSliderValueChanged(float NewValue)
{
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Value Changed: %f"), NewValue));
}

void UPM_SliderParent::ResetSlider()
{
	Slider->SetValue(DefaultValue);
}
