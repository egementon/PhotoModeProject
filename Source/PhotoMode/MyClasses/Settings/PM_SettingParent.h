// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PM_SettingParent.generated.h"

class UPM_MenuWidget;
class UTextBlock;
class UHorizontalBox;
class USizeBox;
class APhotoCamera;
/**
 * 
 */
UCLASS()
class PHOTOMODE_API UPM_SettingParent : public UUserWidget
{
	GENERATED_BODY()

public:

	void SetMenuWidget(UPM_MenuWidget* NewMenuWidget);

	void SetPhotoCamera(APhotoCamera* NewPhotoCamera);
	APhotoCamera* GetPhotoCamera();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText SettingName = FText::FromString(TEXT("Setting Name"));
	
protected:
	
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	
	UPROPERTY()
	APhotoCamera* PhotoCamera2;

	UPROPERTY()
	TObjectPtr<UPM_MenuWidget> MenuWidget;

	// Widget Components
	UPROPERTY(meta = (BindWidget))
	USizeBox* RootSizeBox;

	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* HorizontalBox;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* SettingNameText;

	UPROPERTY(meta = (BindWidget))
	USizeBox* SizeBox;

	UPROPERTY(meta = (BindWidget))
	USizeBox* InnerSizeBox;
	
};
