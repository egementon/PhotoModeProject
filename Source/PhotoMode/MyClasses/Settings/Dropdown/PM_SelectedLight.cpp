// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_SelectedLight.h"

#include "PM_Movement.h"
#include "Components/BillboardComponent.h"
#include "Components/PointLightComponent.h"
#include "PhotoMode/MyClasses/PM_Light.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"
#include "PhotoMode/MyClasses/Settings/Checkbox/PM_AttachToCamera.h"
#include "PhotoMode/MyClasses/Settings/Checkbox/PM_Enabled.h"
#include "PhotoMode/MyClasses/Settings/Slider/PM_Hue.h"
#include "PhotoMode/MyClasses/Settings/Slider/PM_LightIntensity.h"
#include "PhotoMode/MyClasses/Settings/Slider/PM_Saturation.h"

void UPM_SelectedLight::OnDropdownSelectionChanged(FString NewSelectedOption, int32 NewSelectedIndex)
{
	if (!PhotoCamera2) return;

	SelectLight(NewSelectedIndex);
}

void UPM_SelectedLight::SelectNone()
{
	ShowSelectedLightBillboard(false);
	PhotoCamera2->SelectedLight = nullptr;
	ResetLightWidgets();
	
	// Switch to camera movement when None selected
	PhotoCamera2->bUseLightMovement = false;
	MenuWidget->GetMovement()->SetSelection(1);
}

void UPM_SelectedLight::SelectLight(int32 Index)
{
	if (Index == 0)
	{
		SelectNone();
		return;
	}

	ShowSelectedLightBillboard(false);

	APM_Light* NewSelectedLight = nullptr;
	switch (Index)
	{
	case 1:
		NewSelectedLight = PhotoCamera2->Light1;
		break;
	case 2:
		NewSelectedLight = PhotoCamera2->Light2;
		break;
	case 3:
		NewSelectedLight = PhotoCamera2->Light3;
		break;
	default: ;
	}

	if (NewSelectedLight)
	{
		PhotoCamera2->SelectedLight = NewSelectedLight;

		// Update widgets according to last made changes
		UpdateLightWidgets(NewSelectedLight);
	}
	else
	{
		FActorSpawnParameters SpawnParameters;
		auto SpawnedLight = GetWorld()->SpawnActor<APM_Light>(PhotoCamera2->GetLightAttachLocation(), FRotator::ZeroRotator);

		switch (Index)
		{
		case 1:
			PhotoCamera2->Light1 = SpawnedLight;
			break;
		case 2:
			PhotoCamera2->Light2 = SpawnedLight;
			break;
		case 3:
			PhotoCamera2->Light3 = SpawnedLight;
			break;
		default: ;
		}

		PhotoCamera2->SelectedLight = SpawnedLight;

		// Reset widgets for every newly spawned lights
		ResetLightWidgets();

		// Switch to light movement only when first time spawning
		PhotoCamera2->bUseLightMovement = true;
	}

	ShowSelectedLightBillboard(true);
}

void UPM_SelectedLight::ResetLightWidgets()
{
	MenuWidget->GetMovement()->ResetSelection();
	MenuWidget->GetAttachToCamera()->SetCheckState(false);
	MenuWidget->GetEnabled()->SetCheckState(true);

	MenuWidget->GetLightIntensity()->ResetSlider();
	MenuWidget->GetHue()->ResetSlider();
	MenuWidget->GetSaturation()->ResetSlider();
}

void UPM_SelectedLight::UpdateLightWidgets(APM_Light* SelectedLight)
{
	MenuWidget->GetEnabled()->SetCheckState(SelectedLight->bEnabled);
	MenuWidget->GetAttachToCamera()->SetCheckState(SelectedLight->bAttached);

	// "true" returns 0, "false" returns 1
	const int32 SelectionIndex = !SelectedLight->bUseLightMovement;
	MenuWidget->GetMovement()->SetSelection(SelectionIndex);


	MenuWidget->GetLightIntensity()->SetSliderValue(SelectedLight->PointLight->Intensity);
	MenuWidget->GetHue()->SetSliderValue(SelectedLight->HueValue);
	MenuWidget->GetSaturation()->SetSliderValue(SelectedLight->SaturationValue);
}

void UPM_SelectedLight::ShowSelectedLightBillboard(bool NewVisibility)
{
	if (PhotoCamera2->SelectedLight)
	{
		PhotoCamera2->SelectedLight->Billboard->SetVisibility(NewVisibility);
	}
}
