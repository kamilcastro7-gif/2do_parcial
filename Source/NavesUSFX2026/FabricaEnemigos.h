// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FabricaEnemigos.generated.h"

UCLASS()
class NAVESUSFX2026_API UFabricaEnemigos : public UObject
{
	GENERATED_BODY()

public:
	
	static AActor* FabricarSecuaz(FString TipoSecuaz, UWorld* World, FVector UbicacionSpawn);
};
