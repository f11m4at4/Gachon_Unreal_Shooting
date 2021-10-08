// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ShootPlayer.generated.h"


// Static Mesh Component 를 추가하고 싶다.
UCLASS()
class SHOOTING_API AShootPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShootPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Callback Function
	void Horizontal(float v);
	void Vertical(float v);
public:
	// StaticMesh Component
	UPROPERTY(VisibleAnywhere, Category=BodyMesh)
	class UStaticMeshComponent* body;

	UPROPERTY(BlueprintReadWrite, Category=Setting)
	FVector dir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	float speed = 500;
};
