// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemigoTanque.generated.h"

class UStaticMeshComponent;

UCLASS()
class NAVESUSFX2026_API AEnemigoTanque : public AActor
{
	GENERATED_BODY()

private:
	float nivelEnergia = 250.0f;
	float velocidadMovimiento = 100.0f;

public:
	AEnemigoTanque();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* mallaEnemigoTanque;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
