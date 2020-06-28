#pragma once

#include "CoreMinimal.h"
#include "UnrealClient.h"
#include "IPlayScene.h"

#include "Slate/SceneViewport.h"

/** Canvas */
#include "CanvasItem.h"
#include "CanvasTypes.h"

/** Widgets */
#include "Widgets/SCompoundWidget.h"
#include "Widgets/SViewport.h"
#include "Engine/TextureRenderTarget2D.h"

class SWindow;
class SViewport;
class FSceneViewport;

class FPlaySceneViewportClient : public FViewportClient
{
  virtual void Draw(FViewport* Viewport, FCanvas* Canvas) override;
  virtual bool InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed = 1.0f, bool bGamepad = false) override { return false; }
  virtual bool InputAxis(FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples = 1, bool bGamepad = false) override { return false; }
  virtual bool InputGesture(FViewport* Viewport, EGestureEvent GestureType, const FVector2D& GestureDelta, bool bIsDirectionInvertedFromDevice) override { return false; }
  virtual UWorld* GetWorld() const override { return nullptr; }
};

class SPlaySceneViewport : public SCompoundWidget
{
  SLATE_BEGIN_ARGS(SPlaySceneViewport) {}
  SLATE_END_ARGS()

public:
  void Construct(const FArguments& InArgs, FString WinName);
  virtual void Tick(const FGeometry& AllotedGeometry, const double InCurrentTime, const float InDeltaTime) override;

  float FocalLength;
  float Aperture;
  float Ratio;
  FString Name;
  TSharedPtr<SViewport> Viewport;
  TSharedPtr<FSceneViewport> SceneViewport;
  TSharedPtr<FPlaySceneViewportClient> PlaySceneViewportClient;
};

/** Window Initialize Class */
class FPlaySceneSlate
{
public:
  FPlaySceneSlate();

  static void ShutDownAllWindow();
  static void Initialize(FString WinName, FVector2D WindowPosition, FVector2D WindowSize, int index);

private:
  static FString WindowName;
  static FVector2D WindowPos;
  static FVector2D ClientSize;

  TSharedPtr<SWindow> PlaySceneWindow;
  TSharedPtr<SPlaySceneViewport> PlaySceneViewport;

  static TArray<TSharedPtr<FPlaySceneSlate>> PlaySceneSlateArray;
};