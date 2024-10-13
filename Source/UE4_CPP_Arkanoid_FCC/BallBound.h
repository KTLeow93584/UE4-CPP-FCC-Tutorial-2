// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallBound.generated.h"

class UBoxComponent;
class APaddle_PlayerController;

UCLASS()
class UE4_CPP_ARKANOID_FCC_API ABallBound : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABallBound();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* Box_Collision;

	APaddle_PlayerController* PlayerController_Ref;

	UFUNCTION()
	void OnOverlapBegin(
		class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType,
		bool bFromSweep, const FHitResult& SweepResult
	);

	void DestroyBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
