// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class BULLETSTORM_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//Movement
	//Move Forward
	void MoveForward(float AxisValue);

	//MoveBackward
	void MoveBackWards(float AxisValue);

	//LookUp using mouse
	//commenting this up because we can call the lookup value directly for the pawn class using AddControllerPitchInput
	//void LookUp(float AxisValue);

	//Move Right
	void MoveRight(float AxisValue);

};
