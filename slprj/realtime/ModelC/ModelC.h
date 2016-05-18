/*
 * File: ModelC.h
 *
 * Code generated for Simulink model 'ModelC'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Thu Mar 24 12:29:23 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ModelC_h_
#define RTW_HEADER_ModelC_h_
#ifndef ModelC_COMMON_INCLUDES_
# define ModelC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ModelC_COMMON_INCLUDES_ */

#include "ModelC_types.h"

/* Shared type includes */
#include "model_reference_types.h"

/* Parameters (auto storage) */
struct P_ModelC_T_ {
  real_T Constant_Value;               /* Expression: 5
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ModelC_T {
  const char_T **errorStatus;
};

typedef struct {
  RT_MODEL_ModelC_T rtm;
} MdlrefDW_ModelC_T;

/* Model reference registration function */
extern void ModelC_initialize(const char_T **rt_errorStatus, RT_MODEL_ModelC_T *
  const ModelC_M);
extern void ModelC_Start(real_T *rty_Out1);
extern void ModelC(real_T *rty_Out1);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ModelC'
 */
#endif                                 /* RTW_HEADER_ModelC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
