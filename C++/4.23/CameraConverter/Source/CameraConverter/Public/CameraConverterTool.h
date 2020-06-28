#pragma once

#include "EngineMinimal.h"
#include "UObject/Object.h"
#include "CameraConverterEdMode.h"

/** Level Sequence */
#include "LevelSequence.h"
#include "LevelSequencePlayer.h"
#include "LevelSequenceActor.h"

/** Track Sections */
#include "Sections/MovieSceneBoolSection.h"
#include "Sections/MovieSceneSubSection.h"
#include "Sections/MovieSceneFloatSection.h"
#include "Sections/MovieSceneCameraCutSection.h"

/** Tracks */
#include "MovieSceneTrack.h"
#include "Tracks/MovieScene3DTransformTrack.h"
#include "Tracks/MovieSceneFloatTrack.h"
#include "Tracks/MovieSceneBoolTrack.h"

#include "Misc/MessageDialog.h"
#include "CineCameraActor.h"
#include "CineCameraComponent.h"
#include "GameFramework/Actor.h"

#include "Kismet/GameplayStatics.h"

#if WITH_EDITOR
#include "SequencerSettings.h"
#endif

#include "CameraConverterTool.generated.h"

class FCameraConverterEdMode;

struct TransformArray
{
  /** Location */
  TArray<FFrameNumber> Loc_XTime;
  TArray<FFrameNumber> Loc_YTime;
  TArray<FFrameNumber> Loc_ZTime;
  TArray<FMovieSceneFloatValue> Loc_XValue;
  TArray<FMovieSceneFloatValue> Loc_YValue;
  TArray<FMovieSceneFloatValue> Loc_ZValue;

  /** Rotation */
  TArray<FFrameNumber> Rot_XTime;
  TArray<FFrameNumber> Rot_YTime;
  TArray<FFrameNumber> Rot_ZTime;
  TArray<FMovieSceneFloatValue> Rot_XValue;
  TArray<FMovieSceneFloatValue> Rot_YValue;
  TArray<FMovieSceneFloatValue> Rot_ZValue;
};

UCLASS()
class UCameraConverterTool : public UObject
{
  GENERATED_UCLASS_BODY()

public:
  FCameraConverterEdMode* ParentMode;

  void SetParent(FCameraConverterEdMode* NewMode) { ParentMode = NewMode; }

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
    ULevelSequence* LevelSequence;

  UPROPERTY(EditAnywhere, Category = "Settings")
    FString CameraName = "BakedCam";

  UPROPERTY(EditAnywhere, meta = (ClampMin=1), Category = "Settings")
    int TargetFPS = 24;

  UFUNCTION(BlueprintCallable, CallInEditor, Category = "Action")
    void ConvertCamera();

  UFUNCTION(BlueprintCallable, CallInEditor, Category = "Action")
    void ChangeSelectedActorsVisibility();

private:
  UMovieSceneSubSection* CameraSubSection = nullptr;
  UMovieSceneSubSection* TargetPointSubSection = nullptr;
  UMovieSceneSequence* CameraSequence = nullptr;
  UMovieSceneSequence* TargetPointSequence = nullptr;
  UMovieSceneTrack* CameraCutTrack = nullptr;

  UWorld* World = nullptr;
  ULevelSequencePlayer* Player = nullptr;

  int BPCameraCount = 0;
  int TargetPoint = 0;
  int LowerBound = 0;
  int UpperBound = 0;

  TRange<FFrameNumber> PlayBackRange;
  TArray<FFrameNumber> TimeArray;
  TArray<int> MarkedFrameIndexArray;

  AActor* CineCameraOriginActor = nullptr;
  AActor* CameraPawnActor = nullptr;
  AActor* PivotActor = nullptr;
  UCineCameraComponent* CineCameraComponent;

  float SensorWidth = INFINITY;
  float SensorHeight = INFINITY;
  float WhiteTemp = INFINITY;
  float FOV = INFINITY;
  float Focus_Offset = INFINITY;
  
  float Aperture = INFINITY;
  TArray<FFrameNumber> ApertureTimeArray;
  TArray<FMovieSceneFloatValue> ApertureValue;

  float ManualFocusDistance = INFINITY;
  TArray<FFrameNumber> ManualFocusDistanceTimeArray;
  TArray<FMovieSceneFloatValue> ManualFocusDistanceValue;

  float FocalLength = INFINITY;
  TArray<FFrameNumber> FocalLengthTimeArray;
  TArray<FMovieSceneFloatValue> FocalLengthValue;

  TMap<FString, int> UniqueIDArray;

  void SpawnCineCameraActor();
  void GetSequenceData(ULevelSequence* InSequence);

  void CopyCameraSettings(UMovieSceneSequence* Sequence, ACineCameraActor* CineCamera, FGuid CameraGUID);

  void CalculateNewCameraTransform(UMovieScene3DTransformSection* TransformSection);
  void FindActor();

  void GenerateOriginalIDArray();
  void DestroyUnrelatedActors();
  
};