// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_Filters.h"

#include "Components/SceneCaptureComponent2D.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_Filters::OnDropdownSelectionChanged(FString NewSelectedOption, int32 NewSelectedIndex)
{
	if (PhotoCamera2)
	{
		UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(FilterMaterials[NewSelectedIndex], this);
		DynamicMaterial->SetScalarParameterValue(FName("BlendWeight"), 1.0f);
		
		SetPostProcessSettings(DynamicMaterial, PhotoCamera2->SceneCaptureComponent);
		SetPostProcessSettings(DynamicMaterial, PhotoCamera2->Camera);

		//TODO: FilterIntensityWidget->ResetSlider()
	}
}
