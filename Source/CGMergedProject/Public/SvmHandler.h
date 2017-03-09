// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "svm.h"
#include "SvmHandler.generated.h"

UCLASS(Blueprintable)
class CGMERGEDPROJECT_API USvmHandler: public UObject
{
	GENERATED_BODY()
public:

	virtual void BeginDestroy() override;

	struct svm_model *svmModel;

	UFUNCTION(BlueprintCallable, Category="LibSVM")
	bool loadTrainingData(const FString path);

	UFUNCTION(BlueprintCallable, Category="LibSVM")
	void close();

	UFUNCTION(BlueprintCallable, Category="LibSVM")
	int32 predict(const TArray<float> inFeature);
};
