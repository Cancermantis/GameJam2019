// Fill out your copyright notice in the Description page of Project Settings.

#include "DecorBase.h"

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
	
}

// Called every frame
void ADecorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

