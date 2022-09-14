// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryStructs.h"
#include "Components/ActorComponent.h"
#include "InventoryBase.generated.h"

#define PRINT(Time,Text) GEngine->AddOnScreenDebugMessage(-1, Time, FColor::Orange, Text);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryChangedSignature, FItemStruct, Item);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORY_API UInventoryBase : public UActorComponent{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryBase();

	UPROPERTY(BlueprintAssignable)
	FOnInventoryChangedSignature OnInventoryChanged;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType
	                           , FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FItemStruct>& GetItems();

	UFUNCTION(BlueprintCallable)
	bool AddItem(const FItemStruct& NewItem);

	UFUNCTION(BlueprintCallable)
	bool RemoveItem(const FItemStruct& Item); 
		
	UFUNCTION(BlueprintCallable)
	FItemStruct CreateItem(const FItemStruct& Item);
	
	UPROPERTY(EditDefaultsOnly)
	bool bDebug;
	
private:
	TArray<FItemStruct> Items;

	void Debug();
};
