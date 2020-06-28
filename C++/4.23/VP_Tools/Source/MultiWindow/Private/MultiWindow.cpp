#include "MultiWindow.h"
#include "MultiWindowStyle.h"
#include "MultiWindowCommands.h"
#include "PlaySceneSlate.h"

#include "Framework/Docking/TabManager.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Notifications/NotificationManager.h"

/** Slate - Docking */
#include "Widgets/Docking/SDockTab.h"

/** Slate - Layout */
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SGridPanel.h"
#include "Widgets/Layout/SUniformGridPanel.h"

/** Slate - Text */
#include "Widgets/Text/STextBlock.h"

/** Slate - Input */
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SEditableTextBox.h"

/** Slate - Notification */
#include "Widgets/Notifications/SNotificationList.h"

#include "Kismet/GameplayStatics.h"
#include "CineCameraActor.h"
#include "CineCameraComponent.h"

#include "Misc/MessageDialog.h"
#include "Misc/FileHelper.h"

#if WITH_EDITOR
#include "LevelEditor.h"
#include "LevelEditorViewport.h"
#include "Editor/EditorEngine.h"
#include "EditorStyleSet.h"

#include "IDesktopPlatform.h"
#include "DesktopPlatformModule.h"
#include "Interfaces/IMainFrameModule.h"

#include "Engine/ObjectLibrary.h"

#endif

#define LOCTEXT_NAMESPACE "FMultiWindow"

static const FName MultiWindowTabName("MultiWindow");

void FMultiWindowModule::StartupModule()
{
  FMultiWindowStyle::Initialize();
  FMultiWindowStyle::ReloadTextures();

  FMultiWindowCommands::Register();

  PluginCommands = MakeShareable(new FUICommandList);
  PluginCommands->MapAction(
  FMultiWindowCommands::Get().OpenPluginWindow,
    FExecuteAction::CreateRaw(this, &FMultiWindowModule::PluginButtonClicked),
    FCanExecuteAction());

  FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

  TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
  ToolbarExtender->AddToolBarExtension(
    "Settings", 
    EExtensionHook::After, 
    PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FMultiWindowModule::AddToolbarExtension));

  LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);

  FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
    MultiWindowTabName,
    FOnSpawnTab::CreateRaw(this, &FMultiWindowModule::OnSpawnPluginTab))
    .SetDisplayName(LOCTEXT("FMultiWindowTabTitle", "MultiWindow"))
    .SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FMultiWindowModule::ShutdownModule()
{
  FMultiWindowStyle::Shutdown();
  FMultiWindowCommands::Unregister();
  FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(MultiWindowTabName);
}

void FMultiWindowModule::PluginButtonClicked()
{
  FGlobalTabmanager::Get()->InvokeTab(MultiWindowTabName);
}

TWeakObjectPtr<UTextureRenderTarget2D> FMultiWindowModule::GetTextureRenderTarget2D(int index)
{
  return RenderTarget2DArray[index];
}

TArray<TWeakObjectPtr<UTextureRenderTarget2D>> FMultiWindowModule::GetTextureRenderTarget2DArray()
{
  return RenderTarget2DArray;
}

void FMultiWindowModule::SetTextureRenderTarget2D(UTextureRenderTarget2D* RenderTarget)
{
  /** First, Delete STALE Values */
  for (int i = 0; i < RenderTarget2DArray.Num(); ++i)
  {
    if (RenderTarget2DArray[i].IsStale())
    {
      RenderTarget2DArray.RemoveAt(i);
      --i;
    }
  }

  /** Next, Add the Original Render Texture */
  if (RenderTarget2DArray.Find(RenderTarget) == INDEX_NONE && RenderTarget != nullptr)
    RenderTarget2DArray.Add(RenderTarget);
}

void FMultiWindowModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
  Builder.AddToolBarButton(FMultiWindowCommands::Get().OpenPluginWindow);
}

TSharedRef<SWidget> FMultiWindowModule::MakeWidgetForOptions(TSharedPtr<FString> InOption)
{
  return SNew(STextBlock).Text(FText::FromString(*InOption));
}

void FMultiWindowModule::OnMonitorChanged(TSharedPtr<FString> NewValue, ESelectInfo::Type SelectInfo)
{
  MonitorSelection = NewValue;
}

FText FMultiWindowModule::GetMonitorSelection() const
{
  return MonitorSelection.IsValid() ? FText::FromString(*MonitorSelection) : FText::GetEmpty();
}

