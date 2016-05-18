/*
 * File: ModelE_private.h
 *
 * Code generated for Simulink model 'ModelE'.
 *
 * Model version                  : 1.101
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Tue May 17 16:28:35 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ModelE_private_h_
#define RTW_HEADER_ModelE_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

extern void SendThrottleOoutofrangeme_Start(DW_SendThrottleOoutofrangemessa
  *localDW);
extern void SendThrottleOoutofrangemessage(real_T rtu_Trigger, real_T
  rtu_throttle, DW_SendThrottleOoutofrangemessa *localDW,
  ZCE_SendThrottleOoutofrangemess *localZCE);
extern void SendThrottleOoutofrangemes_Term(DW_SendThrottleOoutofrangemessa
  *localDW);

#endif                                 /* RTW_HEADER_ModelE_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
