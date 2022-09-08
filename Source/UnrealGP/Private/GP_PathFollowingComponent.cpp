// Fill out your copyright notice in the Description page of Project Settings.


#include "GP_PathFollowingComponent.h"


// Sets default values for this component's properties
UGP_PathFollowingComponent::UGP_PathFollowingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGP_PathFollowingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGP_PathFollowingComponent::TickComponent(float DeltaTime, ELevelTick TickType
                                               , FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGP_PathFollowingComponent::DrawSphereAtTargetDestination(FLinearColor Color, float Time)
{
	if (!Path)
		return;

	TArray<FNavPathPoint> PathPoints = Path->GetPathPoints();

	for (FNavPathPoint Point : PathPoints)
	{
		DrawDebugSphere(GetWorld(), Point, 60, 12, Color.ToFColorSRGB(), false, Time);
	}
}

