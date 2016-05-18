/*
 * File: raspberrypi_audioequalizer_data.c
 *
 * Code generated for Simulink model 'raspberrypi_audioequalizer'.
 *
 * Model version                  : 1.457
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Thu Mar 10 23:53:18 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "raspberrypi_audioequalizer.h"
#include "raspberrypi_audioequalizer_private.h"

/* Block parameters (auto storage) */
Parameters_raspberrypi_audioequ raspberrypi_audioequalizer_P = {
  /*  Variable: CoeffsMatrix1
   * Referenced by:
   *   '<S1>/Coeffs for Band1'
   *   '<S8>/Unit Delay'
   */
  { 1.11763632F, -1.68922007F, 0.580065072F, -1.68922007F, 0.697701454F },

  /*  Variable: CoeffsMatrix2
   * Referenced by:
   *   '<S1>/Coeffs for Band2'
   *   '<S10>/Unit Delay'
   */
  { 1.06828189F, -1.63569796F, 0.600684285F, -1.63569796F, 0.668966174F },

  /*  Variable: CoeffsMatrix3
   * Referenced by:
   *   '<S1>/Coeffs for Band3'
   *   '<S12>/Unit Delay'
   */
  { 0.894745409F, -1.45116627F, 0.624265134F, -1.45116627F, 0.519010544F },
  0.2F,                                /* Mask Parameter: SmoothCoefficientsLeakyIntegrat
                                        * Referenced by: '<S8>/b0'
                                        */
  0.2F,                                /* Mask Parameter: SmoothCoefficientsLeakyIntegr_c
                                        * Referenced by: '<S10>/b0'
                                        */
  0.2F,                                /* Mask Parameter: SmoothCoefficientsLeakyIntegr_k
                                        * Referenced by: '<S12>/b0'
                                        */
  0.8F,                                /* Computed Parameter: a1_Gain
                                        * Referenced by: '<S8>/a1'
                                        */
  0.8F,                                /* Computed Parameter: a1_Gain_n
                                        * Referenced by: '<S10>/a1'
                                        */
  0.8F,                                /* Computed Parameter: a1_Gain_o
                                        * Referenced by: '<S12>/a1'
                                        */
  0.5F                                 /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S3>/Gain'
                                        */
};

/* Constant parameters (auto storage) */
const ConstParam_raspberrypi_audioequ raspberrypi_audioequaliz_ConstP = {
  /* Expression: device
   * Referenced by: '<Root>/ALSA Audio Playback'
   */
  { 112U, 108U, 117U, 103U, 104U, 119U, 58U, 48U, 44U, 48U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
