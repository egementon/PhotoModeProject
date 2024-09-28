// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhotoMode/MyClasses/Settings/PM_CheckboxParent.h"
#include "PM_Enabled.generated.h"

/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPM_Enabled : public UPM_CheckboxParent
{
	GENERATED_BODY()

protected:
	virtual void OnCheckStateChanged(bool bIsChecked) override;
};
