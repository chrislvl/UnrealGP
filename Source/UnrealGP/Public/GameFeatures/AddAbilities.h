// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "Abilities/GameplayAbility.h"
#include "AddAbilities.generated.h"


struct FGameFeatureStateChangeContext;
USTRUCT()
struct FGameFeatureAbilityEntry{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<AActor> ActorClass;

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UGameplayAbility> AbilityClass;

	TUniquePtr<UObject*> Asd;
};


UCLASS()
class UNREALGP_API UAddAbilities : public UGameFeatureAction{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	TArray<FGameFeatureAbilityEntry> Abilities;
	FDelegateHandle GameInstanceHandle;

	virtual void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;
	virtual void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;

	void HandleGameInstanceStart(UGameInstance* GameInstance, int32 Entry, double CoolEntry);
};
