// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine.h"
#include "Persons/Person.h"

// Sets default values
APerson::APerson()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Collision"));
	SetRootComponent(Collision);
	Collision->SetVisibleFlag(false);
	
	Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	Head->SetupAttachment(Collision);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Engine/EngineMeshes/Sphere"));

	if (SphereVisualAsset.Succeeded()) {
		Head->SetStaticMesh(SphereVisualAsset.Object);
		Head->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Head->SetWorldScale3D(FVector(.3f));
	}
	
}

// Called when the game starts or when spawned
void APerson::BeginPlay()
{
	Super::BeginPlay();
	static ConstructorHelpers::FObjectFinder<UMaterial> BlackMaterialFound(TEXT("/Game/Development/Materials/Persons/BlackMaterial"));
	static ConstructorHelpers::FObjectFinder<UMaterial> FairMaterialFound(TEXT("/Game/Development/Materials/Persons/FairMaterial"));
	UE_LOG(LogTemp, Warning, TEXT("Succedeed"));
	if (BlackMaterialFound.Succeeded() && FairMaterialFound.Succeeded()) {
		UE_LOG(LogTemp, Warning, TEXT("Succedeed"));
		UMaterial * headMaterial = (SkinColor == ESkinColor::BLACK_SKIN) ? BlackMaterialFound.Object : FairMaterialFound.Object;
		UMaterialInstanceDynamic* dynamicHeadMaterialInstiatiate = UMaterialInstanceDynamic::Create(headMaterial, Head);
		Head->SetMaterial(0, headMaterial);
	}



	
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