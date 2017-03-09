// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "IntStringMap.generated.h"

UCLASS(Blueprintable)
class CGMERGEDPROJECT_API UIntStringMap : public UObject
{
	GENERATED_BODY()

public:

	virtual void BeginDestroy() override;

	TMap<int32, FString> map;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Map")
	FString get(int32 key);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Map")
	int32 getKey(FString value);

	UFUNCTION(BlueprintCallable, Category="Map")
	void put(int32 key, FString value);

	UFUNCTION(BlueprintCallable, Category="Map")
	void putAll(TArray<FString> array);

	UFUNCTION(BlueprintCallable, Category="Map")
	void clear();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Map")
	int32 size();
};
