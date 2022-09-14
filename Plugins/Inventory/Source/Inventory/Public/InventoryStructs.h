#pragma once
#include "ItemPDABase.h"

#include "InventoryStructs.generated.h"

USTRUCT(BlueprintType)
struct FItemStruct{
	GENERATED_BODY()

	FItemStruct(): ItemPDA(nullptr), Durability(0)
	{
	}

	FItemStruct(UItemPDABase* ItemPda): ItemPDA(ItemPda), Durability(100), Id(FGuid::NewGuid())
	{
	}

	FItemStruct(UItemPDABase* ItemPda, float Durability) : ItemPDA(ItemPda), Durability(Durability),
	                                                       Id(FGuid::NewGuid())
	{
	}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UItemPDABase* ItemPDA;

	UPROPERTY(BlueprintReadWrite)
	float Durability;

	FGuid Id;

	bool operator ==(const FItemStruct& Other) const
	{
		return this->Id == Other.Id;
	}
};
