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

	static ConstructorHelpers::FObjectFinder<UMaterial> BlackMaterialFound(TEXT("/Game/Development/Materials/Persons/BlackMaterial"));
	if (BlackMaterialFound.Succeeded()) {
		UMaterial* headMaterial = BlackMaterialFound.Object;
		Head->SetMaterial(0, headMaterial);
	}

}

// Called when the game starts or when spawned
void APerson::BeginPlay()
{
	Super::BeginPlay();

	HeadMaterial = Head->GetMaterial(0);
	UMaterialInstanceDynamic* HeadDynamicMaterial = UMaterialInstanceDynamic::Create(HeadMaterial, Head);
	FLinearColor HeadColor = SkinColorToMaterialColorMap[SkinColor];
	HeadDynamicMaterial->SetVectorParameterValue(TEXT("Base Color"), HeadColor);

	Head->SetMaterial(0, HeadDynamicMaterial);

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