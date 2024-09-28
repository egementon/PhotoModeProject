// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_Filters.h"

#include "Components/SceneCaptureComponent2D.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_Filters::OnDropdownSelectionChanged(FString NewSelectedOption, int32 NewSelectedIndex)
{
	if (!PhotoCamera2) return;
	
	UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(FilterMaterials[NewSelectedIndex], this);
	DynamicMaterial->SetScalarParameterValue(FName("BlendWeight"), 1.0f);
	
	SetPostProcessSettings<USceneCaptureComponent2D>(DynamicMaterial, PhotoCamera2->GetSceneCapture());
	SetPostProcessSettings<UCameraComponent>(DynamicMaterial, PhotoCamera2->GetCamera());

	MenuWidget->GetFilterIntensity()->ResetSlider();
}
