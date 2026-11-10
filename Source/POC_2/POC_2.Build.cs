// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class POC_2 : ModuleRules
{
	public POC_2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"POC_2",
			"POC_2/Variant_Platforming",
			"POC_2/Variant_Platforming/Animation",
			"POC_2/Variant_Combat",
			"POC_2/Variant_Combat/AI",
			"POC_2/Variant_Combat/Animation",
			"POC_2/Variant_Combat/Gameplay",
			"POC_2/Variant_Combat/Interfaces",
			"POC_2/Variant_Combat/UI",
			"POC_2/Variant_SideScrolling",
			"POC_2/Variant_SideScrolling/AI",
			"POC_2/Variant_SideScrolling/Gameplay",
			"POC_2/Variant_SideScrolling/Interfaces",
			"POC_2/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
