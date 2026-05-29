// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NavesUSFX2026GameMode.generated.h"

class ABonus;
class AGeneradorLaberinto;
class AJefeNave; // Declaración hacia adelante segura

UCLASS(MinimalAPI)
class ANavesUSFX2026GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANavesUSFX2026GameMode();

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	AGeneradorLaberinto* GeneradorLaberintoInstancia;

	UPROPERTY()
	ABonus* BonusInstancia;

	// Puntero para guardar la referencia del jefe de forma segura
	UPROPERTY()
	AJefeNave* JefePrincipalInstancia;

public:
	virtual void Tick(float DeltaTime) override;
};



