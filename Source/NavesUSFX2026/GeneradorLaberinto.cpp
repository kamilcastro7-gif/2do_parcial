// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorLaberinto.h"
#include "Bloque.h"


// Sets default values
AGeneradorLaberinto::AGeneradorLaberinto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //PosicionOrigenLaberinto = FVector(-1600.0f, -1600.0f, 200.0f);
}

// Called when the game starts or when spawned
void AGeneradorLaberinto::BeginPlay()
{
	Super::BeginPlay();

	//GenerarMapaBase();
	//AbrirCaminosAleatorios();
	//SpawnearBloques();
    //SpawnearBloquesSimple();
    //GetWorldTimerManager().SetTimer(TimerMoverBloques, this, &AGeneradorLaberinto::MoverBloquesAlMargen, 3.0f, false);
}

/*
void AGeneradorLaberinto::ClasificarBloquesPorSector()
{
    TABSI.Empty();
    TABSD.Empty();
    TABII.Empty();
    TABID.Empty();

    if (TABloques.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No hay bloques en TABloques para clasificar."));
        return;
    }

    FVector CentroLaberinto = GetActorLocation() + FVector(
        ((Filas - 1) * TamCelda) * 0.5f,
        ((Columnas - 1) * TamCelda) * 0.5f,
        0.0f
    );

    for (ABloque* Bloque : TABloques)
    {
        if (!Bloque)
        {
            continue;
        }

        FVector Pos = Bloque->GetActorLocation();

        bool bIzquierda = Pos.X < CentroLaberinto.X;
        bool bSuperior = Pos.Y < CentroLaberinto.Y;

        if (bSuperior && bIzquierda)
        {
            TABSI.Add(Bloque);
        }
        else if (bSuperior && !bIzquierda)
        {
            TABSD.Add(Bloque);
        }
        else if (!bSuperior && bIzquierda)
        {
            TABII.Add(Bloque);
        }
        else
        {
            TABID.Add(Bloque);
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("TABSI: %d bloques"), TABSI.Num());
    UE_LOG(LogTemp, Warning, TEXT("TABSD: %d bloques"), TABSD.Num());
    UE_LOG(LogTemp, Warning, TEXT("TABII: %d bloques"), TABII.Num());
    UE_LOG(LogTemp, Warning, TEXT("TABID: %d bloques"), TABID.Num());
}

void AGeneradorLaberinto::MoverSectorAlMargen(TArray<ABloque*>& Sector, const FVector& Inicio, const FVector& Direccion, float Espaciado)
{
    for (int32 i = 0; i < Sector.Num(); ++i)
    {
        ABloque* Bloque = Sector[i];
        if (!Bloque)
        {
            continue;
        }

        FVector NuevaPosicion = Inicio + (Direccion * Espaciado * i);
        Bloque->SetActorLocation(NuevaPosicion);
    }
}

void AGeneradorLaberinto::MoverBloquesAlMargen()
{
    const float MargenExtra = TamCelda * 2.0f;
    const float Espaciado = TamCelda * 1.1f;

    FVector Origen = GetActorLocation();

    float Ancho = (Filas - 1) * TamCelda;
    float Alto = (Columnas - 1) * TamCelda;

    FVector EsquinaSuperiorIzquierda = Origen + FVector(-MargenExtra, -MargenExtra, 0.0f);
    FVector EsquinaSuperiorDerecha = Origen + FVector(Ancho + MargenExtra, -MargenExtra, 0.0f);
    FVector EsquinaInferiorIzquierda = Origen + FVector(-MargenExtra, Alto + MargenExtra, 0.0f);
    FVector EsquinaInferiorDerecha = Origen + FVector(Ancho + MargenExtra, Alto + MargenExtra, 0.0f);

    MoverSectorAlMargen(TABSI, EsquinaSuperiorIzquierda, FVector(1.0f, 0.0f, 0.0f), Espaciado);
    MoverSectorAlMargen(TABSD, EsquinaSuperiorDerecha, FVector(1.0f, 0.0f, 0.0f), Espaciado);
    MoverSectorAlMargen(TABII, EsquinaInferiorIzquierda, FVector(0.0f, -1.0f, 1.0f), Espaciado);
    MoverSectorAlMargen(TABID, EsquinaInferiorDerecha, FVector(-1.0f, 0.0f, 1.0f), Espaciado);

    UE_LOG(LogTemp, Warning, TEXT("Bloques movidos a los margenes del escenario."));
}

void AGeneradorLaberinto::GenerarMapaBase()
{
	Mapa.SetNum(Filas);

	for (int32 F = 0; F < Filas; ++F)
	{
		Mapa[F].SetNum(Columnas);

		for (int32 C = 0; C < Columnas; ++C)
		{
			Mapa[F][C] = 1;
		}
	}
}

void AGeneradorLaberinto::AbrirCaminosAleatorios()
{
    for (int32 F = 1; F < Filas - 1; F += 2)
    {
        for (int32 C = 1; C < Columnas - 1; C += 2)
        {
            Mapa[F][C] = 0;

            TArray<FIntPoint> Direcciones;
            Direcciones.Add(FIntPoint(-1, 0));
            Direcciones.Add(FIntPoint(1, 0));
            Direcciones.Add(FIntPoint(0, -1));
            Direcciones.Add(FIntPoint(0, 1));

            int32 Index = FMath::RandRange(0, Direcciones.Num() - 1);
            FIntPoint Dir = Direcciones[Index];

            int32 NF = F + Dir.X;
            int32 NC = C + Dir.Y;

            if (EsValida(NF, NC) && NF > 0 && NF < Filas - 1 && NC > 0 && NC < Columnas - 1)
            {
                Mapa[NF][NC] = 0;
            }
        }
    }
}
*/
/*
void AGeneradorLaberinto::SpawnearBloques()
{
    if (!GetWorld())
    {
        UE_LOG(LogTemp, Warning, TEXT("World no valido."));
        return;
    }

    TABloques.Empty();

    for (int32 F = 0; F < Filas; ++F)
    {
        for (int32 C = 0; C < Columnas; ++C)
        {
            if (Mapa[F][C] == 1)
            {
				ABloque* Bloque = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(),
                    ObtenerPosicionMundo(F, C),
                    FRotator::ZeroRotator
                );

                if (Bloque)
                {
                    TABloques.Add(Bloque);
                }
            }
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Bloques spawneados: %d"), TABloques.Num());
}
*/

