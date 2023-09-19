// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Item.h"
#include "DrawDebugHelpers.h"
#include "UETest/UETest.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * Period);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * Period);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	float DeltaZ = TransformedSin();
	AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_LINE_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);
	DRAW_POINT_SingleFrame(GetActorLocation() + GetActorForwardVector() * 100.f);

	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	DRAW_POINT_SingleFrame(AvgVector);
}
