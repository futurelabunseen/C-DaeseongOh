// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayTagContainer.h"
#include "MDGA_Bullet_HitAndSpread.generated.h"

class AMDProjectile;
class UGameplayEffect;

/**
 * 
 */
UCLASS()
class MAKEDUNGEON_API UMDGA_Bullet_HitAndSpread : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UMDGA_Bullet_HitAndSpread();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

protected:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSubclassOf<AMDProjectile> ProjectileClass;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSubclassOf<UGameplayEffect> AttackDamageEffect;

	UPROPERTY(EditAnywhere, Category = "GAS")
	TArray<TSubclassOf<UGameplayEffect>> TargetDebuffEffects;

	UPROPERTY(EditAnywhere, Category = "GAS")
	FGameplayTag WeaponDebuff;

	UPROPERTY(EditAnywhere, Category = "GAS")
	FGameplayTag HitEffectTag;

	UPROPERTY(EditAnywhere, Category = "GAS")
	float DetectRadius;

private:
	uint8 bIsFirst : 1;
};
