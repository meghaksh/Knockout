// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class KNOCKOUT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// UPROPERTY(EditAnywhere)
	// int32 MyInt = 99;

	// UPROPERTY(EditAnywhere)
	// float MyFloat = 0.0001;

	// UPROPERTY(EditAnywhere)
	// bool MyBool = true;

	// UPROPERTY(EditAnywhere)
	// float IFA = 0.0;

	// UPROPERTY(EditAnywhere)
	// float IFB = 0.0;

	// UPROPERTY(EditAnywhere)
	// float IFAPLUSIFB = 0.0;

	// UPROPERTY(EditAnywhere)
	// FVector MyVector = FVector(1,2,3);

	// UPROPERTY(EditAnywhere)
	// float XOfMyVector = 0;

	UPROPERTY(EditAnywhere, Category="Moving")
	FVector PlatformVelocity = FVector(100,0,0);
	UPROPERTY(EditAnywhere, Category="Moving")
	float MaxMovedDistanceAllowed = 1000;
	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity;
	// UPROPERTY(VisibleAnywhere)
	// float DistanceMoved = -1;


	FVector StartLocation;


	void MovePlatform(float DeltaTime);

	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn() const;

	float GetDistanceMoved() const;
};
