/*
 * File: ModelC.h
 *
 * Code generated for Simulink model 'ModelC'.
 *
 * Model version                  : 1.51
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Sun Apr 17 15:52:41 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ModelC_h_
#define RTW_HEADER_ModelC_h_
#include <stddef.h>
#include <string.h>
#ifndef ModelC_COMMON_INCLUDES_
# define ModelC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MyCopter.h"
#endif                                 /* ModelC_COMMON_INCLUDES_ */

#include "ModelC_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  void *MATLABSystem_PWORK;            /* '<S3>/MATLAB System' */
  void *_PWORK;                        /* '<Root>/  ' */
  void *_PWORK_f;                      /* '<Root>/   ' */
  void *u_PWORK;                       /* '<Root>/   1' */
  void *u_PWORK_d;                     /* '<Root>/   2' */
  void *u_PWORK_k;                     /* '<Root>/   3' */
  MavlinkMsg_ModelC_T obj;             /* '<S3>/MATLAB System' */
  Gyro_ModelC_T obj_l;                 /* '<Root>/  ' */
  Accel_ModelC_T obj_n;                /* '<Root>/   ' */
  RC_ModelC_T obj_j;                   /* '<Root>/   1' */
  RateController_ModelC_T obj_h;       /* '<Root>/   2' */
  Motors_ModelC_T obj_k;               /* '<Root>/   3' */
  boolean_T objisempty;                /* '<S3>/MATLAB System' */
  boolean_T objisempty_d;              /* '<Root>/  ' */
  boolean_T objisempty_b;              /* '<Root>/   ' */
  boolean_T objisempty_bp;             /* '<Root>/   1' */
  boolean_T objisempty_e;              /* '<Root>/   2' */
  boolean_T objisempty_du;             /* '<Root>/   3' */
} DW_ModelC_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S1>/Triggered Subsystem' */
} PrevZCX_ModelC_T;

/* Parameters (auto storage) */
struct P_ModelC_T_ {
  real_T IntervalTest_lowlimit;        /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S2>/Lower Limit'
                                        */
  real_T IntervalTest_uplimit;         /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S2>/Upper Limit'
                                        */
  real_T Constant_Value;               /* Expression: -inf
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ModelC_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_ModelC_T ModelC_P;

/* Block states (auto storage) */
extern DW_ModelC_T ModelC_DW;

/* Model entry point functions */
extern void ModelC_initialize(void);
extern void ModelC_output(void);
extern void ModelC_update(void);
extern void ModelC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ModelC_T *const ModelC_M;

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
 * '<Root>' : 'ModelC'
 * '<S1>'   : 'ModelC/Subsystem'
 * '<S2>'   : 'ModelC/Subsystem/Interval Test'
 * '<S3>'   : 'ModelC/Subsystem/Triggered Subsystem'
 */
#endif                                 /* RTW_HEADER_ModelC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
