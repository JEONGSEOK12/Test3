// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_DEATH.h"

// 1. ���� �״� �ִϸ��̼��� ������ ȭ�鿡�� ������ ������� �մϴ�.

UBTTask_DEATH::UBTTask_DEATH()
{
	bNotifyTick = true;
	bNotifyTaskFinished = true;
}


EBTNodeResult::Type UBTTask_DEATH::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GetGlobalCharacter(OwnerComp)->SetAniState(AIState::DEATH);

	return EBTNodeResult::Type::InProgress;
}



void UBTTask_DEATH::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DelataSeconds)
{
	DTime += DelataSeconds;
	if (DTime > 1.5f)
	{
		OwnerComp.GetAIOwner()->Destroy();
	}

}
