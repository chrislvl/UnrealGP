#pragma once
#include "ItemPDABase.h"

#include "InventoryStructs.generated.h"

USTRUCT(BlueprintType)
struct FItemStruct{
	GENERATED_BODY()
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UItemPDABase* ItemPDA;

	UPROPERTY(BlueprintReadWrite)
	float Durability;
};
