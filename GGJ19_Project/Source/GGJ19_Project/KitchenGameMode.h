// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "KitchenGameMode.generated.h"


UENUM(BlueprintType)
enum class ECookingPhase : uint8
{
	CutPhase,
	SeasonPhase,
	CookPhase,
	ResultPhase,
	None
};

UENUM(BlueprintType)
enum class EMainDishes : uint8
{
	Lobster,
	Crab,
	Chicken,
	Beef,
	None
};

UENUM(BlueprintType)
enum class ESeasons : uint8
{
	SaltPepper,
	Paprika,
	Butter,
	None
};

UENUM(BlueprintType)
enum class ECookWays : uint8
{
	Undercooked UMETA(DisplayName = "Undercooked"),
	Cooked UMETA(DisplayName = "Cooked"),
	Overcooked UMETA(DisplayName = "Overcooked"),
	None
};

USTRUCT(Blueprintable)
struct FDish
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMainDishes MainDish;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESeasons Seasons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FDish MissionDish;

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
	EMainDishes DishChosen = EMainDishes::None;

	UPROPERTY(VisibleAnywhere, Category = "Gameplay")
	ESeasons SeasonChosen = ESeasons::None;

	UPROPERTY(VisibleAnywhere, Category = "Gameplay")
	ECookWays CookWayChosen = ECookWays::None;

	

	FDish GenerateMainDish() const;

};
