// Fill out your copyright notice in the Description page of Project Settings.


#include "IsActionObject.h"

// Add default functionality here for any IIsActionObject functions that are not pure virtual.
void IIsActionObject::StartTurn()
{
}

FOnTurnEnd* IIsActionObject::GetTurnEndDelegate()
{
	return nullptr;
}