FReply FMultiWindowModule::RefreshDisplayMonitorList()
{
  MonitorComboList.Empty();
  FDisplayMetrics::RebuildDisplayMetrics(DisplayMonitors);

  /** First, Get all of the monitor location (Left/Main/Right */
  FString MainMonitor;
  TArray<FString> LeftMonitor, RightMonitor;

  int MonitorCount = DisplayMonitors.MonitorInfo.Num();

  for (int i = 0; i < MonitorCount; ++i)
  {
    if (DisplayMonitors.MonitorInfo[i].DisplayRect.Left < 0)
      LeftMonitor.Add(DisplayMonitors.MonitorInfo[i].Name);

    else if (DisplayMonitors.MonitorInfo[i].DisplayRect.Left > 0)
      RightMonitor.Add(DisplayMonitors.MonitorInfo[i].Name);

    else
      MainMonitor = DisplayMonitors.MonitorInfo[i].Name;
  }

  /** Next Add Monitor Names to Monitor Combo List with custom Name */
  FString NewCustomName;
  for (int i = 0; i < LeftMonitor.Num(); ++i)
  {
    NewCustomName = (LeftMonitor[i] + "(Left" + FString::FromInt(i + 1) + ")");
    MonitorComboList.Add(MakeShareable(new FString(NewCustomName)));
  }

  NewCustomName = (MainMonitor + "(Main)");
  MonitorComboList.Add(MakeShareable(new FString(NewCustomName)));

  for (int i = 0; i < RightMonitor.Num(); ++i)
  {
    NewCustomName = (RightMonitor[i] + "(Right" + FString::FromInt(i + 1) + ")");
    MonitorComboList.Add(MakeShareable(new FString(NewCustomName)));
  }

  MonitorComboBox->RefreshOptions();

  return FReply::Handled();
}

void FMultiWindowModule::RefreshWindowList()
{
  BookMarkActor.Empty();
  BookMarkedCamera.Empty();
  RenderTarget2DArray.Empty();

  World = GEditor->GetEditorWorldContext().World();

  TArray<AActor*> ActorList;
  UGameplayStatics::GetAllActorsWithTag(World, "HMD", ActorList);

  for (int i = 0; i < ActorList.Num(); ++i)
  {
    auto RenderTarget = ActorList[i]->GetComponentByClass(UPCSceneCaptureComponent2D::StaticClass());
    IPlayScene::Get().SetTextureRenderTarget2D(Cast<UPCSceneCaptureComponent2D>(RenderTarget)->TextureTarget);

    if (ActorList[i]->ActorHasTag("BookMark"))
    {
      BookMarkActor.Add(Cast<ABookMarkActor>(ActorList[i]));

      FString ItemData = "Name: " + ActorList[i]->GetActorLabel() + "\n" + \
        "\tLocation: (" + ActorList[i]->GetActorLocation().ToString() + ")\n" + \
        "\tRotation: (" + ActorList[i]->GetActorRotation().ToString() + ")\n";

      BookMarkedCamera.Add(MakeShareable(new FString(ItemData)));
    }
  }

  BookMarkListView->SetScrollbarVisibility(EVisibility::Visible);
  BookMarkListView->RequestListRefresh();
}

FReply FMultiWindowModule::GenerateWindows()
{
  RefreshWindowList();

  if (MonitorComboList.Num() != 0)
  {
    if (!Opened)
    {
      if (RenderTarget2DArray.Num() != 0)
      {
        int NativeWidth, NativeHeight;
        FPlatformRect Rect;
        FString LeftS, RightS;
        (*MonitorSelection).Split("(", &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromStart);

        /** Initialize Needed */
        for (int i = 0; i < DisplayMonitors.MonitorInfo.Num(); ++i)
        {
          if (LeftS.Equals(DisplayMonitors.MonitorInfo[i].Name))
          {
            Rect = DisplayMonitors.MonitorInfo[i].DisplayRect;
            NativeWidth = DisplayMonitors.MonitorInfo[i].NativeWidth;
            NativeHeight = DisplayMonitors.MonitorInfo[i].NativeHeight;
            break;
          }
        }

        World = GEditor->GetEditorWorldContext().World();

        TArray<AActor*> ActorList;
        UGameplayStatics::GetAllActorsWithTag(World, "HMD", ActorList);

        FoundCameraActor = ActorList;

        for (int i = 0; i < ActorList.Num(); ++i)
        {
          auto FoundComponent = ActorList[i]->GetComponentByClass(UCineCameraComponent::StaticClass());
          auto CineCameraComponent = Cast<UCineCameraComponent>(FoundComponent);

          CineCameraComponent->FilmbackSettings.SensorHeight = SensorHeight;
          CineCameraComponent->FilmbackSettings.SensorWidth = SensorWidth;
          CineCameraComponent->CurrentAperture = Aperture;
          CineCameraComponent->CurrentFocalLength = FocalLength;

          FPlaySceneSlate::Initialize(ActorList[i]->GetActorLabel(), FVector2D(Rect.Left, Rect.Top), FVector2D(NativeWidth / 2, NativeHeight / 2), i);
          Opened = true;
        }
      }
    }

    else
      FMessageDialog::Open(EAppMsgType::Ok, EAppReturnType::Ok, FText::FromString("Close all window first to generate new window"));
  }

  else
    FMessageDialog::Open(EAppMsgType::Ok, EAppReturnType::Ok, FText::FromString("No Monitor is Selected!\nSelect Monitor First!"));

  return FReply::Handled();
}

