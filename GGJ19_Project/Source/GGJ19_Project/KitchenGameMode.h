// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "KitchenGameMode.generated.h"


UENUM()
enum class ECookingPhase : uint8
{
	CutPhase,
	SeasonPhase,
	CookPhase,
	ResultPhase
};

UENUM()
enum class EMainDishes : uint8
{
	None,
	Lobster,
	Crab,
	Chicken,
	Beef
};

UENUM()
enum class ESeasons : uint8
{
	None,
	SaltPepper,
	Paprika,
	Butter
};

UENUM()
enum class ECookWays : uint8
{
	None,
	Fried,
	Boiled
};

USTRUCT()
struct FDish
{
	GENERATED_BODY()

	UPROPERTY()
	EMainDishes MainDish;

	UPROPERTY()
	ESeasons Seasons;

	UPROPERTY()
	ECookWays CookWays;
};

/**
 * 
 */
UCLASS()
class GGJ19_PROJECT_API AKitchenGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AKitchenGameMode();

	void BeginPlay() override;

	UFUNCTION()
	void NextCookingPhase();


protected:

	UFUNCTION(BlueprintPure, Category = "GamePhase")
	ECookingPhase GetCurrentCookingPhase() const;

	UFUNCTION(BlueprintPure, Category = "GamePhase")
	EMainDishes GetDishChosen() const;

	UFUNCTION(BlueprintPure, Category = "GamePhase")
	ESeasons GetSeasonChosen() const;

	UFUNCTION(BlueprintPure, Category = "GamePhase")
	ECookWays GetCookWayChosen() const;

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void SetDishChosen(EMainDishes DishChosen);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void SetSeasonChosen(ESeasons SeasonChosen);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void SetCookWay(ECookWays CookWayChosen);	

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	int32 CheckCurrentCombination() const;

private:


	//UPROPERTY()
	//TArray<ACameraActor*> Cameras;

	//UPROPERTY()
	//ACameraActor* CurrentCamera;


	UPROPERTY(VisibleAnywhere, Category = "Gameplay")
	ECookingPhase CurrentPhase;

	UPROPERTY(VisibleAnywhere, Category = "Gameplay")
	EMainDishes DishChosen;

	UPROPERTY(VisibleAnywhere, Category = "Gameplay")
	ESeasons SeasonChosen;

	UPROPERTY(VisibleAnywhere, Category = "Gameplay")
	ECookWays CookWayChosen;

	UPROPERTY(VisibleAnywhere, Category = "Gameplay")
	FDish MissionDish;

	FDish GenerateMainDish() const;

};
