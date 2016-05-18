/*
 * File: ModelE.h
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

#ifndef RTW_HEADER_ModelE_h_
#define RTW_HEADER_ModelE_h_
#include <stddef.h>
#ifndef ModelE_COMMON_INCLUDES_
# define ModelE_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MyCopter.h"
#endif                                 /* ModelE_COMMON_INCLUDES_ */

#include "ModelE_types.h"
#include "rt_zcfcn.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<S3>/Send Throttle Oout-of-range message' */
typedef struct {
  void *MavlingMessageSender_PWORK;    /* '<S8>/Mavling Message Sender' */
  MavlinkMsg obj;                      /* '<S8>/Mavling Message Sender' */
  boolean_T objisempty;                /* '<S8>/Mavling Message Sender' */
} DW_SendThrottleOoutofrangemessa;

/* Zero-crossing (trigger) state for system '<S3>/Send Throttle Oout-of-range message' */
typedef struct {
  ZCSigState SendThrottleOoutofrangemessage_;/* '<S3>/Send Throttle Oout-of-range message' */
} ZCE_SendThrottleOoutofrangemess;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  void *MavlingMessageSender_PWORK;    /* '<S7>/Mavling Message Sender' */
  void *MavlingMessageSender_PWORK_f;  /* '<S6>/Mavling Message Sender' */
  void *u_PWORK;                       /* '<Root>/   2' */
  void *rc_PWORK;                      /* '<Root>/   rc' */
  void *u_PWORK_k;                     /* '<Root>/   3' */
  void *accel_PWORK;                   /* '<Root>/  accel ' */
  void *est_PWORK;                     /* '<Root>/  est' */
  void *gyro_PWORK;                    /* '<Root>/gyro  ' */
  int32_T clockTickCounter;            /* '<S2>/Pulse Generator' */
  int32_T clockTickCounter_e;          /* '<S3>/Pulse Generator' */
  int32_T clockTickCounter_d;          /* '<S4>/Pulse Generator' */
  MavlinkMsg_ml obj;                   /* '<S7>/Mavling Message Sender' */
  MavlinkMsg_m obj_d;                  /* '<S6>/Mavling Message Sender' */
  RateController obj_h;                /* '<Root>/   2' */
  Motors obj_k;                        /* '<Root>/   3' */
  RC obj_j;                            /* '<Root>/   rc' */
  Accel obj_n;                         /* '<Root>/  accel ' */
  Copter_Self_State obj_jg;            /* '<Root>/  est' */
  Gyro obj_l;                          /* '<Root>/gyro  ' */
  boolean_T objisempty;                /* '<S7>/Mavling Message Sender' */
  boolean_T objisempty_a;              /* '<S6>/Mavling Message Sender' */
  boolean_T objisempty_e;              /* '<Root>/   2' */
  boolean_T objisempty_b;              /* '<Root>/   rc' */
  boolean_T objisempty_d;              /* '<Root>/   3' */
  boolean_T objisempty_bi;             /* '<Root>/  accel ' */
  boolean_T objisempty_m;              /* '<Root>/  est' */
  boolean_T objisempty_dk;             /* '<Root>/gyro  ' */
  DW_SendThrottleOoutofrangemessa SendThrottleOoutofrangemessag_k;/* '<S4>/Send Throttle Oout-of-range message' */
  DW_SendThrottleOoutofrangemessa SendThrottleOoutofrangemessag_m;/* '<S3>/Send Throttle Oout-of-range message' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_SendThrottleOoutofrangemess SendThrottleOoutofrangemessag_k;/* '<S3>/Send Throttle Oout-of-range message' */
  ZCE_SendThrottleOoutofrangemess SendThrottleOoutofrangemessag_m;/* '<S3>/Send Throttle Oout-of-range message' */
  ZCSigState SendThrottleOoutofrangemessag_g;/* '<S2>/Send Throttle Oout-of-range message' */
  ZCSigState SendThrottleOoutofrangemessag_c;/* '<S1>/Send Throttle Oout-of-range message' */
} PrevZCX;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block states (auto storage) */
extern DW rtDW;

/* Model entry point functions */
extern void ModelE_initialize(void);
extern void ModelE_output(void);
extern void ModelE_update(void);
extern void ModelE_terminate(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<Root>' : 'ModelE'
 * '<S1>'   : 'ModelE/Subsystem'
 * '<S2>'   : 'ModelE/Subsystem1'
 * '<S3>'   : 'ModelE/Subsystem2'
 * '<S4>'   : 'ModelE/Subsystem3'
 * '<S5>'   : 'ModelE/Subsystem/Interval Test'
 * '<S6>'   : 'ModelE/Subsystem/Send Throttle Oout-of-range message'
 * '<S7>'   : 'ModelE/Subsystem1/Send Throttle Oout-of-range message'
 * '<S8>'   : 'ModelE/Subsystem2/Send Throttle Oout-of-range message'
 * '<S9>'   : 'ModelE/Subsystem3/Send Throttle Oout-of-range message'
 */
#endif                                 /* RTW_HEADER_ModelE_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
