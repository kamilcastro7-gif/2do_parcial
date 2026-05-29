// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemigoAnimal.generated.h"

class USkeletalMeshComponent;


UCLASS()
class NAVESUSFX2026_API AEnemigoAnimal : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemigoAnimal();
	void MoverBonus();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public: 
	USkeletalMeshComponent* esqueletoEnemigo;  // Ya existe por herencia
};
