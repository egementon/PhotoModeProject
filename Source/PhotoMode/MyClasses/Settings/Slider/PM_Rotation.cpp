// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_Rotation.h"

#include "GameFramework/Character.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_Rotation::OnSliderValueChanged(const float NewValue)
{
	Super::OnSliderValueChanged(NewValue);

	if (PhotoCamera2)
	{
		const float InitialYawRotation = PhotoCamera2->MeshInitialRelativeTransform.GetRotation().Rotator().Yaw;
		const float NewYawRotation =  InitialYawRotation + NewValue;
		const FRotator NewRotation = FRotator(0.f, NewYawRotation, 0.f);
		PhotoCamera2->PlayerCharacter->GetMesh()->SetRelativeRotation(NewRotation);
	}
}
