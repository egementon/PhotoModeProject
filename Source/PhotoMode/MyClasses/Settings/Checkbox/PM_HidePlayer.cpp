// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_HidePlayer.h"

#include "PhotoMode/MyClasses/PM_PhotoCamera.h"


void UPM_HidePlayer::OnCheckStateChanged(bool bIsChecked)
{
	if (PhotoCamera2)
	{
		PhotoCamera2->PlayerPawn->SetActorHiddenInGame(bIsChecked);
	}
}
