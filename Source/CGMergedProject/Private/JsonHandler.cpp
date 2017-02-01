// Fill out your copyright notice in the Description page of Project Settings.

#include "CGMergedProject.h"
#include "JsonHandler.h"

TArray<FObjectData> UJsonHandler::getObjectDataFromJson(const FString inString){
	TArray<FObjectData> array;
 	FJsonObjectConverter::JsonArrayStringToUStruct(inString, &array, 0, 0);
	return array;
}

FString UJsonHandler::getJsonFromObjectData(FObjectData objectData){
	FString outString;
	FJsonObjectConverter::UStructToJsonObjectString(objectData, outString, 0, 0, 1);
	return outString;
}

FString UJsonHandler::getJsonFromTimeStepData(FTimeStepData timestepData){
	FString outString;
	FJsonObjectConverter::UStructToJsonObjectString(timestepData, outString, 0, 0, 1);
	return outString;
}

FString UJsonHandler::getJsonFromRecordData(FRecordData recordData){
	FString outString;
	FJsonObjectConverter::UStructToJsonObjectString(recordData, outString, 0, 0, 1);
	return outString;
}
