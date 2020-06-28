// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CameraConverter.h"
#include "CameraConverterEdMode.h"

#include "Styling/SlateStyleRegistry.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FCameraConverterModule"
#define IMAGE_PLUGIN_BRUSH(RelativePath, ...) FSlateImageBrush(FCameraConverterModule::InContent(RelativePath, ".png"), __VA_ARGS__)

TSharedPtr<class FSlateStyleSet> FCameraConverterModule::StyleSet = nullptr;

TSharedPtr<class ISlateStyle> FCameraConverterModule::Get(void) { return StyleSet; }

void FCameraConverterModule::StartupModule()
{
  Initialize();

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FEditorModeRegistry::Get().RegisterMode<FCameraConverterEdMode>(FCameraConverterEdMode::EM_CameraConverterEdModeId, 
    LOCTEXT("CameraConverterEdModeName", "CameraConverterEdMode"), 
    FSlateIcon(GetStyleSetName(), "LevelEditor.CameraConverter", "LevelEditor.CameraConverter.Small"),
    true);
}

void FCameraConverterModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(FCameraConverterEdMode::EM_CameraConverterEdModeId);
}

BEGIN_FUNCTION_BUILD_OPTIMIZATION

void FCameraConverterModule::Initialize(void)
{
  if (StyleSet.IsValid()) return;

  //Icon Sizes
  const FVector2D Icon8x8(8.0f, 8.0f);
  const FVector2D Icon16x16(16.0f, 16.0f);
  const FVector2D Icon20x20(20.0f, 20.0f);
  const FVector2D Icon40x40(40.0f, 40.0f);

  StyleSet = MakeShareable(new FSlateStyleSet(GetStyleSetName()));
  StyleSet->SetContentRoot(IPluginManager::Get().FindPlugin("CameraConverter")->GetBaseDir() / TEXT("Resources"));
  StyleSet->SetCoreContentRoot(FPaths::EngineContentDir() / TEXT("Slate"));

  StyleSet->Set("LevelEditor.CameraConverter", new IMAGE_PLUGIN_BRUSH("CameraIcon", Icon40x40));
  StyleSet->Set("LevelEditor.CameraConverter.Small", new IMAGE_PLUGIN_BRUSH("CameraIcon", Icon20x20));
  StyleSet->Set("LevelEditor.CameraConverter.Selected", new IMAGE_PLUGIN_BRUSH("CameraIcon", Icon40x40));
  StyleSet->Set("LevelEditor.CameraConverter.Selected.Small", new IMAGE_PLUGIN_BRUSH("CameraIcon", Icon20x20));

  FSlateStyleRegistry::RegisterSlateStyle(*StyleSet.Get());
}

END_FUNCTION_BUILD_OPTIMIZATION

#undef IMAGE_PLUGIN_BRUSH

FName FCameraConverterModule::GetStyleSetName(void)
{
  static FName StyleName(TEXT("CameraConverter"));
  return StyleName;
}

FString FCameraConverterModule::InContent(const FString& RelativePath, const ANSICHAR* Extension)
{
  static FString ContentDir = IPluginManager::Get().FindPlugin("CameraConverter")->GetBaseDir() / TEXT("Resources");
  return (ContentDir / RelativePath) + Extension;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCameraConverterModule, CameraConverter)