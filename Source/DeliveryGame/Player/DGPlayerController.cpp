#include "Player/DGPlayerController.h"
#include "DeliveryGame.h"
#include "Player/DGInputSettings.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

void ADGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!IsLocalController())
	{
		return;
	}

	UInputMappingContext* MappingContext = GetDefault<UDGInputSettings>()->DefaultMappingContext.LoadSynchronous();
	if (!MappingContext)
	{
		UE_LOG(LogDeliveryGame, Warning, TEXT("No DefaultMappingContext set in Project Settings > Delivery Game Input."));
		return;
	}

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MappingContext, 0);
	}
}
