// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"

#include "InventoryBase.h"


// Sets default values
AItemBase::AItemBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
}

void AItemBase::SetOwnedGameplayTags(const FGameplayTagContainer& NewContainer)
{
	OwnedGPTs = NewContainer;
}

void AItemBase::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (GetWorld()->WorldType == EWorldType::Editor)
	{
		Item.Id = FGuid::NewGuid();
	}
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AItemBase::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = OwnedGPTs;
}
