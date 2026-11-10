// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Poc_ProjetPersoGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class APoc_ProjetPersoGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	APoc_ProjetPersoGameMode();
};



