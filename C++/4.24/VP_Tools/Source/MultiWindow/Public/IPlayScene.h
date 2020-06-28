#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class UTextureRenderTarget2D;

class IPlayScene : public IModuleInterface
{
public:
  static inline IPlayScene& Get()
  {
    return FModuleManager::LoadModuleChecked<IPlayScene>("MultiWindow");
  }

  static inline bool IsAvailable()
  {
    return FModuleManager::Get().IsModuleLoaded("MultiWindow");
  }

  /** Virtual Functions */
  virtual TWeakObjectPtr<UTextureRenderTarget2D> GetTextureRenderTarget2D(int index = 0) = 0;
  virtual void SetTextureRenderTarget2D(UTextureRenderTarget2D* RenderTarget) = 0;
  virtual TArray<TWeakObjectPtr<UTextureRenderTarget2D>> GetTextureRenderTarget2DArray() = 0;
  virtual TArray<AActor*> GetCameraActorArray() = 0;
};