// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultiWindow/Public/PCSceneCaptureComponent2D.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePCSceneCaptureComponent2D() {}
// Cross Module References
	MULTIWINDOW_API UClass* Z_Construct_UClass_UPCSceneCaptureComponent2D_NoRegister();
	MULTIWINDOW_API UClass* Z_Construct_UClass_UPCSceneCaptureComponent2D();
	ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D();
	UPackage* Z_Construct_UPackage__Script_MultiWindow();
// End Cross Module References
	void UPCSceneCaptureComponent2D::StaticRegisterNativesUPCSceneCaptureComponent2D()
	{
	}
	UClass* Z_Construct_UClass_UPCSceneCaptureComponent2D_NoRegister()
	{
		return UPCSceneCaptureComponent2D::StaticClass();
	}
	struct Z_Construct_UClass_UPCSceneCaptureComponent2D_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPCSceneCaptureComponent2D_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneCaptureComponent2D,
		(UObject* (*)())Z_Construct_UPackage__Script_MultiWindow,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPCSceneCaptureComponent2D_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Rendering" },
		{ "HideCategories", "Collision Object Physics SceneComponent Collision Object Physics SceneComponent abstract Collision Object Physics SceneComponent Mobility Trigger PhysicsVolume" },
		{ "IncludePath", "PCSceneCaptureComponent2D.h" },
		{ "ModuleRelativePath", "Public/PCSceneCaptureComponent2D.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPCSceneCaptureComponent2D_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPCSceneCaptureComponent2D>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPCSceneCaptureComponent2D_Statics::ClassParams = {
		&UPCSceneCaptureComponent2D::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00A010A4u,
		METADATA_PARAMS(Z_Construct_UClass_UPCSceneCaptureComponent2D_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UPCSceneCaptureComponent2D_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPCSceneCaptureComponent2D()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPCSceneCaptureComponent2D_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPCSceneCaptureComponent2D, 3131285009);
	template<> MULTIWINDOW_API UClass* StaticClass<UPCSceneCaptureComponent2D>()
	{
		return UPCSceneCaptureComponent2D::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPCSceneCaptureComponent2D(Z_Construct_UClass_UPCSceneCaptureComponent2D, &UPCSceneCaptureComponent2D::StaticClass, TEXT("/Script/MultiWindow"), TEXT("UPCSceneCaptureComponent2D"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPCSceneCaptureComponent2D);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
