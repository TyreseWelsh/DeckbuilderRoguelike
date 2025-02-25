// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TileMapGenerator/Public/MapGeneratorComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMapGeneratorComponent() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_UMapData_NoRegister();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_UMapGeneratorComponent();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_UMapGeneratorComponent_NoRegister();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_URoomGenerator_NoRegister();
UPackage* Z_Construct_UPackage__Script_TileMapGenerator();
// End Cross Module References

// Begin Class UMapGeneratorComponent
void UMapGeneratorComponent::StaticRegisterNativesUMapGeneratorComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMapGeneratorComponent);
UClass* Z_Construct_UClass_UMapGeneratorComponent_NoRegister()
{
	return UMapGeneratorComponent::StaticClass();
}
struct Z_Construct_UClass_UMapGeneratorComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MapGeneratorComponent.h" },
		{ "ModuleRelativePath", "Public/MapGeneratorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mpMapData_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/MapGeneratorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mTileClass_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/MapGeneratorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mRoomGeneratorClass_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/MapGeneratorComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_mpMapData;
	static const UECodeGen_Private::FClassPropertyParams NewProp_mTileClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_mRoomGeneratorClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMapGeneratorComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMapGeneratorComponent_Statics::NewProp_mpMapData = { "mpMapData", nullptr, (EPropertyFlags)0x0144000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMapGeneratorComponent, mpMapData), Z_Construct_UClass_UMapData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mpMapData_MetaData), NewProp_mpMapData_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UMapGeneratorComponent_Statics::NewProp_mTileClass = { "mTileClass", nullptr, (EPropertyFlags)0x0044000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMapGeneratorComponent, mTileClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mTileClass_MetaData), NewProp_mTileClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UMapGeneratorComponent_Statics::NewProp_mRoomGeneratorClass = { "mRoomGeneratorClass", nullptr, (EPropertyFlags)0x0044000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMapGeneratorComponent, mRoomGeneratorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_URoomGenerator_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mRoomGeneratorClass_MetaData), NewProp_mRoomGeneratorClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMapGeneratorComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMapGeneratorComponent_Statics::NewProp_mpMapData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMapGeneratorComponent_Statics::NewProp_mTileClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMapGeneratorComponent_Statics::NewProp_mRoomGeneratorClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMapGeneratorComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMapGeneratorComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_TileMapGenerator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMapGeneratorComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMapGeneratorComponent_Statics::ClassParams = {
	&UMapGeneratorComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UMapGeneratorComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UMapGeneratorComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMapGeneratorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UMapGeneratorComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMapGeneratorComponent()
{
	if (!Z_Registration_Info_UClass_UMapGeneratorComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMapGeneratorComponent.OuterSingleton, Z_Construct_UClass_UMapGeneratorComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMapGeneratorComponent.OuterSingleton;
}
template<> TILEMAPGENERATOR_API UClass* StaticClass<UMapGeneratorComponent>()
{
	return UMapGeneratorComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMapGeneratorComponent);
UMapGeneratorComponent::~UMapGeneratorComponent() {}
// End Class UMapGeneratorComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_MapGeneratorComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMapGeneratorComponent, UMapGeneratorComponent::StaticClass, TEXT("UMapGeneratorComponent"), &Z_Registration_Info_UClass_UMapGeneratorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMapGeneratorComponent), 2724334780U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_MapGeneratorComponent_h_1481047223(TEXT("/Script/TileMapGenerator"),
	Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_MapGeneratorComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_MapGeneratorComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
