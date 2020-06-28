#include "PlaySceneSlate.h"

#include "Widgets/SWindow.h"
#include "Framework/Application/SlateApplication.h"

#include "CineCameraComponent.h"

/** Global Variables for this file use */
int RenderIndex = -1;
float SE_W, SE_H;

void FPlaySceneViewportClient::Draw(FViewport* Viewport, FCanvas* Canvas)
{
  Canvas->Clear(FLinearColor::Black);

  auto TextureRenderTarget = IPlayScene::Get().GetTextureRenderTarget2D(RenderIndex);

  if (TextureRenderTarget.IsValid())
  {
    float AspectRatio = SE_W / SE_H;
    float YRatio = (float)Viewport->GetSizeXY().Y / Viewport->GetSizeXY().X;
    TextureRenderTarget->ResizeTarget(Viewport->GetSizeXY().X, Viewport->GetSizeXY().Y);
    TextureRenderTarget->ResizeTarget(Viewport->GetSizeXY().X, (int)(Viewport->GetSizeXY().X * YRatio));

    FCanvasTileItem TileItem(FVector2D(0, 0), TextureRenderTarget->Resource,
      FVector2D(Viewport->GetRenderTargetTexture()->GetSizeX(), Viewport->GetRenderTargetTexture()->GetSizeY()),
      FLinearColor::White);

    TileItem.BlendMode = ESimpleElementBlendMode::SE_BLEND_Opaque;
    Canvas->DrawItem(TileItem);

    int BlackBarHeight = (Viewport->GetSizeXY().Y - (double)(Viewport->GetSizeXY().X / AspectRatio)) / 2;
    int BottomBarPos = Viewport->GetSizeXY().Y - BlackBarHeight;

    Canvas->DrawTile(
      0.f,
      0.f, 
      (float)Viewport->GetSizeXY().X, 
      (float)BlackBarHeight,
      0.f,
      0.f,
      4.f,
      4.f,
      FLinearColor::Black);

    Canvas->DrawTile(
      0.f,
      (float)BottomBarPos,
      (float)Viewport->GetSizeXY().X,
      (float)BlackBarHeight,
      0.f,
      0.f,
      4.f,
      4.f,
      FLinearColor::Black);
  }
}

void SPlaySceneViewport::Construct(const FArguments& InArgs, FString WinName)
{
  Name = WinName;

  Viewport = SNew(SViewport)
    .IsEnabled(true)
    .EnableGammaCorrection(false)
    .ShowEffectWhenDisabled(false)
    .EnableBlending(true);

  PlaySceneViewportClient = MakeShareable(new FPlaySceneViewportClient);
  SceneViewport = MakeShareable(new FSceneViewport(PlaySceneViewportClient.Get(), Viewport));
  Viewport->SetViewportInterface(SceneViewport.ToSharedRef());

  this->ChildSlot[Viewport.ToSharedRef()];
}

void SPlaySceneViewport::Tick(const FGeometry& AllotedGeometry, const double InCurrentTime, const float InDeltaTime)
{
  auto CameraArray = IPlayScene::Get().GetCameraActorArray();

  for (int i = 0; i < CameraArray.Num(); ++i)
  {
    if (CameraArray[i]->GetActorLabel().Equals(Name))
    {
      auto FoundComponent = CameraArray[i]->GetComponentByClass(UCineCameraComponent::StaticClass());
      SE_W = Cast<UCineCameraComponent>(FoundComponent)->Filmback.SensorWidth;
      SE_H = Cast<UCineCameraComponent>(FoundComponent)->Filmback.SensorHeight;

      RenderIndex = i;
      SceneViewport->Draw();
      break;
    }
  }
}

FString FPlaySceneSlate::WindowName = "";
FVector2D FPlaySceneSlate::WindowPos = FVector2D::ZeroVector;
FVector2D FPlaySceneSlate::ClientSize = FVector2D::ZeroVector;
TArray<TSharedPtr<FPlaySceneSlate>> FPlaySceneSlate::PlaySceneSlateArray = TArray<TSharedPtr<FPlaySceneSlate>>();

FPlaySceneSlate::FPlaySceneSlate()
{
  PlaySceneWindow = SNew(SWindow)
    .Title(FText::FromString(WindowName))
    .ScreenPosition(FVector2D(0, 0))
    .ClientSize(ClientSize)
    .AutoCenter(EAutoCenter::PreferredWorkArea)
    .UseOSWindowBorder(false)
    .SaneWindowPlacement(false)
    .SizingRule(ESizingRule::UserSized)
    .HasCloseButton(false)
    .CreateTitleBar(true)
    .IsTopmostWindow(true);

  FSlateApplication::Get().AddWindow(PlaySceneWindow.ToSharedRef());
  PlaySceneViewport = SNew(SPlaySceneViewport, WindowName);
  PlaySceneWindow->SetContent(PlaySceneViewport.ToSharedRef());
  PlaySceneWindow->MoveWindowTo(WindowPos);

  auto TextureArray = IPlayScene::Get().GetTextureRenderTarget2DArray();
  float YRatio = (float)ClientSize.Y / ClientSize.X;

  for (int i = 0; i < TextureArray.Num(); ++i)
  {
    TextureArray[i]->ResizeTarget(ClientSize.X, ClientSize.Y);
    TextureArray[i]->ResizeTarget(ClientSize.X, (int)(ClientSize.X * YRatio));
  }
}

void FPlaySceneSlate::Initialize(FString WinName, FVector2D WindowPosition, FVector2D WindowSize, int index)
{
  WindowName = WinName;
  WindowPos = WindowPosition;
  ClientSize = WindowSize;

  TSharedPtr<FPlaySceneSlate> PlaySceneSlate;
  PlaySceneSlate = MakeShareable(new FPlaySceneSlate);

  if (PlaySceneSlateArray.Num() == 0)
    PlaySceneSlateArray.Add(PlaySceneSlate);

  for (int i = 0; i < PlaySceneSlateArray.Num(); ++i)
  {
    if (!PlaySceneSlateArray[i].Get()->PlaySceneViewport.Get()->Name.Equals(WinName))
      PlaySceneSlateArray.Add(PlaySceneSlate);
  }
}

void FPlaySceneSlate::ShutDownAllWindow()
{
  while (PlaySceneSlateArray.Num() != 0)
  {
    PlaySceneSlateArray[0].Get()->PlaySceneWindow->RequestDestroyWindow();
    PlaySceneSlateArray.RemoveAt(0);
  }

  PlaySceneSlateArray.Empty();
}