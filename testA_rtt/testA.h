/*
 * File: testA.h
 *
 * Code generated for Simulink model 'testA'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Mon Mar 21 23:02:33 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_testA_h_
#define RTW_HEADER_testA_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef testA_COMMON_INCLUDES_
# define testA_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* testA_COMMON_INCLUDES_ */

#include "testA_types.h"

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
} DW_testA_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_testA_T;

/* Parameters (auto storage) */
struct P_testA_T_ {
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
struct tag_RTM_testA_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_testA_T testA_P;

/* Block states (auto storage) */
extern DW_testA_T testA_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_testA_T testA_Y;

/* Model entry point functions */
extern void testA_initialize(void);
extern void testA_output(void);
extern void testA_update(void);
extern void testA_terminate(void);

/* Real-time Model object */
extern RT_MODEL_testA_T *const testA_M;

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
 * '<Root>' : 'testA'
 * '<S1>'   : 'testA/Slider Gain'
 */
#endif                                 /* RTW_HEADER_testA_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