//void AGeneradorLaberinto::SpawnearBloquesSimple()
//{
//    if (!GetWorld())
//    {
//        UE_LOG(LogTemp, Warning, TEXT("World no valido."));
//        return;
//    }
//
//    TABloques.Empty();
//
//    for (int32 nb = 0; nb < 50; nb++)
//    {
//		// Generar posiciones aleatorias dentro del rango del laberinto
//		int32 F = FMath::RandRange(0, Filas - 1);
//		int32 C = FMath::RandRange(0, Columnas - 1);
//
//        ABloque* Bloque = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(),
//            ObtenerPosicionMundo(F, C),
//            FRotator::ZeroRotator
//        );
//
//        if (Bloque)
//        {
//            TABloques.Add(Bloque);
//        }
//    }
//
//    /*
//    for (int32 F = 0; F < Filas; ++F)
//    {
//        for (int32 C = 0; C < Columnas; ++C)
//        {
//            if (Mapa[F][C] == 1)
//            {
//                ABloque* Bloque = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(),
//                    ObtenerPosicionMundo(F, C),
//                    FRotator::ZeroRotator
//                );
//
//                if (Bloque)
//                {
//                    TABloques.Add(Bloque);
//                }
//            }
//        }
//    }
//    */
//    UE_LOG(LogTemp, Warning, TEXT("Bloques spawneados: %d"), TABloques.Num());
//}


