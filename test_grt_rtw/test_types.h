/*
 * test_types.h
 *
 * Code generation for model "test".
 *
 * Model version              : 1.12
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Sun Apr 17 22:43:35 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_test_types_h_
#define RTW_HEADER_test_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "struct_zol899rmfMGVM5eoOIvhgC.h"

/* Custom Type definition for MATLAB Function: '<S19>/rarmax - MATLAB Function' */
#ifndef struct_s3WCz1xwnvWYEAbbf5Yc3C
#define struct_s3WCz1xwnvWYEAbbf5Yc3C

struct s3WCz1xwnvWYEAbbf5Yc3C
{
  uint8_T estimationMethod;
  uint16_T na;
  uint16_T nb;
  uint16_T nc;
  uint16_T nk;
  uint16_T nInputs;
  uint16_T nParameters;
  uint16_T necessaryDataForPhi[4];
  uint16_T necessaryDataForPsi[4];
  uint16_T b0PosInTheta;
  uint16_T b0PosInPsi;
  uint16_T c1PosInTheta;
  uint16_T cncPosInTheta;
  uint16_T c1PosInPhi;
  uint16_T c1PosInPsi;
};

#endif                                 /*struct_s3WCz1xwnvWYEAbbf5Yc3C*/

#ifndef typedef_s3WCz1xwnvWYEAbbf5Yc3C_test_T
#define typedef_s3WCz1xwnvWYEAbbf5Yc3C_test_T

typedef struct s3WCz1xwnvWYEAbbf5Yc3C s3WCz1xwnvWYEAbbf5Yc3C_test_T;

#endif                                 /*typedef_s3WCz1xwnvWYEAbbf5Yc3C_test_T*/

/* Parameters (auto storage) */
typedef struct P_test_T_ P_test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_test_T RT_MODEL_test_T;

#endif                                 /* RTW_HEADER_test_types_h_ */
