// Fill out your copyright notice in the Description page of Project Settings.

#include "CGMergedProject.h"
#include "FileHandler.h"


FString UFileHandler::getHomeDir(){
	stringstream sb;
	char* homePath;
	if ((homePath = getenv("HOME"))!=NULL){//Linux Mac
		sb << homePath<<"/";
	}else if((homePath = getenv("HOMEPATH"))!=NULL){//Windows
		sb << getenv("HOMEDRIVE") << homePath<<"\\";
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

/*UFileHandler* UFileHandler::openFile(FString dir, FString file, UObject *owner, ){	
	stringstream sb;
	sb << TCHAR_TO_UTF8(*dir)<<TCHAR_TO_UTF8(*file)<<".txt";
	string filePath = sb.str();
	if (ifstream(filePath)){
		return NULL;
	}
	ofstream f;
	f.open(filePath);
	if(!f.is_open()){
		return NULL;
	}
	UFileHandler *fH = NewObject<UFileHandler>(owner);
	fH->setHandle(&f);
	return fH;
}*/

bool UFileHandler::openFile(FString dir, FString file){
	stringstream sb;
	sb << TCHAR_TO_UTF8(*dir)<<TCHAR_TO_UTF8(*file)<<".txt";
	string filePath = sb.str();
	if (ifstream(filePath)){
		return false;
	}
	ofstream f;
	f.open(filePath);
	if(!f.is_open()){
		return false;
	}
	setHandle(&f);
	return true;
}

bool UFileHandler::isOpen(){
	return handle->is_open();
}

void UFileHandler::close(){
	if(isOpen()){
		handle->close();
	}
}

void UFileHandler::write(FString text){
	if(isOpen()){
		(*handle) << TCHAR_TO_UTF8(*text);
	}
}

void UFileHandler::writeLine(FString text){
	if(isOpen()){
		(*handle) << TCHAR_TO_UTF8(*text) << "\n";
	}
}

void UFileHandler::setHandle(ofstream *h){
	handle = h;
}
