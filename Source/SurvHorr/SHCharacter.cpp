// Fill out your copyright notice in the Description page of Project Settings.


#include "SHCharacter.h"

// Sets default values
ASHCharacter::ASHCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASHCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASHCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASHCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

