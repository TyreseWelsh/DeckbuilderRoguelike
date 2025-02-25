// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TileMapGenerator/Public/MapData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMapData() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_UMapData();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_UMapData_NoRegister();
UPackage* Z_Construct_UPackage__Script_TileMapGenerator();
// End Cross Module References

// Begin Class UMapData
void UMapData::StaticRegisterNativesUMapData()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMapData);
UClass* Z_Construct_UClass_UMapData_NoRegister()
{
	return UMapData::StaticClass();
}
struct Z_Construct_UClass_UMapData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MapData.h" },
		{ "ModuleRelativePath", "Public/MapData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mapSizeX_MetaData[] = {
		{ "Category", "MapData" },
		{ "ModuleRelativePath", "Public/MapData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mapSizeY_MetaData[] = {
		{ "Category", "MapData" },
		{ "ModuleRelativePath", "Public/MapData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_tileSize_MetaData[] = {
		{ "Category", "MapData" },
		{ "ModuleRelativePath", "Public/MapData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_numBSPSplits_MetaData[] = {
		{ "Category", "MapData" },
		{ "ModuleRelativePath", "Public/MapData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_mapSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_mapSizeY;
	static const UECodeGen_Private::FIntPropertyParams NewProp_tileSize;
	static const UECodeGen_Private::FIntPropertyParams NewProp_numBSPSplits;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMapData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMapData_Statics::NewProp_mapSizeX = { "mapSizeX", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMapData, mapSizeX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mapSizeX_MetaData), NewProp_mapSizeX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMapData_Statics::NewProp_mapSizeY = { "mapSizeY", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMapData, mapSizeY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mapSizeY_MetaData), NewProp_mapSizeY_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMapData_Statics::NewProp_tileSize = { "tileSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMapData, tileSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_tileSize_MetaData), NewProp_tileSize_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMapData_Statics::NewProp_numBSPSplits = { "numBSPSplits", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMapData, numBSPSplits), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_numBSPSplits_MetaData), NewProp_numBSPSplits_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMapData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMapData_Statics::NewProp_mapSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMapData_Statics::NewProp_mapSizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMapData_Statics::NewProp_tileSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMapData_Statics::NewProp_numBSPSplits,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMapData_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMapData_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_TileMapGenerator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMapData_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMapData_Statics::ClassParams = {
	&UMapData::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UMapData_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UMapData_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMapData_Statics::Class_MetaDataParams), Z_Construct_UClass_UMapData_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMapData()
{
	if (!Z_Registration_Info_UClass_UMapData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMapData.OuterSingleton, Z_Construct_UClass_UMapData_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMapData.OuterSingleton;
}
template<> TILEMAPGENERATOR_API UClass* StaticClass<UMapData>()
{
	return UMapData::StaticClass();
}
UMapData::UMapData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMapData);
UMapData::~UMapData() {}
// End Class UMapData

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_MapData_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMapData, UMapData::StaticClass, TEXT("UMapData"), &Z_Registration_Info_UClass_UMapData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMapData), 2669322526U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_MapData_h_3857381437(TEXT("/Script/TileMapGenerator"),
	Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_MapData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_MapData_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
