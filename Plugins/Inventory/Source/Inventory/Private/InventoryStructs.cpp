#include "InventoryStructs.h"

bool FItemStruct::IsValid() const
{
	return ItemPDA != nullptr;
}
