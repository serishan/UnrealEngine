// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MofacLiveLinkBPLibrary.h"
#include "MofacLiveLink.h"

TMap<FString, FMorphShapeData> UMofacLiveLinkBPLibrary::MorphDataMap = TMap<FString, FMorphShapeData>();
TMap<FString, FBoneTransformData> UMofacLiveLinkBPLibrary::BoneTransformMap = TMap<FString, FBoneTransformData>();
TArray<FName> UMofacLiveLinkBPLibrary::OriginalMorphCurveName = TArray<FName>();

static bool Notify = false;
static float ElapsedTime = 0.0f;

UMofacLiveLinkBPLibrary::UMofacLiveLinkBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UMofacLiveLinkBPLibrary::FetchAllMorphCurve(USkeletalMeshComponent* SkeletalMeshComponent)
{
  bool Message = false;

  if(BoneTransformMap.Num() != 0)
    BoneTransformMap.Empty();

  UAnimInstance* ModelAnimInstance = SkeletalMeshComponent->GetAnimInstance();

  TArray<FName> MorphCurveNameArray;
  ModelAnimInstance->GetAllCurveNames(MorphCurveNameArray);

  if (MorphCurveNameArray.Num() != 0)
  {
    for (int i = 0; i < MorphCurveNameArray.Num(); ++i)
    {
      FString LeftS = "", RightS = "";
      FString SourceString = MorphCurveNameArray[i].ToString();
      SourceString.Split("Shape", &LeftS, &RightS);

      if (LeftS.IsEmpty())
        FindNameAndAddToMap(SourceString, i);

      else
        FindNameAndAddToMap(LeftS, i);
    }

    OriginalMorphCurveName = MorphCurveNameArray;
  }

  else
  {
    if (!Message)
    {
      NotifyMessage(FText::FromString("No Morph Data! Check the Live Link Connection!"));
      MessageDialogBox(FText::FromString("No Morph Data! Check the Live Link Connection!"));
      Message = true;
    }
    return;
  }
}

void UMofacLiveLinkBPLibrary::FindNameAndAddToMap(FString Name, int index)
{
  FMorphShapeData MSD;

  auto CustomIndex = MorphDataMap.Find(Name);
  if (!CustomIndex)
  {
    MSD.MorphCurveNameIndex.Add(index);
    MorphDataMap.Add(Name, MSD);
  }
  else
    CustomIndex->MorphCurveNameIndex.Add(index);
}

