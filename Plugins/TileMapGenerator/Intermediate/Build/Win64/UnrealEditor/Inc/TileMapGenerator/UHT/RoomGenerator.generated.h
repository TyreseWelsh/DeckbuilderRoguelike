// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "RoomGenerator.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FRoomData;
#ifdef TILEMAPGENERATOR_RoomGenerator_generated_h
#error "RoomGenerator.generated.h already included, missing '#pragma once' in RoomGenerator.h"
#endif
#define TILEMAPGENERATOR_RoomGenerator_generated_h

#define FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomGenerator_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSplitRoom);


#define FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomGenerator_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURoomGenerator(); \
	friend struct Z_Construct_UClass_URoomGenerator_Statics; \
public: \
	DECLARE_CLASS(URoomGenerator, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TileMapGenerator"), NO_API) \
	DECLARE_SERIALIZER(URoomGenerator)


#define FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomGenerator_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URoomGenerator(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	URoomGenerator(URoomGenerator&&); \
	URoomGenerator(const URoomGenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URoomGenerator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URoomGenerator); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URoomGenerator) \
	NO_API virtual ~URoomGenerator();


#define FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomGenerator_h_15_PROLOG
#define FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomGenerator_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomGenerator_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomGenerator_h_18_INCLASS_NO_PURE_DECLS \
	FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomGenerator_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TILEMAPGENERATOR_API UClass* StaticClass<class URoomGenerator>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomGenerator_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
