// Fill out your copyright notice in the Description page of Project Settings.

#include "CGMergedProject.h"
#include "FileHandler.h"


FString UFileHandler::getHomeDir(){
	std::stringstream sb;
	char* homePath;
	if ((homePath = std::getenv("HOME"))!=NULL){//Linux Mac
		sb << homePath<<"/";
	}else if((homePath = std::getenv("HOMEPATH"))!=NULL){//Windows
		sb << std::getenv("HOMEDRIVE") << homePath<<"\\";
	}else{
		//TODO assert
	}
	return UTF8_TO_TCHAR(sb.str().c_str());
}

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

UFileHandler* UFileHandler::openFile(UObject* owner, FString dir, FString file, bool write){
	UFileHandler *fH = NewObject<UFileHandler>(owner);
	std::stringstream sb;
	sb << TCHAR_TO_UTF8(*dir)<<TCHAR_TO_UTF8(*file)<<".txt";
	int mode = write?std::fstream::out:std::fstream::in;
	(fH->handle).open(sb.str(), mode);
	return fH;
}

void UFileHandler::BeginDestroy(){
	Super::BeginDestroy();
	close();
}

bool UFileHandler::isOpen(){
	return handle.is_open();
}

void UFileHandler::close(){
	if(isOpen()){
		handle.close();
	}
}

FString UFileHandler::readAll(){
	if(isOpen()){
		std::string content((std::istreambuf_iterator<char>(handle)), std::istreambuf_iterator<char>());
		close();
		return UTF8_TO_TCHAR(content.c_str());
	}
	return UTF8_TO_TCHAR("");
}

void UFileHandler::write(FString text){
	if(isOpen()){
		handle << TCHAR_TO_UTF8(*text);
	}
}

void UFileHandler::writeLine(FString text){
	if(isOpen()){
		handle << TCHAR_TO_UTF8(*text) << "\n";
	}
}