void UMofacLiveLinkBPLibrary::UpdateMorphShape(USkeletalMeshComponent* SkeletalMeshComponent, FName MorphShape, bool debug, FString DebugName)
{
  ILiveLinkClient* Client;
  FLiveLinkClientReference ClientRef;

  Client = ClientRef.GetClient();

  if (Client && OriginalMorphCurveName.Num() != 0)
  {
    FLiveLinkSubjectFrameData FrameData;
    FSubjectFrameHandle SubjectFrameHandle;

    if (Client->EvaluateFrame_AnyThread(MorphShape, ULiveLinkAnimationRole::StaticClass(), FrameData))
    {
      const FLiveLinkSkeletonStaticData* SkeletonData = FrameData.StaticData.Cast<FLiveLinkSkeletonStaticData>();
      const FLiveLinkAnimationFrameData* AnimationFrameData = FrameData.FrameData.Cast<FLiveLinkAnimationFrameData>();
      FLiveLinkBlueprintDataStruct BlueprintDataWrapper(FSubjectFrameHandle::StaticStruct(), &SubjectFrameHandle);

      if (SkeletonData == nullptr)
      {
        UE_LOG(LogTemp, Warning, TEXT("No Skeleton Data"));
        MessageDialogBox(FText::FromString("No Skeleton Data!"));
        NotifyMessage(FText::FromString("No Skeleton Data"));
        return;
      }

      if (AnimationFrameData == nullptr)
      {
        UE_LOG(LogTemp, Warning, TEXT("No Animation Data"));
        MessageDialogBox(FText::FromString("No Animation Data!"));
        NotifyMessage(FText::FromString("No Animation Data"));
        return;
      }

      ULiveLinkAnimationRole::StaticClass()->GetDefaultObject<ULiveLinkAnimationRole>()->InitializeBlueprintData(FrameData, BlueprintDataWrapper);
    }

    /****************** Get and Set Morph Shape of Model *******************/
    TMap<FName, float> MorphShapeMap;
    SubjectFrameHandle.GetCurves(MorphShapeMap);

    for (auto it : MorphShapeMap)
    {
      FString LeftS = "", RightS = "";
      FString SourceString = it.Key.ToString();
      SourceString.Split(":", &LeftS, &RightS);

      if (RightS.Equals("Visibility")) continue;
      
      auto CustomIndex = MorphDataMap.Find(RightS);
      if (CustomIndex)
        for (auto id : CustomIndex->MorphCurveNameIndex)
          SkeletalMeshComponent->SetMorphTarget(OriginalMorphCurveName[id], (it.Value / 100.f));;

      if (debug && DebugName.Equals("All"))
        GEngine->AddOnScreenDebugMessage(1, 0.5f, FColor::Magenta, RightS + ": " + FString::SanitizeFloat(it.Value / 100.f));

      else if (debug && DebugName.Equals(RightS))
        GEngine->AddOnScreenDebugMessage(1, 0.5f, FColor::Magenta, RightS + ": " + FString::SanitizeFloat(it.Value / 100.f));
    }
  }

  else
  {
    if (!Notify)
    {
      Notify = !Notify;
      NotifyMessage(FText::FromString("No Morph Data! Check the Live Link Connection!"));
      MessageDialogBox(FText::FromString("No Morph Data! Check the Live Link Connection!"));
    }
    return;
  }
}

void UMofacLiveLinkBPLibrary::AttachCameraToBone(USkeletalMeshComponent* SkeletalMeshComponent, UCameraComponent* Camera, FName BoneName, AttachStyle Style)
{
  switch (Style)
  {
  case KeepRelativeTransform:
    Camera->AttachToComponent(SkeletalMeshComponent, FAttachmentTransformRules::KeepRelativeTransform, BoneName);
    break;

  case KeepWorldTransform:
    Camera->AttachToComponent(SkeletalMeshComponent, FAttachmentTransformRules::KeepWorldTransform, BoneName);
    break;

  case SnapToTargetNoScale:
    Camera->AttachToComponent(SkeletalMeshComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, BoneName);
    break;

  case SnapToTargetWithScale:
    Camera->AttachToComponent(SkeletalMeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, BoneName);
    break;

  default:
    NotifyMessage(FText::FromString("Didn't Set Attaching Style! Check the Style again."));
    return;
  }
}

void UMofacLiveLinkBPLibrary::UpdateJointsAndMorphShapeBySeconds(USkeletalMeshComponent* SkeletalMeshComponent, UPoseableMeshComponent* PoseableMesh, FName MorphName, MobuFPS InputFPS, float DelayTime, bool visible)
{
  UpdateMorphShape(SkeletalMeshComponent, MorphName);
  SaveBonesUpdateForDelayBySecond(SkeletalMeshComponent, PoseableMesh, InputFPS, DelayTime, visible);
}

void UMofacLiveLinkBPLibrary::UpdateJointsAndMorphShapeByFrames(USkeletalMeshComponent* SkeletalMeshComponent, UPoseableMeshComponent* PoseableMesh, FName MorphName, float DelayFrame, bool visible)
{
  UpdateMorphShape(SkeletalMeshComponent, MorphName);
  SaveBonesUpdateForDelayByFrame(SkeletalMeshComponent, PoseableMesh, DelayFrame, visible);
}

