// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhotoMode/MyClasses/Settings/PM_DropdownParent.h"
#include "PM_SelectedLight.generated.h"

class APM_Light;
/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPM_SelectedLight : public UPM_DropdownParent
{
	GENERATED_BODY()

protected:
	
	virtual void OnDropdownSelectionChanged(FString NewSelectedOption, int32 NewSelectedIndex) override;

	void SelectNone();

	void SelectLight(int32 Index);

	void ResetLightWidgets();

	void UpdateLightWidgets(APM_Light* SelectedLight);

	void ShowSelectedLightBillboard(bool NewVisibility);
};
