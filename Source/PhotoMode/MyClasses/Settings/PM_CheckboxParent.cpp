// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_CheckboxParent.h"
#include "Components/CheckBox.h"

void UPM_CheckboxParent::SetCheckState(bool bIsChecked)
{
	CheckBox->SetIsChecked(bIsChecked);
}

void UPM_CheckboxParent::NativePreConstruct()
{
	Super::NativePreConstruct();
	SetCheckState(bIsCheckedAsDefault);
}

void UPM_CheckboxParent::NativeConstruct()
{
	Super::NativeConstruct();
	
	CheckBox->OnCheckStateChanged.AddDynamic(this, &UPM_CheckboxParent::OnCheckStateChanged);
}

void UPM_CheckboxParent::OnCheckStateChanged(bool bIsChecked)
{
	// Logic will be implemented in subclasses
}
