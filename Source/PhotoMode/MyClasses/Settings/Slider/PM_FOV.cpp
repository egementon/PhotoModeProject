// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_FOV.h"

#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_FOV::OnSliderValueChanged(float NewValue)
{
	if (PhotoCamera2)
	{
		PhotoCamera2->GetCamera()->SetFieldOfView(NewValue);
	}
}
