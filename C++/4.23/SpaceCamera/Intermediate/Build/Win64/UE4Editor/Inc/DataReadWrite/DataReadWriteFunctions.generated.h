// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DATAREADWRITE_DataReadWriteFunctions_generated_h
#error "DataReadWriteFunctions.generated.h already included, missing '#pragma once' in DataReadWriteFunctions.h"
#endif
#define DATAREADWRITE_DataReadWriteFunctions_generated_h

#define D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIsEditorPlaying) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UDataReadWrite::IsEditorPlaying(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWriteCageDataToFile) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_XScale); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_YScale); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ZScale); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UDataReadWrite::WriteCageDataToFile(Z_Param_XScale,Z_Param_YScale,Z_Param_ZScale); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWriteCameraDataToFile) \
	{ \
		P_GET_TARRAY(float,Z_Param_NewFocalLengthArray); \
		P_GET_TARRAY(float,Z_Param_NewHeightArray); \
		P_GET_TARRAY(float,Z_Param_NewApertureArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UDataReadWrite::WriteCameraDataToFile(Z_Param_NewFocalLengthArray,Z_Param_NewHeightArray,Z_Param_NewApertureArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadCageDataFromFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_XScale); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_YScale); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_ZScale); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UDataReadWrite::ReadCageDataFromFile(Z_Param_FileName,Z_Param_Out_XScale,Z_Param_Out_YScale,Z_Param_Out_ZScale); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadDataFromFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_GET_TARRAY_REF(float,Z_Param_Out_FocalLengthArray); \
		P_GET_TARRAY_REF(float,Z_Param_Out_HeightArray); \
		P_GET_TARRAY_REF(float,Z_Param_Out_ApertureArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UDataReadWrite::ReadDataFromFile(Z_Param_FileName,Z_Param_Out_FocalLengthArray,Z_Param_Out_HeightArray,Z_Param_Out_ApertureArray); \
		P_NATIVE_END; \
	}


#define D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsEditorPlaying) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UDataReadWrite::IsEditorPlaying(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWriteCageDataToFile) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_XScale); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_YScale); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ZScale); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UDataReadWrite::WriteCageDataToFile(Z_Param_XScale,Z_Param_YScale,Z_Param_ZScale); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWriteCameraDataToFile) \
	{ \
		P_GET_TARRAY(float,Z_Param_NewFocalLengthArray); \
		P_GET_TARRAY(float,Z_Param_NewHeightArray); \
		P_GET_TARRAY(float,Z_Param_NewApertureArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UDataReadWrite::WriteCameraDataToFile(Z_Param_NewFocalLengthArray,Z_Param_NewHeightArray,Z_Param_NewApertureArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadCageDataFromFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_XScale); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_YScale); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_ZScale); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UDataReadWrite::ReadCageDataFromFile(Z_Param_FileName,Z_Param_Out_XScale,Z_Param_Out_YScale,Z_Param_Out_ZScale); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadDataFromFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_GET_TARRAY_REF(float,Z_Param_Out_FocalLengthArray); \
		P_GET_TARRAY_REF(float,Z_Param_Out_HeightArray); \
		P_GET_TARRAY_REF(float,Z_Param_Out_ApertureArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UDataReadWrite::ReadDataFromFile(Z_Param_FileName,Z_Param_Out_FocalLengthArray,Z_Param_Out_HeightArray,Z_Param_Out_ApertureArray); \
		P_NATIVE_END; \
	}


#define D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDataReadWrite(); \
	friend struct Z_Construct_UClass_UDataReadWrite_Statics; \
public: \
	DECLARE_CLASS(UDataReadWrite, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DataReadWrite"), NO_API) \
	DECLARE_SERIALIZER(UDataReadWrite)


#define D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUDataReadWrite(); \
	friend struct Z_Construct_UClass_UDataReadWrite_Statics; \
public: \
	DECLARE_CLASS(UDataReadWrite, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DataReadWrite"), NO_API) \
	DECLARE_SERIALIZER(UDataReadWrite)


#define D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataReadWrite(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataReadWrite) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataReadWrite); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataReadWrite); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDataReadWrite(UDataReadWrite&&); \
	NO_API UDataReadWrite(const UDataReadWrite&); \
public:


#define D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataReadWrite(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDataReadWrite(UDataReadWrite&&); \
	NO_API UDataReadWrite(const UDataReadWrite&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataReadWrite); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataReadWrite); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataReadWrite)


#define D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_PRIVATE_PROPERTY_OFFSET
#define D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_12_PROLOG
#define D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_PRIVATE_PROPERTY_OFFSET \
	D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_RPC_WRAPPERS \
	D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_INCLASS \
	D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_PRIVATE_PROPERTY_OFFSET \
	D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_INCLASS_NO_PURE_DECLS \
	D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DATAREADWRITE_API UClass* StaticClass<class UDataReadWrite>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID D__PluginPackage_TLOOL_SpaceCamera_HostProject_Plugins_SpaceCamera_Source_DataReadWrite_Public_DataReadWriteFunctions_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
