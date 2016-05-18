/*
 * test.c
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
#include "test.h"
#include "test_private.h"

/* Block states (auto storage) */
DW_test_T test_DW;

/* Real-time model */
RT_MODEL_test_T test_M_;
RT_MODEL_test_T *const test_M = &test_M_;
real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model step function */
void test_step(void)
{
  /* local block i/o variables */
  real_T rtb_Output;
  real_T rtb_DiscreteStateSpace;
  real_T c;
  real_T epsilon;
  boolean_T isStable;
  int32_T i;
  real_T rtb_thetaNew_idx_3;
  real_T rtb_psiMemoryNew_idx_2;
  real_T rtb_psiMemoryNew_idx_3;
  real_T rtb_phiMemoryNew_idx_1;
  real_T rtb_psiMemoryNew_idx_1;
  real_T rtb_thetaNew_idx_0;
  real_T rtb_thetaNew_idx_1;
  real_T rtb_thetaNew_idx_2;

  /* Gain: '<S1>/Output' incorporates:
   *  RandomNumber: '<S1>/White Noise'
   */
  rtb_Output = test_P.Output_Gain * test_DW.NextOutput;

  /* DiscreteStateSpace: '<Root>/Discrete State-Space' */
  {
    rtb_DiscreteStateSpace = test_P.DiscreteStateSpace_C*
      test_DW.DiscreteStateSpace_DSTATE[0];
  }

  /* Outputs for Atomic SubSystem: '<S2>/Recursive Polynomial Model Estimator' */
  /* Delay: '<S4>/delayTheta' incorporates:
   *  Constant: '<S4>/InitialParameters'
   */
  if (test_DW.icLoad != 0) {
    test_DW.estimatedParameters[0] = test_P.InitialParameters_Value[0];
    test_DW.estimatedParameters[1] = test_P.InitialParameters_Value[1];
    test_DW.estimatedParameters[2] = test_P.InitialParameters_Value[2];
    test_DW.estimatedParameters[3] = test_P.InitialParameters_Value[3];
  }

  /* Delay: '<S4>/delayP' incorporates:
   *  Constant: '<S4>/InitialCovariance'
   */
  if (test_DW.icLoad_e != 0) {
    for (i = 0; i < 16; i++) {
      test_DW.P[i] = test_P.InitialCovariance_Value;
    }
  }

  /* End of Delay: '<S4>/delayP' */

  /* Delay: '<S4>/delayPhi' incorporates:
   *  Constant: '<S4>/InitialPhiMemory'
   */
  if (test_DW.icLoad_k != 0) {
    test_DW.ioMemory[0] = test_P.InitialPhiMemory_Value[0];
    test_DW.ioMemory[1] = test_P.InitialPhiMemory_Value[1];
    test_DW.ioMemory[2] = test_P.InitialPhiMemory_Value[2];
    test_DW.ioMemory[3] = test_P.InitialPhiMemory_Value[3];
  }

  /* Delay: '<S4>/delayPsi' incorporates:
   *  Constant: '<S4>/InitialPsiMemory'
   */
  if (test_DW.icLoad_kn != 0) {
    test_DW.errorSensitivity[0] = test_P.InitialPsiMemory_Value[0];
    test_DW.errorSensitivity[1] = test_P.InitialPsiMemory_Value[1];
    test_DW.errorSensitivity[2] = test_P.InitialPsiMemory_Value[2];
    test_DW.errorSensitivity[3] = test_P.InitialPsiMemory_Value[3];
  }

  /* MATLAB Function: '<S19>/rarmax - MATLAB Function' incorporates:
   *  Constant: '<S4>/AdaptationParameter'
   *  Constant: '<S4>/Enable'
   *  Delay: '<S4>/delayPhi'
   *  Delay: '<S4>/delayPsi'
   *  Delay: '<S4>/delayTheta'
   */
  /* MATLAB Function 'Recursive Estimation/rarmax/rarmax - MATLAB Function': '<S24>:1' */
  /*    Copyright 2013-2013 The MathWorks, Inc. */
  /*  Use M code for code generation */
  c = rtb_DiscreteStateSpace - (((test_DW.ioMemory[0] *
    test_DW.estimatedParameters[0] + test_DW.ioMemory[1] *
    test_DW.estimatedParameters[1]) + test_DW.ioMemory[2] *
    test_DW.estimatedParameters[2]) + test_DW.ioMemory[3] *
    test_DW.estimatedParameters[3]);
  if (test_P.Enable_Value != 0.0) {
    rtb_thetaNew_idx_3 = ((test_DW.ioMemory[0] * test_DW.ioMemory[0] +
      test_DW.ioMemory[1] * test_DW.ioMemory[1]) + test_DW.ioMemory[2] *
                          test_DW.ioMemory[2]) + test_DW.ioMemory[3] *
      test_DW.ioMemory[3];
    rtb_thetaNew_idx_0 = test_P.AdaptationParameter_Value * test_DW.ioMemory[0] /
      (2.2204460492503131E-16 + rtb_thetaNew_idx_3) * c +
      test_DW.estimatedParameters[0];
    rtb_thetaNew_idx_1 = test_P.AdaptationParameter_Value * test_DW.ioMemory[1] /
      (2.2204460492503131E-16 + rtb_thetaNew_idx_3) * c +
      test_DW.estimatedParameters[1];
    rtb_thetaNew_idx_2 = test_P.AdaptationParameter_Value * test_DW.ioMemory[2] /
      (2.2204460492503131E-16 + rtb_thetaNew_idx_3) * c +
      test_DW.estimatedParameters[2];
    rtb_thetaNew_idx_3 = test_P.AdaptationParameter_Value * test_DW.ioMemory[3] /
      (2.2204460492503131E-16 + rtb_thetaNew_idx_3) * c +
      test_DW.estimatedParameters[3];
  } else {
    rtb_thetaNew_idx_0 = test_DW.estimatedParameters[0];
    rtb_thetaNew_idx_1 = test_DW.estimatedParameters[1];
    rtb_thetaNew_idx_2 = test_DW.estimatedParameters[2];
    rtb_thetaNew_idx_3 = test_DW.estimatedParameters[3];
  }

  if (test_P.Enable_Value != 0.0) {
    c = rtb_thetaNew_idx_3;
    if (1.0 + rtb_thetaNew_idx_3 == 0.0) {
      isStable = false;
    } else if (1.0 + rtb_thetaNew_idx_3 == 0.0) {
      isStable = false;
    } else if ((1.0 - rtb_thetaNew_idx_3 == 0.0) || (((1.0 + rtb_thetaNew_idx_3)
      + (rtb_thetaNew_idx_3 + 1.0)) / (1.0 - rtb_thetaNew_idx_3) <= 0.0)) {
      isStable = false;
    } else {
      isStable = true;
    }

    if (!isStable) {
      c = test_DW.estimatedParameters[3];
      rtb_thetaNew_idx_3 = test_DW.estimatedParameters[3];
    }
  } else {
    c = rtb_thetaNew_idx_3;
  }

  epsilon = rtb_DiscreteStateSpace - (((test_DW.ioMemory[0] * rtb_thetaNew_idx_0
    + test_DW.ioMemory[1] * rtb_thetaNew_idx_1) + test_DW.ioMemory[2] *
    rtb_thetaNew_idx_2) + test_DW.ioMemory[3] * rtb_thetaNew_idx_3);
  rtb_phiMemoryNew_idx_1 = test_DW.ioMemory[0];
  rtb_psiMemoryNew_idx_1 = test_DW.errorSensitivity[0];
  rtb_psiMemoryNew_idx_2 = rtb_Output - test_DW.errorSensitivity[2] * c;
  rtb_psiMemoryNew_idx_3 = epsilon - test_DW.errorSensitivity[3] * c;

  /* Update for Delay: '<S4>/delayTheta' */
  /* '<S24>:1:35' */
  /* '<S24>:1:36' */
  test_DW.icLoad = 0U;
  test_DW.estimatedParameters[0] = rtb_thetaNew_idx_0;
  test_DW.estimatedParameters[1] = rtb_thetaNew_idx_1;
  test_DW.estimatedParameters[2] = rtb_thetaNew_idx_2;
  test_DW.estimatedParameters[3] = rtb_thetaNew_idx_3;

  /* Update for Delay: '<S4>/delayP' */
  test_DW.icLoad_e = 0U;

  /* Update for Delay: '<S4>/delayPhi' incorporates:
   *  MATLAB Function: '<S19>/rarmax - MATLAB Function'
   */
  test_DW.icLoad_k = 0U;
  test_DW.ioMemory[0] = -rtb_DiscreteStateSpace;
  test_DW.ioMemory[1] = rtb_phiMemoryNew_idx_1;
  test_DW.ioMemory[2] = rtb_Output;
  test_DW.ioMemory[3] = epsilon;

  /* Update for Delay: '<S4>/delayPsi' incorporates:
   *  Delay: '<S4>/delayPsi'
   *  MATLAB Function: '<S19>/rarmax - MATLAB Function'
   */
  test_DW.icLoad_kn = 0U;
  test_DW.errorSensitivity[0] = -rtb_DiscreteStateSpace -
    test_DW.errorSensitivity[0] * c;
  test_DW.errorSensitivity[1] = rtb_psiMemoryNew_idx_1;
  test_DW.errorSensitivity[2] = rtb_psiMemoryNew_idx_2;
  test_DW.errorSensitivity[3] = rtb_psiMemoryNew_idx_3;

  /* End of Outputs for SubSystem: '<S2>/Recursive Polynomial Model Estimator' */

  /* Update for RandomNumber: '<S1>/White Noise' */
  /* MATLAB Function 'Estimators/Model Type Converter/Model Type Converter': '<S3>:1' */
  /*  arxToSS Convert an ARX model in Simulink to a state-space */
  /*  representation */
  /*    Copyright 2013-2013 The MathWorks, Inc. */
  /*  #codegen */
  /*  Use M code for code generation */
  /* '<S3>:1:26' */
  test_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&test_DW.RandSeed) *
    test_P.WhiteNoise_StdDev + test_P.WhiteNoise_Mean;

  /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space' */
  {
    real_T xnew[2];
    xnew[0] = (test_P.DiscreteStateSpace_A[0])*
      test_DW.DiscreteStateSpace_DSTATE[0]
      + (test_P.DiscreteStateSpace_A[1])*test_DW.DiscreteStateSpace_DSTATE[1];
    xnew[0] += test_P.DiscreteStateSpace_B*rtb_Output;
    xnew[1] = (test_P.DiscreteStateSpace_A[2])*
      test_DW.DiscreteStateSpace_DSTATE[0];
    (void) memcpy(&test_DW.DiscreteStateSpace_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(test_M->rtwLogInfo, (&test_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [1.0s, 0.0s] */
    if ((rtmGetTFinal(test_M)!=-1) &&
        !((rtmGetTFinal(test_M)-test_M->Timing.taskTime0) >
          test_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(test_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++test_M->Timing.clockTick0)) {
    ++test_M->Timing.clockTickH0;
  }

  test_M->Timing.taskTime0 = test_M->Timing.clockTick0 *
    test_M->Timing.stepSize0 + test_M->Timing.clockTickH0 *
    test_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)test_M, 0,
                sizeof(RT_MODEL_test_T));
  rtmSetTFinal(test_M, 50.0);
  test_M->Timing.stepSize0 = 1.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    test_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(test_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(test_M->rtwLogInfo, (NULL));
    rtliSetLogT(test_M->rtwLogInfo, "tout");
    rtliSetLogX(test_M->rtwLogInfo, "");
    rtliSetLogXFinal(test_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(test_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(test_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(test_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(test_M->rtwLogInfo, 1);
    rtliSetLogY(test_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(test_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(test_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&test_DW, 0,
                sizeof(DW_test_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(test_M->rtwLogInfo, 0.0, rtmGetTFinal(test_M),
    test_M->Timing.stepSize0, (&rtmGetErrorStatus(test_M)));

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* Start for RandomNumber: '<S1>/White Noise' */
    tmp = floor(test_P.WhiteNoise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    test_DW.RandSeed = tseed;
    test_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&test_DW.RandSeed) *
      test_P.WhiteNoise_StdDev + test_P.WhiteNoise_Mean;

    /* End of Start for RandomNumber: '<S1>/White Noise' */
  }

  /* InitializeConditions for DiscreteStateSpace: '<Root>/Discrete State-Space' */
  test_DW.DiscreteStateSpace_DSTATE[0] = test_P.DiscreteStateSpace_X0;
  test_DW.DiscreteStateSpace_DSTATE[1] = test_P.DiscreteStateSpace_X0;

  /* InitializeConditions for Atomic SubSystem: '<S2>/Recursive Polynomial Model Estimator' */
  /* InitializeConditions for Delay: '<S4>/delayTheta' */
  test_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S4>/delayP' */
  test_DW.icLoad_e = 1U;

  /* InitializeConditions for Delay: '<S4>/delayPhi' */
  test_DW.icLoad_k = 1U;

  /* InitializeConditions for Delay: '<S4>/delayPsi' */
  test_DW.icLoad_kn = 1U;

  /* End of InitializeConditions for SubSystem: '<S2>/Recursive Polynomial Model Estimator' */
}

/* Model terminate function */
void test_terminate(void)
{
  /* (no terminate code required) */
}
