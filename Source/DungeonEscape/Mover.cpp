// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"


// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	AActor* owner = GetOwner();
	StartLocation = owner->GetActorLocation();
	
	SetShouldMove(false);
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
 

	
	FVector currentLocation = GetOwner()->GetActorLocation();

	ReachedTarget = currentLocation.Equals(TargetLocation);

	if (!ReachedTarget)
	{
		float Speed = MoveOffset.Length() / MoveTime;

		FVector NewLocation = FMath::VInterpConstantTo(currentLocation, TargetLocation, DeltaTime, Speed);

		GetOwner()->SetActorLocation(NewLocation);


	}

	
	// ...
}

void UMover::SetShouldMove(bool move)
{
	ShouldMove = move;

	if (ShouldMove)
	{
		TargetLocation = StartLocation + MoveOffset;

	}
	else
	{
		TargetLocation = StartLocation;
	}

}

bool UMover::GetShouldMove()
{
	return ShouldMove;
}

 
