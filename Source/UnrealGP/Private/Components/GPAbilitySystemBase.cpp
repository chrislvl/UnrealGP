// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/GPAbilitySystemBase.h"

// Sets default values for this component's properties
UGPAbilitySystemBase::UGPAbilitySystemBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGPAbilitySystemBase::BeginPlay()
{
	Super::BeginPlay();

	if (!GrantAbilities())
	{
		GEngine->AddOnScreenDebugMessage(
			-1, 10, FColor::Red,
			FString::Printf(TEXT("%s has no abilities"), *GetOwner()->GetName())
		);
	}
}

bool UGPAbilitySystemBase::GrantAbilities()
{
	for (const TSubclassOf<UGameplayAbility>& Ability : GrantedAbilities)
	{
		if (Ability == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(
				-1, 10, FColor::Red,
				FString::Printf(TEXT("%s has empty ability slot"), *GetOwner()->GetName())
			);
		}

		FGameplayAbilitySpec AbilitySpec{Ability};
		GiveAbility(AbilitySpec);
	}

	return !GrantedAbilities.IsEmpty();
}
