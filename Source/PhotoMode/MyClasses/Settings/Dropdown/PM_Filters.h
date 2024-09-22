// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "PhotoMode/MyClasses/Settings/PM_DropdownParent.h"
#include "PM_Filters.generated.h"

/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPM_Filters : public UPM_DropdownParent
{
	GENERATED_BODY()

protected:

	virtual void OnDropdownSelectionChanged(FString NewSelectedOption, int32 NewSelectedIndex) override;

	template<typename T>
	void SetPostProcessSettings(UMaterialInstanceDynamic* PostProcessMaterial, T* TargetComponent)
	{
		if (TargetComponent)
		{
			FPostProcessSettings NewPostProcessSettings;
			NewPostProcessSettings.AddBlendable(PostProcessMaterial, 1.0f);

			TargetComponent->PostProcessSettings = NewPostProcessSettings;
		}
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UMaterialInterface*> FilterMaterials;
};
