// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ColorCubeBase.generated.h"

UENUM(BlueprintType)
enum class EColors : uint8{
	Red,
	Green,
	Blue
};

UCLASS()
class UNREALGP_API AColorCubeBase : public AActor{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AColorCubeBase();

	UFUNCTION(BlueprintCallable)
	void ChangeColor();

protected:
	UPROPERTY(EditDefaultsOnly)
	TMap<EColors, UMaterialInterface*> MaterialsMap;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* CubeComponent;

private:
	UPROPERTY(ReplicatedUsing=Rep_CurrentColor)
	EColors CurrentColor;

	UFUNCTION()
	void Rep_CurrentColor();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
