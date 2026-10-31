#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "DGGameState.generated.h"

/**
 * Replicated session state visible to every player: active house, shared objectives,
 * mission phase. Populated from Milestone 4/5 onward.
 */
UCLASS()
class DELIVERYGAME_API ADGGameState : public AGameStateBase
{
	GENERATED_BODY()
};
