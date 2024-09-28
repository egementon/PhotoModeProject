// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_AttachToCamera.h"

#include "PhotoMode/MyClasses/PM_Light.h"
#include "PhotoMode/MyClasses/PM_PhotoCamera.h"

void UPM_AttachToCamera::OnCheckStateChanged(bool bIsChecked)
{
	if (!PhotoCamera2->SelectedLight) return;

	if (bIsChecked)
	{
		const FAttachmentTransformRules AttachmentRules(EAttachmentRule::KeepRelative, true);
		PhotoCamera2->SelectedLight->AttachToActor(PhotoCamera2, AttachmentRules);
		PhotoCamera2->SelectedLight->SetActorLocation(PhotoCamera2->GetActorLocation());
	}
	else
	{
		const FDetachmentTransformRules AttachmentRules(EDetachmentRule::KeepWorld, true);
		PhotoCamera2->SelectedLight->DetachFromActor(AttachmentRules);
	}
	
	PhotoCamera2->SelectedLight->bAttached = bIsChecked;
}
