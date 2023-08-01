// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DDBaseCharacter.generated.h"


class UBaseCharacterMovementComponent;
UCLASS(Abstract, NotBlueprintable)
class GAMECODE_API ADDBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	ADDBaseCharacter(const FObjectInitializer& ObjectInitializer);

	
	virtual void MoveForward(float Value) {};
	virtual void MoveRight(float Value) {};
	virtual void Turn(float Value) {};
	virtual void LookUp(float Value) {};

	virtual void ChangeCrouchState();

	virtual void StartSprint();
	virtual void StopSprint();

	virtual void Tick(float DeltaTime) override;	

	FORCEINLINE UBaseCharacterMovementComponent* GetBaseCharacterMovementComponent() { return BaseCharacterMovementComponent; }


protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character | Movement")
	float SprintSpeed = 790.0f;

	virtual bool CanSprint();

	UBaseCharacterMovementComponent* BaseCharacterMovementComponent;


private:

	void TryChangeSprintState();
	bool bIsSprintRequested = false;

};
