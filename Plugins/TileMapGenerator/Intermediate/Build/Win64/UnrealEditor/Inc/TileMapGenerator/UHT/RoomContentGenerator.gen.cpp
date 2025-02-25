// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TileMapGenerator/Public/RoomContentGenerator.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRoomContentGenerator() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_URoomContentGenerator();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_URoomContentGenerator_NoRegister();
UPackage* Z_Construct_UPackage__Script_TileMapGenerator();
// End Cross Module References

// Begin Class URoomContentGenerator
void URoomContentGenerator::StaticRegisterNativesURoomContentGenerator()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URoomContentGenerator);
UClass* Z_Construct_UClass_URoomContentGenerator_NoRegister()
{
	return URoomContentGenerator::StaticClass();
}
struct Z_Construct_UClass_URoomContentGenerator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "RoomContentGenerator.h" },
		{ "ModuleRelativePath", "Public/RoomContentGenerator.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URoomContentGenerator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_URoomContentGenerator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_TileMapGenerator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URoomContentGenerator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_URoomContentGenerator_Statics::ClassParams = {
	&URoomContentGenerator::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URoomContentGenerator_Statics::Class_MetaDataParams), Z_Construct_UClass_URoomContentGenerator_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_URoomContentGenerator()
{
	if (!Z_Registration_Info_UClass_URoomContentGenerator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URoomContentGenerator.OuterSingleton, Z_Construct_UClass_URoomContentGenerator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_URoomContentGenerator.OuterSingleton;
}
template<> TILEMAPGENERATOR_API UClass* StaticClass<URoomContentGenerator>()
{
	return URoomContentGenerator::StaticClass();
}
URoomContentGenerator::URoomContentGenerator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(URoomContentGenerator);
URoomContentGenerator::~URoomContentGenerator() {}
// End Class URoomContentGenerator

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomContentGenerator_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_URoomContentGenerator, URoomContentGenerator::StaticClass, TEXT("URoomContentGenerator"), &Z_Registration_Info_UClass_URoomContentGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URoomContentGenerator), 1917147633U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomContentGenerator_h_86603926(TEXT("/Script/TileMapGenerator"),
	Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomContentGenerator_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomContentGenerator_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
