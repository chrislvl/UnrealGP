// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryStructs.h"
#include "Components/ActorComponent.h"
#include "InventoryBase.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORY_API UInventoryBase : public UActorComponent{
	GENERATED_BODY()

	FItemStruct Item;
public:	
	// Sets default values for this component's properties
	UInventoryBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType
	                           , FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	TArray<FItemStruct>& GetItems();
	
private:
	TArray<FItemStruct> Items;
};
