#include "MultiWindowCommands.h"

#define LOCTEXT_NAMESPACE "FMultiWindowModule"

void FMultiWindowCommands::RegisterCommands()
{
  UI_COMMAND(OpenPluginWindow, "MultiWindow", "Bring up MultiWindow window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
