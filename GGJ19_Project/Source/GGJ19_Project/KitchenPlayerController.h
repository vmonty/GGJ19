// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "KitchenPlayerController.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGamePhaseChanged);

/**
 * 
 */
UCLASS()
class GGJ19_PROJECT_API AKitchenPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AKitchenPlayerController();

	UPROPERTY()
	FGamePhaseChanged OnPhaseChanged;

	void BeginPlay() override;

protected:

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void ChangeCookPhase();

private:


};
