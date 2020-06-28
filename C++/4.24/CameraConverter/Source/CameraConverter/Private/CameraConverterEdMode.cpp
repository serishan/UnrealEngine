// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CameraConverterEdMode.h"
#include "CameraConverterEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"

const FEditorModeID FCameraConverterEdMode::EM_CameraConverterEdModeId = TEXT("EM_CameraConverterEdMode");

FCameraConverterEdMode::FCameraConverterEdMode()
{
  UISettings = NewObject<UCameraConverterTool>(GetTransientPackage(), TEXT("NewUISettings"), RF_Transactional);
  UISettings->SetParent(this);
}

FCameraConverterEdMode::~FCameraConverterEdMode()
{

}

void FCameraConverterEdMode::AddReferencedObjects(FReferenceCollector& Collector)
{
  FEdMode::AddReferencedObjects(Collector);
  Collector.AddReferencedObject(UISettings);
}

void FCameraConverterEdMode::Enter()
{
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FCameraConverterEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void FCameraConverterEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool FCameraConverterEdMode::UsesToolkits() const
{
	return true;
}




