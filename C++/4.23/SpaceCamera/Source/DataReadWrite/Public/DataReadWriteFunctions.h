#pragma once

#include "CSVHelper.h"
#include "CoreMinimal.h"
#include "CineCameraComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"

//#include "Editor/EditorEngine.h"

#include "DataReadWriteFunctions.generated.h"

UCLASS()
class UDataReadWrite : public UBlueprintFunctionLibrary
{
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable, Category = "Data Writer")
    static void ReadDataFromFile(const FString FileName, TArray<float>& FocalLengthArray, TArray<float>& HeightArray, TArray<float>& ApertureArray);

  UFUNCTION(BlueprintCallable, Category = "Data Writer")
    static void ReadCageDataFromFile(const FString FileName, float& XScale, float& YScale, float& ZScale);

  UFUNCTION(BlueprintCallable, Category = "Data Writer")
    static void WriteCameraDataToFile(TArray<float> NewFocalLengthArray, TArray<float> NewHeightArray, TArray<float> NewApertureArray);

  UFUNCTION(BlueprintCallable, Category = "Data Writer")
    static void WriteCageDataToFile(float XScale, float YScale, float ZScale);

  UFUNCTION(BlueprintCallable, Category = "Editor State")
    static bool IsEditorPlaying();
    
private:
  static FCSVHelper* CSV_Helper;

  static TArray<float> CameraFocalLength;
  static TArray<float> CameraHeight;
  static TArray<float> CameraAperture;

  static FString FilePath;
  static FString CageFilePath;
};