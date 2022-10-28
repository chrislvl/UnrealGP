// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "InputMappingContext.h"
#include "Components/GameFrameworkComponentManager.h"
#include "GameFramework/Character.h"
#include "AddMappingContext.generated.h"

USTRUCT()
struct FGameFeatureMappingEntry{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<ACharacter> CharacterClass = ACharacter::StaticClass();

	UPROPERTY(EditAnywhere)
	UInputMappingContext* MappingContext;
};

UCLASS()
class UNREALGP_API UAddMappingContext : public UGameFeatureAction{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FGameFeatureMappingEntry> MappingEntries;
	FDelegateHandle GameInstanceHandle;

	TArray<TSharedPtr<FComponentRequestHandle>> ExtensionHandlers;

	virtual void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;

	UFUNCTION()
	void HandleGameInstanceStart(UGameInstance* GameInstance);

	UFUNCTION()
	void HandleExtensionDelegate(AActor* ActorClass, FName Name, int32 EntryIndex);
};
