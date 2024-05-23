// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/MDUserWidget.h"
#include "GameplayEffectTypes.h"
#include "MDHpBarUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAKEDUNGEON_API UMDHpBarUserWidget : public UMDUserWidget
{
	GENERATED_BODY()
	
public:
	void UpdateHpBar();

	virtual void SetAbilitySystemComponent(AActor* InOwner) override;
protected:

	virtual void OnHealthChanged(const FOnAttributeChangeData& ChangeData);
	virtual void OnMaxHealthChanged(const FOnAttributeChangeData& ChangeData);
	virtual void OnInvinsibleTagChanged(const FGameplayTag CallbackTag, int32 NewCount);

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UProgressBar> PbHpBar;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> TxtHpStat;

	float CurrentHealth = 0.f;
	float CurrentMaxHealth = 0.1f;

	FLinearColor HealthColor = FLinearColor::Red;
	FLinearColor InvincibleColor = FLinearColor::Green;
};
