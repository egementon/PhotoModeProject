// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_NorthSouth.h"

#include "GameFramework/Character.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_NorthSouth::OnSliderValueChanged(float NewValue)
{
	if (PhotoCamera2)
	{
		const FVector InitialLocation = PhotoCamera2->MeshInitialRelativeTransform.GetLocation();
		const float NewXLocation = InitialLocation.X + NewValue;
		const FVector NewLocation = FVector(NewXLocation, InitialLocation.Y, InitialLocation.Z);
		PhotoCamera2->PlayerCharacter->GetMesh()->SetRelativeLocation(NewLocation);
	}
}
