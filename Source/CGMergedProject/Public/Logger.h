// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include "GameFramework/Actor.h"
#include "Logger.generated.h"
using namespace std;

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

	
	UFUNCTION(BlueprintCallable, Category="Logger")
	bool isLogging();

	UFUNCTION(BlueprintCallable, Category="Logger")
	FString getHomeDir();

	UFUNCTION(BlueprintCallable, Category="Logger")
	bool start(FString filename);

	UFUNCTION(BlueprintCallable, Category="Logger")
	void stop();

	UFUNCTION(BlueprintCallable, Category="Logger")
	void log(FString msg);
};
