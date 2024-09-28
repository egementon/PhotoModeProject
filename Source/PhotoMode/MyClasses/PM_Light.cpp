// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_Light.h"

#include "Components/BillboardComponent.h"
#include "Components/PointLightComponent.h"


APM_Light::APM_Light()
{
	PrimaryActorTick.bCanEverTick = false;

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	RootComponent = PointLight;

	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	Billboard->SetupAttachment(RootComponent);

	bEnabled = true;
	bAttached = false;
	bUseLightMovement = true;
	Hue = 0.0f;
	Saturation = 0.0f;

	PointLight->SetIntensity(10000.f);
	Billboard->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	Billboard->SetHiddenInGame(false);
}
