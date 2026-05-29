// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GeneradorLaberinto.generated.h"

class ABloque;

USTRUCT()
struct FBloqueMovimientoData
{
	GENERATED_BODY()

	/*/
	UPROPERTY()
	ABloque* Bloque = nullptr;

	UPROPERTY()
	FVector Destino = FVector::ZeroVector;
	*/
};

UCLASS()
class NAVESUSFX2026_API AGeneradorLaberinto : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeneradorLaberinto();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int32 CantidadBloques = 100;
	FVector LimitesMapa = FVector(2000.f, 1000.f, 0.f);
	FVector UbicacionMedia = FVector(0.f, 0.f, 200.f);
	/*
	int32 Filas = 18;
	int32 Columnas = 18;
	float TamCelda = 200.0f;*/
public:
	TArray<ABloque*> TABloques;
	/*
public:
	
	//P1
	TArray<ABloque*> TABSI; // Superior Izquierda
	TArray<ABloque*> TABSD; // Superior Derecha
	TArray<ABloque*> TABII; // Inferior Izquierda
	TArray<ABloque*> TABID; // Inferior Derecha
	
	float VelocidadInterpolacion = 1.0f;

	void ClasificarBloquesPorSector();

	void MoverBloquesAlMargen();
	void MoverSectorAlMargen(TArray<ABloque*>& Sector, const FVector& Inicio, const FVector& Direccion, float Espaciado);

private:
	TArray<TArray<int32>> Mapa;

	void GenerarMapaBase();
	void AbrirCaminosAleatorios();
	void SpawnearBloques();
	void SpawnearBloquesSimple();

	bool EsValida(int32 F, int32 C) const;
	FVector PosicionOrigenLaberinto;

	FTimerHandle TimerMoverBloques;

	TArray<FBloqueMovimientoData> BloquesEnMovimiento;

	bool bMoverBloques = false;


	void PrepararMovimientoBloquesAlMargen();
	void ActualizarMovimientoBloques(float DeltaTime);

	void PrepararSectorParaMovimiento(TArray<ABloque*>& Sector, const FVector& Inicio, const FVector& Direccion, float Espaciado);

	bool EsBorde(int32 Fila, int32 Columna) const;
	FVector ObtenerPosicionMundo(int32 Fila, int32 Columna) const;

	*/
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void CrearBloquesEnEscena();
};