FReply FMultiWindowModule::CloseAllWindow()
{
  Opened = false;
  FPlaySceneSlate::ShutDownAllWindow();
  IPlayScene::Get().GetTextureRenderTarget2DArray().Empty();

  return FReply::Handled();
}

FReply FMultiWindowModule::ChangeCameraSettings()
{
  World = GEditor->GetEditorWorldContext().World();

  TArray<AActor*> ActorList;
  UGameplayStatics::GetAllActorsWithTag(World, "HMD", ActorList);

  FoundCameraActor = ActorList;

  for (int i = 0; i < ActorList.Num(); ++i)
  {
    auto FoundComponent = ActorList[i]->GetComponentByClass(UCineCameraComponent::StaticClass());
    auto CineCameraComponent = Cast<UCineCameraComponent>(FoundComponent);

    CineCameraComponent->FilmbackSettings.SensorHeight = SensorHeight;
    CineCameraComponent->FilmbackSettings.SensorWidth = SensorWidth;
    CineCameraComponent->CurrentAperture = Aperture;
    CineCameraComponent->CurrentFocalLength = FocalLength;

    if (ActorList[i]->ActorHasTag("BookMark"))
    {
      ABookMarkActor* BM = Cast<ABookMarkActor>(ActorList[i]);

      FCameraFilmbackSettings NewSettings;
      NewSettings.SensorWidth = SensorWidth;
      NewSettings.SensorHeight = SensorHeight;
      BM->SetFilmBack(NewSettings);
      BM->SetActorFocalLength(FocalLength);
      BM->SetAperture(Aperture);

      BM->CopyCineCameraToRenderTarget();
    }
  }

  return FReply::Handled();
}

FReply FMultiWindowModule::BookMarkWindow()
{
  World = GEditor->GetEditorWorldContext().World();

  UEditorEngine* Editor = CastChecked<UEditorEngine>(GEngine);

  TArray<AActor*> ActorList;
  UGameplayStatics::GetAllActorsWithTag(World, "HMD", ActorList);
  FoundCameraActor = ActorList;
  if (FoundCameraActor.Num() != 0)
  {
    AActor* MainCam = nullptr;
    for (int i = 0; i < FoundCameraActor.Num(); ++i)
    {
      if (FoundCameraActor[i]->ActorHasTag("Main"))
      {
        MainCam = FoundCameraActor[i];
        break;
      }
    }

    if (MainCam->IsValidLowLevel())
    {
      ABookMarkActor* BookMark = World->SpawnActor<ABookMarkActor>(ABookMarkActor::StaticClass());
      BookMark->SetActorLocationAndRotation(MainCam->GetActorLocation(), MainCam->GetActorRotation());

      BookMark->SetAperture(Aperture);
      BookMark->SetActorFocalLength(FocalLength);

      FCameraFilmbackSettings NewSettings;
      NewSettings.SensorHeight = SensorHeight;
      NewSettings.SensorWidth = SensorWidth;
      BookMark->SetFilmBack(NewSettings);

      BookMark->CopyCineCameraToRenderTarget();

      FoundCameraActor.Add(BookMark);

      FString ItemData = "Name: " + BookMark->GetActorLabel() + "\n" + \
        "\tLocation: (" + BookMark->GetActorLocation().ToString() + ")\n" + \
        "\tRotation: (" + BookMark->GetActorRotation().ToString() + ")\n";

      BookMark->CopyCineCameraToRenderTarget();
      BookMarkActor.Add(BookMark);
      BookMarkedCamera.Add(MakeShareable(new FString(ItemData)));
    }

    if (Editor->bIsSimulatingInEditor)
    {
      UWorld* EditorWorld = GCurrentLevelEditingViewportClient->GetWorld();

      ABookMarkActor* BookMark = EditorWorld->SpawnActor<ABookMarkActor>(ABookMarkActor::StaticClass());
      BookMark->SetActorLocationAndRotation(MainCam->GetActorLocation(), MainCam->GetActorRotation());

      BookMark->SetAperture(Aperture);
      BookMark->SetActorFocalLength(FocalLength);

      FCameraFilmbackSettings NewSettings;
      NewSettings.SensorHeight = SensorHeight;
      NewSettings.SensorWidth = SensorWidth;
      BookMark->SetFilmBack(NewSettings);

      BookMark->CopyCineCameraToRenderTarget();
    }

    BookMarkListView->SetVisibility(EVisibility::Visible);
    BookMarkListView->RequestListRefresh();

    CloseAllWindow();
    GenerateWindows();
  }


  else
    FMessageDialog::Open(EAppMsgType::Ok, EAppReturnType::Ok, FText::FromString("Generate Main Camera First!"));

  return FReply::Handled();
}

