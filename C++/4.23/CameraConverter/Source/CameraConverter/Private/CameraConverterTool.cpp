#include "CameraConverterTool.h"
#include "CineCameraComponent.h"
#include "Tracks/MovieSceneSpawnTrack.h"

#include "Channels/MovieSceneChannelProxy.h"
#include "Channels/MovieSceneFloatChannel.h"

#include "FileHelpers.h"
#include "Engine/Selection.h"
#include "Animation/SkeletalMeshActor.h"

UCameraConverterTool::UCameraConverterTool(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
}

void UCameraConverterTool::ConvertCamera()
{
  if (!LevelSequence->IsValidLowLevel())
  {
    const FText Title = FText::FromString("Empty");
    FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Select Level Sequence First!"), &Title);
    return;
  }

  else if (CameraName.IsEmpty())
  {
    const FText Title = FText::FromString("Empty");
    FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Track Name is Empty!"), &Title);
    return;
  }

  else if (TargetFPS == 0.f)
  {
    const FText Title = FText::FromString("TargetFPS Error");
    FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("TargetFPS is 0! Enter Valid FPS!"), &Title);
    return;
  }

  /** Get the Camera Count from the Sequence */
  BPCameraCount = 0;
  TargetPoint = 0;

  UniqueIDArray.Empty();
  World = GEditor->GetEditorWorldContext().World();

  GenerateOriginalIDArray();

  FMovieSceneSequencePlaybackSettings Settings;
  ALevelSequenceActor* OutActor;
  Player = ULevelSequencePlayer::CreateLevelSequencePlayer(World, LevelSequence, Settings, OutActor);
  Player->Initialize(LevelSequence, World->PersistentLevel, Settings);

  GetSequenceData(LevelSequence);
  PlayBackRange = LevelSequence->MovieScene->GetPlaybackRange();
  
  LowerBound = PlayBackRange.GetLowerBoundValue().Value;
  UpperBound = PlayBackRange.GetUpperBoundValue().Value;
  int FPS = LevelSequence->MovieScene->GetDisplayRate().Numerator;
  int SequencerTick =LevelSequence->MovieScene->GetTickResolution().Numerator;
  int Ratio = SequencerTick / TargetFPS;

  TimeArray.Empty();
  FMovieSceneMarkedFrame Frame;

  if (TimeArray.Find(LowerBound) == INDEX_NONE)
  {
    TimeArray.Add(LowerBound);
    Frame.FrameNumber = LowerBound;
    MarkedFrameIndexArray.Add(LevelSequence->MovieScene->AddMarkedFrame(Frame));
  }

  for (int i = LowerBound; i <= UpperBound; ++i)
  {
    if (i % Ratio == 0)
    {
      if (TimeArray.Find(i) == INDEX_NONE)
      {
        TimeArray.Add(i);
        Frame.FrameNumber = i;
        MarkedFrameIndexArray.Add(LevelSequence->MovieScene->AddMarkedFrame(Frame));
      }
    }
  }

  /** Check if we have more camera then we need */
  if (BPCameraCount > 1)
  {
    const FText Title = FText::FromString("Camera Error");
    FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Multiple Camera has been detected.\nCheck Camera in the Sequence"), &Title);
    return;
  }

  else if (BPCameraCount == 0)
  {
    const FText Title = FText::FromString("Camera Error");
    FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("No Camera has been detected.\nCheck Camera in the Sequence"), &Title);
    return;
  }

  if (TargetPoint > 1)
  {
    const FText Title = FText::FromString("Target Point Error");
    FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Multiple TargetPoint has been detected.\nCheck TargetPoint in the Sequence"), &Title);
    return;
  }

  ApertureTimeArray.Empty();
  ApertureValue.Empty();

  ManualFocusDistanceTimeArray.Empty();
  ManualFocusDistanceValue.Empty();

  FocalLengthTimeArray.Empty();
  FocalLengthValue.Empty();

  /** Add Track to Level Sequence */
  SpawnCineCameraActor();

  if (TargetPointSubSection->IsValidLowLevel())
    TargetPointSubSection->SetIsActive(false);

  CameraSubSection->SetIsActive(false);

  /** Delete Marked Frame from Sequence */
  MarkedFrameIndexArray.Empty();
  LevelSequence->MovieScene->ClearMarkedFrames();

  /** Delete Sequence Actors from Level */
  OutActor->Destroy();
  DestroyUnrelatedActors();

  TArray<UClass*> ArrayList;
  ArrayList.Add(ULevelSequence::StaticClass());
  FEditorFileUtils::SaveDirtyContentPackages(ArrayList, true, false, true);
}

