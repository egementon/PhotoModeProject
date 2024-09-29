// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_DropdownParent.h"

#include "Components/ComboBoxString.h"

void UPM_DropdownParent::NativePreConstruct()
{
	Super::NativePreConstruct();
	
	for (FString Option : Options)
	{
		Dropdown->AddOption(Option);	
	}
	
	Dropdown->SetSelectedOption(SelectedOption);
}

void UPM_DropdownParent::NativeConstruct()
{
	Super::NativeConstruct();
	
	Dropdown->OnSelectionChanged.AddDynamic(this, &UPM_DropdownParent::SelectionChangedCallback);
}

void UPM_DropdownParent::SelectionChangedCallback(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	OnDropdownSelectionChanged(SelectedItem, Dropdown->GetSelectedIndex());
}

void UPM_DropdownParent::OnDropdownSelectionChanged(FString NewSelectedOption, int32 NewSelectedIndex)
{
	// Logic will be implemented in subclasses
}

void UPM_DropdownParent::SetSelection(int32 Index)
{
	Dropdown->SetSelectedIndex(Index);
}

void UPM_DropdownParent::ResetSelection()
{
	Dropdown->SetSelectedIndex(0);
}
