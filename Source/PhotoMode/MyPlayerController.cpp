// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"



void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	APawn* PlayerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
}
