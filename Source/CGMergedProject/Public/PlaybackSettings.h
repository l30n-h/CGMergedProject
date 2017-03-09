// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PlaybackSettings.generated.h"

USTRUCT(BlueprintType)
struct FPlaybackSettings {
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlaybackSettings")
	float radiusLeftHand = 0.3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlaybackSettings")
	float radiusRightHand = 0.3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlaybackSettings")
	float radiusHMD = 1.0;
};
