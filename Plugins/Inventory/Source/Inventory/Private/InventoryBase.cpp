// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryBase.h"


// Sets default values for this component's properties
UInventoryBase::UInventoryBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UInventoryBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bDebug)
		Debug();
}

TArray<FItemStruct>& UInventoryBase::GetItems()
{
	return Items;
}

bool UInventoryBase::TransferItem(UInventoryBase* ToInventory, const FItemStruct& Item)
{
	if (ToInventory->AddItem(Item))
	{
		return RemoveItem(Item);
	}
	return false;
}

bool UInventoryBase::AddItem(const FItemStruct& NewItem)
{
	Items.Add(NewItem);
	OnInventoryChanged.Broadcast(NewItem);
	return true;
}

bool UInventoryBase::RemoveItem(const FItemStruct& Item)
{
	if (Items.Remove(Item) > 0)
	{
		OnInventoryChanged.Broadcast(Item);
		return true;
	}

	return false;
}

FItemStruct UInventoryBase::CreateItem(const FItemStruct& Item)
{
	if (Item.ItemPDA)
	{
		return FItemStruct{Item.ItemPDA};
	}
	return FItemStruct{nullptr};
}

void UInventoryBase::Debug()
{
	for (const FItemStruct ItemIndex : GetItems())
	{
		PRINT(0, DebugColor.ToFColorSRGB(), ItemIndex.ItemPDA->Text.ToString());
	}
}

FString UInventoryBase::TextToPrint()
{
	return "Hello World from inventory";
}

void UInventoryBase::CallInterface()
{
	IGP21_Interface* GP21 = Cast<IGP21_Interface>(GetOwner());
	GP21->PrintSomething();
}
