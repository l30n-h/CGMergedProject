// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "JsonObjectConverter.h"
#include "Object.h"
#include "FileHandler.generated.h"
/**
 * 
 */

USTRUCT(BlueprintType)
struct FObjectData{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	FString id;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	FTransform transform;
};

UCLASS()
class CGMERGEDPROJECT_API UFileHandler : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="FileHandler")
	static TArray<FString> GetAllLevels(FString folder);

	UFUNCTION(BlueprintCallable, Category="FileHandler")
	static TArray<FString> GetAllFiles(const FString& baseDir, bool includeFiles, bool includeDirs);

	UFUNCTION(BlueprintCallable, Category="Json")
	static TArray<FObjectData> fromJson(const FString inString);

	UFUNCTION(BlueprintCallable, Category="Json")
	static FString toJson(FObjectData objectData);
};


