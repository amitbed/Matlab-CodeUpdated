#ifndef __c4_identextras_h__
#define __c4_identextras_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_s8I6VPw2Ssn0flwgyUaioQ
#define struct_s8I6VPw2Ssn0flwgyUaioQ

struct s8I6VPw2Ssn0flwgyUaioQ
{
  uint8_T estimationMethod;
  uint16_T na;
  uint16_T nb;
  uint16_T nk;
  uint16_T nInputs;
  uint16_T nParameters;
  uint16_T necessaryDataForPhi[4];
  uint16_T b0CoeffPos[2];
  uint16_T finalInputPos;
  uint16_T bPolyMaxLength;
};

#endif                                 /*struct_s8I6VPw2Ssn0flwgyUaioQ*/

#ifndef typedef_c4_s8I6VPw2Ssn0flwgyUaioQ
#define typedef_c4_s8I6VPw2Ssn0flwgyUaioQ

typedef struct s8I6VPw2Ssn0flwgyUaioQ c4_s8I6VPw2Ssn0flwgyUaioQ;

#endif                                 /*typedef_c4_s8I6VPw2Ssn0flwgyUaioQ*/

#ifndef typedef_SFc4_identextrasInstanceStruct
#define typedef_SFc4_identextrasInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_identextras;
  c4_s8I6VPw2Ssn0flwgyUaioQ c4_algorithmParams;
} SFc4_identextrasInstanceStruct;

#endif                                 /*typedef_SFc4_identextrasInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_identextras_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_identextras_get_check_sum(mxArray *plhs[]);
extern void c4_identextras_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
