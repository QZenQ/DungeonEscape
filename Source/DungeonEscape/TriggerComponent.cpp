// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;	
	 
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();


	if (MoveActor != nullptr)
	{
		Mover = MoveActor->FindComponentByClass<UMover>();
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("MoveActor is not set in %s"), *GetOwner()->GetName());

	if (IsPressurePlate)
	{
		OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapBegin);
		OnComponentEndOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapEnd);
	}
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("PressurePlateActivator"))
	{
		ActivatorCount++;
		if (!IsTriggered)
		{
			Trigger(true);
		}
		 
	}
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor->ActorHasTag("PressurePlateActivator"))
	{
		ActivatorCount--;

		if(IsTriggered && ActivatorCount == 0)
			Trigger(false);	
	}
}

void UTriggerComponent::Trigger(bool isTriggered)
{
	IsTriggered = isTriggered;

	if(Mover)
	{
		Mover->SetShouldMove(IsTriggered);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Mover is not set in %s"), *GetOwner()->GetName());
	}
}

 
 

