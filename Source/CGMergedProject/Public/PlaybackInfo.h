// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "RecordData.h"
#include "Feature.h"
#include "PlaybackSettings.h"
#include "PlaybackInfo.generated.h"

USTRUCT(BlueprintType)
struct FPlaybackInfo {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlaybackInfo")
	FRecordData playbackData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlaybackInfo")
	float timestepSum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlaybackInfo")
	int32 timestepIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlaybackInfo")
	bool isFeatureRecording;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlaybackInfo")
	TArray<FFeature> features;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlaybackInfo")
	float featureTimestepSum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlaybackInfo")
	FString recordsDirectory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlaybackInfo")
	TArray<FString> recordsFilenames;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlaybackInfo")
	int32 recordIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlaybackInfo")
	FPlaybackSettings settings;
};