void UCameraConverterTool::GenerateOriginalIDArray()
{
  TArray<AActor*> ActorList;
  UGameplayStatics::GetAllActorsOfClass(World, AActor::StaticClass(), ActorList);

  for (auto it : ActorList)
    UniqueIDArray.Add(it->GetName(), it->GetUniqueID());
}

void UCameraConverterTool::DestroyUnrelatedActors()
{
  TArray<AActor*> ActorList;
  UGameplayStatics::GetAllActorsOfClass(World, AActor::StaticClass(), ActorList);

  /** Delete Level Sequence Actor */
  for (auto it : ActorList)
  {
    bool destroyActor = true;
    
    for (auto actor : UniqueIDArray)
    {
      if (actor.Value == it->GetUniqueID())
      {
        destroyActor = false;
        break;
      }
    }

    if (destroyActor)
      it->Destroy();
  }
}

void UCameraConverterTool::FindActor()
{
  TArray<AActor*> ActorList;
  UGameplayStatics::GetAllActorsOfClassWithTag(World, AActor::StaticClass(), "SequencerActor", ActorList);

  for (auto it : ActorList)
  {
    if (it->GetName().Contains("TargetPoint"))
      PivotActor = it;

    else if (it->GetName().Contains("BP_CameraPawn"))
    {
      CameraPawnActor = it;

      auto FoundComponents = it->GetComponentByClass(UCineCameraComponent::StaticClass());
      CineCameraComponent = Cast<UCineCameraComponent>(FoundComponents);

      TArray<UActorComponent*> OtherComp = it->GetComponentsByClass(USceneComponent::StaticClass());
      for (auto ac : OtherComp)
      {
        if (ac->GetName().Contains("CineCameraOrigin"))
        {
          CineCameraOriginActor = Cast<AActor>(ac);
          break;
        }
      }
    }
  }
}

void UCameraConverterTool::CalculateNewCameraTransform(UMovieScene3DTransformSection* TransformSection)
{
  TArray<FMovieSceneFloatValue> X_LocArray;
  TArray<FMovieSceneFloatValue> Y_LocArray;
  TArray<FMovieSceneFloatValue> Z_LocArray;
  TArray<FMovieSceneFloatValue> X_RotArray;
  TArray<FMovieSceneFloatValue> Y_RotArray;
  TArray<FMovieSceneFloatValue> Z_RotArray;

  FMovieSceneFloatValue X_Val;
  FMovieSceneFloatValue Y_Val;
  FMovieSceneFloatValue Z_Val;

  for (int i = 0; i < TimeArray.Num(); ++i)
  {
    FindActor();

    X_Val.Value = 0;
    Y_Val.Value = 0;
    Z_Val.Value = 0;

    Player->JumpToMarkedFrame(LevelSequence->MovieScene->GetMarkedFrames()[i].Label);

    X_Val.Value = CineCameraComponent->GetComponentLocation().X;
    Y_Val.Value = CineCameraComponent->GetComponentLocation().Y;
    Z_Val.Value = CineCameraComponent->GetComponentLocation().Z;

    X_LocArray.Add(X_Val);
    Y_LocArray.Add(Y_Val);
    Z_LocArray.Add(Z_Val);

    /** Rotation */
    X_Val.Value = 0;
    Y_Val.Value = 0;
    Z_Val.Value = 0;

    X_Val.Value = CineCameraComponent->GetComponentRotation().Roll;
    Y_Val.Value = CineCameraComponent->GetComponentRotation().Pitch;
    Z_Val.Value = CineCameraComponent->GetComponentRotation().Yaw;

    X_RotArray.Add(X_Val);
    Y_RotArray.Add(Y_Val);
    Z_RotArray.Add(Z_Val);
  }

  /** Location */
  TransformSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->Set(TimeArray, X_LocArray);
  TransformSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(1)->Set(TimeArray, Y_LocArray);
  TransformSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(2)->Set(TimeArray, Z_LocArray);

  /** Rotation */
  TransformSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(3)->Set(TimeArray, X_RotArray);
  TransformSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(4)->Set(TimeArray, Y_RotArray);
  TransformSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(5)->Set(TimeArray, Z_RotArray);

  /** Scale */
  TransformSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(6)->SetDefault(1);
  TransformSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(7)->SetDefault(1);
  TransformSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(8)->SetDefault(1);
}

