#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DGCharacter.generated.h"

class UCameraComponent;
struct FInputActionValue;

/**
 * First-person player character. Movement goes through UCharacterMovementComponent,
 * which already provides client prediction and server correction for multiplayer.
 * Milestone 1 scope: camera, walk and mouse look only.
 */
UCLASS()
class DELIVERYGAME_API ADGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ADGCharacter();

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UCameraComponent> FirstPersonCamera;
};
