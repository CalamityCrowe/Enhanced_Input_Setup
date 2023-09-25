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

	UFUNCTION() // this is used to tag a function for getting used for the inputs or if it needs to be used in the editor somewhere
		virtual void PrintString();

public:

	// any object that has class added in front of it gets the header included later in the cpp file to reduce overhead costs

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera") // this is used to say that the editor can see the object ot make it so they can edit it depending on the parameters passed in
		TObjectPtr<class UCameraComponent> m_Camera;		// this is how pointers for objects on an actor should be defined

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
		TObjectPtr<class USpringArmComponent> m_CameraArm;

	UPROPERTY(EditAnywhere, Category = "Input")
		class UInputMappingContext* InputMappingContext; // this gets assigned in the editor for the mapping context

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
		class UInputConfigData* InputActions; // this is a custom data config that holds a list of pointers that will get assigned in the engine to pull the input actions in

};
