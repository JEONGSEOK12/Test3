// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_RETURN.h"


UBTTask_RETURN::UBTTask_RETURN()
{
	bNotifyTick = true;
	bNotifyTaskFinished = true;
}


EBTNodeResult::Type UBTTask_RETURN::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GetGlobalCharacter(OwnerComp)->SetAniState(AIState::RETURN);
	return EBTNodeResult::Type::InProgress;
}


void UBTTask_RETURN::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DelataSeconds)
{
	FVector PawnPos = GetGlobalCharacter(OwnerComp)->GetActorLocation();

	AAICon* Con = Cast<AAICon>(OwnerComp.GetAIOwner());
	FVector TargetPos = Con->BaseLocation;

	FVector Dir = TargetPos - PawnPos;

	GetGlobalCharacter(OwnerComp)->AddMovementInput(Dir);
	GetGlobalCharacter(OwnerComp)->SetActorRotation(Dir.Rotation());

	if (100.f >= Dir.Size())
	{
		SetStateChange(OwnerComp, AIState::IDLE);
		return;
	}
}