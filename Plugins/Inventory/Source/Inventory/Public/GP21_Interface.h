// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GP21_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UGP21_Interface : public UInterface{
	GENERATED_BODY()
};

class INVENTORY_API IGP21_Interface{
	GENERATED_IINTERFACE_BODY()
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

	UFUNCTION(BlueprintCallable)
	virtual void PrintSomething();

	virtual FString TextToPrint() =0;
};
