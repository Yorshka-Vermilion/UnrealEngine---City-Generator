// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "FastNoise.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RoadsGeneratorHelper.generated.h"

#define DROGA 1

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LAB1_API URoadsGeneratorHelper : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URoadsGeneratorHelper();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	float Remap(float value, float low1, float high1, float low2, float high2);
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void GenerateMeshArrays(const int plateSize, const int mapSize, const int seed, TArray<FVector>& verts, TArray<int>& tris, TArray<FVector2D>& uvs, TArray<FLinearColor>& vertColors);
};
