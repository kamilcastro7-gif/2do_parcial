// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemigoRapido.generated.h"

class UStaticMeshComponent;

UCLASS()
class NAVESUSFX2026_API AEnemigoRapido : public AActor
{
	GENERATED_BODY()

private:
	float nivelEnergia = 80.0f;
	float velocidadMovimiento = 400.0f;

public:
	AEnemigoRapido();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* mallaEnemigoRapido;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
