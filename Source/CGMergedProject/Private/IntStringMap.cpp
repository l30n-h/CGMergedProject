// Fill out your copyright notice in the Description page of Project Settings.

#include "CGMergedProject.h"
#include "IntStringMap.h"

void UIntStringMap::BeginDestroy(){
	Super::BeginDestroy();
	clear();
}

FString UIntStringMap::get(int32 key){
	return map.FindRef(key);
}

int32 UIntStringMap::getKey(FString value){
	const int32 * key= map.FindKey(value);
	if(key){
		return *key;
	}
	return -1;
}

void UIntStringMap::put(int32 key, FString value){
	map.Emplace(key, value);
}

void UIntStringMap::putAll(TArray<FString> array){
	for (int32 i = 0; i != array.Num(); i++){
	    map.Emplace(i, array[i]);
	}
}

void UIntStringMap::clear(){
	map.Reset();
}

int32 UIntStringMap::size(){
	return map.Num();
}