FReply FMultiWindowModule::DestroyBookMark()
{
  CloseAllWindow();

  TArray<AActor*> ActorList;

  World = GEditor->GetEditorWorldContext().World();

  UGameplayStatics::GetAllActorsWithTag(World, "BookMark", ActorList);
  for (auto it : ActorList)
    it->Destroy();
  
  UEditorEngine* Editor = CastChecked<UEditorEngine>(GEngine);
  if (Editor->bIsSimulatingInEditor)
  {
    UWorld* EditorWorld = GCurrentLevelEditingViewportClient->GetWorld();
    UGameplayStatics::GetAllActorsWithTag(EditorWorld, "BookMark", ActorList);

    for (auto it : ActorList)
      it->Destroy();
  }

  BookMarkActor.Empty();
  BookMarkedCamera.Empty();

  for (int i = 0; i < FoundCameraActor.Num(); ++i)
  {
    if (FoundCameraActor[i]->ActorHasTag("BookMark"))
    {
      FoundCameraActor.RemoveAt(i);
      --i;
    }
  }

  return FReply::Handled();
}

void FMultiWindowModule::OnSensorWidthChanged(const FText& InText, ETextCommit::Type CommitType)
{
  if (CommitType == ETextCommit::OnEnter || CommitType == ETextCommit::OnUserMovedFocus || CommitType == ETextCommit::Default)
    SensorWidth = FCString::Atof(*InText.ToString());
}

void FMultiWindowModule::OnSensorHeightChanged(const FText& InText, ETextCommit::Type CommitType)
{
  if (CommitType == ETextCommit::OnEnter || CommitType == ETextCommit::OnUserMovedFocus || CommitType == ETextCommit::Default)
    SensorHeight = FCString::Atof(*InText.ToString());
}

void FMultiWindowModule::OnFocalLengthChanged(const FText& InText, ETextCommit::Type CommitType)
{
  if (CommitType == ETextCommit::OnEnter || CommitType == ETextCommit::OnUserMovedFocus || CommitType == ETextCommit::Default)
    FocalLength = FCString::Atof(*InText.ToString());
}

void FMultiWindowModule::OnApertureChanged(const FText& InText, ETextCommit::Type CommitType)
{
  if (CommitType == ETextCommit::OnEnter || CommitType == ETextCommit::OnUserMovedFocus || CommitType == ETextCommit::Default)
    Aperture = FCString::Atof(*InText.ToString());
}

TArray<AActor*> FMultiWindowModule::GetCameraActorArray()
{
  return FoundCameraActor;
}

TSharedRef<ITableRow> FMultiWindowModule::OnGenerateRowForList(TSharedPtr<FString> Item, const TSharedRef<STableViewBase>& OwnerTable)
{
  return SNew(STableRow<TSharedPtr<FString>>, OwnerTable)
    .Padding(FMargin(5))
    [
      SNew(STextBlock)
      .Text(FText::FromString(*Item.Get()))
      .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 13))
      .ColorAndOpacity(FColor::Silver)
      .OnDoubleClicked_Raw(this, &FMultiWindowModule::TextDoubleClickAction)
    ];
}

FReply FMultiWindowModule::TextDoubleClickAction(const FGeometry& AllotedGeometry, const FPointerEvent& Event)
{
  TArray<TSharedPtr<FString>> SelectedItem;
  BookMarkListView->GetSelectedItems(SelectedItem);

  int ItemIndex = -1;

  for (int i = 0; i < BookMarkedCamera.Num(); ++i)
  {
    if (BookMarkedCamera[i].Get()->Equals(*SelectedItem[0].Get()))
    {
      ItemIndex = i;
      break;
    }
  }

  for (int i = 0; i < FoundCameraActor.Num(); ++i)
  {
    if (FoundCameraActor[i]->ActorHasTag("Main"))
    {
      FoundCameraActor[i]->SetActorLocationAndRotation(
        BookMarkActor[ItemIndex]->GetActorLocation(),
        BookMarkActor[ItemIndex]->GetActorRotation());
      break;
    }
  }

  UEditorEngine* Editor = CastChecked<UEditorEngine>(GEngine);
  if (Editor->bIsSimulatingInEditor)
  {
    TArray<AActor*> SimulateActor;
    World = GEditor->GetEditorWorldContext().World();
    UGameplayStatics::GetAllActorsWithTag(World, "HMD", SimulateActor);

    for (int i = 0; i < SimulateActor.Num(); ++i)
    {
      if (SimulateActor[i]->ActorHasTag("Main"))
      {
        SimulateActor[i]->SetActorLocationAndRotation(
          BookMarkActor[ItemIndex]->GetActorLocation(),
          BookMarkActor[ItemIndex]->GetActorRotation());

        break;
      }
    }
  }

  return FReply::Handled();
}

