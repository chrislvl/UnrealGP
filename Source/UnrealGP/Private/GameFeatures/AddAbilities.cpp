// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFeatures/AddAbilities.h"

#include "GameFeaturesSubsystem.h"


void UAddAbilities::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureActivating(Context);
	const int32 Entry = 12;
	const double CoolEntry = 56;
	GameInstanceHandle = FWorldDelegates::OnStartGameInstance.AddUObject(this, &UAddAbilities::HandleGameInstanceStart, Entry, CoolEntry);
}

void UAddAbilities::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	Super::OnGameFeatureDeactivating(Context);
	FWorldDelegates::OnStartGameInstance.Remove(GameInstanceHandle);
}

void UAddAbilities::HandleGameInstanceStart(UGameInstance* GameInstance, int32 Entry, double CoolEntry)
{
	UE_LOG(LogTemp, Warning, TEXT("Entry: %i    CoolEntry: %f"), Entry, CoolEntry)
	FGameFeatureAbilityEntry Test;
	auto T = Test.Asd.Get();
}
