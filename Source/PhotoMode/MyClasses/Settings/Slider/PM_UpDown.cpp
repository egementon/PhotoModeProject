// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_UpDown.h"

#include "GameFramework/Character.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_UpDown::OnSliderValueChanged(float NewValue)
{
	if (!PhotoCamera2) return;
	
	const FVector CurrentRelativeLocation = PhotoCamera2->PlayerCharacter->GetMesh()->GetRelativeLocation();
	const float CurrentX = CurrentRelativeLocation.X;
	const float CurrentY = CurrentRelativeLocation.Y;
	
	const FVector InitialLocation = PhotoCamera2->MeshInitialRelativeTransform.GetLocation();
	const float NewZLocation = InitialLocation.Z + NewValue;
	const FVector NewLocation = FVector(CurrentX, CurrentY, NewZLocation);
	PhotoCamera2->PlayerCharacter->GetMesh()->SetRelativeLocation(NewLocation);
	
}
