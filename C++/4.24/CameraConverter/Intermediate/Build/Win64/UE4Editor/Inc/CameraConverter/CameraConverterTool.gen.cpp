// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CameraConverter/Public/CameraConverterTool.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCameraConverterTool() {}
// Cross Module References
	CAMERACONVERTER_API UClass* Z_Construct_UClass_UCameraConverterTool_NoRegister();
	CAMERACONVERTER_API UClass* Z_Construct_UClass_UCameraConverterTool();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_CameraConverter();
	CAMERACONVERTER_API UFunction* Z_Construct_UFunction_UCameraConverterTool_ConvertCamera();
	LEVELSEQUENCE_API UClass* Z_Construct_UClass_ULevelSequence_NoRegister();
// End Cross Module References
	void UCameraConverterTool::StaticRegisterNativesUCameraConverterTool()
	{
		UClass* Class = UCameraConverterTool::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ConvertCamera", &UCameraConverterTool::execConvertCamera },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCameraConverterTool_ConvertCamera_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCameraConverterTool_ConvertCamera_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Action" },
		{ "ModuleRelativePath", "Public/CameraConverterTool.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCameraConverterTool_ConvertCamera_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCameraConverterTool, nullptr, "ConvertCamera", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCameraConverterTool_ConvertCamera_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraConverterTool_ConvertCamera_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCameraConverterTool_ConvertCamera()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCameraConverterTool_ConvertCamera_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCameraConverterTool_NoRegister()
	{
		return UCameraConverterTool::StaticClass();
	}
	struct Z_Construct_UClass_UCameraConverterTool_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetFPS_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_TargetFPS;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CameraName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LevelSequence_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LevelSequence;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCameraConverterTool_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_CameraConverter,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCameraConverterTool_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCameraConverterTool_ConvertCamera, "ConvertCamera" }, // 1436410796
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCameraConverterTool_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CameraConverterTool.h" },
		{ "ModuleRelativePath", "Public/CameraConverterTool.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_TargetFPS_MetaData[] = {
		{ "Category", "Settings" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/CameraConverterTool.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_TargetFPS = { "TargetFPS", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCameraConverterTool, TargetFPS), METADATA_PARAMS(Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_TargetFPS_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_TargetFPS_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_CameraName_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/CameraConverterTool.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_CameraName = { "CameraName", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCameraConverterTool, CameraName), METADATA_PARAMS(Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_CameraName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_CameraName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_LevelSequence_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/CameraConverterTool.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_LevelSequence = { "LevelSequence", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCameraConverterTool, LevelSequence), Z_Construct_UClass_ULevelSequence_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_LevelSequence_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_LevelSequence_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCameraConverterTool_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_TargetFPS,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_CameraName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraConverterTool_Statics::NewProp_LevelSequence,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCameraConverterTool_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCameraConverterTool>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCameraConverterTool_Statics::ClassParams = {
		&UCameraConverterTool::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCameraConverterTool_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCameraConverterTool_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCameraConverterTool_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCameraConverterTool_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCameraConverterTool()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCameraConverterTool_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCameraConverterTool, 107360103);
	template<> CAMERACONVERTER_API UClass* StaticClass<UCameraConverterTool>()
	{
		return UCameraConverterTool::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCameraConverterTool(Z_Construct_UClass_UCameraConverterTool, &UCameraConverterTool::StaticClass, TEXT("/Script/CameraConverter"), TEXT("UCameraConverterTool"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCameraConverterTool);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
