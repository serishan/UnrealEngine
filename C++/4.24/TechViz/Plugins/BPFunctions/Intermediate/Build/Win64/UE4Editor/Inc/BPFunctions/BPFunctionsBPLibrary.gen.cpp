// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPFunctions/Public/BPFunctionsBPLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBPFunctionsBPLibrary() {}
// Cross Module References
	BPFUNCTIONS_API UClass* Z_Construct_UClass_UBPFunctionsBPLibrary_NoRegister();
	BPFUNCTIONS_API UClass* Z_Construct_UClass_UBPFunctionsBPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_BPFunctions();
	BPFUNCTIONS_API UFunction* Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence();
	CINEMATICCAMERA_API UClass* Z_Construct_UClass_ACineCameraActor_NoRegister();
	LEVELSEQUENCE_API UClass* Z_Construct_UClass_ULevelSequence_NoRegister();
	BPFUNCTIONS_API UFunction* Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	void UBPFunctionsBPLibrary::StaticRegisterNativesUBPFunctionsBPLibrary()
	{
		UClass* Class = UBPFunctionsBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCameraFromSequence", &UBPFunctionsBPLibrary::execGetCameraFromSequence },
			{ "HideAttachedActors", &UBPFunctionsBPLibrary::execHideAttachedActors },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence_Statics
	{
		struct BPFunctionsBPLibrary_eventGetCameraFromSequence_Parms
		{
			ULevelSequence* LevelSequence;
			ACineCameraActor* Camera;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Camera;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LevelSequence;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BPFunctionsBPLibrary_eventGetCameraFromSequence_Parms, Camera), Z_Construct_UClass_ACineCameraActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence_Statics::NewProp_LevelSequence = { "LevelSequence", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BPFunctionsBPLibrary_eventGetCameraFromSequence_Parms, LevelSequence), Z_Construct_UClass_ULevelSequence_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence_Statics::NewProp_Camera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence_Statics::NewProp_LevelSequence,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence_Statics::Function_MetaDataParams[] = {
		{ "Category", "TechViz" },
		{ "ModuleRelativePath", "Public/BPFunctionsBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBPFunctionsBPLibrary, nullptr, "GetCameraFromSequence", nullptr, nullptr, sizeof(BPFunctionsBPLibrary_eventGetCameraFromSequence_Parms), Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics
	{
		struct BPFunctionsBPLibrary_eventHideAttachedActors_Parms
		{
			TArray<AActor*> SelectedActors;
			bool Visibility;
		};
		static void NewProp_Visibility_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Visibility;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SelectedActors;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SelectedActors_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::NewProp_Visibility_SetBit(void* Obj)
	{
		((BPFunctionsBPLibrary_eventHideAttachedActors_Parms*)Obj)->Visibility = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::NewProp_Visibility = { "Visibility", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(BPFunctionsBPLibrary_eventHideAttachedActors_Parms), &Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::NewProp_Visibility_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::NewProp_SelectedActors = { "SelectedActors", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BPFunctionsBPLibrary_eventHideAttachedActors_Parms, SelectedActors), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::NewProp_SelectedActors_Inner = { "SelectedActors", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::NewProp_Visibility,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::NewProp_SelectedActors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::NewProp_SelectedActors_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::Function_MetaDataParams[] = {
		{ "Category", "TechViz" },
		{ "ModuleRelativePath", "Public/BPFunctionsBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBPFunctionsBPLibrary, nullptr, "HideAttachedActors", nullptr, nullptr, sizeof(BPFunctionsBPLibrary_eventHideAttachedActors_Parms), Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UBPFunctionsBPLibrary_NoRegister()
	{
		return UBPFunctionsBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UBPFunctionsBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBPFunctionsBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_BPFunctions,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UBPFunctionsBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UBPFunctionsBPLibrary_GetCameraFromSequence, "GetCameraFromSequence" }, // 245348927
		{ &Z_Construct_UFunction_UBPFunctionsBPLibrary_HideAttachedActors, "HideAttachedActors" }, // 3652727857
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBPFunctionsBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BPFunctionsBPLibrary.h" },
		{ "ModuleRelativePath", "Public/BPFunctionsBPLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBPFunctionsBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBPFunctionsBPLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBPFunctionsBPLibrary_Statics::ClassParams = {
		&UBPFunctionsBPLibrary::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UBPFunctionsBPLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctionsBPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBPFunctionsBPLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBPFunctionsBPLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBPFunctionsBPLibrary, 1511441264);
	template<> BPFUNCTIONS_API UClass* StaticClass<UBPFunctionsBPLibrary>()
	{
		return UBPFunctionsBPLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBPFunctionsBPLibrary(Z_Construct_UClass_UBPFunctionsBPLibrary, &UBPFunctionsBPLibrary::StaticClass, TEXT("/Script/BPFunctions"), TEXT("UBPFunctionsBPLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBPFunctionsBPLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
