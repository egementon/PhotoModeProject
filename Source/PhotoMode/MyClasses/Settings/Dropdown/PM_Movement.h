// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhotoMode/MyClasses/Settings/PM_DropdownParent.h"
#include "PM_Movement.generated.h"

/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPM_Movement : public UPM_DropdownParent
{
	GENERATED_BODY()

protected:
	virtual void OnDropdownSelectionChanged(FString NewSelectedOption, int32 NewSelectedIndex) override;
};
