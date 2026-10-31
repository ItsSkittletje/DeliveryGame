#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DGGameMode.generated.h"

/**
 * Server-only authority for a play session. Exists only on the server (listen or dedicated),
 * so rules that must not be trusted to clients (mission outcome, entity spawning, event pacing)
 * are owned here or by server-side subsystems it creates.
 */
UCLASS()
class DELIVERYGAME_API ADGGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADGGameMode();
};
