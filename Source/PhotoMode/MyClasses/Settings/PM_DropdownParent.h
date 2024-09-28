// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PM_SettingParent.h"
#include "PM_DropdownParent.generated.h"

class UComboBoxString;
/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPM_DropdownParent : public UPM_SettingParent
{
	GENERATED_BODY()

public:
	
	void SetSelection(int32 Index);
	void ResetSelection();

protected:

	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	UFUNCTION()
	void SelectionChangedCallback(FString SelectedItem, ESelectInfo::Type SelectionType);
	
	virtual void OnDropdownSelectionChanged(FString NewSelectedOption, int32 NewSelectedIndex);
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UComboBoxString> Dropdown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Options;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SelectedOption;
	
	
};
