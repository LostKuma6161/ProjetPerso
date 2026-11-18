#include "MMCharacter.h"

#include "CharacterTrajectoryComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "MMMovementSettings.h"
#include "InputAction.h"
#include "InputMappingContext.h"

AMMCharacter::AMMCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	// Le controller ne fait pas tourner le personnage : c'est le mouvement qui le fait
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	UCharacterMovementComponent* MoveComp = GetCharacterMovement();
	MoveComp->bOrientRotationToMovement = true;
	MoveComp->RotationRate = FRotator(0.f, 500.f, 0.f);
	MoveComp->MaxWalkSpeed = 500.f;
	MoveComp->MaxAcceleration = 1500.f;
	MoveComp->BrakingDecelerationWalking = 1500.f;

	// Camera
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Trajectoire pour Pose Search
	TrajectoryComponent = CreateDefaultSubobject<UCharacterTrajectoryComponent>(TEXT("TrajectoryComponent"));
}

void AMMCharacter::BeginPlay()
{
	Super::BeginPlay();

	ApplyMovementSettings();

	if (APlayerController* PC = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			if (DefaultMappingContext)
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}

void AMMCharacter::ApplyMovementSettings()
{
	// Si aucun DataAsset n'est assigne, on garde les valeurs du constructeur
	if (!MovementSettings)
	{
		return;
	}

	UCharacterMovementComponent* MoveComp = GetCharacterMovement();
	if (!MoveComp)
	{
		return;
	}

	// La vitesse depend de l'etat de deplacement actuel
	MoveComp->MaxWalkSpeed = (CurrentGait == EMMGait::Run)
		? MovementSettings->RunSpeed
		: MovementSettings->WalkSpeed;

	MoveComp->MaxAcceleration = MovementSettings->MaxAcceleration;
	MoveComp->BrakingDecelerationWalking = MovementSettings->BrakingDeceleration;
	MoveComp->RotationRate = FRotator(0.f, MovementSettings->RotationRateYaw, 0.f);
}

void AMMCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction)
		{
			EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMMCharacter::Move);
		}
		if (LookAction)
		{
			EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMMCharacter::Look);
		}
		if (SprintAction)
		{
			EIC->BindAction(SprintAction, ETriggerEvent::Started, this, &AMMCharacter::StartRun);
			EIC->BindAction(SprintAction, ETriggerEvent::Completed, this, &AMMCharacter::StopRun);
		}
	}
}

void AMMCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D Input = Value.Get<FVector2D>();

	if (Controller)
	{
		// Direction basee sur la rotation (yaw) de la camera
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Forward, Input.Y);
		AddMovementInput(Right, Input.X);
	}
}

void AMMCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D Input = Value.Get<FVector2D>();

	AddControllerYawInput(Input.X);
	AddControllerPitchInput(Input.Y);
}

void AMMCharacter::SetGait(EMMGait NewGait)
{
	if (CurrentGait == NewGait)
	{
		return;
	}

	CurrentGait = NewGait;
	ApplyMovementSettings();
}

void AMMCharacter::StartRun(const FInputActionValue& Value)
{
	SetGait(EMMGait::Run);
}

void AMMCharacter::StopRun(const FInputActionValue& Value)
{
	SetGait(EMMGait::Walk);
}