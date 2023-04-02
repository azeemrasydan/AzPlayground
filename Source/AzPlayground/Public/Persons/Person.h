// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Person.generated.h"

UENUM()
enum ESkinColor 
{
	EXTREME_FAIR_SKIN UMETA(DisplayName = "Extreme Fair Skin"),
	FAIR_SKIN UMETA(DisplayName = "Fair Skin"),
	MEDIUM_SKIN UMETA(DisplayName = "Medium Skin"),
	OLIVE_SKIN UMETA(DisplayName = "Olive Skin"),
	BROWN_SKIN UMETA(DisplayName = "Brown Skin"),
	BLACK_SKIN UMETA(DisplayName = "Black Skin")
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ESkinColor)
	TEnumAsByte<ESkinColor> SkinColor;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Init(FString AFirstName, FString ALastName, FDateTime ADateTimeOfBirth, ESkinColor ASkinColor = BLACK_SKIN);

	FString GetFirstName();
	FString GetLastName();
	FDateTime GetDateTimeOfBirth();
	ESkinColor GetSkinColor();

private:
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Collision;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Head;
};


