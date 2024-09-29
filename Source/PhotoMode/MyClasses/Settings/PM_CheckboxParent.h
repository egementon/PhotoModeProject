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

public:
	
	void SetCheckState(bool bIsChecked);
	void ResetCheckState();

protected:

	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	UFUNCTION()
	virtual void OnCheckStateChanged(bool bIsChecked);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsCheckedAsDefault;

	// Widget Components
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UCheckBox> CheckBox;
	
};
