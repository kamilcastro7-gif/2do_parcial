// Fill ut your copyright notice in the Description page of Project Settings.


#include "EnemigoAnimal.h"
#include "Engine/StaticMesh.h"
#include "Bonus.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AEnemigoAnimal::AEnemigoAnimal()
{
    PrimaryActorTick.bCanEverTick = true;

    // ✅ RUTA CORREGIDA (copia desde Content Browser: Right-click → Copy Reference)
    //static ConstructorHelpers::FObjectFinder<USkeletalMesh> ObjetoEsqueletoEnemigo(
    //    TEXT("SkeletalMesh'/Game/QuadrapedCreatures/Barghest/Meshes/BARGHEST_Skeleton.BARGHEST_Skeleton'"));


    //if (!ObjetoEsqueletoEnemigo.Succeeded())
    //{
    //    UE_LOG(LogTemp, Error, TEXT("❌ BARGHEST_Skeleton NO ENCONTRADO - Verifica ruta!"));
    //    return;  // Sale si no carga
    //}
    //UE_LOG(LogTemp, Warning, TEXT("✅ SkeletalMesh cargado correctamente"));


    // ✅ Verificar que se cargó
    //if (ObjetoEsqueletoEnemigo.Succeeded())
    //{
    //     Crear mesh
    //    esqueletoEnemigo = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("EsqueletoEnemigo"));
    //    RootComponent = esqueletoEnemigo;

    //    esqueletoEnemigo->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);  // Mejor perfil

    //     ✅ ASIGNAR SKELETAL MESH
    //    esqueletoEnemigo->SetSkeletalMesh(ObjetoEsqueletoEnemigo.Object);

    //     ✅ ANIM BLUEPRINT (¡CRÍTICO para ver animación!)
    //    static ConstructorHelpers::FClassFinder<UAnimInstance> AnimClass(TEXT("AnimBlueprint'/Game/Path/TuAnimBP.TuAnimBP_C'"));
    //    if (AnimClass.Succeeded())
    //    {
    //        esqueletoEnemigo->SetAnimInstanceClass(AnimClass.Class);
    //    }

    //     ✅ VISIBILIDAD Y UPDATE
    //    esqueletoEnemigo->SetVisibility(true);
    //    esqueletoEnemigo->SetHiddenInGame(false);
    //    esqueletoEnemigo->bCastDynamicShadow = true;  // Sombra opcional
    //}
    //else
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("¡ERROR! No se encontró BARGHEST_Skeleton"));
    //}
}

void AEnemigoAnimal::MoverBonus()
{
	ABonus* Bonus = ABonus::GetInstancia(GetWorld());
    Bonus->SetActorLocation(FVector(0.0f, 0.0f, 250.0f));  
}

// Called when the game starts or when spawned
void AEnemigoAnimal::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AEnemigoAnimal::MoverBonus, 5.0f, false);
	
}

// Called every frame
void AEnemigoAnimal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemigoAnimal::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