const void* FMultiWindowModule::GetParentWindowHandle(void)
{
  const void* ParentWindowHandle = nullptr;

  IMainFrameModule& MainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>("MainFrame");
  const TSharedPtr<SWindow>& MainFrameParentWindow = MainFrameModule.GetParentWindow();
  if (MainFrameParentWindow.IsValid() && MainFrameParentWindow->GetNativeWindow().IsValid())
    ParentWindowHandle = MainFrameParentWindow->GetNativeWindow()->GetOSWindowHandle();

  return ParentWindowHandle;
}

FString FMultiWindowModule::SaveMultiWindowDataFromLevel(void)
{
  FString jsonTxt;
  TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&jsonTxt);

  Writer->WriteObjectStart();

  Writer->WriteObjectStart("FilmBack");
  Writer->WriteValue("Width", SensorWidth);
  Writer->WriteValue("Height", SensorHeight);
  Writer->WriteObjectEnd();

  Writer->WriteValue("Focal Length", FocalLength);
  Writer->WriteValue("Aperture", Aperture);

  Writer->WriteArrayStart("BookMark Camera");
  
  for (int i = 0; i < BookMarkActor.Num(); ++i)
  {
    Writer->WriteObjectStart();
    Writer->WriteValue("Name", BookMarkActor[i]->GetActorLabel());
    Writer->WriteValue("Location", BookMarkActor[i]->GetActorLocation().ToString());
    Writer->WriteValue("Rotation", BookMarkActor[i]->GetActorRotation().ToString());
    Writer->WriteObjectEnd();
  }

  Writer->WriteArrayEnd();

  Writer->WriteObjectEnd();
  Writer->Close();
  return jsonTxt;
}

void FMultiWindowModule::GetMultiWindowDataFromFile(TSharedPtr<FJsonValue> obj)
{
  TArray<AActor*> ActorList;
  World = GEditor->GetEditorWorldContext().World();

  UGameplayStatics::GetAllActorsWithTag(World, "BookMark", ActorList);
  for (auto it : ActorList)
    it->Destroy();

  SensorWidth = obj->AsObject()->GetObjectField("FilmBack")->Values["Width"]->AsNumber();
  SensorHeight = obj->AsObject()->GetObjectField("FilmBack")->Values["Height"]->AsNumber();
  FocalLength = obj->AsObject()->GetNumberField("Focal Length");
  Aperture = obj->AsObject()->GetNumberField("Aperture");

  auto BookMarkCameraArray = obj->AsObject()->GetArrayField("BookMark Camera");
  
  for (int i = 0; i < BookMarkCameraArray.Num(); ++i)
  {
    FString CameraName = BookMarkCameraArray[i]->AsObject()->Values["Name"]->AsString();
    FString LocationString = BookMarkCameraArray[i]->AsObject()->Values["Location"]->AsString();

    FVector Location;
    TArray<FString> DataString;
    LocationString.ParseIntoArray(DataString, TEXT(" "), true);

    FString LeftS, RightS;
    DataString[0].Split("=", &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromStart);
    Location.X = FCString::Atof(*RightS);

    DataString[1].Split("=", &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromStart);
    Location.Y = FCString::Atof(*RightS);

    DataString[2].Split("=", &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromStart);
    Location.Z = FCString::Atof(*RightS);

    DataString.Empty();
    FRotator Rotation;
    FString RotationString = BookMarkCameraArray[i]->AsObject()->Values["Rotation"]->AsString();
    RotationString.ParseIntoArray(DataString, TEXT(" "), true);

    LeftS, RightS;
    DataString[0].Split("=", &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromStart);
    Rotation.Pitch = FCString::Atof(*RightS);

    DataString[1].Split("=", &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromStart);
    Rotation.Yaw = FCString::Atof(*RightS);

    DataString[2].Split("=", &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromStart);
    Rotation.Roll = FCString::Atof(*RightS);

    /***** Spawn BookMark Camera *****/
    ABookMarkActor* BookMark = World->SpawnActor<ABookMarkActor>(ABookMarkActor::StaticClass());

    BookMark->SetActorLabel(CameraName);
    BookMark->SetActorLocationAndRotation(Location, Rotation);

    BookMark->SetAperture(Aperture);
    BookMark->SetActorFocalLength(FocalLength);

    FCameraFilmbackSettings NewSettings;
    NewSettings.SensorHeight = SensorHeight;
    NewSettings.SensorWidth = SensorWidth;
    BookMark->SetFilmBack(NewSettings);

    BookMark->CopyCineCameraToRenderTarget();

    FoundCameraActor.Add(BookMark);

    FString ItemData = "Name: " + BookMark->GetActorLabel() + "\n" + \
      "\tLocation: (" + BookMark->GetActorLocation().ToString() + ")\n" + \
      "\tRotation: (" + BookMark->GetActorRotation().ToString() + ")\n";

    BookMark->CopyCineCameraToRenderTarget();
    BookMarkActor.Add(BookMark);
    BookMarkedCamera.Add(MakeShareable(new FString(ItemData)));
  }
}

