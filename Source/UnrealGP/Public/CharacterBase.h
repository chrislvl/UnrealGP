// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerControllerBase.h"
#include "Components/GPAbilitySystemBase.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS()
class UNREALGP_API ACharacterBase : public ACharacter{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UGPAbilitySystemBase* AbilitySystemComponent;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerInteract(AActor* HitActor, ACharacter* Interactor);

	virtual void PossessedBy(AController* NewController) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
