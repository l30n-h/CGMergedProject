// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Feature.generated.h"

USTRUCT(BlueprintType)
struct FFeature {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feature")
	TArray<float> elements;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feature")
	bool save;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feature")
	TArray<FVector> vectors;
};
