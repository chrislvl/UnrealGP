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

	if (!GrantAttributes())
	{
		GEngine->AddOnScreenDebugMessage(
			-1, 10, FColor::Red,
			FString::Printf(TEXT("%s has no attributes"), *GetOwner()->GetName())
		);
	}

	GetGameplayAttributeValueChangeDelegate(UGPAttributeBase::GetHealthAttribute()).AddUObject(
		this, &UGPAbilitySystemBase::OnHealthChanged
	);
}

bool UGPAbilitySystemBase::GrantAbilities()
{
	for (const TSubclassOf<UGameplayAbility>& Ability : GrantedAbilities)
	{
		checkf(Ability, TEXT("Missing ability slot %s"), *GetOwner()->GetName())

		const FGameplayAbilitySpec* FoundSpec = FindAbilitySpecFromClass(Ability);
		if (FoundSpec)
		{
			if (FoundSpec->Ability->GetClass() == Ability)
				continue;
		}

		FGameplayAbilitySpec AbilitySpec{Ability};
		GiveAbility(AbilitySpec);
	}

	return !GrantedAbilities.IsEmpty();
}

bool UGPAbilitySystemBase::GrantAttributes()
{
	if (GrantedAttribute.IsEmpty())
		return false;

	for (TSubclassOf<UAttributeSet>& Attribute : GrantedAttribute)
	{
		const bool HasAttribute = GetAttributeSubobject(Attribute) != nullptr;

		if (HasAttribute)
			continue;

		UAttributeSet* NewAttribute = NewObject<UAttributeSet>(GetOwner(), Attribute);
		NewAttribute->InitFromMetaDataTable(DTAttribute);
		AddAttributeSetSubobject(NewAttribute);
	}
	return true;
}

void UGPAbilitySystemBase::OnHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthAttributeChanged.Broadcast(Data.Attribute, Data.NewValue);
}
