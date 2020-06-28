#include "DataReadWriteFunctions.h"

FString UDataReadWrite::FilePath = FString();
FString UDataReadWrite::CageFilePath = FString();
FCSVHelper* UDataReadWrite::CSV_Helper = new FCSVHelper();
TArray<float> UDataReadWrite::CameraFocalLength = TArray<float>();
TArray<float> UDataReadWrite::CameraHeight = TArray<float>();
TArray<float> UDataReadWrite::CameraAperture = TArray<float>();

void UDataReadWrite::ReadDataFromFile(const FString FileName, TArray<float>& FocalLengthArray, TArray<float>& HeightArray, TArray<float>& ApertureArray)
{
  CameraFocalLength.Empty();
  CameraHeight.Empty();
  CameraAperture.Empty();

  FilePath = CSV_Helper->ImportCSVFile(FileName);

  auto Data = CSV_Helper->GetData();

  for (int i = 0; i < Data.Num(); ++i)
  {
    FString Name = ("View" + (FString::FromInt(i+1)));
    CameraFocalLength.Add(Data[Name].FocalLength);
    CameraHeight.Add(Data[Name].Height);
    CameraAperture.Add(Data[Name].Aperture);
  }

  FocalLengthArray = CameraFocalLength;
  HeightArray = CameraHeight;
  ApertureArray = CameraAperture;
}

void UDataReadWrite::ReadCageDataFromFile(const FString FileName, float& XScale, float& YScale, float& ZScale)
{
  CageFilePath = CSV_Helper->ImportCageCSVFile(FileName);
  auto Data = CSV_Helper->GetCageData();

  XScale = Data["Cage"].XScale;
  YScale = Data["Cage"].YScale;
  ZScale = Data["Cage"].ZScale;
}

void UDataReadWrite::WriteCameraDataToFile(TArray<float> NewFocalLengthArray, TArray<float> NewHeightArray, TArray<float> NewApertureArray)
{
  auto Data = CSV_Helper->GetData();

  TArray<FString> ContentsArray;
  for (int i = 0; i < Data.Num(); ++i)
  {
    FString Contents;
    FString Name = ("View" + (FString::FromInt(i + 1)));
    Contents = (Name + "," + FString::SanitizeFloat(NewFocalLengthArray[i]) \
      + "," + FString::SanitizeFloat(NewHeightArray[i]) \
      + "," + FString::SanitizeFloat(NewApertureArray[i]));

    ContentsArray.Add(Contents);
  }

  CSV_Helper->ExportCSVFile(FilePath, ContentsArray);
}

void UDataReadWrite::WriteCageDataToFile(float XScale, float YScale, float ZScale)
{
  auto Data = CSV_Helper->GetCageData();  
  TArray<FString> ContentsArray;

  FString Contents;
  Contents = ("Cage," + FString::SanitizeFloat(XScale) + "," + FString::SanitizeFloat(YScale) + "," + FString::SanitizeFloat(ZScale));

  ContentsArray.Add(Contents);

  CSV_Helper->ExportCSVFile(CageFilePath, ContentsArray);
}

bool UDataReadWrite::IsEditorPlaying()
{
  //UEditorEngine* Editor = CastChecked<UEditorEngine>(GEngine);

  //if (Editor->bIsSimulatingInEditor)
  if(GIsPlayInEditorWorld)
    return true;

  return false;
}