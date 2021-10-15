// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// 생성자에 staticMesh 컴포넌트 붙이자.
	// 필요속성 : staticmesh component
	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	// 사용하기위한 staticmesh 데이터도 로드해서 붙여주자.
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
	// 총알이 계속 위로 올라가도록 하고 싶다.
	// P = P0 + vt
	FVector P0 = GetActorLocation();
	FVector vt = FVector::UpVector * speed * DeltaTime;
	FVector P = P0 + vt;
	SetActorLocation(P);
}

