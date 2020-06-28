#include "KDBPLibraryFunctions.h"
//#include "Globals.h"

//float CustomFocalLength = 0.f;

namespace Notification
{
  void NotifyMessage(FText Message)
  {
    FNotificationInfo Info(Message);
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

  void NotifyMessageBox(FText Message)
  {
    FMessageDialog::Debugf(Message);
  }
}

/***************************** UKDBPCamera **********************************/

void UKDBPCamera::CustomCopyCameraSettingToSceneCapture(UCineCameraComponent* Src,
  USceneCaptureComponent2D* Dst, float MaxFocalLength, float MinFocalLength, 
  float CurrentLength, float Aperture, float SensorWidth, float SensorHeight)
{
  //FocalLength = CurrentLength;

  //CustomFocalLength = CurrentLength;

  Dst->FOVAngle = Src->FieldOfView;

  if (Src && Dst)
  {
    if (CurrentLength < MinFocalLength)
    {
      CurrentLength = MinFocalLength;
      GEngine->AddOnScreenDebugMessage(0, 1.f, FColor::Red, "Value is below the minimum Value!");
    }

    else if (CurrentLength > MaxFocalLength)
    {
      CurrentLength = MaxFocalLength;
      GEngine->AddOnScreenDebugMessage(0, 1.f, FColor::Red, "Value is over the maximum Value!");
    }

    else if (CurrentLength >= MinFocalLength && CurrentLength <= MaxFocalLength)
      CurrentLength = CurrentLength;

    Dst->FOVAngle = Src->FieldOfView;
    Src->CurrentFocalLength = CurrentLength;
    Src->CurrentAperture = Aperture;
    Src->Filmback.SensorWidth = SensorWidth;
    Src->Filmback.SensorHeight = SensorHeight;

    FMinimalViewInfo CameraViewInfo;
    Src->GetCameraView(0.0f, CameraViewInfo);//Getting Src View Info

    //Post-Processing
    const FPostProcessSettings& SrcPPSettings = CameraViewInfo.PostProcessSettings;
    FPostProcessSettings& DstPPSettings = Dst->PostProcessSettings;

    FWeightedBlendables DstWeightedBlendables = DstPPSettings.WeightedBlendables;

    //Copy All Settings
    DstPPSettings = SrcPPSettings;
    DstPPSettings.WeightedBlendables = DstWeightedBlendables;
  }
}
