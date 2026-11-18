#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MMMovementSettings.generated.h"

UCLASS(BlueprintType)
class BASICMOVEMENT_API UMMMovementSettings : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	/** Vitesse de marche (cm/s) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Speed", meta = (ClampMin = "0"))
	float WalkSpeed = 200.f;

	/** Vitesse de course (cm/s), utilisee a l'etape 4 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Speed", meta = (ClampMin = "0"))
	float RunSpeed = 500.f;

	/** Acceleration max (cm/s²) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Acceleration", meta = (ClampMin = "0"))
	float MaxAcceleration = 1500.f;

	/** Deceleration au freinage (cm/s²) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Acceleration", meta = (ClampMin = "0"))
	float BrakingDeceleration = 1500.f;

	/** Vitesse de rotation vers la direction du mouvement (deg/s) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rotation", meta = (ClampMin = "0"))
	float RotationRateYaw = 500.f;
};