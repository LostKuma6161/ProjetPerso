#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MMInputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS(BlueprintType)
class BASICMOVEMENT_API UMMInputConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	/** Mapping Context ajoute au joueur au demarrage */
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