// Fill out your copyright notice in the Description page of Project Settings.


#include "TemplateCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputConfigData.h"

#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

// Sets default values
ATemplateCharacter::ATemplateCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_Camera = CreateOptionalDefaultSubobject<UCameraComponent>(TEXT("camera"));

	m_CameraArm = CreateOptionalDefaultSubobject<USpringArmComponent>(TEXT("springArm"));
	m_CameraArm->SetupAttachment(RootComponent);
	m_CameraArm->TargetArmLength = 300;
	m_CameraArm->bEnableCameraLag = true;
	m_CameraArm->bUsePawnControlRotation = true;

	m_Camera->AttachToComponent(m_CameraArm, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void ATemplateCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATemplateCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATemplateCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	APlayerController* PC = Cast<APlayerController>(GetController());



	if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			InputSystem->ClearAllMappings();
			InputSystem->AddMappingContext(InputMappingContext, 0);
		}
	}

	if(UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		PEI->BindAction(InputActions->m_InputMove, ETriggerEvent::Triggered, this, &ATemplateCharacter::PrintString); 
	}

	/*
		APlayerController* PC = Cast<APlayerController>(GetController());

	// Get the local player subsystem
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());
	// Clear out existing mapping, and add our mapping



	*/

	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Input->BindAction(m_WalkForward, ETriggerEvent::Ongoing, this, &ATemplateCharacter::PrintString);
	}

}

void ATemplateCharacter::PrintString()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("CHEESE"));
}