void FMultiWindowModule::NotificationMessage(FString Message)
{
  FNotificationInfo Info(FText::FromString(Message));
  Info.FadeInDuration = 0.1f;
  Info.FadeOutDuration = 0.5f;
  Info.ExpireDuration = 5.f;
  Info.bUseThrobber = false;
  Info.bUseSuccessFailIcons = true;
  Info.bUseLargeFont = true;
  Info.bFireAndForget = false;
  Info.bAllowThrottleWhenFrameRateIsLow = false;

  auto NotificationItem = FSlateNotificationManager::Get().AddNotification(Info);

  NotificationItem->SetCompletionState(SNotificationItem::CS_Success);
  NotificationItem->ExpireAndFadeout();
}

FReply FMultiWindowModule::SaveCurrentCameraData()
{
  CloseAllWindow();

  IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();

  TArray<FString> OutFileName;
  DesktopPlatform->SaveFileDialog(
    GetParentWindowHandle(),
    "Save File...",
    "",
    "",
    "(*.json) | *.json",
    EFileDialogFlags::None,
    OutFileName);

  if (OutFileName.Num() > 0)
  {
    FString OutputText = SaveMultiWindowDataFromLevel();
    FFileHelper::SaveStringToFile(OutputText, *OutFileName[0]);

    NotificationMessage("Finished Saving Data");
  }

  return FReply::Handled();
}

