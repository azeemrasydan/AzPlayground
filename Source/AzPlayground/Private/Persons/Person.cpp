// Fill out your copyright notice in the Description page of Project Settings.


#include "Persons/Person.h"

// Sets default values
APerson::APerson()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APerson::BeginPlay()
{
	Super::BeginPlay();
	
}

void APerson::Init(FString AFirstName, FString ALastName, FDateTime ADateTimeOfBirth, ESkinColor ASkinColor)
{
	FirstName = AFirstName;
	LastName = ALastName;
	DateTimeOfBirth = ADateTimeOfBirth;
	SkinColor = ASkinColor;
}

// Called every frame
void APerson::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


FString APerson::GetFirstName()
{
	return FirstName;
}

FString APerson::GetLastName()
{
	return LastName;
}

FDateTime APerson::GetDateTimeOfBirth()
{
	return DateTimeOfBirth;
}

ESkinColor APerson::GetSkinColor()
{
	return SkinColor;
}