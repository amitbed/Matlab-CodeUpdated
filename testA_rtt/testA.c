/*
 * File: testA.c
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

#include "testA.h"
#include "testA_private.h"

/* Block states (auto storage) */
DW_testA_T testA_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_testA_T testA_Y;

/* Real-time model */
RT_MODEL_testA_T testA_M_;
RT_MODEL_testA_T *const testA_M = &testA_M_;

/* Model output function */
void testA_output(void)
{
  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<S1>/Slider Gain'
   *  Sin: '<Root>/Sine Wave'
   */
  testA_Y.Out1 = (sin(((real_T)testA_DW.counter + testA_P.SineWave_Offset) * 2.0
                      * 3.1415926535897931 / testA_P.SineWave_NumSamp) *
                  testA_P.SineWave_Amp + testA_P.SineWave_Bias) *
    testA_P.SliderGain_gain;
}

/* Model update function */
void testA_update(void)
{
  /* Update for Sin: '<Root>/Sine Wave' */
  testA_DW.counter++;
  if (testA_DW.counter == testA_P.SineWave_NumSamp) {
    testA_DW.counter = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */
}

/* Model initialize function */
void testA_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(testA_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&testA_DW, 0,
                sizeof(DW_testA_T));

  /* external outputs */
  testA_Y.Out1 = 0.0;
}

/* Model terminate function */
void testA_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
