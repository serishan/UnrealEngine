// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Toolkits/BaseToolkit.h"
#include "CameraConverterEdMode.h"
#include "Widgets/Notifications/SErrorText.h"

class IDetailsView;
class SCameraConverter;
struct FPropertyAndParent;

class FCameraConverterEdModeToolkit : public FModeToolkit
{
public:

	FCameraConverterEdModeToolkit();
	
	/** FModeToolkit interface */
	virtual void Init(const TSharedPtr<IToolkitHost>& InitToolkitHost) override;

	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FCameraConverterEdMode* GetEditorMode() const override;
  virtual TSharedPtr<class SWidget> GetInlineContent() const override;

private:

  TSharedPtr<SCameraConverter> CameraConverterWidget;
};

class SCameraConverter : public SCompoundWidget
{
public:
  SLATE_BEGIN_ARGS(SCameraConverter) {}
  SLATE_END_ARGS()

public:
  void Construct(const FArguments& InArgs, TSharedRef<FCameraConverterEdModeToolkit> InParentToolkit);
  void RefreshDetailPanel();

protected:
  class FCameraConverterEdMode* GetEditorMode() const;

  FText GetErrorText() const;
  bool GetEditorIsEnabled() const;
  bool GetIsPropertyVisible(const FPropertyAndParent& PropertyAndParent) const { return true; }

  TSharedPtr<SErrorText> Error;
  TSharedPtr<IDetailsView> DetailPanel;
};