void UCameraConverterTool::GetSequenceData(ULevelSequence* InSequence)
{
#define MOVIE_SCENE InSequence->GetMovieScene()

  if (MOVIE_SCENE->GetCameraCutTrack()->IsValidLowLevel())
    CameraCutTrack = MOVIE_SCENE->GetCameraCutTrack();

  TArray<UMovieSceneTrack*> MasterTracks = MOVIE_SCENE->GetMasterTracks();
  for (auto MasterTrack : MasterTracks)
  {
    TArray<UMovieSceneSection*> Sections = MasterTrack->GetAllSections();

    for (auto TrackSection : Sections)
    {
      if (!TrackSection->IsActive()) continue;

      UMovieSceneSubSection* SubScene = Cast<UMovieSceneSubSection>(TrackSection);
      UMovieSceneSequence* SubSequence = SubScene->GetSequence();

      if (SubScene->IsValidLowLevel() && SubScene->GetName().Contains("Audio")) continue;
      if (SubSequence->IsValidLowLevel() && SubSequence->GetName().Contains("Audio")) continue;

      if (SubSequence->IsValidLowLevel())
      {
        if (SubSequence->GetName().Contains("TargetPoint"))
        {
          TargetPointSubSection = SubScene;
          TargetPointSequence = SubSequence;
          ++TargetPoint;
        }

        if (SubSequence->GetName().Contains("CameraPawn"))
        {
          CameraSubSection = SubScene;
          CameraSequence = SubSequence;
          ++BPCameraCount;
        }

        /** Camera Count and Target Point Count */
        ULevelSequence* RecursiveSequence = Cast<ULevelSequence>(SubSequence);
        GetSequenceData(RecursiveSequence);
      }
    }
  }
  
#undef MOVIE_SCENE
}

