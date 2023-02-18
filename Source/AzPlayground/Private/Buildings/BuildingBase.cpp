// Fill out your copyright notice in the Description page of Project Settings.


#include "Buildings/BuildingBase.h"

// Sets default values
ABuildingBase::ABuildingBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 100.f;
}

// Called when the game starts or when spawned
void ABuildingBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuildingBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ABuildingBase::GetHealth()
{
	return Health;
}

void ABuildingBase::Debug_SetHealth(float health)
{
	Health = health;
}