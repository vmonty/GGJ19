// Fill out your copyright notice in the Description page of Project Settings.

#include "KitchenPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "KitchenGameMode.h"
#include "Engine/World.h"

AKitchenPlayerController::AKitchenPlayerController()
{

}

void AKitchenPlayerController::BeginPlay()
{
	OnPhaseChanged.AddUniqueDynamic(Cast<AKitchenGameMode>(UGameplayStatics::GetGameMode(GetWorld())), &AKitchenGameMode::NextCookingPhase);
}

void AKitchenPlayerController::NextCookPhase()
{
	OnPhaseChanged.Broadcast();
}
