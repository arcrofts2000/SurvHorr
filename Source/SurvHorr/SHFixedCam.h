// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SHFixedCam.generated.h"

class UBoxComponent;
class UCameraComponent;

UCLASS()
class SURVHORR_API ASHFixedCam : public AActor
{
	GENERATED_BODY()
	
public:	

	ASHFixedCam();

	UPROPERTY(EditAnywhere, Category = "Camera")
	float BlendTime = 0.f;

	UPROPERTY(EditAnywhere, Category = "Camera")
	float BlendExponential = 0.f;

protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBoxComponent> BoxComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> Camera;

	UFUNCTION()
	void OnCollision(UPrimitiveComponent* OverlappedComponent, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComponent, 
		int32 OtherBodyIndex, 
		bool bFromSweep, const 
		FHitResult& Hit);

	void ChangePerspective();

};
