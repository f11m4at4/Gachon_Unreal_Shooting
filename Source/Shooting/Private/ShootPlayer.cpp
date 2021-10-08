// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootPlayer.h"

// Sets default values
AShootPlayer::AShootPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// CDO -> Class Default Object

	body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AShootPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShootPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 오른쪽으로 계속 이동하고 싶다.
	// 1. 방향필요
	// 2. 이동하고싶다.
	// P = P0 + vt
	FVector P0 = GetActorLocation();
	FVector vt = dir * speed * DeltaTime;
	FVector P = P0 + vt;
	SetActorLocation(P);
}

// Called to bind functionality to input
void AShootPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &AShootPlayer::Horizontal);
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &AShootPlayer::Vertical);
}

void AShootPlayer::Horizontal(float v)
{
	dir.Y = v;
}

void AShootPlayer::Vertical(float v)
{
	dir.Z = v;
}

