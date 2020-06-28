#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "CineCameraComponent.h"
#include "PCSceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"

#include "BookMarkActor.generated.h"

UCLASS()
class MULTIWINDOW_API ABookMarkActor : public AActor
{
  GENERATED_BODY()

public:
  ABookMarkActor();

  void SetActorFocalLength(float FocalLength);
  void SetFilmBack(FCameraFilmbackSettings FilmBack);
  void SetAperture(float Aperture);
  void CopyCineCameraToRenderTarget();
  void ResizeRenderTarget(FVector2D NewResolution);

public:
  UPCSceneCaptureComponent2D* SceneCapture;
  UTextureRenderTarget2D* RenderTarget;
  UCineCameraComponent* CineCamera;

protected:
  virtual void BeginPlay() override;
  virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};