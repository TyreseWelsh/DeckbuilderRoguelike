// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TileMapGenerator/Public/RoomGenerator.h"
#include "TileMapGenerator/Public/MapRoom.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRoomGenerator() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_AMapRoom_NoRegister();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_URoomGenerator();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_URoomGenerator_NoRegister();
TILEMAPGENERATOR_API UScriptStruct* Z_Construct_UScriptStruct_FRoomData();
UPackage* Z_Construct_UPackage__Script_TileMapGenerator();
// End Cross Module References

// Begin Class URoomGenerator Function SplitRoom
struct Z_Construct_UFunction_URoomGenerator_SplitRoom_Statics
{
	struct RoomGenerator_eventSplitRoom_Parms
	{
		FRoomData _RoomData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RoomGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp__RoomData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_URoomGenerator_SplitRoom_Statics::NewProp__RoomData = { "_RoomData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(RoomGenerator_eventSplitRoom_Parms, _RoomData), Z_Construct_UScriptStruct_FRoomData, METADATA_PARAMS(0, nullptr) }; // 1580932858
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URoomGenerator_SplitRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URoomGenerator_SplitRoom_Statics::NewProp__RoomData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_URoomGenerator_SplitRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URoomGenerator_SplitRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URoomGenerator, nullptr, "SplitRoom", nullptr, nullptr, Z_Construct_UFunction_URoomGenerator_SplitRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URoomGenerator_SplitRoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_URoomGenerator_SplitRoom_Statics::RoomGenerator_eventSplitRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_URoomGenerator_SplitRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_URoomGenerator_SplitRoom_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_URoomGenerator_SplitRoom_Statics::RoomGenerator_eventSplitRoom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_URoomGenerator_SplitRoom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URoomGenerator_SplitRoom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(URoomGenerator::execSplitRoom)
{
	P_GET_STRUCT_REF(FRoomData,Z_Param_Out__RoomData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SplitRoom(Z_Param_Out__RoomData);
	P_NATIVE_END;
}
// End Class URoomGenerator Function SplitRoom

// Begin Class URoomGenerator
void URoomGenerator::StaticRegisterNativesURoomGenerator()
{
	UClass* Class = URoomGenerator::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SplitRoom", &URoomGenerator::execSplitRoom },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URoomGenerator);
UClass* Z_Construct_UClass_URoomGenerator_NoRegister()
{
	return URoomGenerator::StaticClass();
}
struct Z_Construct_UClass_URoomGenerator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "RoomGenerator.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/RoomGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mRoomClass_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "RoomGenerator" },
		{ "ModuleRelativePath", "Public/RoomGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mMinRoomSize_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "RoomGenerator" },
		{ "ModuleRelativePath", "Public/RoomGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_mRoomClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_mMinRoomSize;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_URoomGenerator_SplitRoom, "SplitRoom" }, // 3107095162
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URoomGenerator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_URoomGenerator_Statics::NewProp_mRoomClass = { "mRoomClass", nullptr, (EPropertyFlags)0x0044000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URoomGenerator, mRoomClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AMapRoom_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mRoomClass_MetaData), NewProp_mRoomClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_URoomGenerator_Statics::NewProp_mMinRoomSize = { "mMinRoomSize", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URoomGenerator, mMinRoomSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mMinRoomSize_MetaData), NewProp_mMinRoomSize_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URoomGenerator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URoomGenerator_Statics::NewProp_mRoomClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URoomGenerator_Statics::NewProp_mMinRoomSize,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URoomGenerator_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_URoomGenerator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_TileMapGenerator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URoomGenerator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_URoomGenerator_Statics::ClassParams = {
	&URoomGenerator::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_URoomGenerator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_URoomGenerator_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URoomGenerator_Statics::Class_MetaDataParams), Z_Construct_UClass_URoomGenerator_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_URoomGenerator()
{
	if (!Z_Registration_Info_UClass_URoomGenerator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URoomGenerator.OuterSingleton, Z_Construct_UClass_URoomGenerator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_URoomGenerator.OuterSingleton;
}
template<> TILEMAPGENERATOR_API UClass* StaticClass<URoomGenerator>()
{
	return URoomGenerator::StaticClass();
}
URoomGenerator::URoomGenerator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(URoomGenerator);
URoomGenerator::~URoomGenerator() {}
// End Class URoomGenerator

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomGenerator_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_URoomGenerator, URoomGenerator::StaticClass, TEXT("URoomGenerator"), &Z_Registration_Info_UClass_URoomGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URoomGenerator), 1834097289U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomGenerator_h_3510013243(TEXT("/Script/TileMapGenerator"),
	Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomGenerator_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_RoomGenerator_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
