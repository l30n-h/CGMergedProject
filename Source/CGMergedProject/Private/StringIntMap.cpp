// Fill out your copyright notice in the Description page of Project Settings.

#include "CGMergedProject.h"
#include "StringIntMap.h"

UStringIntMap* UStringIntMap::newMap(UObject* owner){
	UStringIntMap *map = NewObject<UStringIntMap>(owner);
	return map;
}

void UStringIntMap::BeginDestroy(){
	Super::BeginDestroy();
}

int32 UStringIntMap::get(FString key){
	return map.FindRef(key);
}

void UStringIntMap::put(FString key, int32 value){
	map.Emplace(key, value);
}

void UStringIntMap::putAll(TArray<FString> array){
	for (int32 i = 0; i != array.Num(); i++){
	    map.Emplace(array[i], i);
	}
}
