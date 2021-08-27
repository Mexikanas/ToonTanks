// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	
    GetWorld()->GetTimerManager().SetTimer
    (
        FireRateTimerHandle, 
        this, 
        &APawnTurret::CheckFireCondition, 
        FireRate, 
        true
    );

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::CheckFireCondition()
{
    if (!PlayerPawn) {return;}

    if (ReturnDistanceToPlayer() <= FireRange)
    {
        Fire(); 
    }
      
}

float APawnTurret::ReturnDistanceToPlayer()
{
    if (!PlayerPawn) {return 0.f;}

    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}

void APawnTurret::HandleDestruction()
{
    // Call base pawn class HandleDestruction to play effects
    Super::HandleDestruction();
    Destroy();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if(!PlayerPawn || ReturnDistanceToPlayer() > FireRange) {return;}
    UE_LOG(LogTemp, Warning, TEXT("Turn to player"));
    RotateTurret(PlayerPawn->GetActorLocation());
}