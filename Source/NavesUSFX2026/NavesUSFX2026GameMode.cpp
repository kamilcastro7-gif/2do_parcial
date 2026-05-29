// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesUSFX2026GameMode.h"
#include "NavesUSFX2026Pawn.h"
#include "GeneradorLaberinto.h"
#include "Engine/World.h"
#include "Bloque.h"
#include "Bonus.h" 
#include "EnemigoAnimal.h"
#include "Kismet/GameplayStatics.h"

// Inclusiones de sistemas de fábricas
#include "JefeNave.h"
#include "FabricaAbstracta.h"

ANavesUSFX2026GameMode::ANavesUSFX2026GameMode()
{
	DefaultPawnClass = ANavesUSFX2026Pawn::StaticClass();
	GeneradorLaberintoInstancia = nullptr;
	JefePrincipalInstancia = nullptr;
}

void ANavesUSFX2026GameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("GameMode: World no valido."));
		return;
	}

	FVector PosicionSpawn = FVector::ZeroVector;
	FRotator RotacionSpawn = FRotator::ZeroRotator;

	FActorSpawnParameters ParmsSeguros;
	ParmsSeguros.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// 1. Spawneo del Generador del Laberinto
	GeneradorLaberintoInstancia = World->SpawnActor<AGeneradorLaberinto>(
		AGeneradorLaberinto::StaticClass(),
		PosicionSpawn,
		RotacionSpawn,
		ParmsSeguros
	);

	// 2. Lógica de tus Bonus
	for (int i = 0; i < 30; i++)
	{
		ABonus* BonusActual = ABonus::GetInstancia(World);
	}

	// 3. Lógica de tu EnemigoAnimal
	AEnemigoAnimal* EnemigoActual = World->SpawnActor<AEnemigoAnimal>(
		AEnemigoAnimal::StaticClass(),
		FVector(0.f, -200.f, 200.f),
		FRotator::ZeroRotator,
		ParmsSeguros
	);

	// 4. Posicionamiento dinámico frente al jugador para el Jefe
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(World, 0);
	FVector UbicacionBaseJefe = FVector(600.f, 0.f, 200.f);

	if (PlayerPawn)
	{
		FVector UbicacionJugador = PlayerPawn->GetActorLocation();
		UbicacionBaseJefe = UbicacionJugador + FVector(700.f, 0.f, 50.f);
	}

	// 5. Spawneo del Jefe (Factory Method)
	JefePrincipalInstancia = World->SpawnActor<AJefeNave>(
		AJefeNave::StaticClass(),
		UbicacionBaseJefe,
		FRotator::ZeroRotator,
		ParmsSeguros
	);

	if (JefePrincipalInstancia)
	{
		JefePrincipalInstancia->OrdenarSpawnSecuaz(TEXT("Rapido"), UbicacionBaseJefe + FVector(0.f, 300.f, 0.f));
		JefePrincipalInstancia->OrdenarSpawnSecuaz(TEXT("Tanque"), UbicacionBaseJefe + FVector(0.f, -300.f, 0.f));
		JefePrincipalInstancia->OrdenarSpawnSecuaz(TEXT("Comun"), UbicacionBaseJefe + FVector(300.f, 0.f, 0.f));
	}

	// 6. ABSTRACT FACTORY (Familias por niveles: Espacial y Alienígena)
	UFabricaNiveles* FabricaCriaturas = NewObject<UFabricaNiveles>();

	if (FabricaCriaturas)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameMode: Abstract Factory ejecutándose..."));

		// Generamos un miembro de la familia Espacial (Cono) a la derecha
		FabricaCriaturas->CrearCriatura(TEXT("Espacial"), World, UbicacionBaseJefe + FVector(500.f, 200.f, 0.f));

		// Generamos un miembro de la familia Alienígena (Esfera) a la izquierda
		FabricaCriaturas->CrearCriatura(TEXT("Alienigena"), World, UbicacionBaseJefe + FVector(500.f, -200.f, 0.f));
	}
}

void ANavesUSFX2026GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


