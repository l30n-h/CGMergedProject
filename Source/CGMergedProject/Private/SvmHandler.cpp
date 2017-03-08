// Fill out your copyright notice in the Description page of Project Settings.

#include "CGMergedProject.h"
#include "SvmHandler.h"


void USvmHandler::BeginDestroy(){
	Super::BeginDestroy();
	close();
}

bool USvmHandler::loadTrainingData(const FString path){
	close();
	svmModel = svm_load_model(TCHAR_TO_UTF8(*path));
	return svmModel != NULL;
}

void USvmHandler::close(){
	if(svmModel != NULL){
		svm_free_and_destroy_model(&svmModel);
	}
}

int32 USvmHandler::predict(const TArray<float> inFeature){
	if(svmModel==NULL) return -1;
	const int length = inFeature.Num();
	svm_node* feature = new svm_node[length+1]; 
	for(int i=0;i<length;i++){
		feature[i] = {i+1, inFeature[i]};
		UE_LOG(LogTemp, Warning, TEXT("%f"),  inFeature[i]);
	}
	feature[length] = {-1, 0};
	double label = svm_predict(svmModel, feature);
	return (int32) label;
}
