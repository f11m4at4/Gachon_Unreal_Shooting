// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

// Ÿ�������� �̵��ϰ� �ʹ�.
// �ʿ�Ӽ� : Ÿ��

UCLASS()
class SHOOTING_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// �̵��ӵ�
	UPROPERTY(EditAnywhere, Category=Setting)
	float speed = 500;

	UPROPERTY(VisibleAnywhere, Category=BodyMesh)
	class UStaticMeshComponent* bodyMesh;
	
	// �ʿ�Ӽ� : Ÿ��
	UPROPERTY(VisibleAnywhere, Category=Setting)
	class AShootPlayer* target;

	UPROPERTY()
	FVector dir;
};
