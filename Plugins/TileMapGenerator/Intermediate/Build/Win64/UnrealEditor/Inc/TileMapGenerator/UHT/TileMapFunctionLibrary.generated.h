// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TileMapFunctionLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef TILEMAPGENERATOR_TileMapFunctionLibrary_generated_h
#error "TileMapFunctionLibrary.generated.h already included, missing '#pragma once' in TileMapFunctionLibrary.h"
#endif
#define TILEMAPGENERATOR_TileMapFunctionLibrary_generated_h

#define FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileMapFunctionLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUnOccupyTile); \
	DECLARE_FUNCTION(execOccupyTile); \
	DECLARE_FUNCTION(execGetBelowTile);


#define FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileMapFunctionLibrary_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTileMapFunctionLibrary(); \
	friend struct Z_Construct_UClass_UTileMapFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UTileMapFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TileMapGenerator"), NO_API) \
	DECLARE_SERIALIZER(UTileMapFunctionLibrary)


#define FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileMapFunctionLibrary_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTileMapFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UTileMapFunctionLibrary(UTileMapFunctionLibrary&&); \
	UTileMapFunctionLibrary(const UTileMapFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTileMapFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTileMapFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTileMapFunctionLibrary) \
	NO_API virtual ~UTileMapFunctionLibrary();


#define FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileMapFunctionLibrary_h_12_PROLOG
#define FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileMapFunctionLibrary_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileMapFunctionLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileMapFunctionLibrary_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileMapFunctionLibrary_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TILEMAPGENERATOR_API UClass* StaticClass<class UTileMapFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileMapFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
