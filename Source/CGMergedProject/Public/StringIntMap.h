// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "StringIntMap.generated.h"

UCLASS(Blueprintable)
class CGMERGEDPROJECT_API UStringIntMap : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Map")
	static UStringIntMap* newMap(UObject* owner);
	
	virtual void BeginDestroy() override;

	TMap<FString, int32> map;

	UFUNCTION(BlueprintCallable, Category="Map")
	int32 get(FString key);

	UFUNCTION(BlueprintCallable, Category="Map")
	void put(FString key, int32 value);

	UFUNCTION(BlueprintCallable, Category="Map")
	void putAll(TArray<FString> array);

	UFUNCTION(BlueprintCallable, Category="Map")
	void clear();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Map")
	int32 size();
};
