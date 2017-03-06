// Fill out your copyright notice in the Description page of Project Settings.

#include "CGMergedProject.h"
#include "StringIntMap.h"

UStringIntMap* UStringIntMap::newMap(UObject* owner){
	UStringIntMap *map = NewObject<UStringIntMap>(owner);
	return map;
}

void UStringIntMap::BeginDestroy(){
	Super::BeginDestroy();
	clear();
}

int32 UStringIntMap::get(FString key){
	return map.FindRef(key)-1;
}

void UStringIntMap::put(FString key, int32 value){
	map.Emplace(key, value+1);
}

void UStringIntMap::putAll(TArray<FString> array){
	for (int32 i = 0; i != array.Num(); i++){
	    map.Emplace(array[i], i+1);
	}
}

void UStringIntMap::clear(){
	map.Reset();
}

int32 UStringIntMap::size(){
	return map.Num();
}
