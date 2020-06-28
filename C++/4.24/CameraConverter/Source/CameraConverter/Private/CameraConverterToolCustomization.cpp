#include "CameraConverterToolCustomization.h"
#include "PropertyEditing.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SComboButton.h"

TSharedRef<IDetailCustomization> FCameraConverterToolCustomization::MakeInstance()
{
  return MakeShareable(new FCameraConverterToolCustomization);
}

void FCameraConverterToolCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
  TSet<UClass*> Classes;

  TArray<TWeakObjectPtr<UObject>> ObjectBeingCustomized;
  DetailBuilder.GetObjectsBeingCustomized(ObjectBeingCustomized);

  for (auto WeakObject : ObjectBeingCustomized)
  {
    if (UObject* Instance = WeakObject.Get()) Classes.Add(Instance->GetClass());
  }

  //Create Commands Category
  IDetailCategoryBuilder& Category = DetailBuilder.EditCategory("Functions");

  //Create Button For Each Element
  for (UClass* Class : Classes)
  {
    for (TFieldIterator<UFunction> FuncIt(Class); FuncIt; ++FuncIt)
    {
      UFunction* Function = *FuncIt;
      if (Function->HasAnyFunctionFlags(FUNC_Exec) && (Function->NumParms == 0))
      {
        const FString FunctionName = Function->GetName();
        const FText ButtonCaption = FText::FromString(FunctionName);
        Category.AddCustomRow(ButtonCaption)
          .ValueContent()
          [
            SNew(SButton)
            .Text(ButtonCaption)
            .OnClicked(FOnClicked::CreateStatic(&FCameraConverterToolCustomization::ExecuteCommand, &DetailBuilder, Function))
          ];
      }
    }
  }
}

FReply FCameraConverterToolCustomization::ExecuteCommand(IDetailLayoutBuilder* DetailBuilder, UFunction* MethodToExecute)
{
  TArray<TWeakObjectPtr<UObject>> ObjectBeingCustomized;
  DetailBuilder->GetObjectsBeingCustomized(ObjectBeingCustomized);

  for (auto WeakObject : ObjectBeingCustomized)
  {
    if (UObject* Instance = WeakObject.Get())
      Instance->CallFunctionByNameWithArguments(*MethodToExecute->GetName(), *GLog, nullptr, true);
  }

  return FReply::Handled();
}