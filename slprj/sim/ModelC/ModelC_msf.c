#include "__cf_ModelC.h"
#if !defined(S_FUNCTION_NAME)
#define S_FUNCTION_NAME ModelC_msf
#endif
#define S_FUNCTION_LEVEL 2
#if !defined(RTW_GENERATED_S_FUNCTION)
#define RTW_GENERATED_S_FUNCTION
#endif
#include <stdio.h>
#include <math.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define rt_logging_h
#include "ModelC_types.h"
#include "ModelC.h"
#include "ModelC_private.h"
MdlRefChildMdlRec childModels [ 1 ] = { "ModelC" , "ModelC" , 0 } ; const
char * rt_GetMatSignalLoggingFileName ( void ) { return NULL ; } const char *
rt_GetMatSigLogSelectorFileName ( void ) { return NULL ; } boolean_T
slIsRapidAcceleratorSimulating ( void ) { return false ; } void
rt_RAccelReplaceFromFilename ( const char * blockpath , char * fileName ) { (
void ) blockpath ; ( void ) fileName ; } void rt_RAccelReplaceToFilename (
const char * blockpath , char * fileName ) { ( void ) blockpath ; ( void )
fileName ; } static void mdlInitializeSizes ( SimStruct * S ) {
ssSetNumSFcnParams ( S , 0 ) ; ssFxpSetU32BitRegionCompliant ( S , 1 ) ;
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; if ( S -> mdlInfo -> genericFcn != (
NULL ) ) { _GenericFcn fcn = S -> mdlInfo -> genericFcn ; real_T lifeSpan =
1.0 ; real_T startTime = 0.0 ; real_T stopTime = 10.0 ; int_T hwSettings [ 15
] ; int_T opSettings [ 2 ] ; boolean_T concurrTaskSupport = 0 ; boolean_T
hasDiscTs = 1 ; real_T fixedStep = 0.2 ; ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_SOLVER_TYPE_EARLY , 2 , ( NULL ) ) ; ( fcn ) ( S ,
GEN_FCN_MODELREF_RATE_GROUPED , 0 , ( NULL ) ) ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_LIFE_SPAN , - 1 , & lifeSpan ) ) return ; if ( ! ( fcn )
( S , GEN_FCN_CHK_MODELREF_START_TIME , - 1 , & startTime ) ) return ; if ( !
( fcn ) ( S , GEN_FCN_CHK_MODELREF_STOP_TIME , - 1 , & stopTime ) ) return ;
hwSettings [ 0 ] = 8 ; hwSettings [ 1 ] = 16 ; hwSettings [ 2 ] = 32 ;
hwSettings [ 3 ] = 32 ; hwSettings [ 4 ] = 32 ; hwSettings [ 5 ] = 64 ;
hwSettings [ 6 ] = 32 ; hwSettings [ 7 ] = 2 ; hwSettings [ 8 ] = 1 ;
hwSettings [ 9 ] = 32 ; hwSettings [ 10 ] = 1 ; hwSettings [ 11 ] = 3 ;
hwSettings [ 12 ] = 1 ; hwSettings [ 13 ] = 64 ; hwSettings [ 14 ] = 0 ; if (
! ( fcn ) ( S , GEN_FCN_CHK_MODELREF_HARDWARE_SETTINGS , 15 , hwSettings ) )
return ; if ( ! ( fcn ) ( S , GEN_FCN_CHK_MODELREF_DATA_DICTIONARY , 0 , (
void * ) "" ) ) return ; slmrSetDataDictionarySet ( S , "" ) ; opSettings [ 0
] = 0 ; opSettings [ 1 ] = 0 ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_OPTIM_SETTINGS , 2 , opSettings ) ) return ; if ( ! (
fcn ) ( S , GEN_FCN_CHK_MODELREF_CONCURRETNT_TASK_SUPPORT , ( int_T )
concurrTaskSupport , ( NULL ) ) ) return ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_SOLVER_TYPE , 0 , & hasDiscTs ) ) return ; if ( ! ( fcn
) ( S , GEN_FCN_CHK_MODELREF_SOLVER_NAME , 0 , ( void * ) "FixedStepDiscrete"
) ) return ; if ( ! ( fcn ) ( S , GEN_FCN_CHK_MODELREF_SOLVER_MODE ,
SOLVER_MODE_SINGLETASKING , ( NULL ) ) ) return ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_FIXED_STEP , 0 , & fixedStep ) ) return ; ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_FRAME_UPGRADE_DIAGNOSTICS , 1 , ( NULL ) ) ; }
ssSetRTWGeneratedSFcn ( S , 2 ) ; ssSetNumContStates ( S , 0 ) ;
ssSetNumDiscStates ( S , 0 ) ; if ( ! ssSetNumInputPorts ( S , 0 ) ) return ;
if ( ! ssSetNumOutputPorts ( S , 1 ) ) return ; if ( !
ssSetOutputPortVectorDimension ( S , 0 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 0 , SS_DOUBLE )
; } ssSetOutputPortSampleTime ( S , 0 , - 1 ) ;
ssSetOutputPortDiscreteValuedOutput ( S , 0 , 0 ) ; ssSetOutputPortOkToMerge
( S , 0 , SS_OK_TO_MERGE_CONDITIONAL ) ; ssSetOutputPortICAttributes ( S , 0
, true , false , false ) ;
ssSetModelRefOutputBlkIOUpdatedInAnotherExecContext ( S , 0 , false ) ;
slmrModelRefSetOutputPortDrivenByNonCondExecStateflow ( S , 0 , false ) ;
ssSetOutputPortOptimOpts ( S , 0 , SS_NOT_REUSABLE_AND_GLOBAL ) ;
slmrModelRefSetHasDescExpFcnMdl ( S , false ) ; { real_T minValue =
rtMinusInf ; real_T maxValue = rtInf ; ssSetModelRefOutputSignalDesignMin ( S
, 0 , & minValue ) ; ssSetModelRefOutputSignalDesignMax ( S , 0 , & maxValue
) ; } { static ssRTWStorageType storageClass [ 1 ] = { SS_RTW_STORAGE_AUTO }
; ssSetModelRefPortRTWStorageClasses ( S , storageClass ) ; }
ssSetModelRefSignalLoggingSaveFormat ( S , SS_DATASET_FORMAT ) ;
ssSetNumSampleTimes ( S , PORT_BASED_SAMPLE_TIMES ) ; ssSetNumRWork ( S , 0 )
; ssSetNumIWork ( S , 0 ) ; ssSetNumPWork ( S , 0 ) ; ssSetNumModes ( S , 0 )
; { int_T zcsIdx = 0 ; } ssSetOutputPortIsNonContinuous ( S , 0 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 0 , 0 ) ;
ssSetModelReferenceSampleTimeInheritanceRule ( S ,
USE_DEFAULT_FOR_DISCRETE_INHERITANCE ) ; ssSetOptimizeModelRefInitCode ( S ,
1 ) ; ssSetModelReferenceConsistentOutportInitialization ( S , true ) ;
ssSetAcceptsFcnCallInputs ( S ) ; ssSetModelReferenceNormalModeSupport ( S ,
MDL_START_AND_MDL_PROCESS_PARAMS_OK ) ; ssSupportsMultipleExecInstances ( S ,
true ) ; ssHasStateInsideForEachSS ( S , false ) ;
ssSetModelRefHasParforForEachSS ( S , false ) ;
ssSetModelRefHasVariantModelOrSubsystem ( S , false ) ; ssSetNumAsyncTs ( S ,
0 ) ; ssSetOptions ( S , SS_OPTION_ALLOW_PORT_SAMPLE_TIME_IN_TRIGSS |
SS_OPTION_SUPPORTS_ALIAS_DATA_TYPES | SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME
| SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_WORKS_WITH_CODE_REUSE ) ; if ( S
-> mdlInfo -> genericFcn != ( NULL ) ) { ssRegModelRefChildModel ( S , 1 ,
childModels ) ; }
#if SS_SFCN_FOR_SIM
if ( S -> mdlInfo -> genericFcn != ( NULL ) && ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { int_T retVal = 1 ; mr_ModelC_MdlInfoRegFcn ( S
, "ModelC" , & retVal ) ; if ( ! retVal ) return ; }
#endif
if ( ! ssSetNumDWork ( S , 1 ) ) { return ; }
#if SS_SFCN_FOR_SIM
{ int mdlrefDWTypeId ; ssRegMdlRefDWorkType ( S , & mdlrefDWTypeId ) ; if (
mdlrefDWTypeId == INVALID_DTYPE_ID ) return ; if ( ! ssSetDataTypeSize ( S ,
mdlrefDWTypeId , sizeof ( nnopklwnrma ) ) ) return ; ssSetDWorkDataType ( S ,
0 , mdlrefDWTypeId ) ; ssSetDWorkWidth ( S , 0 , 1 ) ; }
#endif
slmrSetDataTypeOverrideSettings ( S , 0 , 0 ) ;
slmrSetHasNonVirtualConstantTs ( S , true ) ; ssSetSimulinkVersionGeneratedIn
( S , "8.3" ) ; ssSetModelRefHasEnablePort ( S , 0 ) ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { return ; }
#define MDL_SET_WORK_WIDTHS
static void mdlSetWorkWidths ( SimStruct * S ) { if ( S -> mdlInfo ->
genericFcn != ( NULL ) ) { _GenericFcn fcn = S -> mdlInfo -> genericFcn ;
ssSetSignalSizesComputeType ( S , SS_VARIABLE_SIZE_FROM_INPUT_VALUE_AND_SIZE
) ; } { static const char * toFileNames [ ] = { "" } ; static const char *
fromFileNames [ ] = { "" } ; if ( ! ssSetModelRefFromFiles ( S , 0 ,
fromFileNames ) ) return ; if ( ! ssSetModelRefToFiles ( S , 0 , toFileNames
) ) return ; } }
#define MDL_START
static void mdlStart ( SimStruct * S ) { nnopklwnrma * dw = ( nnopklwnrma * )
ssGetDWork ( S , 0 ) ; real_T * o_o_B_1_1 = ( real_T * )
ssGetOutputPortSignal ( S , 0 ) ; void * sysRanPtr = ( NULL ) ; int sysTid =
0 ; ssGetContextSysRanBCPtr ( S , & sysRanPtr ) ; ssGetContextSysTid ( S , &
sysTid ) ; if ( sysTid == CONSTANT_TID ) { sysTid = 0 ; } endt0300dt ( S ,
ssGetSampleTimeTaskID ( S , 0 ) , & ( dw -> rtm ) , sysRanPtr , sysTid , (
NULL ) , ( NULL ) , 0 , - 1 ) ; ssSetModelMappingInfoPtr ( S , & ( dw -> rtm
. DataMapInfo . mmi ) ) ; if ( S -> mdlInfo -> genericFcn != ( NULL ) ) {
_GenericFcn fcn = S -> mdlInfo -> genericFcn ; } j4knslj2wd ( o_o_B_1_1 ) ; }
static void mdlOutputs ( SimStruct * S , int_T tid ) { nnopklwnrma * dw = (
nnopklwnrma * ) ssGetDWork ( S , 0 ) ; real_T * o_o_B_1_1 = ( real_T * )
ssGetOutputPortSignal ( S , 0 ) ; if ( tid != CONSTANT_TID ) { ModelC (
o_o_B_1_1 ) ; } } static void mdlTerminate ( SimStruct * S ) { return ; }
#ifdef MATLAB_MEX_FILE 
#include "simulink.c"
#include "fixedpoint.c"
#else
#error Assertion failed: file must be compiled as a MEX-file
#endif
