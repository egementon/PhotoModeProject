// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_Rotation.h"

#include "GameFramework/Character.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_Rotation::OnSliderValueChanged(const float NewValue)
{
	if (!PhotoCamera2) return;
	
	const FRotator InitialRotation = PhotoCamera2->MeshInitialRelativeTransform.GetRotation().Rotator();
	const float NewYawRotation = InitialRotation.Yaw + NewValue;
	const FRotator NewRotation = FRotator(InitialRotation.Pitch, NewYawRotation, InitialRotation.Roll);
	PhotoCamera2->PlayerCharacter->GetMesh()->SetRelativeRotation(NewRotation);
}
