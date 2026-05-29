// Fill out your copyright notice in the Description page of Project Settings.

#include "FabricaEnemigos.h"
#include "Engine/World.h"

// Incluimos todas las clases independientes de los enemigos
#include "Enemigo.h"
#include "EnemigoRapido.h"
#include "EnemigoTanque.h"

AActor* UFabricaEnemigos::FabricarSecuaz(FString TipoSecuaz, UWorld* World, FVector UbicacionSpawn)
{
	if (!World) return nullptr;

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AActor* SecuazCreado = nullptr;

	// La fábrica evalúa el string y ejecuta la orden de spawneo adecuada
	if (TipoSecuaz.Equals(TEXT("Rapido"), ESearchCase::IgnoreCase))
	{
		SecuazCreado = World->SpawnActor<AEnemigoRapido>(AEnemigoRapido::StaticClass(), UbicacionSpawn, FRotator::ZeroRotator, SpawnParams);
	}
	else if (TipoSecuaz.Equals(TEXT("Tanque"), ESearchCase::IgnoreCase))
	{
		SecuazCreado = World->SpawnActor<AEnemigoTanque>(AEnemigoTanque::StaticClass(), UbicacionSpawn, FRotator::ZeroRotator, SpawnParams);
	}
	else if (TipoSecuaz.Equals(TEXT("Comun"), ESearchCase::IgnoreCase))
	{
		SecuazCreado = World->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), UbicacionSpawn, FRotator::ZeroRotator, SpawnParams);
	}

	if (SecuazCreado)
	{
		UE_LOG(LogTemp, Log, TEXT("FabricaEnemigos: Se creó con éxito el enemigo tipo [%s]"), *TipoSecuaz);
	}

	return SecuazCreado;
}
