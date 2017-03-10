// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TimeStepData.h"
#include "CalibrationData.h"
#include "RecordData.generated.h"

USTRUCT(BlueprintType)
struct FRecordData{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	FName level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	FCalibrationData calibrationData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	TArray<FTimeStepData> timeSteps;
};
