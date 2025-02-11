// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MDCharacterBase.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "MDCharacterPlayer.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnGameplayTagChanged);

class USpringArmComponent;
class UEnhancedInputLocalPlayerSubsystem;

/**
 * 
 */
UCLASS()
class MAKEDUNGEON_API AMDCharacterPlayer : public AMDCharacterBase
{
	GENERATED_BODY()
	
public:
	AMDCharacterPlayer();

	virtual void PossessedBy(AController* NewController) override;
	virtual void BeginPlay() override;

	virtual FVector GetAttackLocation() const override;
	virtual FRotator GetAttackDirection(bool GetCursorDirection = false) const override;

	USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	void SetCurrentWeapon(const FGameplayTag& Tag);

	virtual void StopMovement() override;

	void SwapWeapon(FGameplayTag Tag, UEnhancedInputLocalPlayerSubsystem* SubSystem);

	void SetPierceCount(int32 Value);
	void SetVisiblePierceCount(bool IsVisible);

protected:
	virtual void SetDead() override;

	virtual void OnOutOfHealth() override;

	//Temp
	void EquipWeapon(FGameplayTag Tag);

public:
	FOnGameplayTagChanged OnGameplayTagChanged;

// Camera Section
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCamera;

// Input Section
	UPROPERTY(EditAnywhere, Category = "GAS")
	TMap<FGameplayTag, TSubclassOf<UGameplayAbility>> InputAbilities;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UMDWidgetComponent> PierceCount;

private:
	int32 DeathCount;
};
