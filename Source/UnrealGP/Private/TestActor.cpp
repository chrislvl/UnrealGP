// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

void ATestActor::DrawSphereAtTargetDestination(FLinearColor Color, float Time)
{
	FVector PathDestination = GetPathFollowingComponent()->GetPathDestination();
	FNavPathSharedPtr Path = GetPathFollowingComponent()->GetPath();
	DrawDebugSphere(GetWorld(), PathDestination, 100, 12, Color.ToFColorSRGB(), false, Time);
}

// Sets default values
ATestActor::ATestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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
