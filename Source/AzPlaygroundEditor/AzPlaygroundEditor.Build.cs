// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AzPlaygroundEditor : ModuleRules
{
	public AzPlaygroundEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UnrealEd"});

        PublicIncludePaths.AddRange(new string[] { "AzPlaygroundEditor/Public" });
        PrivateIncludePaths.AddRange(new string[] { "AzPlaygroundEditor/Private" });
        PublicDependencyModuleNames.AddRange(new string[] { "AzPlayground" });
        PrivateDependencyModuleNames.AddRange(new string[] { });
        //PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd" });
        PrivateIncludePathModuleNames.AddRange(new string[] { });
        DynamicallyLoadedModuleNames.AddRange(new string[] { });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
