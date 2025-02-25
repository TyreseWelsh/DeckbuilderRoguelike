// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TileMapGenerator/Public/MapRoom.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMapRoom() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_AMapRoom();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_AMapRoom_NoRegister();
TILEMAPGENERATOR_API UScriptStruct* Z_Construct_UScriptStruct_FRoomData();
UPackage* Z_Construct_UPackage__Script_TileMapGenerator();
// End Cross Module References

// Begin ScriptStruct FRoomData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RoomData;
class UScriptStruct* FRoomData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RoomData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RoomData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRoomData, (UObject*)Z_Construct_UPackage__Script_TileMapGenerator(), TEXT("RoomData"));
	}
	return Z_Registration_Info_UScriptStruct_RoomData.OuterSingleton;
}
template<> TILEMAPGENERATOR_API UScriptStruct* StaticStruct<FRoomData>()
{
	return FRoomData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FRoomData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/MapRoom.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mOrigin_MetaData[] = {
		{ "Category", "RoomData" },
		{ "ModuleRelativePath", "Public/MapRoom.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mSizeX_MetaData[] = {
		{ "Category", "RoomData" },
		{ "ModuleRelativePath", "Public/MapRoom.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mSizeY_MetaData[] = {
		{ "Category", "RoomData" },
		{ "ModuleRelativePath", "Public/MapRoom.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mBSPSplitsRemaining_MetaData[] = {
		{ "Category", "RoomData" },
		{ "ModuleRelativePath", "Public/MapRoom.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mMinPadding_MetaData[] = {
		{ "Category", "RoomData" },
		{ "ModuleRelativePath", "Public/MapRoom.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mMaxPadding_MetaData[] = {
		{ "Category", "RoomData" },
		{ "ModuleRelativePath", "Public/MapRoom.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mTileSize_MetaData[] = {
		{ "Category", "RoomData" },
		{ "ModuleRelativePath", "Public/MapRoom.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mTileClass_MetaData[] = {
		{ "Category", "RoomData" },
		{ "ModuleRelativePath", "Public/MapRoom.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_mOrigin;
	static const UECodeGen_Private::FIntPropertyParams NewProp_mSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_mSizeY;
	static const UECodeGen_Private::FIntPropertyParams NewProp_mBSPSplitsRemaining;
	static const UECodeGen_Private::FIntPropertyParams NewProp_mMinPadding;
	static const UECodeGen_Private::FIntPropertyParams NewProp_mMaxPadding;
	static const UECodeGen_Private::FIntPropertyParams NewProp_mTileSize;
	static const UECodeGen_Private::FClassPropertyParams NewProp_mTileClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRoomData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mOrigin = { "mOrigin", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomData, mOrigin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mOrigin_MetaData), NewProp_mOrigin_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mSizeX = { "mSizeX", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomData, mSizeX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mSizeX_MetaData), NewProp_mSizeX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mSizeY = { "mSizeY", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomData, mSizeY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mSizeY_MetaData), NewProp_mSizeY_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mBSPSplitsRemaining = { "mBSPSplitsRemaining", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomData, mBSPSplitsRemaining), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mBSPSplitsRemaining_MetaData), NewProp_mBSPSplitsRemaining_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mMinPadding = { "mMinPadding", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomData, mMinPadding), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mMinPadding_MetaData), NewProp_mMinPadding_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mMaxPadding = { "mMaxPadding", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomData, mMaxPadding), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mMaxPadding_MetaData), NewProp_mMaxPadding_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mTileSize = { "mTileSize", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomData, mTileSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mTileSize_MetaData), NewProp_mTileSize_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mTileClass = { "mTileClass", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoomData, mTileClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mTileClass_MetaData), NewProp_mTileClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRoomData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mOrigin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mSizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mBSPSplitsRemaining,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mMinPadding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mMaxPadding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mTileSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoomData_Statics::NewProp_mTileClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoomData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRoomData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_TileMapGenerator,
	nullptr,
	&NewStructOps,
	"RoomData",
	Z_Construct_UScriptStruct_FRoomData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoomData_Statics::PropPointers),
	sizeof(FRoomData),
	alignof(FRoomData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoomData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FRoomData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FRoomData()
{
	if (!Z_Registration_Info_UScriptStruct_RoomData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RoomData.InnerSingleton, Z_Construct_UScriptStruct_FRoomData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_RoomData.InnerSingleton;
}
// End ScriptStruct FRoomData

// Begin Class AMapRoom
void AMapRoom::StaticRegisterNativesAMapRoom()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMapRoom);
UClass* Z_Construct_UClass_AMapRoom_NoRegister()
{
	return AMapRoom::StaticClass();
}
struct Z_Construct_UClass_AMapRoom_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MapRoom.h" },
		{ "ModuleRelativePath", "Public/MapRoom.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMapRoom>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AMapRoom_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_TileMapGenerator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMapRoom_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMapRoom_Statics::ClassParams = {
	&AMapRoom::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMapRoom_Statics::Class_MetaDataParams), Z_Construct_UClass_AMapRoom_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMapRoom()
{
	if (!Z_Registration_Info_UClass_AMapRoom.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMapRoom.OuterSingleton, Z_Construct_UClass_AMapRoom_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMapRoom.OuterSingleton;
}
template<> TILEMAPGENERATOR_API UClass* StaticClass<AMapRoom>()
{
	return AMapRoom::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMapRoom);
AMapRoom::~AMapRoom() {}
// End Class AMapRoom

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_MapRoom_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FRoomData::StaticStruct, Z_Construct_UScriptStruct_FRoomData_Statics::NewStructOps, TEXT("RoomData"), &Z_Registration_Info_UScriptStruct_RoomData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRoomData), 1580932858U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMapRoom, AMapRoom::StaticClass, TEXT("AMapRoom"), &Z_Registration_Info_UClass_AMapRoom, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMapRoom), 2491135190U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_MapRoom_h_2692553942(TEXT("/Script/TileMapGenerator"),
	Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_MapRoom_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_MapRoom_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_MapRoom_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_MapRoom_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
