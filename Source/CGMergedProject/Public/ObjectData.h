// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ObjectData.generated.h"

USTRUCT(BlueprintType)
struct FObjectData{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	FString id;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Json")
	FTransform transform;
};
