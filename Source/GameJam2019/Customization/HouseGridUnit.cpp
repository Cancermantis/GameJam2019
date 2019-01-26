// Fill out your copyright notice in the Description page of Project Settings.

#include "HouseGridUnit.h"

// Sets default values
AHouseGridUnit::AHouseGridUnit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DetectionVolume = CreateDefaultSubobject<UBoxComponent>(FName("DetectionVolume"));
	DetectionVolume->SetBoxExtent(FVector(100.f));
	RootComponent = DetectionVolume;
}

// Called when the game starts or when spawned
void AHouseGridUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHouseGridUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AHouseGridUnit::SetAssignedDecor(TSubclassOf<ADecorBase> DecorClass)
{
	// If the decor type being assigned isn't allowed, or if there's already decor here, return false
	if (AssignedDecor) return false;
	if (Cast<ADecorBase>(DecorClass->ClassDefaultObject)->DecorType != DecorType) return false;

	//Spawn an instance of the desired decor type
	FActorSpawnParameters Parameters;
	Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AssignedDecor = GetWorld()->SpawnActor<ADecorBase>(DecorClass, GetActorTransform());


	// Return false if the assigned decor was not spawned
	if (AssignedDecor == nullptr)
		return false;

	AssignedDecor->AttachToActor(this, FAttachmentTransformRules::SnapToTargetIncludingScale);

	return true;
}

ADecorBase* AHouseGridUnit::GetAssignedDecor()
{
	return AssignedDecor;
}

TSubclassOf<ADecorBase> AHouseGridUnit::RetrieveAssignedDecor()
{
	TSubclassOf<ADecorBase> OutClass = nullptr;

	if (!AssignedDecor) return OutClass;

	//Get the class of the assigned object
	OutClass = AssignedDecor->GetClass();

	//Destroy the instance of the object
	AssignedDecor->SetLifeSpan(.001f);

	//Clear the reference to the instance of the object
	AssignedDecor = nullptr;

	return OutClass;
}