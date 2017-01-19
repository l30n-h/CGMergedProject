// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/Actor.h"
#include "FileHandler.generated.h"
/**
 * 
 */
UCLASS()
class CGMERGEDPROJECT_API AFileHandler : public AActor
{
	GENERATED_BODY()

public:
	AFileHandler();
	~AFileHandler();

	UFUNCTION(BlueprintCallable, Category="FileHandler")
	static TArray<FString> GetAllLevels(FString folder);

	UFUNCTION(BlueprintCallable, Category="FileHandler")
	static TArray<FString> GetAllFiles(const FString& folder);
};
