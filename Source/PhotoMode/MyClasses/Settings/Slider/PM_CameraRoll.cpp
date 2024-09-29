// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_CameraRoll.h"

#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_CameraRoll::OnSliderValueChanged(float NewValue)
{
	if (!PhotoCamera2) return;

	const FRotator NewRotation = FRotator(
		PhotoCamera2->GetActorRotation().Pitch,
		PhotoCamera2->GetActorRotation().Yaw,
		NewValue);
	
	PhotoCamera2->SetActorRotation(NewRotation);
}
