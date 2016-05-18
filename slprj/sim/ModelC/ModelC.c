#include "__cf_ModelC.h"
#include "ModelC_capi.h"
#include "ModelC.h"
#include "ModelC_private.h"
static RegMdlInfo rtMdlInfo_ModelC [ 21 ] = { { "nnopklwnrma" ,
MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * ) "ModelC" } , { "d3iqutlqzw"
, MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "ModelC" } , {
"i5xjb2lmqq" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"ModelC" } , { "jxshvjxpet" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , (
void * ) "ModelC" } , { "hei1yo4aga" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "ModelC" } , { "dbgowxf1l5" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "ModelC" } , {
"nell5u5qzg" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"ModelC" } , { "bavihnn4rf" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , (
void * ) "ModelC" } , { "jenqgeuadb" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "ModelC" } , { "bdk2dhvbge" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "ModelC" } , {
"kzjbqgpxvz" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"ModelC" } , { "dp4kwei2se" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , (
void * ) "ModelC" } , { "l1emhkdubj" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "ModelC" } , { "ikzbrgexdi" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "ModelC" } , {
"endt0300dt" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"ModelC" } , { "j4knslj2wd" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , (
void * ) "ModelC" } , { "ModelC" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 ,
( NULL ) } , { "ktcqk1cjj2" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , (
void * ) "ModelC" } , { "elpdh2nfxy" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "ModelC" } , { "ModelC.h" , MDL_INFO_MODEL_FILENAME , 0 , 0
, ( NULL ) } , { "ModelC.c" , MDL_INFO_MODEL_FILENAME , 0 , 0 , ( void * )
"ModelC" } } ; fi10jzisup ModelC_P = { 5.0 } ; void j4knslj2wd ( real_T *
eldtnkjqti ) { * eldtnkjqti = ModelC_P . P_0 ; } void ModelC ( real_T *
eldtnkjqti ) { * eldtnkjqti = ModelC_P . P_0 ; } void endt0300dt ( SimStruct
* _mdlRefSfcnS , int_T mdlref_TID0 , elpdh2nfxy * const fy1ti1doyr , void *
sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const
char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) {
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( void ) memset ( ( void * )
fy1ti1doyr , 0 , sizeof ( elpdh2nfxy ) ) ; fy1ti1doyr -> Timing .
mdlref_GlobalTID [ 0 ] = mdlref_TID0 ; fy1ti1doyr -> _mdlRefSfcnS = (
_mdlRefSfcnS ) ; ModelC_InitializeDataMapInfo ( fy1ti1doyr , sysRanPtr ,
contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) && ( rt_ChildPath != ( NULL
) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI , rt_ChildMMIIdx , & (
fy1ti1doyr -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath ( fy1ti1doyr ->
DataMapInfo . mmi , rt_ChildPath ) ; rtwCAPI_MMISetContStateStartIndex (
fy1ti1doyr -> DataMapInfo . mmi , rt_CSTATEIdx ) ; } } void
mr_ModelC_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName ,
int_T * retVal ) { * retVal = 0 ; * retVal = 0 ; ssRegModelRefMdlInfo (
mdlRefSfcnS , modelName , rtMdlInfo_ModelC , 21 ) ; * retVal = 1 ; }
