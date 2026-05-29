// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Enemigo.generated.h"

class UStaticMeshComponent;;

UCLASS()
class NAVESUSFX2026_API AEnemigo : public AActor
{
	GENERATED_BODY()
private:
	float nivelEnergia = 100;
	float nivelAtaque = 10;
	float nivelDefensa = 5;
	float nivelHabilidad = 5;
	FVector posicion;
	float velocidadMovimiento = 200.0f;

public:	
	// Sets default values for this actor's properties
	AEnemigo();

	UStaticMeshComponent* mallaEnemigo;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
