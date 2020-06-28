#pragma once

#include "CoreMinimal.h"

struct CameraData
{
  float FocalLength;
  float Height;
  float Aperture;
};

struct StageData
{
  float XScale;
  float YScale;
  float ZScale;
};

class FCSVHelper
{
public:
  FCSVHelper() {}

  FString ImportCSVFile(const FString FileName);
  FString ImportCageCSVFile(const FString FileName);

  void ExportCSVFile(const FString FilePath, TArray<FString> Contents);

  const TMap<FString, CameraData> GetData() { return Data; }
  const TMap<FString, StageData> GetCageData() { return CageData; }
private:
  TMap<FString, CameraData> Data;
  TMap<FString, StageData> CageData;
};