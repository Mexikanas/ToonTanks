// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProjectileBase.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit); 
	RootComponent = ProjectileMesh;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->InitialSpeed = MovementSpeed;
	ProjectileMovement->MaxSpeed = MovementSpeed;
	InitialLifeSpan = 3.f;
}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();

	
}

void AProjectileBase::OnHit
(
	UPrimitiveComponent* HitComp, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	FVector NormalImpulse, 
	const FHitResult& Hit
)
{
	AActor* MyOwner = GetOwner();
	if (!MyOwner) {return;}
	// if the other actor ISN'T self OR Owner AND exists, then apply damage
	if (OtherActor && OtherActor != this && OtherActor != MyOwner)
	{
		UGameplayStatics::ApplyDamage
		(
			OtherActor,
			Damage,
			MyOwner->GetInstigatorController(),
			this,
			DamageType
		);
	}
	// Play a bunch of effects here during the polish phase - TODO
	Destroy();
}