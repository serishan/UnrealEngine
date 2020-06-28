// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class ULevelSequence;
class ACineCameraActor;
#ifdef BPFUNCTIONS_BPFunctionsBPLibrary_generated_h
#error "BPFunctionsBPLibrary.generated.h already included, missing '#pragma once' in BPFunctionsBPLibrary.h"
#endif
#define BPFUNCTIONS_BPFunctionsBPLibrary_generated_h

#define HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_SPARSE_DATA
#define HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execHideAttachedActors) \
	{ \
		P_GET_TARRAY(AActor*,Z_Param_SelectedActors); \
		P_GET_UBOOL(Z_Param_Visibility); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UBPFunctionsBPLibrary::HideAttachedActors(Z_Param_SelectedActors,Z_Param_Visibility); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCameraFromSequence) \
	{ \
		P_GET_OBJECT(ULevelSequence,Z_Param_LevelSequence); \
		P_GET_OBJECT_REF(ACineCameraActor,Z_Param_Out_Camera); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UBPFunctionsBPLibrary::GetCameraFromSequence(Z_Param_LevelSequence,Z_Param_Out_Camera); \
		P_NATIVE_END; \
	}


#define HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHideAttachedActors) \
	{ \
		P_GET_TARRAY(AActor*,Z_Param_SelectedActors); \
		P_GET_UBOOL(Z_Param_Visibility); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UBPFunctionsBPLibrary::HideAttachedActors(Z_Param_SelectedActors,Z_Param_Visibility); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCameraFromSequence) \
	{ \
		P_GET_OBJECT(ULevelSequence,Z_Param_LevelSequence); \
		P_GET_OBJECT_REF(ACineCameraActor,Z_Param_Out_Camera); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UBPFunctionsBPLibrary::GetCameraFromSequence(Z_Param_LevelSequence,Z_Param_Out_Camera); \
		P_NATIVE_END; \
	}


#define HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBPFunctionsBPLibrary(); \
	friend struct Z_Construct_UClass_UBPFunctionsBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UBPFunctionsBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/BPFunctions"), NO_API) \
	DECLARE_SERIALIZER(UBPFunctionsBPLibrary)


#define HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUBPFunctionsBPLibrary(); \
	friend struct Z_Construct_UClass_UBPFunctionsBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UBPFunctionsBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/BPFunctions"), NO_API) \
	DECLARE_SERIALIZER(UBPFunctionsBPLibrary)


#define HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBPFunctionsBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBPFunctionsBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBPFunctionsBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBPFunctionsBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UBPFunctionsBPLibrary(UBPFunctionsBPLibrary&&); \
	NO_API UBPFunctionsBPLibrary(const UBPFunctionsBPLibrary&); \
public:


#define HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBPFunctionsBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UBPFunctionsBPLibrary(UBPFunctionsBPLibrary&&); \
	NO_API UBPFunctionsBPLibrary(const UBPFunctionsBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBPFunctionsBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBPFunctionsBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBPFunctionsBPLibrary)


#define HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_13_PROLOG
#define HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_SPARSE_DATA \
	HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_RPC_WRAPPERS \
	HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_INCLASS \
	HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_SPARSE_DATA \
	HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h_16_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class BPFunctionsBPLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BPFUNCTIONS_API UClass* StaticClass<class UBPFunctionsBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_BPFunctions_Source_BPFunctions_Public_BPFunctionsBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
