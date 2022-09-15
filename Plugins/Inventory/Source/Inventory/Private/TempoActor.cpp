// Fill out your copyright notice in the Description page of Project Settings.


#include "TempoActor.h"

#include "InventoryBase.h"


// Sets default values
ATempoActor::ATempoActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATempoActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATempoActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FString ATempoActor::TextToPrint()
{
	return "Hello World from TempoActor";
}
