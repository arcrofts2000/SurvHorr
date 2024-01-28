// Fill out your copyright notice in the Description page of Project Settings.


#include "SHFixedCam.h"
#include "Components/BoxComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SHCharacter.h"

// Sets default values
ASHFixedCam::ASHFixedCam()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComp = CreateDefaultSubobject<UBoxComponent>("BoxComp");
	SetRootComponent(BoxComp);
	BoxComp->SetBoxExtent(FVector(500.f, 500.f, 500.f));
	BoxComp->CanCharacterStepUpOn = ECB_No;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ASHFixedCam::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ASHFixedCam::OnCollision);
}

void ASHFixedCam::OnCollision(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComponent,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& Hit)
{
	if (ASHCharacter* Player = Cast<ASHCharacter>(OtherActor))
		ChangePerspective();
}

void ASHFixedCam::ChangePerspective()
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0))
		PC->SetViewTargetWithBlend(this, BlendTime, VTBlend_Linear, BlendExponential);
}