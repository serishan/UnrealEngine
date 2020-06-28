// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KDBPLibrary/Public/KDBPLibraryFunctions.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKDBPLibraryFunctions() {}
// Cross Module References
	KDBPLIBRARY_API UClass* Z_Construct_UClass_UKDBPCamera_NoRegister();
	KDBPLIBRARY_API UClass* Z_Construct_UClass_UKDBPCamera();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_KDBPLibrary();
	KDBPLIBRARY_API UFunction* Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture();
	ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D_NoRegister();
	CINEMATICCAMERA_API UClass* Z_Construct_UClass_UCineCameraComponent_NoRegister();
// End Cross Module References
	void UKDBPCamera::StaticRegisterNativesUKDBPCamera()
	{
		UClass* Class = UKDBPCamera::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CustomCopyCameraSettingToSceneCapture", &UKDBPCamera::execCustomCopyCameraSettingToSceneCapture },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics
	{
		struct KDBPCamera_eventCustomCopyCameraSettingToSceneCapture_Parms
		{
			UCineCameraComponent* Src;
			USceneCaptureComponent2D* Dst;
			float MaxFocalLength;
			float MinFocalLength;
			float CurrentLength;
			float Aperture;
			float SensorWidth;
			float SensorHeight;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SensorHeight;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SensorWidth;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Aperture;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentLength;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MinFocalLength;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxFocalLength;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Dst_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Dst;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Src_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Src;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_SensorHeight = { "SensorHeight", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(KDBPCamera_eventCustomCopyCameraSettingToSceneCapture_Parms, SensorHeight), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_SensorWidth = { "SensorWidth", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(KDBPCamera_eventCustomCopyCameraSettingToSceneCapture_Parms, SensorWidth), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_Aperture = { "Aperture", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(KDBPCamera_eventCustomCopyCameraSettingToSceneCapture_Parms, Aperture), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_CurrentLength = { "CurrentLength", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(KDBPCamera_eventCustomCopyCameraSettingToSceneCapture_Parms, CurrentLength), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_MinFocalLength = { "MinFocalLength", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(KDBPCamera_eventCustomCopyCameraSettingToSceneCapture_Parms, MinFocalLength), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_MaxFocalLength = { "MaxFocalLength", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(KDBPCamera_eventCustomCopyCameraSettingToSceneCapture_Parms, MaxFocalLength), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_Dst_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_Dst = { "Dst", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(KDBPCamera_eventCustomCopyCameraSettingToSceneCapture_Parms, Dst), Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_Dst_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_Dst_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_Src_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_Src = { "Src", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(KDBPCamera_eventCustomCopyCameraSettingToSceneCapture_Parms, Src), Z_Construct_UClass_UCineCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_Src_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_Src_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_SensorHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_SensorWidth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_Aperture,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_CurrentLength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_MinFocalLength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_MaxFocalLength,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_Dst,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::NewProp_Src,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::Function_MetaDataParams[] = {
		{ "Category", "Mofac|SceneCapture" },
		{ "ModuleRelativePath", "Public/KDBPLibraryFunctions.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKDBPCamera, nullptr, "CustomCopyCameraSettingToSceneCapture", nullptr, nullptr, sizeof(KDBPCamera_eventCustomCopyCameraSettingToSceneCapture_Parms), Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UKDBPCamera_NoRegister()
	{
		return UKDBPCamera::StaticClass();
	}
	struct Z_Construct_UClass_UKDBPCamera_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UKDBPCamera_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_KDBPLibrary,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UKDBPCamera_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UKDBPCamera_CustomCopyCameraSettingToSceneCapture, "CustomCopyCameraSettingToSceneCapture" }, // 171091714
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKDBPCamera_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** Camera Setting Class */" },
		{ "IncludePath", "KDBPLibraryFunctions.h" },
		{ "ModuleRelativePath", "Public/KDBPLibraryFunctions.h" },
		{ "ToolTip", "Camera Setting Class" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UKDBPCamera_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UKDBPCamera>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UKDBPCamera_Statics::ClassParams = {
		&UKDBPCamera::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UKDBPCamera_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UKDBPCamera_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UKDBPCamera()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UKDBPCamera_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UKDBPCamera, 1830293013);
	template<> KDBPLIBRARY_API UClass* StaticClass<UKDBPCamera>()
	{
		return UKDBPCamera::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UKDBPCamera(Z_Construct_UClass_UKDBPCamera, &UKDBPCamera::StaticClass, TEXT("/Script/KDBPLibrary"), TEXT("UKDBPCamera"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UKDBPCamera);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
