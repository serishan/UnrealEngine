#pragma once

#include "CoreMinimal.h"

//Camera
#include "CineCameraComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneCaptureComponent2D.h"

//Engine
#include "Engine/Engine.h"
#include "Engine/Scene.h"

//Misc/Notification
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "GenericPlatform/GenericPlatformMisc.h"
#include "Misc/MessageDialog.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "KDBPLibraryFunctions.generated.h"

/** Global Notify Message Functions */
namespace Notification
{
  void NotifyMessage(FText Message);
  void NotifyMessageBox(FText Message);
}

/** Camera Setting Class */
UCLASS()
class UKDBPCamera : public UBlueprintFunctionLibrary
{
  GENERATED_BODY()
  
public:
  UFUNCTION(BlueprintCallable, Category = "Mofac|SceneCapture")
    static void CustomCopyCameraSettingToSceneCapture(UCineCameraComponent* Src,
      USceneCaptureComponent2D* Dst,
      float MaxFocalLength,
      float MinFocalLength,
      float CurrentLength,
      float Aperture,
      float SensorWidth,
      float SensorHeight);
};