void UCameraConverterTool::CopyCameraSettings(UMovieSceneSequence* Sequence, ACineCameraActor* CineCamera, FGuid CameraGUID)
{
  /** Bind Camera to New Camera GUID */
  UMovieSceneSection* CameraMovieSceneSection = CameraCutTrack->GetAllSections()[0];
  UMovieSceneCameraCutSection* CameraCutSection = Cast<UMovieSceneCameraCutSection>(CameraMovieSceneSection);
  CameraCutSection->SetCameraGuid(CameraGUID);

  auto CurrentSequence = Cast<ULevelSequence>(Sequence);
  auto Bindings = CurrentSequence->MovieScene->GetBindings();
  auto Tracks = Bindings[4].GetTracks();

  for (auto it : Tracks)
  {
    if (it->GetName().Contains("FloatTrack"))
    {
      UMovieSceneFloatTrack* Property = Cast<UMovieSceneFloatTrack>(it);

      if (Property->GetPropertyName().ToString().Contains("Aperture"))
      {
        auto Data = Property->GetAllSections()[0]->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0);

        if (Data->GetTimes().Num() > 0)
        {
          for (int i = 0; i < Data->GetTimes().Num(); ++i)
          {
            ApertureTimeArray.Add(Data->GetTimes()[i]);
            ApertureValue.Add(Data->GetValues()[i]);
          }

          Aperture = ApertureValue[0].Value;
        }

        else
          Aperture = Data->GetDefault().GetValue();

        CineCamera->GetCineCameraComponent()->CurrentAperture = Aperture;
      }

      else if (Property->GetPropertyName().ToString().Contains("FocalLength"))
      {
        auto Data = Property->GetAllSections()[0]->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0);

        if (Data->GetTimes().Num() > 0)
        {
          for (int i = 0; i < Data->GetTimes().Num(); ++i)
          {
            FocalLengthTimeArray.Add(Data->GetTimes()[i]);
            FocalLengthValue.Add(Data->GetValues()[i]);
          }

          FocalLength = FocalLengthValue[0].Value;
        }

        else
          FocalLength = Data->GetDefault().GetValue();

        CineCamera->GetCineCameraComponent()->CurrentFocalLength = FocalLength;
      }

      else if (Property->GetPropertyName().ToString().Contains("SensorWidth"))
      {
        SensorWidth = Property->GetAllSections()[0]->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->GetDefault().GetValue();
        CineCamera->GetCineCameraComponent()->FilmbackSettings.SensorWidth = SensorWidth;
      }

      else if (Property->GetPropertyName().ToString().Contains("SensorHeight"))
      {
        SensorHeight = Property->GetAllSections()[0]->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->GetDefault().GetValue();
        CineCamera->GetCineCameraComponent()->FilmbackSettings.SensorHeight = SensorHeight;
      }

      else if (Property->GetPropertyName().ToString().Contains("ManualFocusDistance"))
      {
        auto Data = Property->GetAllSections()[0]->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0);

        if (Data->GetTimes().Num() > 0)
        {
          for (int i = 0; i < Data->GetTimes().Num(); ++i)
          {
            ManualFocusDistanceTimeArray.Add(Data->GetTimes()[i]);
            ManualFocusDistanceValue.Add(Data->GetValues()[i]);
          }

          ManualFocusDistance = ManualFocusDistanceValue[0].Value;
        }

        else
          ManualFocusDistance = Data->GetDefault().GetValue();

        CineCamera->GetCineCameraComponent()->FocusSettings.ManualFocusDistance = ManualFocusDistance;
      }
      
      else if (Property->GetPropertyName().ToString().Contains("WhiteTemp"))
      {
        WhiteTemp = Property->GetAllSections()[0]->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->GetDefault().GetValue();
        CineCamera->GetCineCameraComponent()->PostProcessSettings.WhiteTemp = WhiteTemp;
      }

      else if (Property->GetPropertyName().ToString().Contains("FieldOfView"))
      {
        FOV = Property->GetAllSections()[0]->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->GetDefault().GetValue();
        CineCamera->GetCineCameraComponent()->FieldOfView = FOV;
      }

      else if (Property->GetPropertyName().ToString().Contains("FocusOffset"))
      {
        Focus_Offset = Property->GetAllSections()[0]->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->GetDefault().GetValue();
        CineCamera->GetCineCameraComponent()->FocusSettings.FocusOffset = Focus_Offset;
      }
    }
  }
}

