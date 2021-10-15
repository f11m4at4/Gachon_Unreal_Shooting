// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// �����ڿ� staticMesh ������Ʈ ������.
	// �ʿ�Ӽ� : staticmesh component
	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	// ����ϱ����� staticmesh �����͵� �ε��ؼ� �ٿ�����.
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (tempMesh.Succeeded())
	{
		bodyMesh->SetStaticMesh(tempMesh.Object);
	}
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// �Ѿ��� ��� ���� �ö󰡵��� �ϰ� �ʹ�.
	// P = P0 + vt
	FVector P0 = GetActorLocation();
	FVector vt = FVector::UpVector * speed * DeltaTime;
	FVector P = P0 + vt;
	SetActorLocation(P);
}

