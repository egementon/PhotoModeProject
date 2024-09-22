// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_SettingParent.h"

#include "Blueprint/WidgetTree.h"
#include "Components/HorizontalBox.h"
#include "Components/PanelWidget.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"

void UPM_SettingParent::NativePreConstruct()
{
	Super::NativePreConstruct();
	if (SettingNameText) //TODO: remove if
	{
		SettingNameText->SetText(SettingName);
	}
}

void UPM_SettingParent::NativeConstruct()
{
	Super::NativeConstruct();

	RootSizeBox = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("RootSizeBox"));
	WidgetTree->RootWidget = RootSizeBox;

	HorizontalBox = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("HorizontalBox"));
	RootSizeBox->AddChild(HorizontalBox);

	SettingNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Text_Name"));
	//SettingNameText->SetText(FText::FromString("Setting Name"));
	HorizontalBox->AddChildToHorizontalBox(SettingNameText);

	SizeBox = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("SizeBox"));
	HorizontalBox->AddChildToHorizontalBox(SizeBox);

	InnerSizeBox = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("InnerSizeBox"));
	SizeBox->AddChild(InnerSizeBox);
	
	
}
