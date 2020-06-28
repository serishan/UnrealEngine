// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CameraConverterEdModeToolkit.h"
#include "CameraConverterEdMode.h"
#include "Engine/Selection.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "EditorModeManager.h"

#include "CameraConverterToolCustomization.h"
#include "PropertyEditorModule.h"

#define LOCTEXT_NAMESPACE "FCameraConverterEdModeToolkit"

FCameraConverterEdModeToolkit::FCameraConverterEdModeToolkit()
{
}

void FCameraConverterEdModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost)
{
  FCameraConverterEdMode* CameraEdMode = GetEditorMode();
  CameraConverterWidget = SNew(SCameraConverter, SharedThis(this));
	FModeToolkit::Init(InitToolkitHost);
}

FName FCameraConverterEdModeToolkit::GetToolkitFName() const
{
	return FName("CameraConverterEdMode");
}

FText FCameraConverterEdModeToolkit::GetBaseToolkitName() const
{
	return NSLOCTEXT("CameraConverterEdModeToolkit", "DisplayName", "CameraConverterEdMode Tool");
}

FCameraConverterEdMode* FCameraConverterEdModeToolkit::GetEditorMode() const
{
  return (FCameraConverterEdMode*)GLevelEditorModeTools().GetActiveMode(FCameraConverterEdMode::EM_CameraConverterEdModeId);
}

TSharedPtr<class SWidget> FCameraConverterEdModeToolkit::GetInlineContent() const
{
  return CameraConverterWidget;
}

/*****************************************************************************/

BEGIN_FUNCTION_BUILD_OPTIMIZATION

void SCameraConverter::Construct(const FArguments& InArgs, TSharedRef<FCameraConverterEdModeToolkit> InParentToolkit)
{
  FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
  PropertyEditorModule.RegisterCustomClassLayout("NewVertexControllerTool",
    FOnGetDetailCustomizationInstance::CreateStatic(&FCameraConverterToolCustomization::MakeInstance));
  PropertyEditorModule.NotifyCustomizationModuleChanged();

  FDetailsViewArgs DetailsViewArgs(false, false, false, FDetailsViewArgs::HideNameArea);

  DetailPanel = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
  DetailPanel->SetIsPropertyVisibleDelegate(FIsPropertyVisible::CreateSP(this, &SCameraConverter::GetIsPropertyVisible));

  FCameraConverterEdMode* NewCameraMode = GetEditorMode();

  ChildSlot
    [
      SNew(SVerticalBox)
      + SVerticalBox::Slot()
      .Padding(0)
      [
        SNew(SVerticalBox)
        .IsEnabled(this, &SCameraConverter::GetEditorIsEnabled)
        + SVerticalBox::Slot()
        .Padding(0)
        [
          DetailPanel.ToSharedRef()
        ]
      ]
    ];

  RefreshDetailPanel();
}

END_FUNCTION_BUILD_OPTIMIZATION

FCameraConverterEdMode* SCameraConverter::GetEditorMode() const
{
  return (FCameraConverterEdMode*)GLevelEditorModeTools().GetActiveMode(FCameraConverterEdMode::EM_CameraConverterEdModeId);
}

FText SCameraConverter::GetErrorText() const
{
  FCameraConverterEdMode* CameraMode = GetEditorMode();
  return FText::GetEmpty();
}

bool SCameraConverter::GetEditorIsEnabled() const
{
  FCameraConverterEdMode* CameraMode = GetEditorMode();

  if (CameraMode) return true;

  return false;
}

void SCameraConverter::RefreshDetailPanel()
{
  FCameraConverterEdMode* CameraMode = GetEditorMode();

  if (CameraMode)
    DetailPanel->SetObject(CameraMode->UISettings, true);
}

#undef LOCTEXT_NAMESPACE
