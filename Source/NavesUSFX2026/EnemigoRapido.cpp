// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemigoRapido.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

AEnemigoRapido::AEnemigoRapido()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaCapsulaAngosta(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));

	mallaEnemigoRapido = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigoRapido"));
	RootComponent = mallaEnemigoRapido;
	mallaEnemigoRapido->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);

	if (MallaCapsulaAngosta.Succeeded())
	{
		mallaEnemigoRapido->SetStaticMesh(MallaCapsulaAngosta.Object);
	}
}

void AEnemigoRapido::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemigoRapido::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

