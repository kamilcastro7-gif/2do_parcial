// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Criatura.h"
#include "FabricaAbstracta.generated.h"

/**
 * Clase base Abstracta de la Fábrica
 */
UCLASS(Abstract)
class NAVESUSFX2026_API UFabricaAbstracta : public UObject
{
	GENERATED_BODY()

public:
	// Método virtual puro conceptual para que las subfábricas hereden la firma
	virtual ACriatura* CrearCriatura(FString TipoFamilia, UWorld* World, FVector Ubicacion) { return nullptr; }
};

/**
 * Fábrica Concreta que implementa la generación de familias por Niveles
 */
UCLASS()
class NAVESUSFX2026_API UFabricaNiveles : public UFabricaAbstracta
{
	GENERATED_BODY()

public:
	// Implementación final que fabrica CriaturaEspacial y CriaturaAlienigena
	virtual ACriatura* CrearCriatura(FString TipoFamilia, UWorld* World, FVector Ubicacion) override;
};
