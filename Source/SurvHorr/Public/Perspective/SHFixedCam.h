// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SHFixedCam.generated.h"

class UBoxComponent;
class UCameraComponent;

UENUM(BlueprintType)
enum class ECameraType : uint8 {
	E_Fixed UMETA(DisplayName = "FixedCamera"),
	E_TPS UMETA(DisplayName = "Third Person"),
	E_FPS UMETA(DisplayName = "First Person"),
	E_Default UMETA(DisplayName = "Default")
};

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	TEnumAsByte<ECameraType> E_CameraType;

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
