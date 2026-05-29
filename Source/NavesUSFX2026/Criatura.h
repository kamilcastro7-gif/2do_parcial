// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Criatura.generated.h"

class UStaticMeshComponent;

UCLASS()
class NAVESUSFX2026_API ACriatura : public AActor
{
	GENERATED_BODY()

public:
	ACriatura();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* mallaCriatura;

protected:
	virtual void BeginPlay() override;
};
