// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PM_SettingParent.h"
#include "PM_CheckboxParent.generated.h"

class UCheckBox;
/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPM_CheckboxParent : public UPM_SettingParent
{
	GENERATED_BODY()

protected:

	virtual void NativeConstruct() override;

	UFUNCTION()
	virtual void OnCheckStateChanged(bool bIsChecked);
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UCheckBox> CheckBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsCheckedAsDefault;
	
};
