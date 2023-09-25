// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TemplateCharacter.generated.h"

UCLASS()
class INPUTSETUPS_API ATemplateCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATemplateCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		virtual void PrintString();

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
		TObjectPtr<class UCameraComponent> m_Camera;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
		TObjectPtr<class USpringArmComponent> m_CameraArm;

	UPROPERTY(EditAnywhere, Category = "Input")
		class UInputMappingContext* InputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
		class UInputConfigData* InputActions; 

};
