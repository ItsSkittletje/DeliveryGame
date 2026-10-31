#include "Player/DGCharacter.h"
#include "DeliveryGame.h"
#include "Player/DGInputSettings.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"

ADGCharacter::ADGCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(40.f, 90.f);

	// First-person: the body turns with the controller, the camera pitches with it.
	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	// Deliberate walking pace; sprint/crouch speeds arrive in Milestone 2.
	GetCharacterMovement()->MaxWalkSpeed = 300.f;

	BaseEyeHeight = 64.f;

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	FirstPersonCamera->SetRelativeLocation(FVector(0.f, 0.f, BaseEyeHeight));
	FirstPersonCamera->bUsePawnControlRotation = true;
}

void ADGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!EnhancedInput)
	{
		UE_LOG(LogDeliveryGame, Error, TEXT("Input component is not an EnhancedInputComponent. Check DefaultInput.ini."));
		return;
	}

	const UDGInputSettings* Settings = GetDefault<UDGInputSettings>();

	if (UInputAction* MoveAction = Settings->MoveAction.LoadSynchronous())
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADGCharacter::Move);
	}
	if (UInputAction* LookAction = Settings->LookAction.LoadSynchronous())
	{
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADGCharacter::Look);
	}
}

void ADGCharacter::Move(const FInputActionValue& Value)
{
	// X = right, Y = forward.
	const FVector2D Axis = Value.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector(), Axis.Y);
	AddMovementInput(GetActorRightVector(), Axis.X);
}

void ADGCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D Axis = Value.Get<FVector2D>();
	AddControllerYawInput(Axis.X);
	AddControllerPitchInput(-Axis.Y);
}
