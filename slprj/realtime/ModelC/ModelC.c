/*
 * File: ModelC.c
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

#include "ModelC.h"
#include "ModelC_private.h"

P_ModelC_T ModelC_P = {
  5.0                                  /* Expression: 5
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Start for referenced model: 'ModelC' */
void ModelC_Start(real_T *rty_Out1)
{
  /* Start for Constant: '<Root>/Constant' */
  *rty_Out1 = ModelC_P.Constant_Value;
}

/* Output and update for referenced model: 'ModelC' */
void ModelC(real_T *rty_Out1)
{
  /* Constant: '<Root>/Constant' */
  *rty_Out1 = ModelC_P.Constant_Value;
}

/* Model initialize function */
void ModelC_initialize(const char_T **rt_errorStatus, RT_MODEL_ModelC_T *const
  ModelC_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(ModelC_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
