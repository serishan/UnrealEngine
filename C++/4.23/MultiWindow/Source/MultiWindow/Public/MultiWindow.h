#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#include "IPlayScene.h"

#include "Framework/Commands/UICommandList.h"
#include "GenericPlatform/GenericApplication.h"

#include "Engine/TextureRenderTarget2D.h"

#include "BookMarkActor.h"

/** Slate */
#include "Widgets/SWidget.h"
#include "Widgets/Input/SComboBox.h"
#include "Input/Reply.h"

#include "Widgets/Views/SListView.h"
#include "Widgets/Views/STableRow.h"

/** JSON */
#include "Dom/JsonValue.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

class FToolBarBuilder;
class FMenuBuilder;

class FMultiWindowModule : public IPlayScene
{

public:
  /** IModuleInterface implementation */
  virtual void StartupModule() override;
  virtual void ShutdownModule() override;

  void PluginButtonClicked();

  /** IPlayScene Virtual Functions */
  virtual TWeakObjectPtr<UTextureRenderTarget2D> GetTextureRenderTarget2D(int index = 0) override;
  virtual void SetTextureRenderTarget2D(UTextureRenderTarget2D* RenderTarget) override;
  virtual TArray<TWeakObjectPtr<UTextureRenderTarget2D>> GetTextureRenderTarget2DArray() override;
  virtual TArray<AActor*> GetCameraActorArray() override;

private:
  /** Functions */
  void AddToolbarExtension(FToolBarBuilder& Builder);
  TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);

  TSharedRef<SWidget> MakeWidgetForOptions(TSharedPtr<FString> InOption);
  TSharedRef<ITableRow> OnGenerateRowForList(TSharedPtr<FString> Item, const TSharedRef<STableViewBase>& OwnerTable);

  void OnMonitorChanged(TSharedPtr<FString> NewValue, ESelectInfo::Type SelectInfo);
  FText GetMonitorSelection() const;

  FReply RefreshDisplayMonitorList();
  FReply GenerateWindows();
  FReply ChangeCameraSettings();
  FReply CloseAllWindow();
  FReply BookMarkWindow();
  FReply DestroyBookMark();

  FReply TextDoubleClickAction(const FGeometry& AllotedGeometry, const FPointerEvent& Event);

  FReply SaveCurrentCameraData();
  FReply LoadCurrentCameraData();

  void OnSensorWidthChanged(const FText& InText, ETextCommit::Type CommitType);
  void OnSensorHeightChanged(const FText& InText, ETextCommit::Type CommitType);
  void OnFocalLengthChanged(const FText& InText, ETextCommit::Type CommitType);
  void OnApertureChanged(const FText& InText, ETextCommit::Type CommitType);

  void RefreshWindowList();

  const void* GetParentWindowHandle(void);
  FString SaveMultiWindowDataFromLevel(void);
  void GetMultiWindowDataFromFile(TSharedPtr<FJsonValue> obj);
  void NotificationMessage(FString Message);

private:
  /** Members */
  UWorld* World = nullptr;
  TSharedPtr<class FUICommandList> PluginCommands;
  FDisplayMetrics DisplayMonitors;//For Monitor Selection

  /** Monitor ComboBox */
  TSharedPtr<FString> MonitorSelection;
  TArray<TSharedPtr<FString>> MonitorComboList;
  TSharedPtr<SComboBox<TSharedPtr<FString>>> MonitorComboBox;

  /** BookMark List View */
  TArray<TSharedPtr<FString>> BookMarkedCamera;
  TSharedPtr<SListView<TSharedPtr<FString>>> BookMarkListView;

  float SensorWidth = 0.f, SensorHeight = 0.f;
  float FocalLength = 0.f, Aperture = 0.f;

  TArray<AActor*> FoundCameraActor;
  TArray<ABookMarkActor*> BookMarkActor;
  TArray<TWeakObjectPtr<UTextureRenderTarget2D>> RenderTarget2DArray;

  FString FileLocation = "Not Selected";
  bool Opened = false;
};