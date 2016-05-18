/*
 * File: testB.c
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

#include "testB.h"
#include "testB_private.h"

/* Block states (auto storage) */
DW_testB_T testB_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_testB_T testB_Y;

/* Real-time model */
RT_MODEL_testB_T testB_M_;
RT_MODEL_testB_T *const testB_M = &testB_M_;

/* Model output function */
void testB_output(void)
{
  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<S1>/Slider Gain'
   *  Sin: '<Root>/Sine Wave'
   */
  testB_Y.Out1 = (sin(((real_T)testB_DW.counter + testB_P.SineWave_Offset) * 2.0
                      * 3.1415926535897931 / testB_P.SineWave_NumSamp) *
                  testB_P.SineWave_Amp + testB_P.SineWave_Bias) *
    testB_P.SliderGain_gain;
}

/* Model update function */
void testB_update(void)
{
  /* Update for Sin: '<Root>/Sine Wave' */
  testB_DW.counter++;
  if (testB_DW.counter == testB_P.SineWave_NumSamp) {
    testB_DW.counter = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */
}

/* Model initialize function */
void testB_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(testB_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&testB_DW, 0,
                sizeof(DW_testB_T));

  /* external outputs */
  testB_Y.Out1 = 0.0;
}

/* Model terminate function */
void testB_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
