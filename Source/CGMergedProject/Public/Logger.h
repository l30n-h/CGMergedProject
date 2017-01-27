// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include "JsonObjectConverter.h"
#include "Object.h"
#include "GameFramework/Actor.h"
#include "Logger.generated.h"
using namespace std;


USTRUCT(BlueprintType)
struct FObjectData{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	FString id;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	FTransform transform;
};

USTRUCT(BlueprintType)
struct FTimeStepData{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	int32 time;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	TArray<FObjectData> objects;
};

USTRUCT(BlueprintType)
struct FRecordData{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	FName level;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	TArray<FTimeStepData> timeSteps;
};

UCLASS()
class CGMERGEDPROJECT_API ALogger : public AActor
{
	GENERATED_BODY()
	
	
public:	
	// Sets default values for this actor's properties
	ALogger();
	~ALogger();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	
	UFUNCTION(BlueprintCallable, Category="Json")
	static TArray<FObjectData> getObjectDataFromJson(const FString inString);

	UFUNCTION(BlueprintCallable, Category="Json")
	static FString getJsonFromObjectData(FObjectData objectData);

	UFUNCTION(BlueprintCallable, Category="Json")
	static FString getJsonFromTimeStepData(FTimeStepData timestepData);

	UFUNCTION(BlueprintCallable, Category="Json")
	static FString getJsonFromRecordData(FRecordData recordData);
};


