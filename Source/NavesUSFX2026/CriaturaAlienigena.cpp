// Fill out your copyright notice in the Description page of Project Settings.

#include "CriaturaAlienigena.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

ACriaturaAlienigena::ACriaturaAlienigena()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (Malla.Succeeded() && mallaCriatura)
	{
		mallaCriatura->SetStaticMesh(Malla.Object);
	}
}