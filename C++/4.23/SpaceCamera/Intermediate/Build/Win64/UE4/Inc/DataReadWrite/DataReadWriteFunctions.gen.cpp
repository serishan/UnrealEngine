// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DataReadWrite/Public/DataReadWriteFunctions.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDataReadWriteFunctions() {}
// Cross Module References
	DATAREADWRITE_API UClass* Z_Construct_UClass_UDataReadWrite_NoRegister();
	DATAREADWRITE_API UClass* Z_Construct_UClass_UDataReadWrite();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_DataReadWrite();
	DATAREADWRITE_API UFunction* Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying();
	DATAREADWRITE_API UFunction* Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile();
	DATAREADWRITE_API UFunction* Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile();
	DATAREADWRITE_API UFunction* Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile();
	DATAREADWRITE_API UFunction* Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile();
// End Cross Module References
	void UDataReadWrite::StaticRegisterNativesUDataReadWrite()
	{
		UClass* Class = UDataReadWrite::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "IsEditorPlaying", &UDataReadWrite::execIsEditorPlaying },
			{ "ReadCageDataFromFile", &UDataReadWrite::execReadCageDataFromFile },
			{ "ReadDataFromFile", &UDataReadWrite::execReadDataFromFile },
			{ "WriteCageDataToFile", &UDataReadWrite::execWriteCageDataToFile },
			{ "WriteCameraDataToFile", &UDataReadWrite::execWriteCameraDataToFile },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying_Statics
	{
		struct DataReadWrite_eventIsEditorPlaying_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DataReadWrite_eventIsEditorPlaying_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DataReadWrite_eventIsEditorPlaying_Parms), &Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying_Statics::Function_MetaDataParams[] = {
		{ "Category", "Editor State" },
		{ "ModuleRelativePath", "Public/DataReadWriteFunctions.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataReadWrite, nullptr, "IsEditorPlaying", nullptr, nullptr, sizeof(DataReadWrite_eventIsEditorPlaying_Parms), Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics
	{
		struct DataReadWrite_eventReadCageDataFromFile_Parms
		{
			FString FileName;
			float XScale;
			float YScale;
			float ZScale;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ZScale;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_YScale;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_XScale;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FileName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::NewProp_ZScale = { "ZScale", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataReadWrite_eventReadCageDataFromFile_Parms, ZScale), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::NewProp_YScale = { "YScale", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataReadWrite_eventReadCageDataFromFile_Parms, YScale), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::NewProp_XScale = { "XScale", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataReadWrite_eventReadCageDataFromFile_Parms, XScale), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::NewProp_FileName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataReadWrite_eventReadCageDataFromFile_Parms, FileName), METADATA_PARAMS(Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::NewProp_FileName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::NewProp_FileName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::NewProp_ZScale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::NewProp_YScale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::NewProp_XScale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::NewProp_FileName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data Writer" },
		{ "ModuleRelativePath", "Public/DataReadWriteFunctions.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataReadWrite, nullptr, "ReadCageDataFromFile", nullptr, nullptr, sizeof(DataReadWrite_eventReadCageDataFromFile_Parms), Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics
	{
		struct DataReadWrite_eventReadDataFromFile_Parms
		{
			FString FileName;
			TArray<float> FocalLengthArray;
			TArray<float> HeightArray;
			TArray<float> ApertureArray;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ApertureArray;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ApertureArray_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_HeightArray;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HeightArray_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_FocalLengthArray;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FocalLengthArray_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FileName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_ApertureArray = { "ApertureArray", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataReadWrite_eventReadDataFromFile_Parms, ApertureArray), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_ApertureArray_Inner = { "ApertureArray", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_HeightArray = { "HeightArray", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataReadWrite_eventReadDataFromFile_Parms, HeightArray), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_HeightArray_Inner = { "HeightArray", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_FocalLengthArray = { "FocalLengthArray", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataReadWrite_eventReadDataFromFile_Parms, FocalLengthArray), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_FocalLengthArray_Inner = { "FocalLengthArray", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_FileName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataReadWrite_eventReadDataFromFile_Parms, FileName), METADATA_PARAMS(Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_FileName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_FileName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_ApertureArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_ApertureArray_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_HeightArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_HeightArray_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_FocalLengthArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_FocalLengthArray_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::NewProp_FileName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data Writer" },
		{ "ModuleRelativePath", "Public/DataReadWriteFunctions.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataReadWrite, nullptr, "ReadDataFromFile", nullptr, nullptr, sizeof(DataReadWrite_eventReadDataFromFile_Parms), Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics
	{
		struct DataReadWrite_eventWriteCageDataToFile_Parms
		{
			float XScale;
			float YScale;
			float ZScale;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ZScale;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_YScale;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_XScale;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics::NewProp_ZScale = { "ZScale", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataReadWrite_eventWriteCageDataToFile_Parms, ZScale), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics::NewProp_YScale = { "YScale", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataReadWrite_eventWriteCageDataToFile_Parms, YScale), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics::NewProp_XScale = { "XScale", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataReadWrite_eventWriteCageDataToFile_Parms, XScale), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics::NewProp_ZScale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics::NewProp_YScale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics::NewProp_XScale,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data Writer" },
		{ "ModuleRelativePath", "Public/DataReadWriteFunctions.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataReadWrite, nullptr, "WriteCageDataToFile", nullptr, nullptr, sizeof(DataReadWrite_eventWriteCageDataToFile_Parms), Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics
	{
		struct DataReadWrite_eventWriteCameraDataToFile_Parms
		{
			TArray<float> NewFocalLengthArray;
			TArray<float> NewHeightArray;
			TArray<float> NewApertureArray;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_NewApertureArray;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewApertureArray_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_NewHeightArray;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewHeightArray_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_NewFocalLengthArray;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewFocalLengthArray_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::NewProp_NewApertureArray = { "NewApertureArray", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataReadWrite_eventWriteCameraDataToFile_Parms, NewApertureArray), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::NewProp_NewApertureArray_Inner = { "NewApertureArray", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::NewProp_NewHeightArray = { "NewHeightArray", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataReadWrite_eventWriteCameraDataToFile_Parms, NewHeightArray), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::NewProp_NewHeightArray_Inner = { "NewHeightArray", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::NewProp_NewFocalLengthArray = { "NewFocalLengthArray", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataReadWrite_eventWriteCameraDataToFile_Parms, NewFocalLengthArray), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::NewProp_NewFocalLengthArray_Inner = { "NewFocalLengthArray", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::NewProp_NewApertureArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::NewProp_NewApertureArray_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::NewProp_NewHeightArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::NewProp_NewHeightArray_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::NewProp_NewFocalLengthArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::NewProp_NewFocalLengthArray_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data Writer" },
		{ "ModuleRelativePath", "Public/DataReadWriteFunctions.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataReadWrite, nullptr, "WriteCameraDataToFile", nullptr, nullptr, sizeof(DataReadWrite_eventWriteCameraDataToFile_Parms), Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UDataReadWrite_NoRegister()
	{
		return UDataReadWrite::StaticClass();
	}
	struct Z_Construct_UClass_UDataReadWrite_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDataReadWrite_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_DataReadWrite,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDataReadWrite_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDataReadWrite_IsEditorPlaying, "IsEditorPlaying" }, // 624807359
		{ &Z_Construct_UFunction_UDataReadWrite_ReadCageDataFromFile, "ReadCageDataFromFile" }, // 2138127563
		{ &Z_Construct_UFunction_UDataReadWrite_ReadDataFromFile, "ReadDataFromFile" }, // 3420095788
		{ &Z_Construct_UFunction_UDataReadWrite_WriteCageDataToFile, "WriteCageDataToFile" }, // 486572021
		{ &Z_Construct_UFunction_UDataReadWrite_WriteCameraDataToFile, "WriteCameraDataToFile" }, // 1698048785
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataReadWrite_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DataReadWriteFunctions.h" },
		{ "ModuleRelativePath", "Public/DataReadWriteFunctions.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDataReadWrite_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDataReadWrite>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UDataReadWrite_Statics::ClassParams = {
		&UDataReadWrite::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UDataReadWrite_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UDataReadWrite_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDataReadWrite()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UDataReadWrite_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UDataReadWrite, 1950209532);
	template<> DATAREADWRITE_API UClass* StaticClass<UDataReadWrite>()
	{
		return UDataReadWrite::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDataReadWrite(Z_Construct_UClass_UDataReadWrite, &UDataReadWrite::StaticClass, TEXT("/Script/DataReadWrite"), TEXT("UDataReadWrite"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDataReadWrite);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
