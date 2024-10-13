// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Paddle.h"

#include "Paddle_PlayerController.generated.h"

class ABall;

UCLASS()
class UE4_CPP_ARKANOID_FCC_API APaddle_PlayerController : public APlayerController
{
	GENERATED_BODY()

	APaddle_PlayerController();

	UFUNCTION()
	virtual void SetupInputComponent() override;

	UPROPERTY()
	APaddle* MyPawn;

protected:
	virtual void BeginPlay() override;

	void MoveHorizontal(float AxisValue);

	// Ball Reference
	void Launch();

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABall> BallObj;

	ABall* MyBall;

	FVector SpawnLocation = FVector(10.0f, 0.0f, 40.0f);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnParams;

public:
	void SpawnNewBall();
};
