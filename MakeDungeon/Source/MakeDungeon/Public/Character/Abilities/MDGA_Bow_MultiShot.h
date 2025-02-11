// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MDGA_Bow_MultiShot.generated.h"

class AMDProjectile;
class UGameplayEffect;

/**
 * 
 */
UCLASS()
class MAKEDUNGEON_API UMDGA_Bow_MultiShot : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UMDGA_Bow_MultiShot();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void InputPressed(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) override;
	virtual void InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) override;
	virtual void CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

protected:
	

protected:
	// For Anim
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AnimPlaySpeed = 0.5f;

	// For Attack
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSubclassOf<AMDProjectile> ProjectileClass;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSubclassOf<UGameplayEffect> AttackDamageEffect;

	UPROPERTY(EditAnywhere, Category = "GAS")
	TSubclassOf<UGameplayEffect> TargetDebuffEffect;

private:
	// For Anim

	// For Attack
	float Range;
	double OuterAngle;
	double DecreaseAngle;
	FName SocketName;
};
