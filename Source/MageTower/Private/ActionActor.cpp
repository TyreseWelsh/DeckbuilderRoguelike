// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionActor.h"
#include "MageTowerGameMode.h"

// Sets default values
AActionActor::AActionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mpOrigin = CreateDefaultSubobject<USceneComponent>(TEXT("Origin"));
	mpOrigin->SetMobility(EComponentMobility::Type::Movable);
	SetRootComponent(mpOrigin);

	mpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mpMesh->SetMobility(EComponentMobility::Type::Movable);
	mpMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	mpMesh->SetupAttachment(mpOrigin);
}

// Called when the game starts or when spawned
void AActionActor::BeginPlay()
{
	Super::BeginPlay();

	mpPlayer = Cast<AMageTowerGameMode>(GetWorld()->GetAuthGameMode())->GetPlayer();
}

// Called every frame
void AActionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActionActor::StartTurn()
{
}

