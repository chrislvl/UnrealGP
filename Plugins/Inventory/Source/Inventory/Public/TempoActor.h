// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GP21_Interface.h"
#include "GameFramework/Actor.h"
#include "TempoActor.generated.h"

UCLASS(BlueprintType)
class INVENTORY_API ATempoActor : public AActor, public IGP21_Interface{

	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATempoActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual FString TextToPrint() override;
};
