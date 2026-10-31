#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DGPlayerController.generated.h"

/**
 * Owns the local player's input context. Input setup runs only on the owning client;
 * on the server a remote player's controller exists without a local player.
 */
UCLASS()
class DELIVERYGAME_API ADGPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};
