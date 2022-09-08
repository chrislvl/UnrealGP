// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

#include "GP_PathFollowingComponent.h"

// Sets default values
ATestActor::ATestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

ATestActor::ATestActor(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer.SetDefaultSubobjectClass<UGP_PathFollowingComponent>(TEXT("PathFollowingComponent")))
{	
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
