// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_ShowGrid.h"

void UPM_ShowGrid::NativeConstruct()
{
	Super::NativeConstruct();
	GridWidgetInstance = CreateWidget(GetOwningPlayer(), GridWidgetClass);
	GridWidgetInstance->SetVisibility(ESlateVisibility::Collapsed);
	GridWidgetInstance->AddToViewport();
}

void UPM_ShowGrid::OnCheckStateChanged(bool bIsChecked)
{
	if (bIsChecked)
	{
		GridWidgetInstance->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
	else
	{
		GridWidgetInstance->SetVisibility(ESlateVisibility::Collapsed);
	}
}
