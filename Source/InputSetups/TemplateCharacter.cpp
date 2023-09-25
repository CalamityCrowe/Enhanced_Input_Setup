// Fill out your copyright notice in the Description page of Project Settings.


#include "TemplateCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputConfigData.h" // this is the custom input config includes

 //these four are used for the files relevant to the Enhanced input system
 //UProject and build.cs need to be edited so it knows about these files
 //UPROJECT needs to know about the plugin to know what one to enable
 //build.cs needs to know about the dependencies so it can link them
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

	APlayerController* PC = Cast<APlayerController>(GetController()); // gets an instance of the player controller



	if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer()) // this gets the local player using the controller (need to check that's what that actually does)
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()) // checks if it can get the local subsystem that has been assigned in the editor
		{
			InputSystem->ClearAllMappings(); // clears any mapping contexts if they had been assigned by mistake
			InputSystem->AddMappingContext(InputMappingContext, 0); // assigns the mapping contexts as the highest priority
		}
	}

	if(UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent)) // checks if the player input component can be cast to the enhanced version
	{
#pragma region Setup Actions Comments
		/* Bind Action Setup
		
		 {
			 BindAction(UInputAction,
			 ETriggerEvent,
			 CharacterObject(this),
			 Function Reference (&Template::Do Thing)
			)
		 }

		 ETriggerEvents
		 {
			 None         = (0x0),
			 Triggered    = (1 << 0), Triggering occurred after one or more processing ticks.
			 Started      = (1 << 1), An event has occurred that has begun Trigger evaluation. Note: Triggered may also occur this frame, but this event will always be fired first.
			 Ongoing      = (1 << 2), Triggering is still being processed.
			 Canceled     = (1 << 3), Triggering has been canceled.
			 Completed    = (1 << 4), The trigger state has transitioned from Triggered to None this frame, i.e. Triggering has finished.
		 }
		*/
#pragma endregion

		PEI->BindAction(InputActions->m_InputMove, ETriggerEvent::Triggered, this, &ATemplateCharacter::PrintString); // binds an action to the input component

	}

}

void ATemplateCharacter::PrintString()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, TEXT("I AM PRINTING"));
}

