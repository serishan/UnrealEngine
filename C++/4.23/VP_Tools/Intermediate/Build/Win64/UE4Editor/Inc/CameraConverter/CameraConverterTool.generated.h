// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CAMERACONVERTER_CameraConverterTool_generated_h
#error "CameraConverterTool.generated.h already included, missing '#pragma once' in CameraConverterTool.h"
#endif
#define CAMERACONVERTER_CameraConverterTool_generated_h

#define D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execConvertCamera) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ConvertCamera(); \
		P_NATIVE_END; \
	}


#define D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execConvertCamera) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ConvertCamera(); \
		P_NATIVE_END; \
	}


#define D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCameraConverterTool(); \
	friend struct Z_Construct_UClass_UCameraConverterTool_Statics; \
public: \
	DECLARE_CLASS(UCameraConverterTool, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CameraConverter"), NO_API) \
	DECLARE_SERIALIZER(UCameraConverterTool)


#define D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_INCLASS \
private: \
	static void StaticRegisterNativesUCameraConverterTool(); \
	friend struct Z_Construct_UClass_UCameraConverterTool_Statics; \
public: \
	DECLARE_CLASS(UCameraConverterTool, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CameraConverter"), NO_API) \
	DECLARE_SERIALIZER(UCameraConverterTool)


#define D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCameraConverterTool(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCameraConverterTool) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCameraConverterTool); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCameraConverterTool); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCameraConverterTool(UCameraConverterTool&&); \
	NO_API UCameraConverterTool(const UCameraConverterTool&); \
public:


#define D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCameraConverterTool(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCameraConverterTool(UCameraConverterTool&&); \
	NO_API UCameraConverterTool(const UCameraConverterTool&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCameraConverterTool); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCameraConverterTool); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCameraConverterTool)


#define D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_PRIVATE_PROPERTY_OFFSET
#define D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_58_PROLOG
#define D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_PRIVATE_PROPERTY_OFFSET \
	D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_RPC_WRAPPERS \
	D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_INCLASS \
	D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_PRIVATE_PROPERTY_OFFSET \
	D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_RPC_WRAPPERS_NO_PURE_DECLS \
	D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_INCLASS_NO_PURE_DECLS \
	D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h_61_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class CameraConverterTool."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CAMERACONVERTER_API UClass* StaticClass<class UCameraConverterTool>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID D__PluginPackage_VP_Tools_HostProject_Plugins_VP_Tools_Source_CameraConverter_Public_CameraConverterTool_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
