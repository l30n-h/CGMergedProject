// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CalibrationData.generated.h"

USTRUCT(BlueprintType)
struct FCalibrationData {
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feature")
	float height;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feature")
	float armLength;
};
