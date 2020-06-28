#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MultiWindowStyle.h"

class FMultiWindowCommands : public TCommands<FMultiWindowCommands>
{
public:

  FMultiWindowCommands()
    : TCommands<FMultiWindowCommands>(TEXT("MultiWindow"), NSLOCTEXT("Contexts", "MultiWindow", "MultiWindow Plugin"), NAME_None, FMultiWindowStyle::GetStyleSetName())
  {
  }

  // TCommands<> interface
  virtual void RegisterCommands() override;

public:
  TSharedPtr< FUICommandInfo > OpenPluginWindow;
};
