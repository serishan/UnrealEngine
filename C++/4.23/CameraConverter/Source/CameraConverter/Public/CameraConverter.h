// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#include "Styling/SlateStyle.h"
#include "Styling/ISlateStyle.h"

class FCameraConverterModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

  static void Initialize(void);

  static TSharedPtr<class ISlateStyle> Get(void);

  static FName GetStyleSetName(void);

private:
  static FString InContent(const FString& RelativePath, const ANSICHAR* Extension);

  static TSharedPtr<class FSlateStyleSet> StyleSet;
};
