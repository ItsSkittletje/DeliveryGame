#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "DGPlayerState.generated.h"

/**
 * Replicated per-player state that must survive pawn death/respawn
 * (e.g. downed status, clues found). Populated as those systems arrive.
 */
UCLASS()
class DELIVERYGAME_API ADGPlayerState : public APlayerState
{
	GENERATED_BODY()
};
