// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadsGeneratorHelper.h"

// Sets default values for this component's properties
URoadsGeneratorHelper::URoadsGeneratorHelper()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URoadsGeneratorHelper::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
float URoadsGeneratorHelper::Remap(float value, float low1, float high1, float low2, float high2)
{
	return low2 + (value - low1) * (high2 - low2) / (high1 - low1);
}

// Called every frame
void URoadsGeneratorHelper::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URoadsGeneratorHelper::GenerateMeshArrays(const int plateSize, const int mapSize, const int seed, TArray<FVector>& verts, TArray<int>& tris, TArray<FVector2D>& uvs, TArray<FLinearColor>& vertColors)
{
	FastNoiseLite noise;
	noise.SetNoiseType(FastNoiseLite::NoiseType_Cellular);
	noise.SetSeed(seed);
	noise.SetFrequency(0.02);
	noise.SetRotationType3D(FastNoiseLite::RotationType3D_ImproveXYPlanes);
	noise.SetCellularJitter(1);
	noise.SetCellularDistanceFunction(FastNoiseLite::CellularDistanceFunction_Manhattan);
	noise.SetCellularReturnType(FastNoiseLite::CellularReturnType_Distance2Div);
	

	float uvSpace = 50.f / FMath::Max(mapSize, mapSize);
	int v = 0;
	float vertexOffset = plateSize * 0.5f;

	for (int32 x = 0; x <= mapSize; x++)
	{
		for (int32 y = 0; y <= mapSize; y++)
		{
			float height = noise.GetNoise( (float)x, (float)y);
			height = Remap(height, -1, 1, 0, 1);
			
			if (height > 0.48) {
				vertColors.Add(FLinearColor(1, 0, 0, 1)); //Droga
			}
			else {
				vertColors.Add(FLinearColor(0, 0, 0, 1)); //Droga
			}
			//vertColors.Add(FLinearColor(height, 0, 0, 1));
			verts.Add(FVector((x * plateSize) - vertexOffset, (y * plateSize) - vertexOffset, 0));
			uvs.Add(FVector2D(x * uvSpace, y * uvSpace));
			
			if (y < mapSize && x < mapSize) {
				tris.Add(v);
				tris.Add(v + 1);
				tris.Add(v + (mapSize + 1));

				tris.Add(v + (mapSize + 1));
				tris.Add(v + 1);
				tris.Add(v + (mapSize + 1) + 1);

				v++;
			}
		}
		if (x < mapSize) {
			v++;
		}
	}
}

