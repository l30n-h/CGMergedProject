// Fill out your copyright notice in the Description page of Project Settings.

#include "CGMergedProject.h"
#include "Logger.h"

ofstream logfile;
string homeDir;
// Sets default values
ALogger::ALogger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	stringstream stringStream;
	char* homePath;
	if ((homePath = getenv("HOME"))!=NULL){//Linux Mac
		stringStream << homePath<<"/";
	}else if((homePath = getenv("HOMEPATH"))!=NULL){//Windows
		stringStream << getenv("HOMEDRIVE") << homePath<<"\\";
	}else{
		//TODO assert
	}
	homeDir = stringStream.str();
}

ALogger::~ALogger()
{
	//stop();
}

// Called when the game starts or when spawned
void ALogger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALogger::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}


bool ALogger::isLogging(){
	return logfile.is_open();
}

FString ALogger::getHomeDir(){
	return UTF8_TO_TCHAR(homeDir.c_str());
}

bool ALogger::start(FString filename){
	if(isLogging()){ 
		return false;
	}
	stringstream stringStream;
	stringStream << homeDir<<TCHAR_TO_UTF8(*filename)<<".txt";
	string file = stringStream.str();
	if (ifstream(file)){
		return false;
	}
	stop();
	logfile.open(file);
	return isLogging();
}

void ALogger::stop(){
	if (isLogging()){
		logfile.close();
	}
}

void ALogger::log(FString msg){
	if (isLogging()){
		logfile << TCHAR_TO_UTF8(*msg) << "\n";
	}
}

