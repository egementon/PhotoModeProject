// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_WestEast.h"

#include "GameFramework/Character.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_WestEast::OnSliderValueChanged(float NewValue)
{
	if (!PhotoCamera2) return;
	
	const FVector CurrentRelativeLocation = PhotoCamera2->PlayerCharacter->GetMesh()->GetRelativeLocation();
	const float CurrentX = CurrentRelativeLocation.X;
	const float CurrentZ = CurrentRelativeLocation.Z;
	
	const FVector InitialLocation = PhotoCamera2->MeshInitialRelativeTransform.GetLocation();
	const float NewYLocation = InitialLocation.Y + NewValue;
	const FVector NewLocation = FVector(CurrentX, NewYLocation, CurrentZ);
	PhotoCamera2->PlayerCharacter->GetMesh()->SetRelativeLocation(NewLocation);
}
