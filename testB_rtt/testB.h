/*
 * File: testB.h
 *
 * Code generated for Simulink model 'testB'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Mon Mar 21 22:59:00 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_testB_h_
#define RTW_HEADER_testB_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef testB_COMMON_INCLUDES_
# define testB_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* testB_COMMON_INCLUDES_ */

#include "testB_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T counter;                     /* '<Root>/Sine Wave' */
} DW_testB_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_testB_T;

/* Parameters (auto storage) */
struct P_testB_T_ {
  real_T SliderGain_gain;              /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S1>/Slider Gain'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_NumSamp;             /* Expression: 50
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Offset;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_testB_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_testB_T testB_P;

/* Block states (auto storage) */
extern DW_testB_T testB_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_testB_T testB_Y;

/* Model entry point functions */
extern void testB_initialize(void);
extern void testB_output(void);
extern void testB_update(void);
extern void testB_terminate(void);

/* Real-time Model object */
extern RT_MODEL_testB_T *const testB_M;

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
 * '<Root>' : 'testB'
 * '<S1>'   : 'testB/Slider Gain'
 */
#endif                                 /* RTW_HEADER_testB_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
