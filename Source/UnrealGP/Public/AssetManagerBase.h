// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "UObject/Object.h"
#include "AssetManagerBase.generated.h"

/**
 * 
 */
UCLASS()
class UNREALGP_API UAssetManagerBase : public UAssetManager{
	GENERATED_BODY()


	virtual void StartInitialLoading() override;
};
