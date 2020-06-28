#pragma once

#include "Input/Reply.h"
#include "IDetailCustomization.h"

class FCameraConverterToolCustomization : public IDetailCustomization
{
public:
  virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

  static TSharedRef<IDetailCustomization> MakeInstance();
  static FReply ExecuteCommand(IDetailLayoutBuilder* DetailBuilder, UFunction* MethodToExecute);
};