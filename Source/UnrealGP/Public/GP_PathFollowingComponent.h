// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Navigation/PathFollowingComponent.h"
#include "GP_PathFollowingComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UNREALGP_API UGP_PathFollowingComponent : public UPathFollowingComponent{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGP_PathFollowingComponent();

	/**
	 * If true, shows debug sphere for path
	 */
	UPROPERTY(EditAnywhere, Category="Debug❤")
	bool Debug;

	/**
	 * The color to debug
	 */
	UPROPERTY(EditDefaultsOnly, Category="Debug❤")
	FLinearColor DebugColor;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType
	                           , FActorComponentTickFunction* ThisTickFunction) override;

	/**
	 * @param Color Color to use
	 * @param Time Time used to display spheres
	 */
	UFUNCTION(BlueprintCallable)
	void DrawSphereAtTargetDestination(FLinearColor Color, float Time);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Pathfinding")
	bool IsDestinationReachable(FVector EndLocation);
};
