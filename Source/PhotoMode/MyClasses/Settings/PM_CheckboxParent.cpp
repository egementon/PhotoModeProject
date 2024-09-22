// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_CheckboxParent.h"

#include "Components/CheckBox.h"
#include "Kismet/KismetSystemLibrary.h"

void UPM_CheckboxParent::NativeConstruct()
{
	Super::NativeConstruct();

	CheckBox->SetIsChecked(bIsCheckedAsDefault);

	CheckBox->OnCheckStateChanged.AddDynamic(this, &UPM_CheckboxParent::OnCheckStateChanged);
}

void UPM_CheckboxParent::OnCheckStateChanged(bool bIsChecked)
{
	UKismetSystemLibrary::PrintString(this, TEXT("Check State Changed"));
}
