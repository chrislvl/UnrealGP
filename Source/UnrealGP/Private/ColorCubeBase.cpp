// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorCubeBase.h"

#include "Net/UnrealNetwork.h"


// Sets default values
AColorCubeBase::AColorCubeBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CubeComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
}

void AColorCubeBase::Rep_CurrentColor()
{
	CubeComponent->SetMaterial(0, MaterialsMap[CurrentColor]);
}

void AColorCubeBase::ChangeColor()
{
	switch (CurrentColor)
	{
	case EColors::Red:
		CurrentColor = EColors::Green;
		break;
	case EColors::Green:
		CurrentColor = EColors::Blue;
		break;
	case EColors::Blue:
		CurrentColor = EColors::Red;
		break;
	}
	Rep_CurrentColor();
}

void AColorCubeBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AColorCubeBase, CurrentColor);
}

void AColorCubeBase::Interact_Implementation(ACharacter* Interactor)
{
	ChangeColor();
}
