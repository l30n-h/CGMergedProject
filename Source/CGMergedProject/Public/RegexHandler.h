// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "svm.h"
#include "RegexHandler.generated.h"

UCLASS()
class CGMERGEDPROJECT_API URegexHandler: public UObject
{
	GENERATED_BODY()
public:
	//UFUNCTION(BlueprintCallable, Category="Regex")
	//static FString replace(const FString inString, const FString regex, const FString replacement);

	UFUNCTION(BlueprintCallable, Category="LibSVM")
	static bool loadTrainingData(const FString path);
};
