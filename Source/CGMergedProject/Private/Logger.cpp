// Fill out your copyright notice in the Description page of Project Settings.

#include "CGMergedProject.h"
#include "Logger.h"

// Sets default values
ALogger::ALogger()
{
	PrimaryActorTick.bCanEverTick = true;
}

ALogger::~ALogger()
{
}

// Called when the game starts or when spawned
void ALogger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALogger::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}



TArray<FObjectData> ALogger::getObjectDataFromJson(const FString inString){
	TArray<FObjectData> array;
 	FJsonObjectConverter::JsonArrayStringToUStruct(inString, &array, 0, 0);
	return array;
}

FString ALogger::getJsonFromObjectData(FObjectData objectData){
	FString outString;
	FJsonObjectConverter::UStructToJsonObjectString(objectData, outString, 0, 0, 1);
	return outString;
}

FString ALogger::getJsonFromTimeStepData(FTimeStepData timestepData){
	FString outString;
	FJsonObjectConverter::UStructToJsonObjectString(timestepData, outString, 0, 0, 1);
	return outString;
}

FString ALogger::getJsonFromRecordData(FRecordData recordData){
	FString outString;
	FJsonObjectConverter::UStructToJsonObjectString(recordData, outString, 0, 0, 1);
	return outString;
}
