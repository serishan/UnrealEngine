#include "BookMarkActor.h"
#include "IPlayScene.h"

void ABookMarkActor::BeginPlay()
{
  Super::BeginPlay();
}

void ABookMarkActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
  Super::EndPlay(EndPlayReason);
}

ABookMarkActor::ABookMarkActor()
{
  PrimaryActorTick.bCanEverTick = false;

  SceneCapture = CreateDefaultSubobject<UPCSceneCaptureComponent2D>("SceneCapture");
  CineCamera = CreateDefaultSubobject<UCineCameraComponent>("CineCamera");

  RenderTarget = NewObject<UTextureRenderTarget2D>();
  RenderTarget->ClearColor = FLinearColor::Black;
  RenderTarget->TargetGamma = 1;
  RenderTarget->InitAutoFormat(1920, 1080);

  SceneCapture->TextureTarget = RenderTarget;
  IPlayScene::Get().SetTextureRenderTarget2D(RenderTarget);

  SceneCapture->SetVisibility(true);
  CineCamera->SetVisibility(true);

  SceneCapture->SetHiddenInGame(false);
  CineCamera->SetHiddenInGame(false);
 
  CineCamera->SetupAttachment(RootComponent);
  SceneCapture->SetupAttachment(CineCamera);

  /** If Render is too slow, make this to EComponentMobility::Static */
  CineCamera->Mobility = EComponentMobility::Movable;
  SceneCapture->Mobility = EComponentMobility::Movable;

  this->Tags.Add("HMD");
  this->Tags.Add("BookMark");
}

void ABookMarkActor::SetActorFocalLength(float FocalLength)
{
  CineCamera->CurrentFocalLength = FocalLength;
}

void ABookMarkActor::SetFilmBack(FCameraFilmbackSettings FilmBack)
{
  CineCamera->Filmback = FilmBack;
}

void ABookMarkActor::SetAperture(float Aperture)
{
  CineCamera->CurrentAperture = Aperture;
}

void ABookMarkActor::CopyCineCameraToRenderTarget()
{
  SceneCapture->FOVAngle = CineCamera->FieldOfView;

  FMinimalViewInfo CameraViewInfo;
  CineCamera->GetCameraView(0.f, CameraViewInfo);

  const FPostProcessSettings& SrcPPSettings = CameraViewInfo.PostProcessSettings;
  FPostProcessSettings& DstPPSettings = SceneCapture->PostProcessSettings;

  FWeightedBlendables DstWeightedBlendables = DstPPSettings.WeightedBlendables;

  DstPPSettings = SrcPPSettings;

  DstPPSettings.WeightedBlendables = DstWeightedBlendables;
}

void ABookMarkActor::ResizeRenderTarget(FVector2D NewResolution)
{
  RenderTarget->ResizeTarget(NewResolution.X, NewResolution.Y);
}