void UCameraConverterTool::SpawnCineCameraActor()
{
  ACineCameraActor* CameraActor = World->SpawnActor<ACineCameraActor>();
  CameraActor->SetActorLabel(CameraName);
  CameraActor->GetCineCameraComponent()->PostProcessSettings.bOverride_WhiteTemp = true;
  UniqueIDArray.Add(CameraName, CameraActor->GetUniqueID());

  FName UniqueTemplateName = MakeUniqueObjectName(LevelSequence, CameraActor->GetClass(), NAME_None);
  auto CachedObjectTemplate = CastChecked<AActor>(LevelSequence->MakeSpawnableTemplateFromInstance(*CameraActor, UniqueTemplateName));
  FGuid CachedObjectBindingGuid = LevelSequence->MovieScene->AddSpawnable(CameraName, *CachedObjectTemplate);

  /** Add Transform Track */
  UMovieSceneTrack* TransformTrack = LevelSequence->MovieScene->AddTrack(UMovieScene3DTransformTrack::StaticClass(), CachedObjectBindingGuid);
  UMovieScene3DTransformSection* TransformSection = Cast<UMovieScene3DTransformSection>(TransformTrack->CreateNewSection());
  TransformSection->SetRange(TRange<FFrameNumber>());

  CalculateNewCameraTransform(TransformSection);

  TransformTrack->AddSection(*TransformSection);

  /** Adding Camera Component Track */
  UCineCameraComponent* CameraComponent = CameraActor->GetCineCameraComponent();
  FGuid ComponentGUID = LevelSequence->MovieScene->AddPossessable(CameraComponent->GetName(), CameraComponent->GetClass());
  LevelSequence->BindPossessableObject(ComponentGUID, *CameraComponent, CameraActor);

  FMovieScenePossessable* ChildPossesable = LevelSequence->MovieScene->FindPossessable(ComponentGUID);
  ChildPossesable->SetParent(CachedObjectBindingGuid);

  /** Add Spawnable Track */
  UMovieSceneSpawnTrack* SpawnTrack = Cast<UMovieSceneSpawnTrack>(LevelSequence->MovieScene->AddTrack(UMovieSceneSpawnTrack::StaticClass(), CachedObjectBindingGuid));
 
  UMovieSceneBoolSection* SpawnSection = Cast<UMovieSceneBoolSection>(SpawnTrack->CreateNewSection());
  SpawnSection->GetChannel().SetDefault(true);
  SpawnSection->SetRange(TRange<FFrameNumber>::All());
  SpawnTrack->AddSection(*SpawnSection);
  SpawnTrack->SetObjectId(CachedObjectBindingGuid);
  
  CopyCameraSettings(CameraSequence, CameraActor, CachedObjectBindingGuid);

  /** Adding Current Aperture Settings */
  UMovieSceneTrack* Track = LevelSequence->MovieScene->AddTrack(UMovieSceneFloatTrack::StaticClass(), ComponentGUID);
  UMovieSceneFloatTrack* ApertureTrack = Cast<UMovieSceneFloatTrack>(Track);
  ApertureTrack->SetPropertyNameAndPath("Current Aperture", "CurrentAperture");
  UMovieSceneFloatSection* ApertureSection = Cast<UMovieSceneFloatSection>(ApertureTrack->CreateNewSection());
  ApertureSection->SetRange(TRange<FFrameNumber>());
  
  if(ApertureTimeArray.Num() > 0)
    ApertureSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->Set(ApertureTimeArray, ApertureValue);

  else
    ApertureSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->SetDefault(Aperture);

  ApertureTrack->AddSection(*ApertureSection);

  /** Adding Focal Length Settings */
  Track = LevelSequence->MovieScene->AddTrack(UMovieSceneFloatTrack::StaticClass(), ComponentGUID);
  UMovieSceneFloatTrack* FocalLengthTrack = Cast<UMovieSceneFloatTrack>(Track);
  FocalLengthTrack->SetPropertyNameAndPath("Focal Length", "CurrentFocalLength");
  UMovieSceneFloatSection* FocalLengthSection = Cast<UMovieSceneFloatSection>(FocalLengthTrack->CreateNewSection());
  FocalLengthSection->SetRange(TRange<FFrameNumber>());

  if(FocalLengthTimeArray.Num() > 0)
    FocalLengthSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->Set(FocalLengthTimeArray, FocalLengthValue);

  else
    FocalLengthSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->SetDefault(FocalLength);

  FocalLengthTrack->AddSection(*FocalLengthSection);

  Track = LevelSequence->MovieScene->AddTrack(UMovieSceneFloatTrack::StaticClass(), ComponentGUID);
  UMovieSceneFloatTrack* FOVTrack = Cast<UMovieSceneFloatTrack>(Track);
  FOVTrack->SetPropertyNameAndPath("Field Of View", "FieldOfView");
  UMovieSceneFloatSection* FOVSection = Cast<UMovieSceneFloatSection>(FOVTrack->CreateNewSection());
  FOVSection->SetRange(TRange<FFrameNumber>());
  FOVSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->SetDefault(FOV);

  FOVTrack->AddSection(*FOVSection);

  /** Adding FilmBack Setting */
  Track = LevelSequence->MovieScene->AddTrack(UMovieSceneFloatTrack::StaticClass(), ComponentGUID);
  UMovieSceneFloatTrack* SensorWidthTrack = Cast<UMovieSceneFloatTrack>(Track);
  SensorWidthTrack->SetPropertyNameAndPath("Sensor Width(Filmback Settings)", "FilmbackSettings.SensorWidth");
  UMovieSceneFloatSection* SensorWidthSection = Cast<UMovieSceneFloatSection>(SensorWidthTrack->CreateNewSection());
  SensorWidthSection->SetRange(TRange<FFrameNumber>());
  SensorWidthSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->SetDefault(SensorWidth);

  SensorWidthTrack->AddSection(*SensorWidthSection);

  Track = LevelSequence->MovieScene->AddTrack(UMovieSceneFloatTrack::StaticClass(), ComponentGUID);
  UMovieSceneFloatTrack* SensorHeightrack = Cast<UMovieSceneFloatTrack>(Track);
  SensorHeightrack->SetPropertyNameAndPath("Sensor Height(Filmback Settings)", "FilmbackSettings.SensorHeight");
  UMovieSceneFloatSection* SensorHeightSection = Cast<UMovieSceneFloatSection>(SensorHeightrack->CreateNewSection());
  SensorHeightSection->SetRange(TRange<FFrameNumber>());
  SensorHeightSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->SetDefault(SensorHeight);

  SensorHeightrack->AddSection(*SensorHeightSection);
  
  /** Focus Settings */
  Track = LevelSequence->MovieScene->AddTrack(UMovieSceneFloatTrack::StaticClass(), ComponentGUID);
  UMovieSceneFloatTrack* ManualFocusDistanceTrack = Cast<UMovieSceneFloatTrack>(Track);
  ManualFocusDistanceTrack->SetPropertyNameAndPath("Manual Focus Distance", "FocusSettings.ManualFocusDistance");
  UMovieSceneFloatSection* ManualFocusDistanceSection = Cast<UMovieSceneFloatSection>(ManualFocusDistanceTrack->CreateNewSection());
  ManualFocusDistanceSection->SetRange(TRange<FFrameNumber>());

  if(ManualFocusDistanceTimeArray.Num() > 0)
    ManualFocusDistanceSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->Set(ManualFocusDistanceTimeArray, ManualFocusDistanceValue);

  else
    ManualFocusDistanceSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->SetDefault(ManualFocusDistance);

  ManualFocusDistanceTrack->AddSection(*ManualFocusDistanceSection);

  Track = LevelSequence->MovieScene->AddTrack(UMovieSceneFloatTrack::StaticClass(), ComponentGUID);
  UMovieSceneFloatTrack* FocusOffsetTrack = Cast<UMovieSceneFloatTrack>(Track);
  FocusOffsetTrack->SetPropertyNameAndPath("Focus Offset", "FocusSettings.FocusOffset");
  UMovieSceneFloatSection* FocusOffsetSection = Cast<UMovieSceneFloatSection>(FocusOffsetTrack->CreateNewSection());
  FocusOffsetSection->SetRange(TRange<FFrameNumber>());
  FocusOffsetSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->SetDefault(Focus_Offset);
  FocusOffsetTrack->AddSection(*FocusOffsetSection);

  /** Post Process */
  Track = LevelSequence->MovieScene->AddTrack(UMovieSceneFloatTrack::StaticClass(), ComponentGUID);
  UMovieSceneFloatTrack* WhiteTempTrack = Cast<UMovieSceneFloatTrack>(Track);
  WhiteTempTrack->SetPropertyNameAndPath("WhiteTemp(PostProcessSetting)", "PostProcessSettings.WhiteTemp");
  UMovieSceneFloatSection* WhiteTempSection = Cast<UMovieSceneFloatSection>(WhiteTempTrack->CreateNewSection());
  WhiteTempSection->SetRange(TRange<FFrameNumber>());
  WhiteTempSection->GetChannelProxy().GetChannel<FMovieSceneFloatChannel>(0)->SetDefault(WhiteTemp);
  WhiteTempTrack->AddSection(*WhiteTempSection);

  /** Destroy Actor */
  CameraActor->Destroy();
}

void UCameraConverterTool::ChangeSelectedActorsVisibility()
{
  World = GEditor->GetEditorWorldContext().World();

  USelection* SelectedActors = GEditor->GetSelectedActors();

  if (SelectedActors)
  {
    TArray<UObject*> ActorList;
    SelectedActors->GetSelectedObjects(AActor::StaticClass(), ActorList);

    if (ActorList.Num() != 0)
    {
      for (int i = 0; i < ActorList.Num(); ++i)
      {
        AActor* SelectedActor = Cast<AActor>(ActorList[i]);
        auto RootComp = SelectedActor->GetRootComponent();
        
        if(RootComp->bVisible)
          RootComp->SetVisibility(false);

        else if(!RootComp->bVisible)
          RootComp->SetVisibility(true);
      }
    }
  }
}