/*
bool AGeneradorLaberinto::EsValida(int32 F, int32 C) const
{
	return F >= 0 && F < Filas && C >= 0 && C < Columnas;
}
*/
/*
void AGeneradorLaberinto::PrepararMovimientoBloquesAlMargen()
{
    BloquesEnMovimiento.Empty();

    const float MargenExtra = TamCelda * 2.0f;
    const float Espaciado = TamCelda * 1.1f;

    const FVector Origen = GetActorLocation();
    const float Ancho = (Filas - 1) * TamCelda;
    const float Alto = (Columnas - 1) * TamCelda;

    const FVector SI = Origen + FVector(-MargenExtra, -MargenExtra, 0.0f);
    const FVector SD = Origen + FVector(Ancho + MargenExtra, -MargenExtra, 0.0f);
    const FVector II = Origen + FVector(-MargenExtra, Alto + MargenExtra, 0.0f);
    const FVector ID = Origen + FVector(Ancho + MargenExtra, Alto + MargenExtra, 0.0f);

    PrepararSectorParaMovimiento(TABSI, SI, FVector(-1.0f, 1.0f, 1.0f), Espaciado);
    PrepararSectorParaMovimiento(TABSD, SD, FVector(1.0f, -1.0f, 1.0f), Espaciado);
    PrepararSectorParaMovimiento(TABII, II, FVector(1.0f, 1.0f, 1.0f), Espaciado);
    PrepararSectorParaMovimiento(TABID, ID, FVector(-1.0f, -1.0f, 1.0f), Espaciado);

    bMoverBloques = true;

    UE_LOG(LogTemp, Warning, TEXT("Movimiento paulatino iniciado."));
}
*/
/*
void AGeneradorLaberinto::ActualizarMovimientoBloques(float DeltaTime)
{
    bool bTodosLlegaron = true;

    for (FBloqueMovimientoData& Data : BloquesEnMovimiento)
    {
        if (!Data.Bloque)
        {
            continue;
        }

        FVector Actual = Data.Bloque->GetActorLocation();
        FVector Nuevo = FMath::VInterpTo(Actual, Data.Destino, DeltaTime, VelocidadInterpolacion);

        Data.Bloque->SetActorLocation(Nuevo);

        float Distancia = FVector::Dist(Nuevo, Data.Destino);
        if (Distancia > 2.0f)
        {
            bTodosLlegaron = false;
        }
        else
        {
            Data.Bloque->SetActorLocation(Data.Destino);
        }
    }

    if (bTodosLlegaron)
    {
        bMoverBloques = false;
        UE_LOG(LogTemp, Warning, TEXT("Todos los bloques llegaron al margen."));
    }
}

void AGeneradorLaberinto::PrepararSectorParaMovimiento(TArray<ABloque*>& Sector, const FVector& Inicio, const FVector& Direccion, float Espaciado)
{
    for (int32 i = 0; i < Sector.Num(); ++i)
    {
        ABloque* Bloque = Sector[i];
        if (!Bloque)
        {
            continue;
        }

        FBloqueMovimientoData Data;
        Data.Bloque = Bloque;
        Data.Destino = Inicio + (Direccion * Espaciado * i);

        BloquesEnMovimiento.Add(Data);
    }
}

bool AGeneradorLaberinto::EsBorde(int32 Fila, int32 Columna) const
{
    return (Fila == 0 || Fila == Filas - 1 || Columna == 0 || Columna == Columnas - 1);
}

FVector AGeneradorLaberinto::ObtenerPosicionMundo(int32 F, int32 C) const
{
    //return GetActorLocation() + FVector(F * TamCelda, C * TamCelda, 0.0f);
    //return GetActorLocation() + FVector(F * TamCelda, C * TamCelda, 400.0f);
    return PosicionOrigenLaberinto + FVector(F * TamCelda, C * TamCelda, 50.0f);
}
*/
// Called every frame
void AGeneradorLaberinto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    /*
    if (bMoverBloques)
    {
        ActualizarMovimientoBloques(DeltaTime);
    }
    */
}

void AGeneradorLaberinto::CrearBloquesEnEscena()
{
    UWorld* World = GetWorld();
    if (!World) return;

    /*    FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;*/

    const FVector Origin = FVector::ZeroVector;

    for (int32 i = 0; i < CantidadBloques; ++i)
    {
        const FVector RandomOffset(
            FMath::FRandRange(-LimitesMapa.X, LimitesMapa.X),
            FMath::FRandRange(-LimitesMapa.Y, LimitesMapa.Y),
            FMath::FRandRange(0.f, LimitesMapa.Z)
        );

        const FVector SpawnLocation = UbicacionMedia + RandomOffset;
        const FRotator SpawnRotation = FRotator::ZeroRotator;

        ABloque* BloqueNuevo = World->SpawnActor<ABloque>(ABloque::StaticClass(), SpawnLocation, SpawnRotation);

        if (BloqueNuevo)
        {
            TABloques.Add(BloqueNuevo);
        }
    }
}
