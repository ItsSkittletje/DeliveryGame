#include "Player/DGStaminaComponent.h"
#include "Player/DGCharacterMovementComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"
#include "HAL/IConsoleManager.h"
#include "Net/UnrealNetwork.h"

static TAutoConsoleVariable<bool> CVarDebugStamina(
	TEXT("dg.Debug.Stamina"),
	false,
	TEXT("Show the local player's stamina on screen."));

UDGStaminaComponent::UDGStaminaComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicatedByDefault(true);
}

void UDGStaminaComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(UDGStaminaComponent, Stamina, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(UDGStaminaComponent, bExhausted, COND_OwnerOnly);
}

void UDGStaminaComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Other players' copies have no input to simulate; they never need stamina.
	if (GetOwnerRole() == ROLE_SimulatedProxy)
	{
		return;
	}

	const ACharacter* Character = Cast<ACharacter>(GetOwner());
	const UDGCharacterMovementComponent* Movement = Character ? Cast<UDGCharacterMovementComponent>(Character->GetCharacterMovement()) : nullptr;

	if (Movement && Movement->IsSprinting())
	{
		TimeSinceSprint = 0.f;
		Stamina = FMath::Max(0.f, Stamina - DrainRate * DeltaTime);
		if (Stamina <= 0.f)
		{
			bExhausted = true;
		}
	}
	else
	{
		TimeSinceSprint += DeltaTime;
		if (TimeSinceSprint >= RegenDelay)
		{
			Stamina = FMath::Min(MaxStamina, Stamina + RegenRate * DeltaTime);
		}
		if (bExhausted && Stamina >= RecoverThreshold)
		{
			bExhausted = false;
		}
	}

	if (CVarDebugStamina.GetValueOnGameThread() && Character && Character->IsLocallyControlled() && GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			reinterpret_cast<uint64>(this), 0.f, bExhausted ? FColor::Red : FColor::Green,
			FString::Printf(TEXT("Stamina %.0f / %.0f%s  Sprinting: %s"),
				Stamina, MaxStamina, bExhausted ? TEXT(" (exhausted)") : TEXT(""),
				Movement && Movement->IsSprinting() ? TEXT("yes") : TEXT("no")));
	}
}
