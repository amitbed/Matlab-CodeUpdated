#ifndef __c5_identextras_h__
#define __c5_identextras_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_szWfN9fHfXTSMrK3Q1hTVMH
#define struct_szWfN9fHfXTSMrK3Q1hTVMH

struct szWfN9fHfXTSMrK3Q1hTVMH
{
  uint8_T estimationMethod;
  uint16_T na;
  uint16_T nb;
  uint16_T nc;
  uint16_T nk;
  uint16_T nInputs;
  uint16_T nParameters;
  uint16_T necessaryDataForPhi[5];
  uint16_T necessaryDataForPsi[5];
  uint16_T b0PosInTheta;
  uint16_T b0PosInPsi;
  uint16_T c1PosInTheta;
  uint16_T cncPosInTheta;
  uint16_T c1PosInPhi;
  uint16_T c1PosInPsi;
};

#endif                                 /*struct_szWfN9fHfXTSMrK3Q1hTVMH*/

#ifndef typedef_c5_szWfN9fHfXTSMrK3Q1hTVMH
#define typedef_c5_szWfN9fHfXTSMrK3Q1hTVMH

typedef struct szWfN9fHfXTSMrK3Q1hTVMH c5_szWfN9fHfXTSMrK3Q1hTVMH;

#endif                                 /*typedef_c5_szWfN9fHfXTSMrK3Q1hTVMH*/

#ifndef typedef_SFc5_identextrasInstanceStruct
#define typedef_SFc5_identextrasInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_isStable;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_identextras;
  c5_szWfN9fHfXTSMrK3Q1hTVMH c5_algorithmParams;
} SFc5_identextrasInstanceStruct;

#endif                                 /*typedef_SFc5_identextrasInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_identextras_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_identextras_get_check_sum(mxArray *plhs[]);
extern void c5_identextras_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