void UMofacLiveLinkBPLibrary::SaveBonesUpdateForDelayBySecond(USkeletalMeshComponent* SkeletalMeshComponent, UPoseableMeshComponent* PoseableMesh, MobuFPS InputFPS, const float DelayTime, bool visible)
{
#define BONENAME(i) SkeletalMeshComponent->GetBoneName(i)
#define BONETRANSFORM(i) SkeletalMeshComponent->GetBoneTransform(i)

  int CurrentFPS = 0;

  switch (InputFPS)
  {
  case FPS_24:
    CurrentFPS = 24;
    break;
  
  case FPS_30:
    CurrentFPS = 30;
    break;

  case FPS_120:
    CurrentFPS = 120;
    break;
  }

  const int FrameCountToSave = ceil(CurrentFPS * DelayTime);//Round Up
  int TotalBoneNum = SkeletalMeshComponent->GetNumBones();//Total Number of Bones

  SkeletalMeshComponent->bVisible = visible;

  for (int i = 0; i < TotalBoneNum; ++i)
  {
    //Save Bone Transform into Seperate Array
    auto BoneData = BoneTransformMap.Find(BONENAME(i).ToString());

    if (!BoneData)
    {
      FBoneTransformData BTD;
      BTD.BoneTransformArray.Add(BONETRANSFORM(i));
      BoneTransformMap.Add(BONENAME(i).ToString(), BTD);
      PoseableMesh->SetVisibility(false);
      continue;
    }
    
    else
      BoneData->BoneTransformArray.Add(BONETRANSFORM(i));

    //Check if each array have more than allowed data. We already know that each seperate array is valid. No Empty Array
    if (BoneData->BoneTransformArray.Num() > FrameCountToSave)
    {
      PoseableMesh->SetVisibility(true);
      PoseableMesh->SetBoneTransformByName(BONENAME(i), BoneData->BoneTransformArray[0], EBoneSpaces::WorldSpace);
      BoneData->BoneTransformArray.RemoveAt(0);
    }
  }

#undef BONETRANSFORM
#undef BONENAME
}

void UMofacLiveLinkBPLibrary::SaveBonesUpdateForDelayByFrame(USkeletalMeshComponent* SkeletalMeshComponent, UPoseableMeshComponent* PoseableMesh, const float DelayFrame, bool visible)
{
#define BONENAME(i) SkeletalMeshComponent->GetBoneName(i)
#define BONETRANSFORM(i) SkeletalMeshComponent->GetBoneTransform(i)

  int TotalBoneNum = SkeletalMeshComponent->GetNumBones();//Total Number of Bones
  SkeletalMeshComponent->bVisible = visible;

  for (int i = 0; i < TotalBoneNum; ++i)
  {
    //Save Bone Transform into Seperate Array
    auto BoneData = BoneTransformMap.Find(BONENAME(i).ToString());

    if (!BoneData)
    {
      FBoneTransformData BTD;
      BTD.BoneTransformArray.Add(BONETRANSFORM(i));
      BoneTransformMap.Add(BONENAME(i).ToString(), BTD);
      PoseableMesh->SetVisibility(false);
      continue;
    }

    else
      BoneData->BoneTransformArray.Add(BONETRANSFORM(i));

    //Check if each array have more than allowed data. We already know that each seperate array is valid. No Empty Array
    if (BoneData->BoneTransformArray.Num() > DelayFrame)
    {
      PoseableMesh->SetVisibility(true);
      PoseableMesh->SetBoneTransformByName(BONENAME(i), BoneData->BoneTransformArray[0], EBoneSpaces::WorldSpace);
      BoneData->BoneTransformArray.RemoveAt(0);
    }
  }

#undef BONENAME
#undef BONETRANSFORM
}

void UMofacLiveLinkBPLibrary::NotifyMessage(FText Message)
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

void UMofacLiveLinkBPLibrary::MessageDialogBox(FText Message)
{
  FMessageDialog::Debugf(Message);
}