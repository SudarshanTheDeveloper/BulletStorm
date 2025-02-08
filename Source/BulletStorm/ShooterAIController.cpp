// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();
    if (AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);
        
        UE_LOG(LogTemp, Warning, TEXT("Behavior Tree Started Successfully"));
        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());

        GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("AIBehavior is NULL!"));
    }

}

void AShooterAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
  /*  APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (LineOfSightTo(PlayerPawn))
    {
        SetFocus(PlayerPawn);
        MoveToActor(PlayerPawn, AcceptanceRadius);
    }
    else
    {
        ClearFocus(EAIFocusPriority::Gameplay);
        StopMovement();
    }*/
}