// Fill out your copyright notice in the Description page of Project Settings.

#include "CriaturaEspacial.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

ACriaturaEspacial::ACriaturaEspacial()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	if (Malla.Succeeded() && mallaCriatura)
	{
		mallaCriatura->SetStaticMesh(Malla.Object);
	}
}