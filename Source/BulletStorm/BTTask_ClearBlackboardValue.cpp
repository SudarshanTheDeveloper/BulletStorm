// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_ClearBlackboardValue.h"
#include "BehaviorTree/BlackboardComponent.h" // Fix: Include this header
#include "BehaviorTree/BehaviorTreeComponent.h"

UBTTask_ClearBlackboardValue::UBTTask_ClearBlackboardValue()
{
	NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTask_ClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	// Get the blackboard component
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	//if (!BlackboardComp)
	//{
	//	return EBTNodeResult::Failed; // Fail if BlackboardComp is null
	//}

	//// Clear the selected blackboard key
	//BlackboardComp->ClearValue(GetSelectedBlackboardKey());

	return EBTNodeResult::Succeeded;
}
