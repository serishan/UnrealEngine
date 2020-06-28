// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "VP_Tools.h"

#define LOCTEXT_NAMESPACE "FVP_ToolsModule"

void FVP_ToolsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FVP_ToolsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FVP_ToolsModule, VP_Tools)