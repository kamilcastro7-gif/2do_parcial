// Fill out your copyright notice in the Description page of Project Settings.

#include "Criatura.h"
#include "Components/StaticMeshComponent.h"

ACriatura::ACriatura()
{
	PrimaryActorTick.bCanEverTick = false;
	mallaCriatura = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaCriatura"));
	RootComponent = mallaCriatura;
	mallaCriatura->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
}

void ACriatura::BeginPlay()
{
	Super::BeginPlay();
}

