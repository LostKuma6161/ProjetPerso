// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Poc_ProjetPerso : ModuleRules
{
	public Poc_ProjetPerso(ReadOnlyTargetRules Target) : base(Target)
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
			"Poc_ProjetPerso",
			"Poc_ProjetPerso/Variant_Platforming",
			"Poc_ProjetPerso/Variant_Platforming/Animation",
			"Poc_ProjetPerso/Variant_Combat",
			"Poc_ProjetPerso/Variant_Combat/AI",
			"Poc_ProjetPerso/Variant_Combat/Animation",
			"Poc_ProjetPerso/Variant_Combat/Gameplay",
			"Poc_ProjetPerso/Variant_Combat/Interfaces",
			"Poc_ProjetPerso/Variant_Combat/UI",
			"Poc_ProjetPerso/Variant_SideScrolling",
			"Poc_ProjetPerso/Variant_SideScrolling/AI",
			"Poc_ProjetPerso/Variant_SideScrolling/Gameplay",
			"Poc_ProjetPerso/Variant_SideScrolling/Interfaces",
			"Poc_ProjetPerso/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
