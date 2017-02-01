// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <sstream> 
#include <fstream>
#include <iostream>
#include <string>
#include "FileHandler.generated.h"

UCLASS()
class CGMERGEDPROJECT_API UFileHandler : public UObject
{
	GENERATED_BODY()	

public:	

	UFUNCTION(BlueprintCallable, Category="FileHandler")
	static FString getHomeDir();	

	UFUNCTION(BlueprintCallable, Category="FileHandler")
	static TArray<FString> GetAllLevels(FString folder);

	UFUNCTION(BlueprintCallable, Category="FileHandler")
	static TArray<FString> GetAllFiles(const FString& baseDir, bool includeFiles, bool includeDirs);

	UFUNCTION(BlueprintCallable, Category="FileHandler")
	static UFileHandler* openFile(FString dir, FString file, UObject* owner);
	
	virtual void BeginDestroy() override;

	std::ofstream handle;

	UFUNCTION(BlueprintCallable, Category="FileHandler")
	bool isOpen();

	UFUNCTION(BlueprintCallable, Category="FileHandler")
	void close();

	UFUNCTION(BlueprintCallable, Category="FileHandler")
	void write(FString text);

	UFUNCTION(BlueprintCallable, Category="FileHandler")
	void writeLine(FString text);
};


