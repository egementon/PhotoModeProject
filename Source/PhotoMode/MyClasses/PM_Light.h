// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PM_Light.generated.h"

UCLASS()
class PHOTOMODE_API APM_Light : public AActor
{
	GENERATED_BODY()

public:
	APM_Light();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UPointLightComponent* PointLight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBillboardComponent* Billboard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAttached;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUseLightMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Hue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Saturation;
	
	
};
