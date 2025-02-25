// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TileMapGenerator/Public/TileMapFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTileMapFunctionLibrary() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_UTileMapFunctionLibrary();
TILEMAPGENERATOR_API UClass* Z_Construct_UClass_UTileMapFunctionLibrary_NoRegister();
UPackage* Z_Construct_UPackage__Script_TileMapGenerator();
// End Cross Module References

// Begin Class UTileMapFunctionLibrary Function GetBelowTile
struct Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics
{
	struct TileMapFunctionLibrary_eventGetBelowTile_Parms
	{
		AActor* StartingActor;
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/TileMapFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StartingActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics::NewProp_StartingActor = { "StartingActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TileMapFunctionLibrary_eventGetBelowTile_Parms, StartingActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TileMapFunctionLibrary_eventGetBelowTile_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics::NewProp_StartingActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTileMapFunctionLibrary, nullptr, "GetBelowTile", nullptr, nullptr, Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics::TileMapFunctionLibrary_eventGetBelowTile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics::TileMapFunctionLibrary_eventGetBelowTile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTileMapFunctionLibrary::execGetBelowTile)
{
	P_GET_OBJECT(AActor,Z_Param_StartingActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=UTileMapFunctionLibrary::GetBelowTile(Z_Param_StartingActor);
	P_NATIVE_END;
}
// End Class UTileMapFunctionLibrary Function GetBelowTile

// Begin Class UTileMapFunctionLibrary Function OccupyTile
struct Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics
{
	struct TileMapFunctionLibrary_eventOccupyTile_Parms
	{
		AActor* OccupyingActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/TileMapFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OccupyingActor;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::NewProp_OccupyingActor = { "OccupyingActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TileMapFunctionLibrary_eventOccupyTile_Parms, OccupyingActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((TileMapFunctionLibrary_eventOccupyTile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(TileMapFunctionLibrary_eventOccupyTile_Parms), &Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::NewProp_OccupyingActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTileMapFunctionLibrary, nullptr, "OccupyTile", nullptr, nullptr, Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::TileMapFunctionLibrary_eventOccupyTile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::TileMapFunctionLibrary_eventOccupyTile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTileMapFunctionLibrary::execOccupyTile)
{
	P_GET_OBJECT(AActor,Z_Param_OccupyingActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UTileMapFunctionLibrary::OccupyTile(Z_Param_OccupyingActor);
	P_NATIVE_END;
}
// End Class UTileMapFunctionLibrary Function OccupyTile

// Begin Class UTileMapFunctionLibrary Function UnOccupyTile
struct Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics
{
	struct TileMapFunctionLibrary_eventUnOccupyTile_Parms
	{
		AActor* UnOccupyingActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/TileMapFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UnOccupyingActor;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::NewProp_UnOccupyingActor = { "UnOccupyingActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TileMapFunctionLibrary_eventUnOccupyTile_Parms, UnOccupyingActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((TileMapFunctionLibrary_eventUnOccupyTile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(TileMapFunctionLibrary_eventUnOccupyTile_Parms), &Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::NewProp_UnOccupyingActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTileMapFunctionLibrary, nullptr, "UnOccupyTile", nullptr, nullptr, Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::TileMapFunctionLibrary_eventUnOccupyTile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::TileMapFunctionLibrary_eventUnOccupyTile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTileMapFunctionLibrary::execUnOccupyTile)
{
	P_GET_OBJECT(AActor,Z_Param_UnOccupyingActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UTileMapFunctionLibrary::UnOccupyTile(Z_Param_UnOccupyingActor);
	P_NATIVE_END;
}
// End Class UTileMapFunctionLibrary Function UnOccupyTile

// Begin Class UTileMapFunctionLibrary
void UTileMapFunctionLibrary::StaticRegisterNativesUTileMapFunctionLibrary()
{
	UClass* Class = UTileMapFunctionLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetBelowTile", &UTileMapFunctionLibrary::execGetBelowTile },
		{ "OccupyTile", &UTileMapFunctionLibrary::execOccupyTile },
		{ "UnOccupyTile", &UTileMapFunctionLibrary::execUnOccupyTile },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTileMapFunctionLibrary);
UClass* Z_Construct_UClass_UTileMapFunctionLibrary_NoRegister()
{
	return UTileMapFunctionLibrary::StaticClass();
}
struct Z_Construct_UClass_UTileMapFunctionLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "TileMapFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/TileMapFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UTileMapFunctionLibrary_GetBelowTile, "GetBelowTile" }, // 2925782796
		{ &Z_Construct_UFunction_UTileMapFunctionLibrary_OccupyTile, "OccupyTile" }, // 1061384326
		{ &Z_Construct_UFunction_UTileMapFunctionLibrary_UnOccupyTile, "UnOccupyTile" }, // 280453998
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTileMapFunctionLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UTileMapFunctionLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_TileMapGenerator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTileMapFunctionLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTileMapFunctionLibrary_Statics::ClassParams = {
	&UTileMapFunctionLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTileMapFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UTileMapFunctionLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UTileMapFunctionLibrary()
{
	if (!Z_Registration_Info_UClass_UTileMapFunctionLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTileMapFunctionLibrary.OuterSingleton, Z_Construct_UClass_UTileMapFunctionLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTileMapFunctionLibrary.OuterSingleton;
}
template<> TILEMAPGENERATOR_API UClass* StaticClass<UTileMapFunctionLibrary>()
{
	return UTileMapFunctionLibrary::StaticClass();
}
UTileMapFunctionLibrary::UTileMapFunctionLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UTileMapFunctionLibrary);
UTileMapFunctionLibrary::~UTileMapFunctionLibrary() {}
// End Class UTileMapFunctionLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileMapFunctionLibrary_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTileMapFunctionLibrary, UTileMapFunctionLibrary::StaticClass, TEXT("UTileMapFunctionLibrary"), &Z_Registration_Info_UClass_UTileMapFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTileMapFunctionLibrary), 3102630446U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileMapFunctionLibrary_h_3754780330(TEXT("/Script/TileMapGenerator"),
	Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileMapFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_tyres_Documents_Unreal_Projects_MageTower_Plugins_TileMapGenerator_Source_TileMapGenerator_Public_TileMapFunctionLibrary_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
