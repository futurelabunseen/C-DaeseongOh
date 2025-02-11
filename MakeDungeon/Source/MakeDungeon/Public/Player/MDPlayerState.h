// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "MDPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MAKEDUNGEON_API AMDPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	AMDPlayerState();

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	class UMDCharacterAttributeSet* GetAttributeSet() const;

protected:
	UPROPERTY(EditAnywhere, Category = "GAS");
	TObjectPtr<UAbilitySystemComponent> ASC;

	UPROPERTY()
	TObjectPtr<class UMDCharacterAttributeSet> AttributeSet;
	
	UPROPERTY()
	TObjectPtr<class UMDCharacterSkillAttributeSet> SkillAttributeSet;
};
