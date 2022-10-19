// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/GPAttributeBase.h"

#include "Net/UnrealNetwork.h"

void UGPAttributeBase::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGPAttributeBase, MaxHealth, OldMaxHealth)
}

void UGPAttributeBase::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGPAttributeBase, Health, OldHealth)
}

void UGPAttributeBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UGPAttributeBase, Health, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGPAttributeBase, MaxHealth, COND_None, REPNOTIFY_Always)
}

void UGPAttributeBase::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxHealth());
	}
}
