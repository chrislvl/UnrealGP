// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "GPAttributeBase.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class UNREALGP_API UGPAttributeBase : public UAttributeSet{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Attributes|Health", ReplicatedUsing=OnRep_Health)
	FGameplayAttributeData Health = 150;
	ATTRIBUTE_ACCESSORS(UGPAttributeBase, Health)

	UPROPERTY(BlueprintReadOnly, Category="Attributes|Health", ReplicatedUsing=OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth = 100;
	ATTRIBUTE_ACCESSORS(UGPAttributeBase, MaxHealth)

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};
