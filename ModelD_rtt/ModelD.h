/*
 * File: ModelD.h
 *
 * Code generated for Simulink model 'ModelD'.
 *
 * Model version                  : 1.93
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Thu Apr 21 16:48:29 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ModelD_h_
#define RTW_HEADER_ModelD_h_
#include <stddef.h>
#ifndef ModelD_COMMON_INCLUDES_
# define ModelD_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MyCopter.h"
#endif                                 /* ModelD_COMMON_INCLUDES_ */

#include "ModelD_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T FilterCoefficient;            /* '<S1>/Filter Coefficient' */
  real_T FilterCoefficient_p;          /* '<S2>/Filter Coefficient' */
  uint16_T FixPtSwitch;                /* '<S14>/FixPt Switch' */
  uint16_T FixPtSwitch_i;              /* '<S18>/FixPt Switch' */
  uint16_T FixPtSwitch_c;              /* '<S22>/FixPt Switch' */
  uint16_T FixPtSwitch_l;              /* '<S26>/FixPt Switch' */
  uint16_T FixPtSwitch_g;              /* '<S30>/FixPt Switch' */
} B;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Filter_DSTATE;                /* '<S1>/Filter' */
  real_T Filter_DSTATE_f;              /* '<S2>/Filter' */
  void *MavlingMessageSender_PWORK;    /* '<S28>/Mavling Message Sender' */
  void *MavlingMessageSender_PWORK_m;  /* '<S24>/Mavling Message Sender' */
  void *MavlingMessageSender_PWORK_k;  /* '<S20>/Mavling Message Sender' */
  void *MavlingMessageSender_PWORK_g;  /* '<S16>/Mavling Message Sender' */
  void *MavlingMessageSender_PWORK_e;  /* '<S12>/Mavling Message Sender' */
  void *MavlingMessageSender_PWORK_f;  /* '<S10>/Mavling Message Sender' */
  void *_PWORK;                        /* '<Root>/  ' */
  void *u_PWORK;                       /* '<Root>/   1' */
  void *_PWORK_f;                      /* '<Root>/   ' */
  void *u_PWORK_d;                     /* '<Root>/   2' */
  void *u_PWORK_k;                     /* '<Root>/   3' */
  MavlinkMsg_hx5h obj;                 /* '<S28>/Mavling Message Sender' */
  MavlinkMsg_hx5 obj_m;                /* '<S24>/Mavling Message Sender' */
  MavlinkMsg_h obj_d;                  /* '<S20>/Mavling Message Sender' */
  MavlinkMsg_hx obj_n;                 /* '<S16>/Mavling Message Sender' */
  MavlinkMsg_h obj_nl;                 /* '<S12>/Mavling Message Sender' */
  MavlinkMsg obj_dw;                   /* '<S10>/Mavling Message Sender' */
  uint16_T Output_DSTATE;              /* '<S11>/Output' */
  uint16_T Output_DSTATE_c;            /* '<S15>/Output' */
  uint16_T Output_DSTATE_a;            /* '<S19>/Output' */
  uint16_T Output_DSTATE_j;            /* '<S23>/Output' */
  uint16_T Output_DSTATE_cf;           /* '<S27>/Output' */
  Gyro obj_l;                          /* '<Root>/  ' */
  Accel obj_no;                        /* '<Root>/   ' */
  RC obj_j;                            /* '<Root>/   1' */
  RateController obj_h;                /* '<Root>/   2' */
  Motors obj_k;                        /* '<Root>/   3' */
  boolean_T objisempty;                /* '<S28>/Mavling Message Sender' */
  boolean_T objisempty_h;              /* '<S24>/Mavling Message Sender' */
  boolean_T objisempty_k;              /* '<S20>/Mavling Message Sender' */
  boolean_T objisempty_i;              /* '<S16>/Mavling Message Sender' */
  boolean_T objisempty_m;              /* '<S12>/Mavling Message Sender' */
  boolean_T objisempty_a;              /* '<S10>/Mavling Message Sender' */
  boolean_T objisempty_d;              /* '<Root>/  ' */
  boolean_T objisempty_b;              /* '<Root>/   1' */
  boolean_T objisempty_bi;             /* '<Root>/   ' */
  boolean_T objisempty_e;              /* '<Root>/   2' */
  boolean_T objisempty_du;             /* '<Root>/   3' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SendThrottleOoutofrangemessage3;/* '<S8>/Send Throttle Oout-of-range message3' */
  ZCSigState SendThrottleOoutofrangemessag_j;/* '<S7>/Send Throttle Oout-of-range message3' */
  ZCSigState SendThrottleOoutofrangemessag_n;/* '<S6>/Send Throttle Oout-of-range message3' */
  ZCSigState SendThrottleOoutofrangemessag_p;/* '<S5>/Send Throttle Oout-of-range message3' */
  ZCSigState SendThrottleOoutofrangemessag_b;/* '<S4>/Send Throttle Oout-of-range message3' */
  ZCSigState SendThrottleOoutofrangemessage_;/* '<S3>/Send Throttle Oout-of-range message' */
} PrevZCX;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern B rtB;

/* Block states (auto storage) */
extern DW rtDW;

/* Model entry point functions */
extern void ModelD_initialize(void);
extern void ModelD_output(void);
extern void ModelD_update(void);
extern void ModelD_terminate(void);

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
 * '<Root>' : 'ModelD'
 * '<S1>'   : 'ModelD/Discrete PID Controller'
 * '<S2>'   : 'ModelD/Discrete PID Controller1'
 * '<S3>'   : 'ModelD/Subsystem'
 * '<S4>'   : 'ModelD/log'
 * '<S5>'   : 'ModelD/log1'
 * '<S6>'   : 'ModelD/log2'
 * '<S7>'   : 'ModelD/log3'
 * '<S8>'   : 'ModelD/log4'
 * '<S9>'   : 'ModelD/Subsystem/Interval Test'
 * '<S10>'  : 'ModelD/Subsystem/Send Throttle Oout-of-range message'
 * '<S11>'  : 'ModelD/log/Counter Limited'
 * '<S12>'  : 'ModelD/log/Send Throttle Oout-of-range message3'
 * '<S13>'  : 'ModelD/log/Counter Limited/Increment Real World'
 * '<S14>'  : 'ModelD/log/Counter Limited/Wrap To Zero'
 * '<S15>'  : 'ModelD/log1/Counter Limited'
 * '<S16>'  : 'ModelD/log1/Send Throttle Oout-of-range message3'
 * '<S17>'  : 'ModelD/log1/Counter Limited/Increment Real World'
 * '<S18>'  : 'ModelD/log1/Counter Limited/Wrap To Zero'
 * '<S19>'  : 'ModelD/log2/Counter Limited'
 * '<S20>'  : 'ModelD/log2/Send Throttle Oout-of-range message3'
 * '<S21>'  : 'ModelD/log2/Counter Limited/Increment Real World'
 * '<S22>'  : 'ModelD/log2/Counter Limited/Wrap To Zero'
 * '<S23>'  : 'ModelD/log3/Counter Limited'
 * '<S24>'  : 'ModelD/log3/Send Throttle Oout-of-range message3'
 * '<S25>'  : 'ModelD/log3/Counter Limited/Increment Real World'
 * '<S26>'  : 'ModelD/log3/Counter Limited/Wrap To Zero'
 * '<S27>'  : 'ModelD/log4/Counter Limited'
 * '<S28>'  : 'ModelD/log4/Send Throttle Oout-of-range message3'
 * '<S29>'  : 'ModelD/log4/Counter Limited/Increment Real World'
 * '<S30>'  : 'ModelD/log4/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_ModelD_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
