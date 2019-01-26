// Fill out your copyright notice in the Description page of Project Settings.

#include "DecorBase.h"
#include "Runtime/Engine/Classes/Components/MeshComponent.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"

// Sets default values
ADecorBase::ADecorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADecorBase::BeginPlay()
{
	Super::BeginPlay();
	TArray<UActorComponent*> Meshes = GetComponentsByClass(UMeshComponent::StaticClass());

	for (UActorComponent* Component : Meshes)
	{
		UMeshComponent* Mesh = Cast<UMeshComponent>(Component);

		UMaterialInterface* MatTemplate = Mesh->GetMaterial(0);

		if (MatTemplate)
		{
			Mesh->CreateAndSetMaterialInstanceDynamicFromMaterial(0, MatTemplate);
		}
	}
}

// Called every frame
void ADecorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADecorBase::AssignColor(FLinearColor Color)
{
	TArray<UActorComponent*> Meshes = GetComponentsByClass(UMeshComponent::StaticClass());

	for (UActorComponent* Component : Meshes)
	{
		UMeshComponent* Mesh = Cast<UMeshComponent>(Component);

		if (UMaterialInstanceDynamic* Mat = Cast<UMaterialInstanceDynamic>(Mesh->GetMaterial(0)))
		{
			Mat->SetVectorParameterValue(FName("CustomColor"), Color);
		}
	}
}