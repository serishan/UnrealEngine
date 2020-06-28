// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MultiWindow : ModuleRules
{
	public MultiWindow(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
    PrecompileForTargets = PrecompileTargetsType.Any;
    bPrecompile = true;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
        "Renderer",
        "Projects",
        "CinematicCamera"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
        "InputCore",
        "CoreUObject",
        "Engine",
        "Slate",
        "SlateCore",
        "RHI",
        "RenderCore",
        "ApplicationCore",
        "UMG",
        "Json"
				// ... add private dependencies that you statically link with here ...	
			}
			);

    if (Target.Type == TargetRules.TargetType.Editor)
    {
      PrivateDependencyModuleNames.AddRange(
        new string[]
        {
          "DesktopPlatform",
          "UnrealEd",
          "LevelEditor",
          "MainFrame"
        }
        );
    }

    DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
