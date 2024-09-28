// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_Movement.h"

#include "PhotoMode/MyClasses/PM_Light.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_Movement::OnDropdownSelectionChanged(FString NewSelectedOption, int32 NewSelectedIndex)
{
	if (!PhotoCamera2) return;
	
	const bool bNew = NewSelectedIndex == 0;
	
	PhotoCamera2->bUseLightMovement = bNew;
	PhotoCamera2->SelectedLight->bUseLightMovement = bNew;
	
}
