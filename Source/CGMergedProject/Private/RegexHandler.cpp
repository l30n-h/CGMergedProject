// Fill out your copyright notice in the Description page of Project Settings.

#include "CGMergedProject.h"
#include "RegexHandler.h"

//FString URegexHandler::replace(const FString inString, const FString regex, const FString replacement){
//	const FRegexPattern myPattern(TEXT("^[a-z,A-Z,0-9,\\-,_]+\\.[exe|dll]+"));
//	FRegexMatcher myMatcher(myPattern, TEXT("ntldll.dll"));
//	return UTF8_TO_TCHAR("");
//}

bool URegexHandler::loadTrainingData(const FString path){
	struct svm_model *model = svm_load_model("path");
	return true;
}
