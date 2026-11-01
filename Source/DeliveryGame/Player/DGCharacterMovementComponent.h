#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DGCharacterMovementComponent.generated.h"

class UDGStaminaComponent;

/**
 * Adds a client-predicted sprint to the standard character movement.
 * The sprint request travels to the server inside each saved move (FLAG_Custom_0),
 * so the server simulates the same speed the client predicted and corrections stay rare.
 */
UCLASS()
class DELIVERYGAME_API UDGCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

	friend class FDGSavedMove;

public:
	UDGCharacterMovementComponent();

	void SetWantsToSprint(bool bNewWantsToSprint) { bWantsToSprint = bNewWantsToSprint; }

	/** True while actually moving at sprint speed (button held, on ground, moving forward, stamina left). */
	UFUNCTION(BlueprintPure, Category = "Movement|Sprint")
	bool IsSprinting() const;

	virtual float GetMaxSpeed() const override;
	virtual void UpdateFromCompressedFlags(uint8 Flags) override;
	virtual FNetworkPredictionData_Client* GetPredictionData_Client() const override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement|Sprint", meta = (ClampMin = "0", ForceUnits = "cm/s"))
	float MaxSprintSpeed = 520.f;

	/** Sprint only counts when the movement direction is within this cosine of the facing direction (0.5 = 60 degrees). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement|Sprint", meta = (ClampMin = "-1", ClampMax = "1"))
	float SprintMinForwardDot = 0.5f;

protected:
	virtual void BeginPlay() override;

private:
	bool bWantsToSprint = false;

	/** Optional. Without a stamina component, sprint is unlimited. */
	UPROPERTY(Transient)
	TObjectPtr<UDGStaminaComponent> Stamina;
};
