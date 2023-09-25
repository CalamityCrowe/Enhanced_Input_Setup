// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputAction.h"
#include "InputConfigData.generated.h"

/**
 * 
 */
UCLASS()
class INPUTSETUPS_API UInputConfigData : public UDataAsset
{
	GENERATED_BODY()
public: 

    // this is where you add more input actions so they can be added in the editor after all the parameters have been added

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UInputAction* m_InputMove;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        UInputAction* m_InputLook;
};
