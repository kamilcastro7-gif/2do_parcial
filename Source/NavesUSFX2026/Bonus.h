#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bonus.generated.h"

class UStaticMeshComponent;

UCLASS()
class NAVESUSFX2026_API ABonus : public AActor
{
	GENERATED_BODY()

private:
	ABonus();

public:
	

	static ABonus* GetInstancia(UWorld* World);

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	static ABonus* Instancia;

	UStaticMeshComponent* Mesh;
};