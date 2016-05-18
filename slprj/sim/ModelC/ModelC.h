#include "__cf_ModelC.h"
#ifndef RTW_HEADER_ModelC_h_
#define RTW_HEADER_ModelC_h_
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef ModelC_COMMON_INCLUDES_
#define ModelC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "ModelC_types.h"
#include "multiword_types.h"
#include "model_reference_types.h"
#include "rt_nonfinite.h"
struct fi10jzisup_ { real_T P_0 ; } ; struct ktcqk1cjj2 { struct
SimStruct_tag * _mdlRefSfcnS ; struct { rtwCAPI_ModelMappingInfo mmi ;
rtwCAPI_ModelMapLoggingInstanceInfo mmiLogInstanceInfo ; sysRanDType *
systemRan [ 2 ] ; int_T systemTid [ 2 ] ; } DataMapInfo ; struct { int_T
mdlref_GlobalTID [ 1 ] ; } Timing ; } ; typedef struct { elpdh2nfxy rtm ; }
nnopklwnrma ; extern void endt0300dt ( SimStruct * _mdlRefSfcnS , int_T
mdlref_TID0 , elpdh2nfxy * const fy1ti1doyr , void * sysRanPtr , int
contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_ModelC_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName ,
int_T * retVal ) ; extern const rtwCAPI_ModelMappingStaticInfo *
ModelC_GetCAPIStaticMap ( void ) ; extern void j4knslj2wd ( real_T *
eldtnkjqti ) ; extern void ModelC ( real_T * eldtnkjqti ) ;
#endif
