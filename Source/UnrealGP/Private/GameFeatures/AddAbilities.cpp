// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFeatures/AddAbilities.h"

#include "AbilitySystemComponent.h"
#include "GameFeaturesSubsystem.h"
#include "Components/GameFrameworkComponentManager.h"
#include "Components/GPAbilitySystemBase.h"


void UAddAbilities::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureActivating(Context);
	GameInstanceHandle = FWorldDelegates::OnStartGameInstance.AddUObject(this, &UAddAbilities::HandleGameInstanceStart);
}

void UAddAbilities::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	Super::OnGameFeatureDeactivating(Context);
	FWorldDelegates::OnStartGameInstance.Remove(GameInstanceHandle);
}

void UAddAbilities::HandleGameInstanceStart(UGameInstance* GameInstance)
{
	UGameFrameworkComponentManager* ComponentManager = UGameInstance::GetSubsystem<
		UGameFrameworkComponentManager>(GameInstance);

	for (int32 EntryIndex = 0; EntryIndex < Abilities.Num(); ++EntryIndex)
	{
		FGameFeatureAbilityEntry AbilityEntry = Abilities[EntryIndex];
		const auto ExtensionDelegate = UGameFrameworkComponentManager::FExtensionHandlerDelegate::CreateUObject(
			this, &UAddAbilities::HandleExtensionDelegate, EntryIndex
		);
		ExtensionHandler.Add(ComponentManager->AddExtensionHandler(AbilityEntry.ActorClass, ExtensionDelegate));
	}
}

void UAddAbilities::HandleExtensionDelegate(AActor* ActorClass, FName Name, int32 EntryIndex)
{
	UGPAbilitySystemBase* AbilitySystemComponent = ActorClass->FindComponentByClass<UGPAbilitySystemBase>();

	const TSubclassOf<UGameplayAbility> Ability = Abilities[EntryIndex].AbilityClass.LoadSynchronous();
	const FGameplayAbilitySpec AbilitySpec{Ability};
	AbilitySystemComponent->GiveAbility(AbilitySpec);
}
