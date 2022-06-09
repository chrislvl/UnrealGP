// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintLibrary.h"

void UBlueprintLibrary::Print(FString MyText)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, MyText);
}
