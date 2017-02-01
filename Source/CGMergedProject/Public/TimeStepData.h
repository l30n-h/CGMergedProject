// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ObjectData.h"
#include "TimeStepData.generated.h"

USTRUCT(BlueprintType)
struct FTimeStepData{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	float time;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	TArray<FObjectData> objects;
};
