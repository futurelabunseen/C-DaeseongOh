// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MDGA_Skill_01.generated.h"

/**
 * 
 */
UCLASS()
class MAKEDUNGEON_API UMDGA_Skill_01 : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UMDGA_Skill_01();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void InputPressed(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) override;
	virtual void InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) override;

protected:
	UFUNCTION()
	void OnCompletedStart();

	UFUNCTION()
	void OnCompletedEnd();

	UFUNCTION()
	void OnInterruptedCallback();

private:
	uint8 bInputReleased : 1;
	float AnimPlaySpeed;
};
