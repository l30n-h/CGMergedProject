// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ObjectData.h"
#include "TimeStepData.h"
#include "RecordData.h"
#include "JsonObjectConverter.h"
#include "JsonHandler.generated.h"

UCLASS()
class CGMERGEDPROJECT_API UJsonHandler: public UObject
{
	GENERATED_BODY()	
public:

	UFUNCTION(BlueprintCallable, Category="Json")
	static TArray<FObjectData> getObjectDataFromJson(const FString inString);

	UFUNCTION(BlueprintCallable, Category="Json")
	static FString getJsonFromObjectData(FObjectData objectData);

	UFUNCTION(BlueprintCallable, Category="Json")
	static FString getJsonFromTimeStepData(FTimeStepData timestepData);

	UFUNCTION(BlueprintCallable, Category="Json")
	static FString getJsonFromRecordData(FRecordData recordData);
};
