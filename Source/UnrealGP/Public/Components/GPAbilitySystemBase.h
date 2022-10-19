// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Attributes/GPAttributeBase.h"
#include "GPAbilitySystemBase.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UNREALGP_API UGPAbilitySystemBase : public UAbilitySystemComponent{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGPAbilitySystemBase();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UGameplayAbility>> GrantedAbilities;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UAttributeSet>> GrantedAttribute;

	UPROPERTY(EditDefaultsOnly)
	UDataTable* DTAttribute;
private:
	bool GrantAbilities();

	bool GrantAttributes();
};
