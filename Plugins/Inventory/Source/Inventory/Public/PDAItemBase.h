// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PDAItemBase.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UPDAItemBase : public UPrimaryDataAsset{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Basic")
	FText Name;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Basic")
	UStaticMesh* Mesh;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Basic")
	UTexture2D* Thumbnail;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Basic")
	FGameplayTagContainer Tags;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool Use(APawn* Pawn);


};
