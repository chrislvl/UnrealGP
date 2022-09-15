// Fill out your copyright notice in the Description page of Project Settings.


#include "GP21_Interface.h"

#include "InventoryBase.h"


// Add default functionality here for any IGP21_Interface functions that are not pure virtual.
void IGP21_Interface::PrintSomething()
{
	PRINT(10, FColor::Blue, TextToPrint())
}
