#include "PlaySceneSlate.h"

#include "Widgets/SWindow.h"
#include "Framework/Application/SlateApplication.h"

#include "CineCameraComponent.h"
#include "Widgets/Layout/SUniformGridPanel.h"
#include "Widgets/Text/STextBlock.h"

/** Global Variables for this file use */
int RenderIndex = -1;
float SE_W, SE_H;
FVector2D InitialSize;

void FPlaySceneViewportClient::Draw(FViewport* Viewport, FCanvas* Canvas)
{
  Canvas->Clear(FLinearColor::Blue);

  auto TextureRenderTarget = IPlayScene::Get().GetTextureRenderTarget2D(RenderIndex);

  if (TextureRenderTarget.IsValid())
  {
    float AspectRatio = SE_W / SE_H;
    float YRatio = (float)Viewport->GetSizeXY().Y / Viewport->GetSizeXY().X;

    int BlackBarHeight = (Viewport->GetSizeXY().Y - (double)(Viewport->GetSizeXY().X / AspectRatio)) / 2;
    int BlackBarWidth = (Viewport->GetSizeXY().X - (double)(Viewport->GetSizeXY().Y * AspectRatio)) / 2;

    if (BlackBarHeight < 0) BlackBarHeight = 0;
    if (BlackBarWidth < 0) BlackBarWidth = 0;

    int BottomBarPos = Viewport->GetSizeXY().Y - BlackBarHeight;
    int RightBarPos = Viewport->GetSizeXY().X - BlackBarWidth;

    TextureRenderTarget->ResizeTarget(InitialSize.X, InitialSize.Y);

    FVector2D NewSize(Viewport->GetSizeXY().X - (2*BlackBarWidth), Viewport->GetSizeXY().Y - (2*BlackBarHeight));

    FCanvasTileItem TileItem(FVector2D(BlackBarWidth, BlackBarHeight), TextureRenderTarget->Resource,
      NewSize,
      FLinearColor::White);


    TileItem.BlendMode = ESimpleElementBlendMode::SE_BLEND_Opaque;
    Canvas->DrawItem(TileItem);


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

    Canvas->DrawTile(
      0.f,
      0.f,
      (float)BlackBarWidth,
      (float)Viewport->GetSizeXY().Y,
      0.f,
      0.f,
      4.f,
      4.f,
      FLinearColor::Black);

    Canvas->DrawTile(
      (float)RightBarPos,
      0.f,
      (float)BlackBarWidth,
      (float)Viewport->GetSizeXY().Y,
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
    .EnableBlending(true)
    [
      SNew(SOverlay)
      +SOverlay::Slot()
      .HAlign(HAlign_Left)
      .VAlign(VAlign_Top)
      .Padding(FMargin(10, 5, 0, 0))
      [
        SNew(SUniformGridPanel)
        .SlotPadding(FMargin(10, 0, 0, 0))

        + SUniformGridPanel::Slot(0, 0)
        .HAlign(HAlign_Left)
        .VAlign(VAlign_Center)
        [
          SNew(STextBlock)
          .Text(FText::FromString("Name: " + Name))
          .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 11))
          .ColorAndOpacity(FSlateColor(FColor::White))
        ]
        + SUniformGridPanel::Slot(1, 0)
        .HAlign(HAlign_Left)
        .VAlign(VAlign_Center)
        [
          SNew(STextBlock)
          .Text_Lambda([this]()->FText {return FText::FromString("Focal Length: " + FString::SanitizeFloat(FocalLength) + " mm"); })
          .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 11))
          .ColorAndOpacity(FSlateColor(FColor::White))
        ]

        + SUniformGridPanel::Slot(2, 0)
        .HAlign(HAlign_Left)
        .VAlign(VAlign_Center)
        [
          SNew(STextBlock)
          .Text_Lambda([this]()->FText {return FText::FromString("Aperture: " + FString::SanitizeFloat(Aperture) + " mm"); })
          .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 11))
          .ColorAndOpacity(FSlateColor(FColor::White))
        ]

        + SUniformGridPanel::Slot(3, 0)
        .HAlign(HAlign_Left)
        .VAlign(VAlign_Center)
        [
          SNew(STextBlock)
          .Text_Lambda([this]()->FText {return FText::FromString("Ratio: " + FString::SanitizeFloat((float)((int)(Ratio*100))/100) + " : 1"); })
          .Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 11))
          .ColorAndOpacity(FSlateColor(FColor::White))
        ]
      ]
    ];

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
      SE_W = Cast<UCineCameraComponent>(FoundComponent)->FilmbackSettings.SensorWidth;
      SE_H = Cast<UCineCameraComponent>(FoundComponent)->FilmbackSettings.SensorHeight;
      FocalLength = Cast<UCineCameraComponent>(FoundComponent)->CurrentFocalLength;
      Aperture = Cast<UCineCameraComponent>(FoundComponent)->CurrentAperture;
      Ratio = SE_W / SE_H;

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
  InitialSize = ClientSize;

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