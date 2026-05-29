// Fill out your copyright notice in the Description page of Project Settings.

#include "JefeNave.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
// Incluimos la fábrica dedicada
#include "FabricaEnemigos.h"

AJefeNave::AJefeNave()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaCapsulaAncha(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));

	mallaJefe = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaJefe"));
	RootComponent = mallaJefe;

	if (MallaCapsulaAncha.Succeeded())
	{
		mallaJefe->SetStaticMesh(MallaCapsulaAncha.Object);
	}
}

void AJefeNave::BeginPlay()
{
	Super::BeginPlay();
}

AActor* AJefeNave::OrdenarSpawnSecuaz(FString TipoSecuaz, FVector UbicacionSpawn)
{
	// Delegamos la responsabilidad por completo a la clase Factory dedicada
	return UFabricaEnemigos::FabricarSecuaz(TipoSecuaz, GetWorld(), UbicacionSpawn);
}

