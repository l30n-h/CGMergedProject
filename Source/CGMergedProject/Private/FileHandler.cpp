// Fill out your copyright notice in the Description page of Project Settings.

#include "CGMergedProject.h"
#include "FileHandler.h"

TArray<FString> UFileHandler::GetAllLevels(FString folder){
	auto ObjectLibrary = UObjectLibrary::CreateLibrary(UWorld::StaticClass(), false, true);
	ObjectLibrary->LoadAssetDataFromPath(folder);
	TArray<FAssetData> AssetDatas;
	ObjectLibrary->GetAssetDataList(AssetDatas);

	TArray<FString> Names = TArray<FString>();

	for (int32 i = 0; i < AssetDatas.Num(); ++i){
		FAssetData& AssetData = AssetDatas[i];
		auto name = AssetData.AssetName.ToString();
		Names.Add(name);
	}
	return Names;
}

TArray<FString> UFileHandler::GetAllFiles(const FString& baseDir, bool includeFiles, bool includeDirs){
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	TArray<FString> files = TArray<FString>();	
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(files, *baseDir, includeFiles, includeDirs);
	files.Sort();
	return files;
}

TArray<FObjectData> UFileHandler::fromJson(const FString inString){
	TArray<FObjectData> array;
 	FJsonObjectConverter::JsonArrayStringToUStruct(inString, &array, 0, 0);
	return array;
}

FString UFileHandler::toJson(FObjectData objectData){
	FString outString;
	FJsonObjectConverter::UStructToJsonObjectString(objectData, outString, 0, 0, 1);
	return outString;
	//FJsonObject o = FJsonObjectConverter::UStructToJsonObject(objectData, 0, 0);
}
