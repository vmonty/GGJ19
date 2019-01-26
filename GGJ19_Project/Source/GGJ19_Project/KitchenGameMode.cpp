// Fill out your copyright notice in the Description page of Project Settings.

#include "KitchenGameMode.h"

AKitchenGameMode::AKitchenGameMode()
{

}

void AKitchenGameMode::BeginPlay()
{
	Super::BeginPlay();
	MissionDish = GenerateMainDish();
	CurrentPhase = ECookingPhase::CutPhase;
}

ECookingPhase AKitchenGameMode::GetCurrentCookingPhase() const
{
	return CurrentPhase;
}

EMainDishes AKitchenGameMode::GetDishChosen() const
{
	return DishChosen;
}

ESeasons AKitchenGameMode::GetSeasonChosen() const
{
	return SeasonChosen;
}

ECookWays AKitchenGameMode::GetCookWayChosen() const
{
	return CookWayChosen;
}

void AKitchenGameMode::NextCookingPhase()
{
	CurrentPhase = (ECookingPhase)((uint8)CurrentPhase + (uint8)1);
	
	/*if (CurrentPhase == ECookingPhase::CutPhase)
	{
		CurrentPhase = ECookingPhase::SeasonPhase;
	}
	if (CurrentPhase == ECookingPhase::SeasonPhase)
	{
		CurrentPhase = ECookingPhase::CookPhase;
	}
	if (CurrentPhase == ECookingPhase::CookPhase)
	{
		CurrentPhase = ECookingPhase::ResultPhase;
	}*/
	
}

void AKitchenGameMode::SetDishChosen(EMainDishes NewDish)
{
	DishChosen = NewDish;
}

void AKitchenGameMode::SetSeasonChosen(ESeasons NewSeason)
{
	SeasonChosen = NewSeason;
}

void AKitchenGameMode::SetCookWay(ECookWays NewCookWay)
{
	CookWayChosen = NewCookWay;
}

int32 AKitchenGameMode::CheckCurrentCombination() const
{
	int32 Score = 0;
	if (MissionDish.MainDish == DishChosen)
	{
		++Score;
	}
	if (MissionDish.Seasons == SeasonChosen)
	{
		++Score;
	}
	if (MissionDish.CookWays == CookWayChosen)
	{
		++Score;
	}
	return Score;
}

FDish AKitchenGameMode::GenerateMainDish() const
{
	//Para hacerlo procedural
	
	FDish TargetDish;
	/*TargetDish.MainDish = (EMainDishes)FMath::RandRange(0, 1);
	TargetDish.Seasons = (ESeasons)FMath::RandRange(0, 1);
	TargetDish.CookWays = (ECookWays)FMath::RandRange(0, 1);
	*/
	TargetDish.MainDish = EMainDishes::Lobster;
	TargetDish.Seasons = ESeasons::Paprika;
	TargetDish.CookWays = ECookWays::Boiled;
	return TargetDish;


}
