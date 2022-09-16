// Fill out your copyright notice in the Description page of Project Settings.


#include "GP21_Interface.h"

#include "InventoryBase.h"


void IGP21_Interface::PrintSomething()
{
	PRINT(10, FColor::Blue, "%s", *TextToPrint())
}
