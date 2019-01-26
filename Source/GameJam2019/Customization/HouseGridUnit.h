// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DecorBase.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "HouseGridUnit.generated.h"

UCLASS(BlueprintType)
class GAMEJAM2019_API AHouseGridUnit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHouseGridUnit();

	/*Type of decor that can be assigned to this grid slot*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Settings") EDecorType DecorType = EDecorType::Floor;

	/*Function for assigning an item the player is holding to a grid square. Returns false if the item can't be assigned*/
	UFUNCTION(BlueprintCallable, Category = "Decor") bool SetAssignedDecor(TSubclassOf<ADecorBase> DecorClass);

	/*Retrieves a reference to the assigned decor object so that external objects can call functions on it*/
	UFUNCTION(BlueprintCallable, Category = "Decor") ADecorBase* GetAssignedDecor();

	/*Removes the assigned decor object instance, converting it into the class subtype for storage*/
	UFUNCTION(BlueprintCallable, Category = "Decor") TSubclassOf<ADecorBase> RetrieveAssignedDecor();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Settings") UBoxComponent* DetectionVolume = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	ADecorBase* AssignedDecor;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
