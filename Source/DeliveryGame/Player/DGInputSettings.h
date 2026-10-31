#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "DGInputSettings.generated.h"

class UInputAction;
class UInputMappingContext;

/**
 * Project Settings > Game > Delivery Game Input.
 * Points C++ at the Enhanced Input assets so no asset paths are hardcoded and no
 * Blueprint subclass is required just to wire up input. Stored in DefaultGame.ini.
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Delivery Game Input"))
class DELIVERYGAME_API UDGInputSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(Config, EditAnywhere, Category = "Input|Actions")
	TSoftObjectPtr<UInputAction> MoveAction;

	UPROPERTY(Config, EditAnywhere, Category = "Input|Actions")
	TSoftObjectPtr<UInputAction> LookAction;
};
