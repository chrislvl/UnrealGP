// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "InventoryStructs.h"
#include "Engine/StaticMeshActor.h"
#include "ItemBase.generated.h"

UCLASS()
class INVENTORY_API AItemBase : public AStaticMeshActor, public IGameplayTagAssetInterface{
private:
	GENERATED_BODY()

	
public:
	// Sets default values for this actor's properties
	AItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable)
	void SetOwnedGameplayTags(const FGameplayTagContainer& NewContainer);
		
	virtual void OnConstruction(const FTransform& Transform) override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(ExposeOnSpawn=true))
	FItemStruct Item;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

private:
	FGameplayTagContainer OwnedGPTs;
};
