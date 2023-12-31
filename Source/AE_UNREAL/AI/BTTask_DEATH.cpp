// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_DEATH.h"
#include "Monster.h"

// 1. 몬스터 죽는 애니메이션을 끝나면 화면에서 완전히 사라져야 합니다.

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


	GetBlackboardComponent(OwnerComp)->GetValueAsFloat(TEXT("deathtime"));

	APawn* MonPawn = OwnerComp.GetAIOwner()->GetPawn();
	AMonster* MonMon = Cast<AMonster>(MonPawn);
	MonMon->DeathTime += DelataSeconds;

	if (MonMon->DeathTime > 1.2f)
	{
		OwnerComp.GetAIOwner()->GetPawn()->Destroy();
	}
	//123
}

