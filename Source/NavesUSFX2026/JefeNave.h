// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JefeNave.generated.h"

class UStaticMeshComponent;

UCLASS()
class NAVESUSFX2026_API AJefeNave : public AActor
{
	GENERATED_BODY()

public:
	AJefeNave();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* mallaJefe;

protected:
	virtual void BeginPlay() override;

public:
	AActor* OrdenarSpawnSecuaz(FString TipoSecuaz, FVector UbicacionSpawn);
};
