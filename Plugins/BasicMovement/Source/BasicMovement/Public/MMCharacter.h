#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MMCharacter.generated.h"

class UMMMovementSettings;
class UCharacterTrajectoryComponent;
class UInputAction;
class UInputMappingContext;
class USpringArmComponent;
class UCameraComponent;

UENUM(BlueprintType)
enum class EMMGait : uint8
{
	Walk UMETA(DisplayName = "Walk"),
	Run  UMETA(DisplayName = "Run")
};

UCLASS()
class BASICMOVEMENT_API AMMCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMMCharacter();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	/** Applique les reglages du DataAsset au CharacterMovementComponent */
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void ApplyMovementSettings();

	/** Change l'etat de deplacement (marche / course) */
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void SetGait(EMMGait NewGait);

	UFUNCTION(BlueprintPure, Category = "Movement")
	EMMGait GetGait() const { return CurrentGait; }
	
protected:
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StartRun(const FInputActionValue& Value);
	void StopRun(const FInputActionValue& Value);
	
	/** Etat de deplacement actuel */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	EMMGait CurrentGait = EMMGait::Walk;

	/** Reglages de mouvement (DataAsset a assigner dans le Blueprint) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	TObjectPtr<UMMMovementSettings> MovementSettings;
	
	/** Composant de trajectoire (Motion Trajectory) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Motion Matching")
	TObjectPtr<UCharacterTrajectoryComponent> TrajectoryComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UCameraComponent> FollowCamera;

	/** Mapping Context a assigner dans le Blueprint */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;
	
	/** Action de course (touche maintenue) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> SprintAction;
};