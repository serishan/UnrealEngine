// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CameraConverter : ModuleRules
{
	public CameraConverter(ReadOnlyTargetRules Target) : base(Target)
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
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"InputCore",
				"UnrealEd",
				"LevelEditor",
        "LevelSequence",
        "MovieScene",
        "CinematicCamera",
        "MovieSceneTracks"
				// ... add private dependencies that you statically link with here ...	
			}
			);

    if (Target.Type == TargetRules.TargetType.Editor)
    {
      PrivateDependencyModuleNames.AddRange(
        new string[]
        {
          //"UnrealEd",
          "PropertyEditor",
          "DesktopPlatform",
          "MainFrame",
          "MovieSceneTools",
          "Sequencer",
          "Projects"
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