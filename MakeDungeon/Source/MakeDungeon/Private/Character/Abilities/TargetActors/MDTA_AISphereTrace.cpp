// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Abilities/TargetActors/MDTA_AISphereTrace.h"
#include "Character/Abilities/AttributeSets/MDCharacterAttributeSet.h"
#include "Character/MDCharacterPlayer.h"
#include "Abilities/GameplayAbility.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Physics/MDCollision.h"
#include "DrawDebugHelpers.h"
#include "../MakeDungeon.h"

FGameplayAbilityTargetDataHandle AMDTA_AISphereTrace::MakeTargetData() const
{
	ACharacter* Character = CastChecked<ACharacter>(SourceActor);

	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(SourceActor);

	if (!ASC)
	{
		MD_LOG(LogMD, Log, TEXT("ASC not found"));
		return FGameplayAbilityTargetDataHandle();
	}

	const UMDCharacterAttributeSet* AttributeSet = ASC->GetSet<UMDCharacterAttributeSet>();
	if (!AttributeSet)
	{
		MD_LOG(LogMD, Log, TEXT("MDCharacterAttributeSet not found"));
		return FGameplayAbilityTargetDataHandle();
	}

	FHitResult OutHitResult;
	const float AttackRange = AttributeSet->GetAttackRange();
	const float AttackRadius = AttributeSet->GetAttackRadius();

	FCollisionQueryParams Params(SCENE_QUERY_STAT(AMDTA_AISphereTrace), false, Character);
	const FVector Forward = Character->GetActorForwardVector();
	const FVector Start = Character->GetActorLocation() + Forward * AttackRange;
	const FVector End = Start + AttackRange;

	bool HitDetected = GetWorld()->SweepSingleByChannel(OutHitResult, Start, End, FQuat::Identity, CCHANNEL_MDACTION, FCollisionShape::MakeSphere(AttackRadius), Params);

	AMDCharacterPlayer* HitPlayer = Cast<AMDCharacterPlayer>(OutHitResult.GetActor());

	FGameplayAbilityTargetDataHandle DataHandle;
	if (HitDetected && HitPlayer)
	{
		FGameplayAbilityTargetData_SingleTargetHit* TargetData = new FGameplayAbilityTargetData_SingleTargetHit(OutHitResult);
		DataHandle.Add(TargetData);
	}

#if ENABLE_DRAW_DEBUG

	if (bShowDebug)
	{
		FColor DrawColor = HitDetected && HitPlayer ? FColor::Green : FColor::Red;
		DrawDebugSphere(GetWorld(), Start, AttackRadius, 16, DrawColor, false, 5.f);
	}
#endif

	return DataHandle;
}
