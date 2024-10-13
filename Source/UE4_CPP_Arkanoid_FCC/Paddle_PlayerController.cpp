// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle_PlayerController.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "Paddle.h"
#include "Ball.h"

APaddle_PlayerController::APaddle_PlayerController()
{
}

void APaddle_PlayerController::BeginPlay()
{
	MyPawn = Cast<APaddle>(GetPawn());

	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams ViewParams;
	SetViewTarget(CameraActors[0]);

	SpawnNewBall();
}

void APaddle_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);

	InputComponent->BindAxis("MoveHorizontal", this, &APaddle_PlayerController::MoveHorizontal);
	InputComponent->BindAction("Launch", IE_Pressed, this, &APaddle_PlayerController::Launch);
}

void APaddle_PlayerController::MoveHorizontal(float AxisValue)
{
	if (!MyPawn)
		return;
	MyPawn->MoveHorizontal(AxisValue);
}

void APaddle_PlayerController::Launch()
{
	if (!MyBall)
		return;
	MyBall->Launch();
}

void APaddle_PlayerController::SpawnNewBall()
{
	if (!MyBall)
		MyBall = nullptr;

	if (BallObj)
	{
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotation, SpawnParams);
	}
}
