// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMeshSocket.h"

//=============== Notification ====================
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Misc/MessageDialog.h"

//=============== Animation ====================
#include "Animation/AnimInstance.h"
//#include "Animation/MorphTarget.h"//

//=============== Camera ====================
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

//=============== Engine ====================
//#include "Engine/GameViewportClient.h"//

//=============== UnrealEd ====================
//#if WITH_EDITOR
//#include "LevelEditorViewport.h"
//#endif

//=============== Live Link ====================
#include "Engine/Engine.h"
#include "LiveLinkComponent.h"
#include "LiveLinkDrivenComponent.h"
#include "Roles/LiveLinkAnimationRole.h"
#include "LiveLinkBlueprintLibrary.h"
#include "LiveLinkMessageBusFinder.h"
#include "Components/SceneComponent.h"
#include "Components/PoseableMeshComponent.h"
#include "Roles/LiveLinkAnimationBlueprintStructs.h"
#include "Features/IModularFeatures.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "MofacLiveLinkBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/

USTRUCT()
struct FMorphShapeData
{
  GENERATED_BODY()

  UPROPERTY()
  TArray<int> MorphCurveNameIndex;
};

USTRUCT()
struct FBoneTransformData
{
  GENERATED_BODY()

    UPROPERTY()
    TArray<FTransform> BoneTransformArray;
};

UENUM()
enum AttachStyle
{
  KeepRelativeTransform,
  KeepWorldTransform,
  SnapToTargetNoScale,
  SnapToTargetWithScale
};

UENUM()
enum MobuFPS
{
  FPS_24,
  FPS_30,
  FPS_120
};

UCLASS()
class UMofacLiveLinkBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
  /* Live Link Functions */
  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Attach Camera To Bone", ToolTip = "This will create Socket and attach camera to the bone"), Category = "Mofac")
    static void AttachCameraToBone(USkeletalMeshComponent* SkeletalMeshComponent, UCameraComponent* Camera, FName BoneName, AttachStyle Style);

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Fetch All Morph Curve", ToolTip = "This will fetch all morph shape from Skeletal Mesh Component", AdvancedDisplay = "1", UpdateJointSeperately = false), Category = "Mofac")
    static void FetchAllMorphCurve(USkeletalMeshComponent* SkeletalMeshComponent);

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Update Morph Shape", ToolTip = "This will update Morph shape of Skeletal Mesh Component", AdvancedDisplay = "2", MorphShape = "Morph Shape"), Category = "Mofac")
    static void UpdateMorphShape(USkeletalMeshComponent* SkeletalMeshComponent, FName MorphShape, bool debug = false, FString DebugName = "All");

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Update Joints and Morph Shape by Seconds", ToolTip = "This will update Skeletal Mesh with Delay(Seconds)", DelayTime = 0.2f), Category = "Mofac")
    static void UpdateJointsAndMorphShapeBySeconds(USkeletalMeshComponent* SkeletalMeshComponent, UPoseableMeshComponent* PoseableMesh, FName MorphName, MobuFPS InputFPS, float DelayTime, bool visible);

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Update Joints and Morph Shape by Frame", ToolTip = "This will update Skeletal Mesh with Delay(Frame)"), Category = "Mofac")
    static void UpdateJointsAndMorphShapeByFrames(USkeletalMeshComponent* SkeletalMeshComponent, UPoseableMeshComponent* PoseableMesh, FName MorphName, float DelayFrame, bool visible);

  UFUNCTION(BlueprintInternalUseOnly)
    static void SaveBonesUpdateForDelayBySecond(USkeletalMeshComponent* SkeletalMeshComponent, UPoseableMeshComponent* PoseableMesh, MobuFPS InputFPS, const float DelayTime, bool visible);
  
  UFUNCTION(BlueprintInternalUseOnly)
    static void SaveBonesUpdateForDelayByFrame(USkeletalMeshComponent* SkeletalMeshComponent, UPoseableMeshComponent* PoseableMesh, const float DelayFrame, bool visible);

  UFUNCTION(BlueprintInternalUseOnly)
  static void NotifyMessage(FText Message);

  UFUNCTION(BlueprintInternalUseOnly)
  static void MessageDialogBox(FText Message);

private:
  static void FindNameAndAddToMap(FString Name, int index);

  static TArray<FName> OriginalMorphCurveName;
  static TMap<FString, FBoneTransformData> BoneTransformMap;
  static TMap<FString, FMorphShapeData> MorphDataMap;
};
