#include "PCSceneCaptureComponent2D.h"
#include "IPlayScene.h"

void UPCSceneCaptureComponent2D::Activate(bool bReset)
{
  Super::Activate();

  // Assign Render texture to shared module variable
  IPlayScene::Get().SetTextureRenderTarget2D(this->TextureTarget);
}

void UPCSceneCaptureComponent2D::OnRegister()
{
  Super::OnRegister();

  // Assign Render texture to shared module variable
  IPlayScene::Get().SetTextureRenderTarget2D(this->TextureTarget);
}