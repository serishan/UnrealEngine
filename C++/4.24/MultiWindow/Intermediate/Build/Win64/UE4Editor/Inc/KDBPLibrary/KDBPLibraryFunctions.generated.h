// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UCineCameraComponent;
class USceneCaptureComponent2D;
#ifdef KDBPLIBRARY_KDBPLibraryFunctions_generated_h
#error "KDBPLibraryFunctions.generated.h already included, missing '#pragma once' in KDBPLibraryFunctions.h"
#endif
#define KDBPLIBRARY_KDBPLibraryFunctions_generated_h

#define HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_SPARSE_DATA
#define HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCustomCopyCameraSettingToSceneCapture) \
	{ \
		P_GET_OBJECT(UCineCameraComponent,Z_Param_Src); \
		P_GET_OBJECT(USceneCaptureComponent2D,Z_Param_Dst); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MaxFocalLength); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MinFocalLength); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_CurrentLength); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Aperture); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_SensorWidth); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_SensorHeight); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UKDBPCamera::CustomCopyCameraSettingToSceneCapture(Z_Param_Src,Z_Param_Dst,Z_Param_MaxFocalLength,Z_Param_MinFocalLength,Z_Param_CurrentLength,Z_Param_Aperture,Z_Param_SensorWidth,Z_Param_SensorHeight); \
		P_NATIVE_END; \
	}


#define HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCustomCopyCameraSettingToSceneCapture) \
	{ \
		P_GET_OBJECT(UCineCameraComponent,Z_Param_Src); \
		P_GET_OBJECT(USceneCaptureComponent2D,Z_Param_Dst); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MaxFocalLength); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MinFocalLength); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_CurrentLength); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Aperture); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_SensorWidth); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_SensorHeight); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UKDBPCamera::CustomCopyCameraSettingToSceneCapture(Z_Param_Src,Z_Param_Dst,Z_Param_MaxFocalLength,Z_Param_MinFocalLength,Z_Param_CurrentLength,Z_Param_Aperture,Z_Param_SensorWidth,Z_Param_SensorHeight); \
		P_NATIVE_END; \
	}


#define HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUKDBPCamera(); \
	friend struct Z_Construct_UClass_UKDBPCamera_Statics; \
public: \
	DECLARE_CLASS(UKDBPCamera, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/KDBPLibrary"), NO_API) \
	DECLARE_SERIALIZER(UKDBPCamera)


#define HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_INCLASS \
private: \
	static void StaticRegisterNativesUKDBPCamera(); \
	friend struct Z_Construct_UClass_UKDBPCamera_Statics; \
public: \
	DECLARE_CLASS(UKDBPCamera, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/KDBPLibrary"), NO_API) \
	DECLARE_SERIALIZER(UKDBPCamera)


#define HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UKDBPCamera(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UKDBPCamera) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UKDBPCamera); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UKDBPCamera); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UKDBPCamera(UKDBPCamera&&); \
	NO_API UKDBPCamera(const UKDBPCamera&); \
public:


#define HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UKDBPCamera(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UKDBPCamera(UKDBPCamera&&); \
	NO_API UKDBPCamera(const UKDBPCamera&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UKDBPCamera); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UKDBPCamera); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UKDBPCamera)


#define HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_31_PROLOG
#define HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_SPARSE_DATA \
	HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_RPC_WRAPPERS \
	HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_INCLASS \
	HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_SPARSE_DATA \
	HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h_34_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> KDBPLIBRARY_API UClass* StaticClass<class UKDBPCamera>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_MultiWindow_Source_KDBPLibrary_Public_KDBPLibraryFunctions_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
