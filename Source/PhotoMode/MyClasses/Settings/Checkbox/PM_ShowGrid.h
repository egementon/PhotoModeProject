// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhotoMode/MyClasses/Settings/PM_CheckboxParent.h"
#include "PM_ShowGrid.generated.h"

/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPM_ShowGrid : public UPM_CheckboxParent
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void OnCheckStateChanged(bool bIsChecked) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> GridWidgetClass;

	UPROPERTY()
	TObjectPtr<UUserWidget> GridWidgetInstance;
	
};
