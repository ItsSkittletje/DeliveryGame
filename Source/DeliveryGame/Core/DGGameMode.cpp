#include "Core/DGGameMode.h"
#include "Core/DGGameState.h"
#include "Core/DGPlayerState.h"
#include "Player/DGCharacter.h"
#include "Player/DGPlayerController.h"

ADGGameMode::ADGGameMode()
{
	DefaultPawnClass = ADGCharacter::StaticClass();
	PlayerControllerClass = ADGPlayerController::StaticClass();
	GameStateClass = ADGGameState::StaticClass();
	PlayerStateClass = ADGPlayerState::StaticClass();
}