FReply FMultiWindowModule::LoadCurrentCameraData()
{
  TArray<FString> InFileName;
  IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
  DesktopPlatform->OpenFileDialog(
    GetParentWindowHandle(),
    "Open File...",
    "",
    "",
    "(*.json) | *.json",
    EFileDialogFlags::None,
    InFileName);

  if (InFileName.Num() > 0)
  {
    if (InFileName[0].Contains(".."))
    {
      FString LeftS, RightS;
      InFileName[0].Split("..", &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
      FileLocation = RightS;
    }

    else
      FileLocation = InFileName[0];

    FString DataString;
    FFileHelper::LoadFileToString(DataString, *InFileName[0]);

    TSharedPtr<FJsonValue> jsonObj;
    TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(DataString);

    if (FJsonSerializer::Deserialize(JsonReader, jsonObj))
    {
      GetMultiWindowDataFromFile(jsonObj);
      RefreshWindowList();
    }
  }

  return FReply::Handled();
}

TSharedRef<class SDockTab> FMultiWindowModule::OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs)
{
  FDisplayMetrics::RebuildDisplayMetrics(DisplayMonitors);

  return SNew(SDockTab)
    .TabRole(ETabRole::NomadTab)
    [
      SNew(SScrollBox)
      +SScrollBox::Slot()
      [
        SNew(SVerticalBox)
        +SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .AutoHeight()
        [
          SNew(STextBlock)
          .Text(FText::FromString("Monitor Selection"))
          .ColorAndOpacity(FColor(255, 153, 102))
          .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 15))
        ]

        + SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .AutoHeight()
        [
          SNew(SGridPanel)
          .FillColumn(0, 1.0f)
          .FillColumn(1, 1.0f)
          .FillRow(0, 1.0f)

          +SGridPanel::Slot(0, 0)
          [
            SAssignNew(MonitorComboBox, SComboBox<TSharedPtr<FString>>)
            .OptionsSource(&MonitorComboList)
            .OnGenerateWidget_Raw(this, &FMultiWindowModule::MakeWidgetForOptions)
            .OnSelectionChanged_Raw(this, &FMultiWindowModule::OnMonitorChanged)
            .InitiallySelectedItem(MonitorSelection)
            [
              SNew(STextBlock)
              .Text_Raw(this, &FMultiWindowModule::GetMonitorSelection)
            ]
          ]

          +SGridPanel::Slot(1, 0)
          [
            SNew(SButton)
            .VAlign(VAlign_Center)
            .HAlign(HAlign_Center)
            .OnClicked_Raw(this, &FMultiWindowModule::RefreshDisplayMonitorList)
            [
              SNew(STextBlock)
              .Text(FText::FromString("Refresh Display Monitors"))
            .ColorAndOpacity(FColor::Black)
            ]
          ]
        ]

        +SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .AutoHeight()
        [
          SNew(STextBlock)
          .Text(FText::FromString("Camera Settings (Unit: mm)"))
          .ColorAndOpacity(FColor(255, 153, 102))
          .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 15))
        ]

        + SVerticalBox::Slot()
        .Padding(FMargin(20, 0, 0, 0))
        .AutoHeight()
        [
          SNew(STextBlock)
          .Text(FText::FromString("- Sensor"))
          .ColorAndOpacity(FColor(255, 153, 102))
          .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 13))
        ]

        +SVerticalBox::Slot()
        .Padding(FMargin(20, 5, 10, 0))
        .AutoHeight()
        [
          SNew(SUniformGridPanel)
          .SlotPadding(FMargin(5))

          +SUniformGridPanel::Slot(0, 0)
          .HAlign(HAlign_Center)
          .VAlign(VAlign_Center)
          [
            SNew(STextBlock)
            .Text(FText::FromString("Width"))
            .ColorAndOpacity(FColor::Silver)
            .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 10))
          ]

          +SUniformGridPanel::Slot(1, 0)
          .HAlign(HAlign_Fill)
          .VAlign(VAlign_Center)
          [
            SNew(SEditableTextBox)
            .Text_Lambda([this]()->FText {return FText::AsNumber(SensorWidth); })
            .OnTextCommitted_Raw(this, &FMultiWindowModule::OnSensorWidthChanged)
          ]

          + SUniformGridPanel::Slot(2, 0)
          .HAlign(HAlign_Center)
          .VAlign(VAlign_Center)
          [
            SNew(STextBlock)
            .Text(FText::FromString("Height"))
            .ColorAndOpacity(FColor::Silver)
            .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 10))
          ]

          + SUniformGridPanel::Slot(3, 0)
          .HAlign(HAlign_Fill)
          .VAlign(VAlign_Center)
          [
            SNew(SEditableTextBox)
            .Text_Lambda([this]()->FText {return FText::AsNumber(SensorHeight); })
            .OnTextCommitted_Raw(this, &FMultiWindowModule::OnSensorHeightChanged)
          ]
        ]

        + SVerticalBox::Slot()
        .Padding(FMargin(20, 0, 0, 0))
        .AutoHeight()
        [
          SNew(STextBlock)
          .Text(FText::FromString("- Cine Camera Settings"))
          .ColorAndOpacity(FColor(255, 153, 102))
          .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 13))
        ]

        + SVerticalBox::Slot()
        .Padding(FMargin(20, 5, 10, 0))
        .AutoHeight()
        [
          SNew(SUniformGridPanel)
          .SlotPadding(FMargin(5))

          + SUniformGridPanel::Slot(0, 0)
          .HAlign(HAlign_Center)
          .VAlign(VAlign_Center)
          [
            SNew(STextBlock)
            .Text(FText::FromString("Focal Length"))
            .ColorAndOpacity(FColor::Silver)
            .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 10))
          ]

          + SUniformGridPanel::Slot(1, 0)
          .HAlign(HAlign_Fill)
          .VAlign(VAlign_Center)
          [
            SNew(SEditableTextBox)
            .Text_Lambda([this]()->FText {return FText::AsNumber(FocalLength); })
            .OnTextCommitted_Raw(this, &FMultiWindowModule::OnFocalLengthChanged)
          ]

          + SUniformGridPanel::Slot(2, 0)
          .HAlign(HAlign_Center)
          .VAlign(VAlign_Center)
          [
            SNew(STextBlock)
            .Text(FText::FromString("Aperture"))
            .ColorAndOpacity(FColor::Silver)
            .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 10))
          ]

          + SUniformGridPanel::Slot(3, 0)
          .HAlign(HAlign_Fill)
          .VAlign(VAlign_Center)
          [
            SNew(SEditableTextBox)
            .Text_Lambda([this]()->FText {return FText::AsNumber(Aperture); })
            .OnTextCommitted_Raw(this, &FMultiWindowModule::OnApertureChanged)
          ]
        ]

        + SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .AutoHeight()
        [
          SNew(STextBlock)
          .Text(FText::FromString("BookMark List"))
          .ColorAndOpacity(FColor(255, 153, 102))
          .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 15))
        ]

        + SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .HAlign(HAlign_Left)
        .VAlign(VAlign_Center)
        .AutoHeight()
        [
          SAssignNew(BookMarkListView, SListView<TSharedPtr<FString>>)
          .ItemHeight(24)
          .ListItemsSource(&BookMarkedCamera)
          .OnGenerateRow_Raw(this, &FMultiWindowModule::OnGenerateRowForList)
        ]

        /***************************************** Button Actions *******************************************/
        +SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .AutoHeight()
        [
          SNew(STextBlock)
          .Text(FText::FromString("Actions"))
          .ColorAndOpacity(FColor(255, 153, 102))
          .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 15))
        ]

        +SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .AutoHeight()
        [
          SNew(SButton)
          .VAlign(VAlign_Center)
          .HAlign(HAlign_Center)
          .OnClicked_Raw(this, &FMultiWindowModule::GenerateWindows)
          [
            SNew(STextBlock)
            .Text(FText::FromString("Generate Window"))
            .ColorAndOpacity(FColor::Black)
          ]
        ]

        + SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .AutoHeight()
        [
          SNew(SButton)
          .VAlign(VAlign_Center)
          .HAlign(HAlign_Center)
          .OnClicked_Raw(this, &FMultiWindowModule::ChangeCameraSettings)
          [
            SNew(STextBlock)
            .Text(FText::FromString("Change Camera Values"))
            .ColorAndOpacity(FColor::Black)
          ]
        ]

        + SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .AutoHeight()
        [
          SNew(SButton)
          .VAlign(VAlign_Center)
          .HAlign(HAlign_Center)
          .OnClicked_Raw(this, &FMultiWindowModule::CloseAllWindow)
          [
            SNew(STextBlock)
            .Text(FText::FromString("Close All Windows"))
            .ColorAndOpacity(FColor::Black)
          ]
        ]

        + SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .AutoHeight()
        [
          SNew(SButton)
          .VAlign(VAlign_Center)
          .HAlign(HAlign_Center)
          .OnClicked_Raw(this, &FMultiWindowModule::BookMarkWindow)
          [
            SNew(STextBlock)
            .Text(FText::FromString("Generate BookMark Camera"))
            .ColorAndOpacity(FColor::Black)
          ]
        ]

        + SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .AutoHeight()
        [
          SNew(SButton)
          .VAlign(VAlign_Center)
          .HAlign(HAlign_Center)
          .OnClicked_Raw(this, &FMultiWindowModule::DestroyBookMark)
          [
            SNew(STextBlock)
            .Text(FText::FromString("Destroy BookMark Camera"))
            .ColorAndOpacity(FColor::Black)
          ]
        ]

        + SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .AutoHeight()
        [
          SNew(STextBlock)
          .Text(FText::FromString("File Management"))
          .ColorAndOpacity(FColor(255, 153, 102))
          .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 15))
        ]

        + SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .AutoHeight()
        [
          SNew(SGridPanel)
          .FillColumn(0, 0.3f)
          .FillColumn(1, 1.0f)
          .FillRow(0, 1.0f)

          +SGridPanel::Slot(0, 0)
          .HAlign(HAlign_Center)
          .VAlign(VAlign_Center)
          [
            SNew(STextBlock)
            .Text(FText::FromString("Location:"))
            .ColorAndOpacity(FColor::Silver)
            .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 15))
          ]

        + SGridPanel::Slot(1, 0)
          .HAlign(HAlign_Left)
          .VAlign(VAlign_Center)
          [
            SNew(STextBlock)
            .Text_Lambda([this]()->FText { return FText::FromString(FileLocation); })
            .ColorAndOpacity(FColor::Silver)
            .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Regular.ttf"), 15))
          ]

        ]

        + SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .AutoHeight()
        [
          SNew(SButton)
          .VAlign(VAlign_Center)
          .HAlign(HAlign_Center)
          .OnClicked_Raw(this, &FMultiWindowModule::SaveCurrentCameraData)
          [
            SNew(STextBlock)
            .Text(FText::FromString("Save MultiWindow Data"))
            .ColorAndOpacity(FColor::Black)
          ]
        ]

        + SVerticalBox::Slot()
        .Padding(FMargin(10, 10, 10, 0))
        .AutoHeight()
        [
          SNew(SButton)
          .VAlign(VAlign_Center)
          .HAlign(HAlign_Center)
          .OnClicked_Raw(this, &FMultiWindowModule::LoadCurrentCameraData)
          [
            SNew(STextBlock)
            .Text(FText::FromString("Load MultiWindow Data"))
            .ColorAndOpacity(FColor::Black)
          ]
        ]
      ]
    ];
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMultiWindowModule, MultiWindow)