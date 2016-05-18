/*
 * File: ModelE.c
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

#include "ModelE.h"
#include "ModelE_private.h"

/* Block states (auto storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/*
 * Start for trigger system:
 *    '<S3>/Send Throttle Oout-of-range message'
 *    '<S4>/Send Throttle Oout-of-range message'
 */
void SendThrottleOoutofrangeme_Start(DW_SendThrottleOoutofrangemessa *localDW)
{
  boolean_T flag;
  static const char_T tmp[17] = { 'e', 's', 't', 'i', 'm', 'a', 't', 'e', 'd',
    ' ', 'p', 'i', 't', 'c', 'h', ':', ' ' };

  int32_T i;

  /* Start for MATLABSystem: '<S8>/Mavling Message Sender' */
  localDW->obj.isInitialized = false;
  localDW->obj.isReleased = false;
  localDW->obj.tunablePropertyChanged = false;
  localDW->objisempty = true;
  if (localDW->obj.isInitialized && (!localDW->obj.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    localDW->obj.TunablePropsChanged = true;
  }

  for (i = 0; i < 17; i++) {
    localDW->obj.Message[i] = tmp[i];
  }

  if (localDW->obj.isInitialized && (!localDW->obj.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    localDW->obj.TunablePropsChanged = true;
    localDW->obj.tunablePropertyChanged = true;
  }

  localDW->obj.isInitialized = true;
  localDW->obj.TunablePropsChanged = false;

  /* End of Start for MATLABSystem: '<S8>/Mavling Message Sender' */
}

/*
 * Output and update for trigger system:
 *    '<S3>/Send Throttle Oout-of-range message'
 *    '<S4>/Send Throttle Oout-of-range message'
 */
void SendThrottleOoutofrangemessage(real_T rtu_Trigger, real_T rtu_throttle,
  DW_SendThrottleOoutofrangemessa *localDW, ZCE_SendThrottleOoutofrangemess
  *localZCE)
{
  MAV_SEVERITY f;
  char_T str[100];
  ZCEventType zcEvent;
  char_T tmp[22];
  int32_T i;

  /* Outputs for Triggered SubSystem: '<S3>/Send Throttle Oout-of-range message' incorporates:
   *  TriggerPort: '<S8>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &localZCE->SendThrottleOoutofrangemessage_,
                     (rtu_Trigger));
  if (zcEvent != NO_ZCEVENT) {
    /* Start for MATLABSystem: '<S8>/Mavling Message Sender' incorporates:
     *  MATLABSystem: '<S8>/Mavling Message Sender'
     */
    if (localDW->obj.TunablePropsChanged) {
      localDW->obj.TunablePropsChanged = false;
      localDW->obj.tunablePropertyChanged = false;
    }

    /* function setupImpl(~) */
    /*  Implement tasks that need to be performed only once,  */
    /*  such as pre-computed constants. */
    /* end */
    f = MAV_SEVERITY_INFO;

    /* coder.ceval('copter.gcs_send_text',f, [obj.Message char(0)]); */
    for (i = 0; i < 100; i++) {
      str[i] = '\x00';
    }

    for (i = 0; i < 17; i++) {
      tmp[i] = localDW->obj.Message[i];
    }

    tmp[17] = ':';
    tmp[18] = ' ';
    tmp[19] = '%';
    tmp[20] = 'f';
    tmp[21] = '\x00';
    sprintf(str, tmp, rtu_throttle);
    copter.gcs_send_text(f, str);

    /* End of Start for MATLABSystem: '<S8>/Mavling Message Sender' */
  }

  /* End of Outputs for SubSystem: '<S3>/Send Throttle Oout-of-range message' */
}

/*
 * Termination for trigger system:
 *    '<S3>/Send Throttle Oout-of-range message'
 *    '<S4>/Send Throttle Oout-of-range message'
 */
void SendThrottleOoutofrangemes_Term(DW_SendThrottleOoutofrangemessa *localDW)
{
  boolean_T flag;
  static const char_T tmp[17] = { 'e', 's', 't', 'i', 'm', 'a', 't', 'e', 'd',
    ' ', 'p', 'i', 't', 'c', 'h', ':', ' ' };

  int32_T i;

  /* Start for MATLABSystem: '<S8>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S8>/Mavling Message Sender'
   */
  localDW->obj.isInitialized = false;
  localDW->obj.isReleased = false;
  localDW->obj.tunablePropertyChanged = false;
  localDW->objisempty = true;
  if (localDW->obj.isInitialized && (!localDW->obj.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    localDW->obj.TunablePropsChanged = true;
  }

  /* Terminate for MATLABSystem: '<S8>/Mavling Message Sender' incorporates:
   *  Start for MATLABSystem: '<S8>/Mavling Message Sender'
   */
  for (i = 0; i < 17; i++) {
    localDW->obj.Message[i] = tmp[i];
  }

  /* Start for MATLABSystem: '<S8>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S8>/Mavling Message Sender'
   */
  if (localDW->obj.isInitialized && (!localDW->obj.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    localDW->obj.TunablePropsChanged = true;
    localDW->obj.tunablePropertyChanged = true;
  }

  if (localDW->obj.isInitialized) {
    localDW->obj.isReleased = true;
  }
}

/* Model output function */
void ModelE_output(void)
{
  /* local block i/o variables */
  real_T rtb_PulseGenerator_f;
  real_T rtb_PulseGenerator_j;
  real_T rtb_est_o1;
  real_T rtb_est_o3;
  real_T varargout_1;
  MAV_SEVERITY f;
  char_T str[100];
  boolean_T rtb_LogicalOperator;
  real_T rtb_PulseGenerator;
  ZCEventType zcEvent;
  char_T tmp[21];
  char_T tmp_0[34];
  int32_T i;

  /* Start for MATLABSystem: '<Root>/   rc' incorporates:
   *  MATLABSystem: '<Root>/   rc'
   */
  GET_DESIRED_YAW_RATE();
  varargout_1 = GET_DESIRED_THROTLE();
  GET_DESIRED_ROLL();
  GET_DESIRED_PITCH();

  /* Start for MATLABSystem: '<Root>/   3' incorporates:
   *  MATLABSystem: '<Root>/   3'
   *  MATLABSystem: '<Root>/   rc'
   *  Start for MATLABSystem: '<Root>/   rc'
   */
  if (varargout_1 >= 0.0) {
    copter.motors.set_throttle(varargout_1);
  }

  /* End of Start for MATLABSystem: '<Root>/   3' */

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S5>/Lower Limit'
   *  Constant: '<S5>/Upper Limit'
   *  Logic: '<S5>/AND'
   *  MATLABSystem: '<Root>/   rc'
   *  Start for MATLABSystem: '<Root>/   rc'
   *  RelationalOperator: '<S5>/Lower Test'
   *  RelationalOperator: '<S5>/Upper Test'
   */
  rtb_LogicalOperator = !((1000.0 <= varargout_1) && (varargout_1 <= 0.0));

  /* Outputs for Triggered SubSystem: '<S1>/Send Throttle Oout-of-range message' incorporates:
   *  TriggerPort: '<S6>/Trigger'
   */
  if (rtb_LogicalOperator && (rtPrevZCX.SendThrottleOoutofrangemessag_c !=
       POS_ZCSIG)) {
    /* Start for MATLABSystem: '<S6>/Mavling Message Sender' incorporates:
     *  MATLABSystem: '<Root>/   rc'
     *  Start for MATLABSystem: '<Root>/   rc'
     *  MATLABSystem: '<S6>/Mavling Message Sender'
     */
    if (rtDW.obj_d.TunablePropsChanged) {
      rtDW.obj_d.TunablePropsChanged = false;
      rtDW.obj_d.tunablePropertyChanged = false;
    }

    /* function setupImpl(~) */
    /*  Implement tasks that need to be performed only once,  */
    /*  such as pre-computed constants. */
    /* end */
    f = MAV_SEVERITY_INFO;

    /* coder.ceval('copter.gcs_send_text',f, [obj.Message char(0)]); */
    for (i = 0; i < 100; i++) {
      str[i] = '\x00';
    }

    for (i = 0; i < 29; i++) {
      tmp_0[i] = rtDW.obj_d.Message[i];
    }

    tmp_0[29] = ':';
    tmp_0[30] = ' ';
    tmp_0[31] = '%';
    tmp_0[32] = 'f';
    tmp_0[33] = '\x00';
    sprintf(str, tmp_0, varargout_1);
    copter.gcs_send_text(f, str);

    /* End of Start for MATLABSystem: '<S6>/Mavling Message Sender' */
  }

  rtPrevZCX.SendThrottleOoutofrangemessag_c = (uint8_T)(rtb_LogicalOperator ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* End of Outputs for SubSystem: '<S1>/Send Throttle Oout-of-range message' */

  /* Start for MATLABSystem: '<Root>/  accel ' incorporates:
   *  MATLABSystem: '<Root>/  accel '
   */
  GET_ACCEL_X();
  GET_ACCEL_Y();
  GET_ACCEL_Z();

  /* MATLABSystem: '<Root>/  est' incorporates:
   *  Start for MATLABSystem: '<Root>/  est'
   */
  rtb_est_o1 = GET_YAW_STATE();

  /* Start for MATLABSystem: '<Root>/  est' incorporates:
   *  MATLABSystem: '<Root>/  est'
   */
  varargout_1 = GET_ROLL_STATE();

  /* MATLABSystem: '<Root>/  est' incorporates:
   *  Start for MATLABSystem: '<Root>/  est'
   */
  rtb_est_o3 = GET_PITCH_STATE();

  /* DiscretePulseGenerator: '<S2>/Pulse Generator' */
  rtb_PulseGenerator = (rtDW.clockTickCounter < 1) && (rtDW.clockTickCounter >=
    0) ? 1.0 : 0.0;
  if (rtDW.clockTickCounter >= 99) {
    rtDW.clockTickCounter = 0;
  } else {
    rtDW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S2>/Pulse Generator' */

  /* Outputs for Triggered SubSystem: '<S2>/Send Throttle Oout-of-range message' incorporates:
   *  TriggerPort: '<S7>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &rtPrevZCX.SendThrottleOoutofrangemessag_g,
                     (rtb_PulseGenerator));
  if (zcEvent != NO_ZCEVENT) {
    /* Start for MATLABSystem: '<S7>/Mavling Message Sender' incorporates:
     *  MATLABSystem: '<Root>/  est'
     *  Start for MATLABSystem: '<Root>/  est'
     *  MATLABSystem: '<S7>/Mavling Message Sender'
     */
    if (rtDW.obj.TunablePropsChanged) {
      rtDW.obj.TunablePropsChanged = false;
      rtDW.obj.tunablePropertyChanged = false;
    }

    /* function setupImpl(~) */
    /*  Implement tasks that need to be performed only once,  */
    /*  such as pre-computed constants. */
    /* end */
    f = MAV_SEVERITY_INFO;

    /* coder.ceval('copter.gcs_send_text',f, [obj.Message char(0)]); */
    for (i = 0; i < 100; i++) {
      str[i] = '\x00';
    }

    for (i = 0; i < 16; i++) {
      tmp[i] = rtDW.obj.Message[i];
    }

    tmp[16] = ':';
    tmp[17] = ' ';
    tmp[18] = '%';
    tmp[19] = 'f';
    tmp[20] = '\x00';
    sprintf(str, tmp, varargout_1);
    copter.gcs_send_text(f, str);

    /* End of Start for MATLABSystem: '<S7>/Mavling Message Sender' */
  }

  /* End of Outputs for SubSystem: '<S2>/Send Throttle Oout-of-range message' */

  /* DiscretePulseGenerator: '<S3>/Pulse Generator' */
  rtb_PulseGenerator_f = (rtDW.clockTickCounter_e < 1) &&
    (rtDW.clockTickCounter_e >= 0) ? 1.0 : 0.0;
  if (rtDW.clockTickCounter_e >= 99) {
    rtDW.clockTickCounter_e = 0;
  } else {
    rtDW.clockTickCounter_e++;
  }

  /* End of DiscretePulseGenerator: '<S3>/Pulse Generator' */

  /* Outputs for Triggered SubSystem: '<S3>/Send Throttle Oout-of-range message' */
  SendThrottleOoutofrangemessage(rtb_PulseGenerator_f, rtb_est_o1,
    &rtDW.SendThrottleOoutofrangemessag_m,
    &rtPrevZCX.SendThrottleOoutofrangemessag_m);

  /* End of Outputs for SubSystem: '<S3>/Send Throttle Oout-of-range message' */

  /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
  rtb_PulseGenerator_j = (rtDW.clockTickCounter_d < 1) &&
    (rtDW.clockTickCounter_d >= 0) ? 1.0 : 0.0;
  if (rtDW.clockTickCounter_d >= 99) {
    rtDW.clockTickCounter_d = 0;
  } else {
    rtDW.clockTickCounter_d++;
  }

  /* End of DiscretePulseGenerator: '<S4>/Pulse Generator' */

  /* Outputs for Triggered SubSystem: '<S4>/Send Throttle Oout-of-range message' */
  SendThrottleOoutofrangemessage(rtb_PulseGenerator_j, rtb_est_o3,
    &rtDW.SendThrottleOoutofrangemessag_k,
    &rtPrevZCX.SendThrottleOoutofrangemessag_k);

  /* End of Outputs for SubSystem: '<S4>/Send Throttle Oout-of-range message' */

  /* Start for MATLABSystem: '<Root>/gyro  ' incorporates:
   *  MATLABSystem: '<Root>/gyro  '
   */
  GET_GYRO_X();
  GET_GYRO_Y();
  GET_GYRO_Z();
}

/* Model update function */
void ModelE_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void ModelE_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    boolean_T flag;
    static const char_T tmp[29] = { 't', 'h', 'r', 'o', 't', 't', 'l', 'e', ' ',
      'n', 'o', 't', ' ', 'b', 'e', 't', 'w', 'e', 'e', 'n', ' ', '0', ' ', 't',
      'o', ' ', '1', ':', ' ' };

    static const char_T tmp_0[16] = { 'e', 's', 't', 'i', 'm', 'a', 't', 'e',
      'd', ' ', 'r', 'o', 'l', 'l', ':', ' ' };

    int32_T i;

    /* Start for MATLABSystem: '<Root>/   2' */
    rtDW.obj_h.isInitialized = false;
    rtDW.obj_h.isReleased = false;
    rtDW.objisempty_e = true;
    rtDW.obj_h.isInitialized = true;

    /* Start for MATLABSystem: '<Root>/   rc' */
    rtDW.obj_j.isInitialized = false;
    rtDW.obj_j.isReleased = false;
    rtDW.objisempty_b = true;
    rtDW.obj_j.isInitialized = true;

    /* Start for MATLABSystem: '<Root>/   3' */
    rtDW.obj_k.isInitialized = false;
    rtDW.obj_k.isReleased = false;
    rtDW.objisempty_d = true;
    rtDW.obj_k.isInitialized = true;

    /* Start for Triggered SubSystem: '<S1>/Send Throttle Oout-of-range message' */
    /* Start for MATLABSystem: '<S6>/Mavling Message Sender' */
    rtDW.obj_d.isInitialized = false;
    rtDW.obj_d.isReleased = false;
    rtDW.obj_d.tunablePropertyChanged = false;
    rtDW.objisempty_a = true;
    if (rtDW.obj_d.isInitialized && (!rtDW.obj_d.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      rtDW.obj_d.TunablePropsChanged = true;
    }

    for (i = 0; i < 29; i++) {
      rtDW.obj_d.Message[i] = tmp[i];
    }

    if (rtDW.obj_d.isInitialized && (!rtDW.obj_d.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      rtDW.obj_d.TunablePropsChanged = true;
      rtDW.obj_d.tunablePropertyChanged = true;
    }

    rtDW.obj_d.isInitialized = true;
    rtDW.obj_d.TunablePropsChanged = false;

    /* End of Start for MATLABSystem: '<S6>/Mavling Message Sender' */
    /* End of Start for SubSystem: '<S1>/Send Throttle Oout-of-range message' */

    /* Start for MATLABSystem: '<Root>/  accel ' */
    rtDW.obj_n.isInitialized = false;
    rtDW.obj_n.isReleased = false;
    rtDW.objisempty_bi = true;
    rtDW.obj_n.isInitialized = true;

    /* Start for MATLABSystem: '<Root>/  est' */
    rtDW.obj_jg.isInitialized = false;
    rtDW.obj_jg.isReleased = false;
    rtDW.objisempty_m = true;
    rtDW.obj_jg.isInitialized = true;

    /* Start for Triggered SubSystem: '<S2>/Send Throttle Oout-of-range message' */
    /* Start for MATLABSystem: '<S7>/Mavling Message Sender' */
    rtDW.obj.isInitialized = false;
    rtDW.obj.isReleased = false;
    rtDW.obj.tunablePropertyChanged = false;
    rtDW.objisempty = true;
    if (rtDW.obj.isInitialized && (!rtDW.obj.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      rtDW.obj.TunablePropsChanged = true;
    }

    for (i = 0; i < 16; i++) {
      rtDW.obj.Message[i] = tmp_0[i];
    }

    if (rtDW.obj.isInitialized && (!rtDW.obj.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      rtDW.obj.TunablePropsChanged = true;
      rtDW.obj.tunablePropertyChanged = true;
    }

    rtDW.obj.isInitialized = true;
    rtDW.obj.TunablePropsChanged = false;

    /* End of Start for MATLABSystem: '<S7>/Mavling Message Sender' */
    /* End of Start for SubSystem: '<S2>/Send Throttle Oout-of-range message' */

    /* Start for Triggered SubSystem: '<S3>/Send Throttle Oout-of-range message' */
    SendThrottleOoutofrangeme_Start(&rtDW.SendThrottleOoutofrangemessag_m);

    /* End of Start for SubSystem: '<S3>/Send Throttle Oout-of-range message' */

    /* Start for Triggered SubSystem: '<S4>/Send Throttle Oout-of-range message' */
    SendThrottleOoutofrangeme_Start(&rtDW.SendThrottleOoutofrangemessag_k);

    /* End of Start for SubSystem: '<S4>/Send Throttle Oout-of-range message' */

    /* Start for MATLABSystem: '<Root>/gyro  ' */
    rtDW.obj_l.isInitialized = false;
    rtDW.obj_l.isReleased = false;
    rtDW.objisempty_dk = true;
    rtDW.obj_l.isInitialized = true;

    /* Start for MATLABSystem: '<Root>/   2' incorporates:
     *  Constant: '<Root>/Constant1'
     *  ConstCode for MATLABSystem: '<Root>/   2'
     */
    SET_YAW_RATE_TARGET((rtMinusInf));
    SET_PITCH_RATE_TARGET((rtMinusInf));
    SET_ROLL_RATE_TARGET((rtMinusInf));
  }

  rtPrevZCX.SendThrottleOoutofrangemessag_k.SendThrottleOoutofrangemessage_ =
    UNINITIALIZED_ZCSIG;
  rtPrevZCX.SendThrottleOoutofrangemessag_m.SendThrottleOoutofrangemessage_ =
    UNINITIALIZED_ZCSIG;
  rtPrevZCX.SendThrottleOoutofrangemessag_g = UNINITIALIZED_ZCSIG;
  rtPrevZCX.SendThrottleOoutofrangemessag_c = POS_ZCSIG;
}

/* Model terminate function */
void ModelE_terminate(void)
{
  boolean_T flag;
  static const char_T tmp[29] = { 't', 'h', 'r', 'o', 't', 't', 'l', 'e', ' ',
    'n', 'o', 't', ' ', 'b', 'e', 't', 'w', 'e', 'e', 'n', ' ', '0', ' ', 't',
    'o', ' ', '1', ':', ' ' };

  static const char_T tmp_0[16] = { 'e', 's', 't', 'i', 'm', 'a', 't', 'e', 'd',
    ' ', 'r', 'o', 'l', 'l', ':', ' ' };

  int32_T i;

  /* Start for MATLABSystem: '<Root>/   2' incorporates:
   *  Terminate for MATLABSystem: '<Root>/   2'
   */
  rtDW.obj_h.isInitialized = false;
  rtDW.obj_h.isReleased = false;
  rtDW.objisempty_e = true;
  if (rtDW.obj_h.isInitialized) {
    rtDW.obj_h.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/   2' */

  /* Start for MATLABSystem: '<Root>/   rc' incorporates:
   *  Terminate for MATLABSystem: '<Root>/   rc'
   */
  rtDW.obj_j.isInitialized = false;
  rtDW.obj_j.isReleased = false;
  rtDW.objisempty_b = true;
  if (rtDW.obj_j.isInitialized) {
    rtDW.obj_j.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/   rc' */

  /* Start for MATLABSystem: '<Root>/   3' incorporates:
   *  Terminate for MATLABSystem: '<Root>/   3'
   */
  rtDW.obj_k.isInitialized = false;
  rtDW.obj_k.isReleased = false;
  rtDW.objisempty_d = true;
  if (rtDW.obj_k.isInitialized) {
    rtDW.obj_k.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/   3' */

  /* Terminate for Triggered SubSystem: '<S1>/Send Throttle Oout-of-range message' */
  /* Start for MATLABSystem: '<S6>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S6>/Mavling Message Sender'
   */
  rtDW.obj_d.isInitialized = false;
  rtDW.obj_d.isReleased = false;
  rtDW.obj_d.tunablePropertyChanged = false;
  rtDW.objisempty_a = true;
  if (rtDW.obj_d.isInitialized && (!rtDW.obj_d.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    rtDW.obj_d.TunablePropsChanged = true;
  }

  /* Terminate for MATLABSystem: '<S6>/Mavling Message Sender' incorporates:
   *  Start for MATLABSystem: '<S6>/Mavling Message Sender'
   */
  for (i = 0; i < 29; i++) {
    rtDW.obj_d.Message[i] = tmp[i];
  }

  /* Start for MATLABSystem: '<S6>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S6>/Mavling Message Sender'
   */
  if (rtDW.obj_d.isInitialized && (!rtDW.obj_d.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    rtDW.obj_d.TunablePropsChanged = true;
    rtDW.obj_d.tunablePropertyChanged = true;
  }

  if (rtDW.obj_d.isInitialized) {
    rtDW.obj_d.isReleased = true;
  }

  /* End of Terminate for SubSystem: '<S1>/Send Throttle Oout-of-range message' */

  /* Start for MATLABSystem: '<Root>/  accel ' incorporates:
   *  Terminate for MATLABSystem: '<Root>/  accel '
   */
  rtDW.obj_n.isInitialized = false;
  rtDW.obj_n.isReleased = false;
  rtDW.objisempty_bi = true;
  if (rtDW.obj_n.isInitialized) {
    rtDW.obj_n.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/  accel ' */

  /* Start for MATLABSystem: '<Root>/  est' incorporates:
   *  Terminate for MATLABSystem: '<Root>/  est'
   */
  rtDW.obj_jg.isInitialized = false;
  rtDW.obj_jg.isReleased = false;
  rtDW.objisempty_m = true;
  if (rtDW.obj_jg.isInitialized) {
    rtDW.obj_jg.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/  est' */

  /* Terminate for Triggered SubSystem: '<S2>/Send Throttle Oout-of-range message' */
  /* Start for MATLABSystem: '<S7>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S7>/Mavling Message Sender'
   */
  rtDW.obj.isInitialized = false;
  rtDW.obj.isReleased = false;
  rtDW.obj.tunablePropertyChanged = false;
  rtDW.objisempty = true;
  if (rtDW.obj.isInitialized && (!rtDW.obj.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    rtDW.obj.TunablePropsChanged = true;
  }

  /* Terminate for MATLABSystem: '<S7>/Mavling Message Sender' incorporates:
   *  Start for MATLABSystem: '<S7>/Mavling Message Sender'
   */
  for (i = 0; i < 16; i++) {
    rtDW.obj.Message[i] = tmp_0[i];
  }

  /* Start for MATLABSystem: '<S7>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S7>/Mavling Message Sender'
   */
  if (rtDW.obj.isInitialized && (!rtDW.obj.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    rtDW.obj.TunablePropsChanged = true;
    rtDW.obj.tunablePropertyChanged = true;
  }

  if (rtDW.obj.isInitialized) {
    rtDW.obj.isReleased = true;
  }

  /* End of Terminate for SubSystem: '<S2>/Send Throttle Oout-of-range message' */

  /* Terminate for Triggered SubSystem: '<S3>/Send Throttle Oout-of-range message' */
  SendThrottleOoutofrangemes_Term(&rtDW.SendThrottleOoutofrangemessag_m);

  /* End of Terminate for SubSystem: '<S3>/Send Throttle Oout-of-range message' */

  /* Terminate for Triggered SubSystem: '<S4>/Send Throttle Oout-of-range message' */
  SendThrottleOoutofrangemes_Term(&rtDW.SendThrottleOoutofrangemessag_k);

  /* End of Terminate for SubSystem: '<S4>/Send Throttle Oout-of-range message' */

  /* Start for MATLABSystem: '<Root>/gyro  ' incorporates:
   *  Terminate for MATLABSystem: '<Root>/gyro  '
   */
  rtDW.obj_l.isInitialized = false;
  rtDW.obj_l.isReleased = false;
  rtDW.objisempty_dk = true;
  if (rtDW.obj_l.isInitialized) {
    rtDW.obj_l.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/gyro  ' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
