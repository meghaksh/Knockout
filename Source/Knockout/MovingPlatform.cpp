// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	//IFAPLUSIFB  = IFA + IFB;

	//XOfMyVector = MyVector.X;

	//SetActorLocation(MyVector);

	StartLocation = GetActorLocation();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//FVector MyLocalVector = MyVector;
	//MyLocalVector.Z += 100;
	//MyVector.Y += 1;
	//SetActorLocation(MyLocalVector);

	//Moveing platform forward
		//1.Get current location
	FVector CurrentLocation = GetActorLocation();
		//2. Add vector to the current location
	CurrentLocation += (PlatformVelocity * DeltaTime);
		//3. Set the location
	SetActorLocation(CurrentLocation);

	//Moving platform backward
		//1. Check how far it has gone
		float DistanceMoved = FVector::Dist(CurrentLocation, StartLocation);
		//2. Reverse direction of motion if too far. 
		if(DistanceMoved>MaxMovedDistanceAllowed){
			
			FVector MoveDirection = PlatformVelocity.GetSafeNormal();
			StartLocation = StartLocation + MoveDirection * MaxMovedDistanceAllowed;
			SetActorLocation(StartLocation);
			PlatformVelocity = -PlatformVelocity;
		}

}

