// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

// 생성자에 staticMesh 컴포넌트 붙이자.
// 사용하기위한 staticmesh 데이터도 로드해서 붙여주자.
// 총알이 계속 위로 올라가도록 하고 싶다.
// 필요속성 : 이동속도
UCLASS()
class SHOOTING_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// 필요속성 : staticmesh component
	UPROPERTY(VisibleAnywhere, Category=BodyMesh)
	class UStaticMeshComponent* bodyMesh;
	// 필요속성 : 이동속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	float speed = 1000;
};
