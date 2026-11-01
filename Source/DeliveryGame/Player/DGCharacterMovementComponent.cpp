#include "Player/DGCharacterMovementComponent.h"
#include "Player/DGStaminaComponent.h"
#include "GameFramework/Character.h"

class FDGSavedMove : public FSavedMove_Character
{
public:
	using Super = FSavedMove_Character;

	uint8 bSavedWantsToSprint : 1 = false;

	virtual void Clear() override
	{
		Super::Clear();
		bSavedWantsToSprint = false;
	}

	virtual uint8 GetCompressedFlags() const override
	{
		uint8 Flags = Super::GetCompressedFlags();
		if (bSavedWantsToSprint)
		{
			Flags |= FLAG_Custom_0;
		}
		return Flags;
	}

	virtual bool CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InCharacter, float MaxDelta) const override
	{
		if (bSavedWantsToSprint != static_cast<const FDGSavedMove*>(NewMove.Get())->bSavedWantsToSprint)
		{
			return false;
		}
		return Super::CanCombineWith(NewMove, InCharacter, MaxDelta);
	}

	virtual void SetMoveFor(ACharacter* C, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData) override
	{
		Super::SetMoveFor(C, InDeltaTime, NewAccel, ClientData);
		if (const UDGCharacterMovementComponent* Movement = Cast<UDGCharacterMovementComponent>(C->GetCharacterMovement()))
		{
			bSavedWantsToSprint = Movement->bWantsToSprint;
		}
	}

	virtual void PrepMoveFor(ACharacter* C) override
	{
		Super::PrepMoveFor(C);
		if (UDGCharacterMovementComponent* Movement = Cast<UDGCharacterMovementComponent>(C->GetCharacterMovement()))
		{
			Movement->bWantsToSprint = bSavedWantsToSprint;
		}
	}
};

class FDGNetworkPredictionData_Client : public FNetworkPredictionData_Client_Character
{
public:
	explicit FDGNetworkPredictionData_Client(const UCharacterMovementComponent& ClientMovement)
		: FNetworkPredictionData_Client_Character(ClientMovement)
	{
	}

	virtual FSavedMovePtr AllocateNewMove() override
	{
		return FSavedMovePtr(new FDGSavedMove());
	}
};

UDGCharacterMovementComponent::UDGCharacterMovementComponent()
{
	// Deliberate, heavy pace for horror; sprint is a short burst, not the default.
	MaxWalkSpeed = 300.f;
	MaxWalkSpeedCrouched = 150.f;
	SetCrouchedHalfHeight(55.f);
	NavAgentProps.bCanCrouch = true;
}

void UDGCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	Stamina = GetOwner() ? GetOwner()->FindComponentByClass<UDGStaminaComponent>() : nullptr;
}

bool UDGCharacterMovementComponent::IsSprinting() const
{
	if (!bWantsToSprint || !CharacterOwner || !IsMovingOnGround() || IsCrouching())
	{
		return false;
	}

	const FVector MoveDirection = GetCurrentAcceleration().GetSafeNormal2D();
	if (MoveDirection.IsNearlyZero()
		|| FVector::DotProduct(MoveDirection, CharacterOwner->GetActorForwardVector()) < SprintMinForwardDot)
	{
		return false;
	}

	return !Stamina || Stamina->CanSprint();
}

float UDGCharacterMovementComponent::GetMaxSpeed() const
{
	return IsSprinting() ? MaxSprintSpeed : Super::GetMaxSpeed();
}

void UDGCharacterMovementComponent::UpdateFromCompressedFlags(uint8 Flags)
{
	Super::UpdateFromCompressedFlags(Flags);
	bWantsToSprint = (Flags & FSavedMove_Character::FLAG_Custom_0) != 0;
}

FNetworkPredictionData_Client* UDGCharacterMovementComponent::GetPredictionData_Client() const
{
	if (!ClientPredictionData)
	{
		UDGCharacterMovementComponent* MutableThis = const_cast<UDGCharacterMovementComponent*>(this);
		MutableThis->ClientPredictionData = new FDGNetworkPredictionData_Client(*this);
	}
	return ClientPredictionData;
}
