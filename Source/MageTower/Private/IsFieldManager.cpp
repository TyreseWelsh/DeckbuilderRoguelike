// Fill out your copyright notice in the Description page of Project Settings.


#include "IsFieldManager.h"

// Add default functionality here for any IIsFieldManager functions that are not pure virtual.

UFieldManager* IIsFieldManager::GetFieldManager()
{
	return nullptr;
}

APawn* IIsFieldManager::GetPlayer()
{
	return nullptr;
}

UDataTable* IIsFieldManager::GetEnemyDataTable()
{
	return nullptr;
}
