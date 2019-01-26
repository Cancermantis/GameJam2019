// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DecorBase.generated.h"

UENUM(BlueprintType)
enum class EDecorType : uint8
{
	Floor,
	Wall
};

UCLASS()
class GAMEJAM2019_API ADecorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecorBase();

	/*Type of decor that this is considered to be*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Decor") EDecorType DecorType = EDecorType::Floor;

	UFUNCTION(BlueprintCallable, Category = "Decor") void AssignColor(FColor Color);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
