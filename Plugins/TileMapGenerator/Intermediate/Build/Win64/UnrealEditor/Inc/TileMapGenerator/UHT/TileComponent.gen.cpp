// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TileMapGenerator/Public/TileComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTileComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_UTileComponent();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_UTileComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_TileMapGenerator();
// End Cross Module References

// Begin Class UTileComponent
void UTileComponent::StaticRegisterNativesUTileComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTileComponent);
UClass* Z_Construct_UClass_UTileComponent_NoRegister()
{
	return UTileComponent::StaticClass();
}
struct Z_Construct_UClass_UTileComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "HideCategories", "Object LOD Lighting TextureStreaming Object LOD Lighting TextureStreaming Activation Components|Activation Trigger VirtualTexture" },
		{ "IncludePath", "TileComponent.h" },
		{ "ModuleRelativePath", "Public/TileComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mpParentTile_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/TileComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mpNeighbourTiles_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/TileComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_mpParentTile;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_mpNeighbourTiles_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_mpNeighbourTiles;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTileComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTileComponent_Statics::NewProp_mpParentTile = { "mpParentTile", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTileComponent, mpParentTile), Z_Construct_UClass_UTileComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mpParentTile_MetaData), NewProp_mpParentTile_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTileComponent_Statics::NewProp_mpNeighbourTiles_Inner = { "mpNeighbourTiles", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UTileComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UTileComponent_Statics::NewProp_mpNeighbourTiles = { "mpNeighbourTiles", nullptr, (EPropertyFlags)0x0010008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTileComponent, mpNeighbourTiles), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mpNeighbourTiles_MetaData), NewProp_mpNeighbourTiles_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTileComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTileComponent_Statics::NewProp_mpParentTile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTileComponent_Statics::NewProp_mpNeighbourTiles_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTileComponent_Statics::NewProp_mpNeighbourTiles,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTileComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UTileComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBoxComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_TileMapGenerator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTileComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTileComponent_Statics::ClassParams = {
	&UTileComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UTileComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UTileComponent_Statics::PropPointers),
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTileComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UTileComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UTileComponent()
{
	if (!Z_Registration_Info_UClass_UTileComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTileComponent.OuterSingleton, Z_Construct_UClass_UTileComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTileComponent.OuterSingleton;
}
template<> TILEMAPGENERATOR_API UClass* StaticClass<UTileComponent>()
{
	return UTileComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UTileComponent);
UTileComponent::~UTileComponent() {}
// End Class UTileComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTileComponent, UTileComponent::StaticClass, TEXT("UTileComponent"), &Z_Registration_Info_UClass_UTileComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTileComponent), 814604954U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileComponent_h_1462447991(TEXT("/Script/TileMapGenerator"),
	Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
