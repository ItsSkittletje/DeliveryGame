#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DGStaminaComponent.generated.h"

/**
 * Sprint stamina. Simulated on the server and predicted on the owning client;
 * the server value replicates to the owner only. Drains while the owner's
 * UDGCharacterMovementComponent reports IsSprinting().
 *
 * Once fully drained the player is "exhausted" and cannot sprint again until
 * stamina recovers to RecoverThreshold, which prevents stutter-sprinting at 0.
 */
UCLASS(ClassGroup = (DeliveryGame), meta = (BlueprintSpawnableComponent))
class DELIVERYGAME_API UDGStaminaComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UDGStaminaComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	bool CanSprint() const { return !bExhausted && Stamina > 0.f; }

	UFUNCTION(BlueprintPure, Category = "Stamina")
	float GetStamina() const { return Stamina; }

	UFUNCTION(BlueprintPure, Category = "Stamina")
	float GetStaminaFraction() const { return MaxStamina > 0.f ? Stamina / MaxStamina : 0.f; }

	UFUNCTION(BlueprintPure, Category = "Stamina")
	bool IsExhausted() const { return bExhausted; }

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina", meta = (ClampMin = "1"))
	float MaxStamina = 100.f;

	/** Per second while sprinting. 100 / 20 = 5 seconds of continuous sprint. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina", meta = (ClampMin = "0"))
	float DrainRate = 20.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina", meta = (ClampMin = "0"))
	float RegenRate = 12.5f;

	/** Seconds after sprinting stops before stamina starts to recover. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina", meta = (ClampMin = "0", ForceUnits = "s"))
	float RegenDelay = 1.f;

	/** Stamina required to sprint again after becoming exhausted. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina", meta = (ClampMin = "0"))
	float RecoverThreshold = 30.f;

private:
	UPROPERTY(Replicated)
	float Stamina = 100.f;

	UPROPERTY(Replicated)
	bool bExhausted = false;

	float TimeSinceSprint = 0.f;
};
