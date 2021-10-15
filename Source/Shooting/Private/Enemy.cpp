// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "ShootPlayer.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	// Target À» Ã£ÀÚ
	target = Cast<AShootPlayer>(UGameplayStatics::GetActorOfClass(GetWorld(), AShootPlayer::StaticClass()));

	dir = target->GetActorLocation() - GetActorLocation();
	dir.Normalize();

}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	FVector P = GetActorLocation() + dir * speed * DeltaTime;
	SetActorLocation(P);
}

