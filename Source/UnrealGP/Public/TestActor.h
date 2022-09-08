// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()
class UNREALGP_API ATestActor : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="GP_21")
	void DrawSphere(FVector Location, FColor Color);
	
	// Sets default values for this actor's properties
	ATestActor();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
