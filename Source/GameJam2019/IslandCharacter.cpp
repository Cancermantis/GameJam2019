// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandCharacter.h"

// Sets default values
AIslandCharacter::AIslandCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIslandCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIslandCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AIslandCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

