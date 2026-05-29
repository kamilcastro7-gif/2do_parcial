// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemigoTanque.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

AEnemigoTanque::AEnemigoTanque()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaCilindro(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));

	mallaEnemigoTanque = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigoTanque"));
	RootComponent = mallaEnemigoTanque;
	mallaEnemigoTanque->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);

	if (MallaCilindro.Succeeded())
	{
		mallaEnemigoTanque->SetStaticMesh(MallaCilindro.Object);
	}
}

void AEnemigoTanque::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemigoTanque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

