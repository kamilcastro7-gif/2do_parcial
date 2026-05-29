#include "Bonus.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"

ABonus* ABonus::Instancia = nullptr;

ABonus::ABonus()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBonus"));
	RootComponent = Mesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaBonus(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'")
	);

	if (MallaBonus.Succeeded())
	{
		Mesh->SetStaticMesh(MallaBonus.Object);
	}
}

ABonus* ABonus::GetInstancia(UWorld* World)
{
	if (!World)
	{
		return nullptr;
	}

	if (Instancia == nullptr || !IsValid(Instancia))
	{
		const FVector SpawnLocation(
			FMath::FRandRange(-500.f, 500.f),
			FMath::FRandRange(-500.f, 500.f),
			FMath::FRandRange(100.f, 250.f)
		);

		const FRotator SpawnRotation = FRotator::ZeroRotator;

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride =
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		Instancia = World->SpawnActor<ABonus>(
			ABonus::StaticClass(),
			SpawnLocation,
			SpawnRotation,
			SpawnParams
		);
	}

	return Instancia;
}

void ABonus::BeginPlay()
{
	Super::BeginPlay();

	if (Instancia == nullptr)
	{
		Instancia = this;
	}
}

void ABonus::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (Instancia == this)
	{
		Instancia = nullptr;
	}

	Super::EndPlay(EndPlayReason);
}

void ABonus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}