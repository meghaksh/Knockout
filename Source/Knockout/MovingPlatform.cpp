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

	FString name = GetName();		//gives the name of the actor.

	UE_LOG(LogTemp, Display, TEXT("Configured Moved Distance : %s"), *name);
	
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector MyLocalVector = MyVector;
	//MyLocalVector.Z += 100;
	//MyVector.Y += 1;
	//SetActorLocation(MyLocalVector);


	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

//A prefix is for the Actor
void AMovingPlatform :: MovePlatform(float DeltaTime)
{
	// //Moveing platform forward
	// 	//1.Get current location
	// FVector CurrentLocation = GetActorLocation();
	// 	//2. Add vector to the current location
	// CurrentLocation += (PlatformVelocity * DeltaTime);
	// 	//3. Set the location
	// SetActorLocation(CurrentLocation);

	//Moving platform backward
		//1. Check how far it has gone
		//float DistanceMoved = FVector::Dist(CurrentLocation, StartLocation);
		//2. Reverse direction of motion if too far. 
		if(ShouldPlatformReturn()){
			// float OverShoot = DistanceMoved - MaxMovedDistanceAllowed;

			// FString name = GetName();
			// UE_LOG(LogTemp, Display, TEXT("OverShoot of the %s : %f"), *name, OverShoot);
			FVector MoveDirection = PlatformVelocity.GetSafeNormal();
			StartLocation = StartLocation + MoveDirection * MaxMovedDistanceAllowed;
			SetActorLocation(StartLocation);
			PlatformVelocity = -PlatformVelocity;
		}else{
			//Moveing platform forward
					//1.Get current location
				FVector CurrentLocation = GetActorLocation();
					//2. Add vector to the current location
				CurrentLocation += (PlatformVelocity * DeltaTime);
					//3. Set the location
				SetActorLocation(CurrentLocation);
		}
}

void AMovingPlatform :: RotatePlatform(float DeltaTime)
{
	//UE_LOG(LogTemp, Display, TEXT("RotatePlatformFunction of %s") ,*GetName());

	//This doesn't work sometime due to complexity with rotation as it wraps around current rotation and we need to reset it. 
	// FRotator CurrentRotation = GetActorRotation();
	// CurrentRotation = CurrentRotation + RotationVelocity * DeltaTime;
	// SetActorRotation(CurrentRotation);

	//This is a better approach than shown above. 
	AddActorLocalRotation( RotationVelocity *  DeltaTime );

}

bool AMovingPlatform :: ShouldPlatformReturn() const
{
	return GetDistanceMoved()>MaxMovedDistanceAllowed;
}

float AMovingPlatform :: GetDistanceMoved() const
{
	return FVector::Dist(GetActorLocation(), StartLocation);
}

