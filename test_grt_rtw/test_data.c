/*
 * test_data.c
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

/* Block parameters (auto storage) */
P_test_T test_P = {
  1.0,                                 /* Expression: initializationParams.adg
                                        * Referenced by: '<S4>/AdaptationParameter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Enable'
                                        */

  /*  Expression: initializationParams.theta0
   * Referenced by: '<S4>/InitialParameters'
   */
  { 2.2204460492503131E-16, 2.2204460492503131E-16, 2.2204460492503131E-16,
    2.2204460492503131E-16 },
  10000.0,                             /* Expression: initializationParams.P0
                                        * Referenced by: '<S4>/InitialCovariance'
                                        */

  /*  Expression: initializationParams.phiMemory0
   * Referenced by: '<S4>/InitialPhiMemory'
   */
  { -0.0, -0.0, 0.0, 0.0 },

  /*  Expression: initializationParams.psiMemory0
   * Referenced by: '<S4>/InitialPsiMemory'
   */
  { 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S1>/White Noise'
                                        */
  0.0,                                 /* Expression: seed
                                        * Referenced by: '<S1>/White Noise'
                                        */
  0.31622776601683794,                 /* Expression: [sqrt(Cov)]/[sqrt(Ts)]
                                        * Referenced by: '<S1>/Output'
                                        */

  /*  Computed Parameter: DiscreteStateSpace_A
   * Referenced by: '<Root>/Discrete State-Space'
   */
  { 11.0, 1.0, 12.0 },
  1.0,                                 /* Computed Parameter: DiscreteStateSpace_B
                                        * Referenced by: '<Root>/Discrete State-Space'
                                        */
  1.0,                                 /* Computed Parameter: DiscreteStateSpace_C
                                        * Referenced by: '<Root>/Discrete State-Space'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Discrete State-Space'
                                        */
  1U,                                  /* Computed Parameter: delayTheta_DelayLength
                                        * Referenced by: '<S4>/delayTheta'
                                        */
  1U,                                  /* Computed Parameter: delayP_DelayLength
                                        * Referenced by: '<S4>/delayP'
                                        */
  1U,                                  /* Computed Parameter: delayPhi_DelayLength
                                        * Referenced by: '<S4>/delayPhi'
                                        */
  1U                                   /* Computed Parameter: delayPsi_DelayLength
                                        * Referenced by: '<S4>/delayPsi'
                                        */
};
