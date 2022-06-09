// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CPPTESTING_API UBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int MyInt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MyFloat = 0.0f;

	UFUNCTION(BlueprintCallable, Category="BlueprintLibrary|MyPrinting")
	static void Print(FString MyText);

private:
	
	
};
