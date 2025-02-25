// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MapGeneratorComponent.generated.h"

class UMapData;
class URoomGenerator;
class URoomContentGenerator;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TILEMAPGENERATOR_API UMapGeneratorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMapGeneratorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float _DeltaTime, ELevelTick _TickType, FActorComponentTickFunction* _ThisTickFunction) override;

	void Init();
	void GenerateMap();
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Data", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMapData> mpMapData;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Data", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> mTileClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Data", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<URoomGenerator> mRoomGeneratorClass;
	TObjectPtr<URoomGenerator> mpRoomGenerator;
	TObjectPtr<URoomContentGenerator> mpRoomContentGenerator;
};