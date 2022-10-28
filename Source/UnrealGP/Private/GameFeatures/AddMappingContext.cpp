// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFeatures/AddMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "Components/GameFrameworkComponentManager.h"
#include "GameFramework/Character.h"

void UAddMappingContext::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureActivating(Context);
	GameInstanceHandle = FWorldDelegates::OnStartGameInstance.AddUObject(
		this, &UAddMappingContext::HandleGameInstanceStart);
}

void UAddMappingContext::HandleGameInstanceStart(UGameInstance* GameInstance)
{
	UGameFrameworkComponentManager* ComponentManager = UGameInstance::GetSubsystem<
		UGameFrameworkComponentManager>(GameInstance);

	for (int Entry = 0; Entry < MappingEntries.Num(); ++Entry)
	{
		FGameFeatureMappingEntry MappingEntry = MappingEntries[Entry];
		const UGameFrameworkComponentManager::FExtensionHandlerDelegate ExtensionHandler =
			UGameFrameworkComponentManager::FExtensionHandlerDelegate::CreateUObject(
				this, &UAddMappingContext::HandleExtensionDelegate, Entry
			);

		ExtensionHandlers.Add(ComponentManager->AddExtensionHandler(MappingEntry.CharacterClass, ExtensionHandler));
	}
}

void UAddMappingContext::HandleExtensionDelegate(AActor* ActorClass, FName Name, int32 EntryIndex)
{
	const ACharacter* PlayerCharacter = Cast<ACharacter>(ActorClass);
	const APlayerController* PlayerController = Cast<APlayerController>(PlayerCharacter->Controller);
	const auto InputSubsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()
		);

	InputSubsystem->AddMappingContext(MappingEntries[EntryIndex].MappingContext, 1);
}
