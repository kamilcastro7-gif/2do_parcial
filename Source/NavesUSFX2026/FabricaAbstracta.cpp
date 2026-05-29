// Fill out your copyright notice in the Description page of Project Settings.

#include "FabricaAbstracta.h"
#include "Engine/World.h"

// Inclusiones correctas de las dos familias activas
#include "CriaturaEspacial.h"
#include "CriaturaAlienigena.h"

ACriatura* UFabricaNiveles::CrearCriatura(FString TipoFamilia, UWorld* World, FVector Ubicacion)
{
	if (!World) return nullptr;

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	ACriatura* NuevaCriatura = nullptr;

	// La fábrica ahora procesa Espacial y Alienígena
	if (TipoFamilia.Equals(TEXT("Espacial"), ESearchCase::IgnoreCase))
	{
		NuevaCriatura = World->SpawnActor<ACriaturaEspacial>(ACriaturaEspacial::StaticClass(), Ubicacion, FRotator::ZeroRotator, SpawnParams);
	}
	else if (TipoFamilia.Equals(TEXT("Alienigena"), ESearchCase::IgnoreCase))
	{
		NuevaCriatura = World->SpawnActor<ACriaturaAlienigena>(ACriaturaAlienigena::StaticClass(), Ubicacion, FRotator::ZeroRotator, SpawnParams);
	}

	return NuevaCriatura;
}