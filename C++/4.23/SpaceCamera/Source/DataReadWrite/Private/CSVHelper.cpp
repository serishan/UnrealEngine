#include "CSVHelper.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

FString FCSVHelper::ImportCSVFile(const FString FileName)
{
  FString RootPath = FPaths::ProjectPluginsDir() / TEXT("SpaceCamera/Content/Data");
  RootPath += ("/" + FileName + ".csv");

  TArray<FString> Row;
  FFileHelper::LoadFileToStringArray(Row, *RootPath);

  if (Row.Num() > 0)
  {
    for (int i = 0; i < Row.Num(); ++i)
    {
      TArray<FString> RowData;
      Row[i].ParseIntoArray(RowData, TEXT(","), true);
      Data.Add(RowData[0]);

      Data[RowData[0]].FocalLength = FCString::Atof(*RowData[1]);
      Data[RowData[0]].Height = FCString::Atof(*RowData[2]);
      Data[RowData[0]].Aperture = FCString::Atof(*RowData[3]);
    }
  }

  return RootPath;
}

FString FCSVHelper::ImportCageCSVFile(const FString FileName)
{
  FString RootPath = FPaths::ProjectPluginsDir() / TEXT("SpaceCamera/Content/Data");
  RootPath += ("/" + FileName + ".csv");
  
  TArray<FString> Row;
  FFileHelper::LoadFileToStringArray(Row, *RootPath);

  if (Row.Num() > 0)
  {
    for (int i = 0; i < Row.Num(); ++i)
    {
      TArray<FString> RowData;
      Row[i].ParseIntoArray(RowData, TEXT(","), true);
      CageData.Add(RowData[0]);

      CageData[RowData[0]].XScale = FCString::Atof(*RowData[1]);
      CageData[RowData[0]].YScale = FCString::Atof(*RowData[2]);
      CageData[RowData[0]].ZScale = FCString::Atof(*RowData[3]);
    }
  }

  return RootPath;
}

void FCSVHelper::ExportCSVFile(const FString FilePath, TArray<FString> Contents)
{
  FFileHelper::SaveStringArrayToFile(Contents, *FilePath);
}