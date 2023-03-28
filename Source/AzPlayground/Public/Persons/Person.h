// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Person.generated.h"

enum ESkinColor : uint8
{
	EXTREME_FAIR_SKIN,
	FAIR_SKIN,
	MEDIUM_SKIN,
	OLIVE_SKIN,
	BROWN_SKIN,
	BLACK_SKIN
};

UCLASS()
class AZPLAYGROUND_API APerson : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APerson();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FString FirstName;
	FString LastName;
	FDateTime DateTimeOfBirth;
	ESkinColor SkinColor;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Init(FString AFirstName, FString ALastName, FDateTime ADateTimeOfBirth, ESkinColor ASkinColor = BLACK_SKIN);

	FString GetFirstName();
	FString GetLastName();
	FDateTime GetDateTimeOfBirth();
	ESkinColor GetSkinColor();
};
