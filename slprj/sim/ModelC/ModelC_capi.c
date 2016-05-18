#include "__cf_ModelC.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "ModelC_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "ModelC.h"
#include "ModelC_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_States rtBlockStates [ ] = { { 0 , - 1
, ( NULL ) , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 } } ; static
TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "" , "" , 0 , 0 , 0
, 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 0 , 0 } } ; static uint_T rtDimensionArray [ ] = { 0 } ;
static rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( NULL ) , ( NULL ) , 0 , 0 } } ; static int_T
rtContextSystems [ 2 ] ; static rtwCAPI_LoggingMetaInfo loggingMetaInfo [ ] =
{ { 0 , 0 , "" , 0 } } ; static rtwCAPI_ModelMapLoggingStaticInfo
mmiStaticInfoLogging = { 2 , rtContextSystems , loggingMetaInfo , 0 , NULL ,
{ 0 , NULL , NULL } , 0 , ( NULL ) } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 0 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL
) , 0 , ( NULL ) , 0 } , { rtBlockStates , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 2016697558U , 151889855U , 3420451790U ,
2351290145U } , & mmiStaticInfoLogging , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * ModelC_GetCAPIStaticMap ( ) { return &
mmiStatic ; } static void ModelC_InitializeSystemRan ( elpdh2nfxy * const
fy1ti1doyr , sysRanDType * systemRan [ ] , int_T systemTid [ ] , void *
rootSysRanPtr , int rootTid ) { systemRan [ 0 ] = ( sysRanDType * )
rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemTid [ 1 ] = rootTid ;
systemTid [ 0 ] = rootTid ; rtContextSystems [ 0 ] = 0 ; rtContextSystems [ 1
] = 0 ; }
#ifndef HOST_CAPI_BUILD
void ModelC_InitializeDataMapInfo ( elpdh2nfxy * const fy1ti1doyr , void *
sysRanPtr , int contextTid ) { rtwCAPI_SetVersion ( fy1ti1doyr -> DataMapInfo
. mmi , 1 ) ; rtwCAPI_SetStaticMap ( fy1ti1doyr -> DataMapInfo . mmi , &
mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( fy1ti1doyr -> DataMapInfo . mmi ,
& mmiStaticInfoLogging ) ; rtwCAPI_SetPath ( fy1ti1doyr -> DataMapInfo . mmi
, ( NULL ) ) ; rtwCAPI_SetFullPath ( fy1ti1doyr -> DataMapInfo . mmi , ( NULL
) ) ; rtwCAPI_SetInstanceLoggingInfo ( fy1ti1doyr -> DataMapInfo . mmi , &
fy1ti1doyr -> DataMapInfo . mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray (
fy1ti1doyr -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen (
fy1ti1doyr -> DataMapInfo . mmi , 0 ) ; ModelC_InitializeSystemRan (
fy1ti1doyr , fy1ti1doyr -> DataMapInfo . systemRan , fy1ti1doyr ->
DataMapInfo . systemTid , sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan (
fy1ti1doyr -> DataMapInfo . mmi , fy1ti1doyr -> DataMapInfo . systemRan ) ;
rtwCAPI_SetSystemTid ( fy1ti1doyr -> DataMapInfo . mmi , fy1ti1doyr ->
DataMapInfo . systemTid ) ; rtwCAPI_SetGlobalTIDMap ( fy1ti1doyr ->
DataMapInfo . mmi , & fy1ti1doyr -> Timing . mdlref_GlobalTID [ 0 ] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void ModelC_host_InitializeDataMapInfo ( ModelC_host_DataMapInfo_T * dataMap
, const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
