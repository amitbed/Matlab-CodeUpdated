/*
 * File: ModelD.c
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

#include "ModelD.h"
#include "ModelD_private.h"

/* Block signals (auto storage) */
B rtB;

/* Block states (auto storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model output function */
void ModelD_output(void)
{
  real_T varargout_4;
  real_T varargout_3;
  real_T varargout_1;
  real_T varargout_1_0;
  MAV_SEVERITY f;
  char_T str[100];
  real_T rtb_Gain2;
  real_T rtb_Sum;
  real_T rtb_Sum1;
  real_T rtb_Sum_n;
  real_T rtb_Gain4;
  boolean_T rtb_LogicalOperator;
  uint16_T rtb_Output;
  char_T tmp[16];
  char_T tmp_0[15];
  char_T tmp_1[22];
  char_T tmp_2[14];
  char_T tmp_3[34];
  int32_T i;

  /* Start for MATLABSystem: '<Root>/  ' incorporates:
   *  MATLABSystem: '<Root>/  '
   */
  GET_GYRO_X();
  GET_GYRO_Y();
  GET_GYRO_Z();

  /* Start for MATLABSystem: '<Root>/   1' incorporates:
   *  MATLABSystem: '<Root>/   1'
   */
  rtb_Sum1 = GET_DESIRED_YAW_RATE();
  varargout_1 = GET_DESIRED_THROTLE();
  varargout_4 = GET_DESIRED_ROLL();
  varargout_3 = GET_DESIRED_PITCH();

  /* Gain: '<Root>/Gain2' incorporates:
   *  MATLABSystem: '<Root>/   1'
   *  Start for MATLABSystem: '<Root>/   1'
   */
  rtb_Gain2 = 7.0 * rtb_Sum1;

  /* Start for MATLABSystem: '<Root>/   ' incorporates:
   *  MATLABSystem: '<Root>/   '
   */
  varargout_1_0 = GET_ACCEL_X();
  rtb_Sum1 = GET_ACCEL_Y();
  GET_ACCEL_Z();

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain3'
   *  MATLABSystem: '<Root>/   '
   *  Start for MATLABSystem: '<Root>/   '
   *  MATLABSystem: '<Root>/   1'
   *  Start for MATLABSystem: '<Root>/   1'
   */
  rtb_Sum = varargout_3 - 900.0 * varargout_1_0;

  /* Gain: '<S1>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S1>/Filter'
   *  Gain: '<S1>/Derivative Gain'
   *  Sum: '<S1>/SumD'
   */
  rtB.FilterCoefficient = (0.1 * rtb_Sum - rtDW.Filter_DSTATE) * 3.0;

  /* Sum: '<S1>/Sum' */
  rtb_Sum_n = rtb_Sum + rtB.FilterCoefficient;

  /* Gain: '<Root>/Gain4' */
  rtb_Gain4 = 7.0 * rtb_Sum_n;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Gain5'
   *  MATLABSystem: '<Root>/   '
   *  Start for MATLABSystem: '<Root>/   '
   *  MATLABSystem: '<Root>/   1'
   *  Start for MATLABSystem: '<Root>/   1'
   */
  rtb_Sum1 = varargout_4 - -900.0 * rtb_Sum1;

  /* Gain: '<S2>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S2>/Filter'
   *  Gain: '<S2>/Derivative Gain'
   *  Sum: '<S2>/SumD'
   */
  rtB.FilterCoefficient_p = (0.1 * rtb_Sum1 - rtDW.Filter_DSTATE_f) * 3.0;

  /* Gain: '<Root>/Gain6' incorporates:
   *  Sum: '<S2>/Sum'
   */
  rtb_Sum1 = (rtb_Sum1 + rtB.FilterCoefficient_p) * 7.0;

  /* Start for MATLABSystem: '<Root>/   2' incorporates:
   *  MATLABSystem: '<Root>/   2'
   */
  SET_YAW_RATE_TARGET(rtb_Gain2);
  SET_PITCH_RATE_TARGET(rtb_Gain4);
  SET_ROLL_RATE_TARGET(rtb_Sum1);

  /* Start for MATLABSystem: '<Root>/   3' incorporates:
   *  MATLABSystem: '<Root>/   1'
   *  Start for MATLABSystem: '<Root>/   1'
   *  MATLABSystem: '<Root>/   3'
   */
  if (varargout_1 >= 0.0) {
    copter.motors.set_throttle(varargout_1);
  }

  /* End of Start for MATLABSystem: '<Root>/   3' */

  /* Logic: '<S3>/Logical Operator' incorporates:
   *  Constant: '<S9>/Lower Limit'
   *  Constant: '<S9>/Upper Limit'
   *  Logic: '<S9>/AND'
   *  MATLABSystem: '<Root>/   1'
   *  Start for MATLABSystem: '<Root>/   1'
   *  RelationalOperator: '<S9>/Lower Test'
   *  RelationalOperator: '<S9>/Upper Test'
   */
  rtb_LogicalOperator = !((1000.0 <= varargout_1) && (varargout_1 <= 0.0));

  /* Outputs for Triggered SubSystem: '<S3>/Send Throttle Oout-of-range message' incorporates:
   *  TriggerPort: '<S10>/Trigger'
   */
  if (rtb_LogicalOperator && (rtPrevZCX.SendThrottleOoutofrangemessage_ !=
       POS_ZCSIG)) {
    /* Start for MATLABSystem: '<S10>/Mavling Message Sender' incorporates:
     *  MATLABSystem: '<Root>/   1'
     *  Start for MATLABSystem: '<Root>/   1'
     *  MATLABSystem: '<S10>/Mavling Message Sender'
     */
    if (rtDW.obj_dw.TunablePropsChanged) {
      rtDW.obj_dw.TunablePropsChanged = false;
      rtDW.obj_dw.tunablePropertyChanged = false;
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
      tmp_3[i] = rtDW.obj_dw.Message[i];
    }

    tmp_3[29] = ':';
    tmp_3[30] = ' ';
    tmp_3[31] = '%';
    tmp_3[32] = 'f';
    tmp_3[33] = '\x00';
    sprintf(str, tmp_3, varargout_1);
    copter.gcs_send_text(f, str);

    /* End of Start for MATLABSystem: '<S10>/Mavling Message Sender' */
  }

  rtPrevZCX.SendThrottleOoutofrangemessage_ = (uint8_T)(rtb_LogicalOperator ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* End of Outputs for SubSystem: '<S3>/Send Throttle Oout-of-range message' */

  /* UnitDelay: '<S11>/Output' */
  rtb_Output = rtDW.Output_DSTATE;

  /* Outputs for Triggered SubSystem: '<S4>/Send Throttle Oout-of-range message3' incorporates:
   *  TriggerPort: '<S12>/Trigger'
   */
  if ((rtDW.Output_DSTATE > 0) && (rtPrevZCX.SendThrottleOoutofrangemessag_b !=
       POS_ZCSIG)) {
    /* Start for MATLABSystem: '<S12>/Mavling Message Sender' incorporates:
     *  MATLABSystem: '<Root>/   1'
     *  Start for MATLABSystem: '<Root>/   1'
     *  MATLABSystem: '<S12>/Mavling Message Sender'
     */
    if (rtDW.obj_nl.TunablePropsChanged) {
      rtDW.obj_nl.TunablePropsChanged = false;
      rtDW.obj_nl.tunablePropertyChanged = false;
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

    for (i = 0; i < 9; i++) {
      tmp_2[i] = rtDW.obj_nl.Message[i];
    }

    tmp_2[9] = ':';
    tmp_2[10] = ' ';
    tmp_2[11] = '%';
    tmp_2[12] = 'f';
    tmp_2[13] = '\x00';
    sprintf(str, tmp_2, varargout_3);
    copter.gcs_send_text(f, str);

    /* End of Start for MATLABSystem: '<S12>/Mavling Message Sender' */
  }

  /* End of UnitDelay: '<S11>/Output' */
  rtPrevZCX.SendThrottleOoutofrangemessag_b = (uint8_T)(rtb_Output > 0 ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* End of Outputs for SubSystem: '<S4>/Send Throttle Oout-of-range message3' */

  /* Sum: '<S13>/FixPt Sum1' incorporates:
   *  Constant: '<S13>/FixPt Constant'
   */
  rtb_Output++;

  /* Switch: '<S14>/FixPt Switch' incorporates:
   *  Constant: '<S14>/Constant'
   */
  if (rtb_Output > 400) {
    rtB.FixPtSwitch = 0U;
  } else {
    rtB.FixPtSwitch = rtb_Output;
  }

  /* End of Switch: '<S14>/FixPt Switch' */

  /* UnitDelay: '<S15>/Output' */
  rtb_Output = rtDW.Output_DSTATE_c;

  /* Outputs for Triggered SubSystem: '<S5>/Send Throttle Oout-of-range message3' incorporates:
   *  TriggerPort: '<S16>/Trigger'
   */
  if ((rtDW.Output_DSTATE_c > 0) && (rtPrevZCX.SendThrottleOoutofrangemessag_p
       != POS_ZCSIG)) {
    /* Start for MATLABSystem: '<S16>/Mavling Message Sender' incorporates:
     *  MATLABSystem: '<S16>/Mavling Message Sender'
     */
    if (rtDW.obj_n.TunablePropsChanged) {
      rtDW.obj_n.TunablePropsChanged = false;
      rtDW.obj_n.tunablePropertyChanged = false;
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
      tmp_1[i] = rtDW.obj_n.Message[i];
    }

    tmp_1[17] = ':';
    tmp_1[18] = ' ';
    tmp_1[19] = '%';
    tmp_1[20] = 'f';
    tmp_1[21] = '\x00';
    sprintf(str, tmp_1, rtb_Gain4);
    copter.gcs_send_text(f, str);

    /* End of Start for MATLABSystem: '<S16>/Mavling Message Sender' */
  }

  /* End of UnitDelay: '<S15>/Output' */
  rtPrevZCX.SendThrottleOoutofrangemessag_p = (uint8_T)(rtb_Output > 0 ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* End of Outputs for SubSystem: '<S5>/Send Throttle Oout-of-range message3' */

  /* Sum: '<S17>/FixPt Sum1' incorporates:
   *  Constant: '<S17>/FixPt Constant'
   */
  rtb_Output++;

  /* Switch: '<S18>/FixPt Switch' incorporates:
   *  Constant: '<S18>/Constant'
   */
  if (rtb_Output > 400) {
    rtB.FixPtSwitch_i = 0U;
  } else {
    rtB.FixPtSwitch_i = rtb_Output;
  }

  /* End of Switch: '<S18>/FixPt Switch' */

  /* UnitDelay: '<S19>/Output' */
  rtb_Output = rtDW.Output_DSTATE_a;

  /* Outputs for Triggered SubSystem: '<S6>/Send Throttle Oout-of-range message3' incorporates:
   *  TriggerPort: '<S20>/Trigger'
   */
  if ((rtDW.Output_DSTATE_a > 0) && (rtPrevZCX.SendThrottleOoutofrangemessag_n
       != POS_ZCSIG)) {
    /* Start for MATLABSystem: '<S20>/Mavling Message Sender' incorporates:
     *  MATLABSystem: '<Root>/   '
     *  Start for MATLABSystem: '<Root>/   '
     *  MATLABSystem: '<S20>/Mavling Message Sender'
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

    for (i = 0; i < 9; i++) {
      tmp_2[i] = rtDW.obj_d.Message[i];
    }

    tmp_2[9] = ':';
    tmp_2[10] = ' ';
    tmp_2[11] = '%';
    tmp_2[12] = 'f';
    tmp_2[13] = '\x00';
    sprintf(str, tmp_2, varargout_1_0);
    copter.gcs_send_text(f, str);

    /* End of Start for MATLABSystem: '<S20>/Mavling Message Sender' */
  }

  /* End of UnitDelay: '<S19>/Output' */
  rtPrevZCX.SendThrottleOoutofrangemessag_n = (uint8_T)(rtb_Output > 0 ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* End of Outputs for SubSystem: '<S6>/Send Throttle Oout-of-range message3' */

  /* Sum: '<S21>/FixPt Sum1' incorporates:
   *  Constant: '<S21>/FixPt Constant'
   */
  rtb_Output++;

  /* Switch: '<S22>/FixPt Switch' incorporates:
   *  Constant: '<S22>/Constant'
   */
  if (rtb_Output > 400) {
    rtB.FixPtSwitch_c = 0U;
  } else {
    rtB.FixPtSwitch_c = rtb_Output;
  }

  /* End of Switch: '<S22>/FixPt Switch' */

  /* UnitDelay: '<S23>/Output' */
  rtb_Output = rtDW.Output_DSTATE_j;

  /* Outputs for Triggered SubSystem: '<S7>/Send Throttle Oout-of-range message3' incorporates:
   *  TriggerPort: '<S24>/Trigger'
   */
  if ((rtDW.Output_DSTATE_j > 0) && (rtPrevZCX.SendThrottleOoutofrangemessag_j
       != POS_ZCSIG)) {
    /* Start for MATLABSystem: '<S24>/Mavling Message Sender' incorporates:
     *  MATLABSystem: '<S24>/Mavling Message Sender'
     */
    if (rtDW.obj_m.TunablePropsChanged) {
      rtDW.obj_m.TunablePropsChanged = false;
      rtDW.obj_m.tunablePropertyChanged = false;
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

    for (i = 0; i < 10; i++) {
      tmp_0[i] = rtDW.obj_m.Message[i];
    }

    tmp_0[10] = ':';
    tmp_0[11] = ' ';
    tmp_0[12] = '%';
    tmp_0[13] = 'f';
    tmp_0[14] = '\x00';
    sprintf(str, tmp_0, rtb_Sum);
    copter.gcs_send_text(f, str);

    /* End of Start for MATLABSystem: '<S24>/Mavling Message Sender' */
  }

  /* End of UnitDelay: '<S23>/Output' */
  rtPrevZCX.SendThrottleOoutofrangemessag_j = (uint8_T)(rtb_Output > 0 ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* End of Outputs for SubSystem: '<S7>/Send Throttle Oout-of-range message3' */

  /* Sum: '<S25>/FixPt Sum1' incorporates:
   *  Constant: '<S25>/FixPt Constant'
   */
  rtb_Output++;

  /* Switch: '<S26>/FixPt Switch' incorporates:
   *  Constant: '<S26>/Constant'
   */
  if (rtb_Output > 400) {
    rtB.FixPtSwitch_l = 0U;
  } else {
    rtB.FixPtSwitch_l = rtb_Output;
  }

  /* End of Switch: '<S26>/FixPt Switch' */

  /* UnitDelay: '<S27>/Output' */
  rtb_Output = rtDW.Output_DSTATE_cf;

  /* Outputs for Triggered SubSystem: '<S8>/Send Throttle Oout-of-range message3' incorporates:
   *  TriggerPort: '<S28>/Trigger'
   */
  if ((rtDW.Output_DSTATE_cf > 0) && (rtPrevZCX.SendThrottleOoutofrangemessage3
       != POS_ZCSIG)) {
    /* Start for MATLABSystem: '<S28>/Mavling Message Sender' incorporates:
     *  MATLABSystem: '<S28>/Mavling Message Sender'
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

    for (i = 0; i < 11; i++) {
      tmp[i] = rtDW.obj.Message[i];
    }

    tmp[11] = ':';
    tmp[12] = ' ';
    tmp[13] = '%';
    tmp[14] = 'f';
    tmp[15] = '\x00';
    sprintf(str, tmp, rtb_Sum_n);
    copter.gcs_send_text(f, str);

    /* End of Start for MATLABSystem: '<S28>/Mavling Message Sender' */
  }

  /* End of UnitDelay: '<S27>/Output' */
  rtPrevZCX.SendThrottleOoutofrangemessage3 = (uint8_T)(rtb_Output > 0 ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* End of Outputs for SubSystem: '<S8>/Send Throttle Oout-of-range message3' */

  /* Sum: '<S29>/FixPt Sum1' incorporates:
   *  Constant: '<S29>/FixPt Constant'
   */
  rtb_Output++;

  /* Switch: '<S30>/FixPt Switch' incorporates:
   *  Constant: '<S30>/Constant'
   */
  if (rtb_Output > 400) {
    rtB.FixPtSwitch_g = 0U;
  } else {
    rtB.FixPtSwitch_g = rtb_Output;
  }

  /* End of Switch: '<S30>/FixPt Switch' */
}

/* Model update function */
void ModelD_update(void)
{
  /* Update for DiscreteIntegrator: '<S1>/Filter' */
  rtDW.Filter_DSTATE += 0.2 * rtB.FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S2>/Filter' */
  rtDW.Filter_DSTATE_f += 0.2 * rtB.FilterCoefficient_p;

  /* Update for UnitDelay: '<S11>/Output' */
  rtDW.Output_DSTATE = rtB.FixPtSwitch;

  /* Update for UnitDelay: '<S15>/Output' */
  rtDW.Output_DSTATE_c = rtB.FixPtSwitch_i;

  /* Update for UnitDelay: '<S19>/Output' */
  rtDW.Output_DSTATE_a = rtB.FixPtSwitch_c;

  /* Update for UnitDelay: '<S23>/Output' */
  rtDW.Output_DSTATE_j = rtB.FixPtSwitch_l;

  /* Update for UnitDelay: '<S27>/Output' */
  rtDW.Output_DSTATE_cf = rtB.FixPtSwitch_g;
}

/* Model initialize function */
void ModelD_initialize(void)
{
  {
    boolean_T flag;
    static const char_T tmp[29] = { 't', 'h', 'r', 'o', 't', 't', 'l', 'e', ' ',
      'n', 'o', 't', ' ', 'b', 'e', 't', 'w', 'e', 'e', 'n', ' ', '0', ' ', 't',
      'o', ' ', '1', ':', ' ' };

    static const char_T tmp_0[9] = { 'r', 'c', ' ', 'p', 'i', 't', 'c', 'h', ':'
    };

    static const char_T tmp_1[17] = { 'r', 'a', 't', 'e', ' ', 'c', 'o', 'n',
      't', '.', ' ', 'p', 'i', 't', 'c', 'h', ':' };

    static const char_T tmp_2[9] = { 'A', 'c', 'c', 'e', 'l', '.', ' ', 'x', ':'
    };

    static const char_T tmp_3[10] = { 'b', 'e', 'f', 'o', 'r', ' ', 'P', 'I',
      'D', ':' };

    static const char_T tmp_4[11] = { 'A', 'f', 't', 'e', 'r', ' ', 'P', 'I',
      'D', ':', ' ' };

    int32_T i;

    /* Start for MATLABSystem: '<Root>/  ' */
    rtDW.obj_l.isInitialized = false;
    rtDW.obj_l.isReleased = false;
    rtDW.objisempty_d = true;
    rtDW.obj_l.isInitialized = true;

    /* Start for MATLABSystem: '<Root>/   1' */
    rtDW.obj_j.isInitialized = false;
    rtDW.obj_j.isReleased = false;
    rtDW.objisempty_b = true;
    rtDW.obj_j.isInitialized = true;

    /* Start for MATLABSystem: '<Root>/   ' */
    rtDW.obj_no.isInitialized = false;
    rtDW.obj_no.isReleased = false;
    rtDW.objisempty_bi = true;
    rtDW.obj_no.isInitialized = true;

    /* Start for MATLABSystem: '<Root>/   2' */
    rtDW.obj_h.isInitialized = false;
    rtDW.obj_h.isReleased = false;
    rtDW.objisempty_e = true;
    rtDW.obj_h.isInitialized = true;

    /* Start for MATLABSystem: '<Root>/   3' */
    rtDW.obj_k.isInitialized = false;
    rtDW.obj_k.isReleased = false;
    rtDW.objisempty_du = true;
    rtDW.obj_k.isInitialized = true;

    /* Start for Triggered SubSystem: '<S3>/Send Throttle Oout-of-range message' */
    /* Start for MATLABSystem: '<S10>/Mavling Message Sender' */
    rtDW.obj_dw.isInitialized = false;
    rtDW.obj_dw.isReleased = false;
    rtDW.obj_dw.tunablePropertyChanged = false;
    rtDW.objisempty_a = true;
    if (rtDW.obj_dw.isInitialized && (!rtDW.obj_dw.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      rtDW.obj_dw.TunablePropsChanged = true;
    }

    for (i = 0; i < 29; i++) {
      rtDW.obj_dw.Message[i] = tmp[i];
    }

    if (rtDW.obj_dw.isInitialized && (!rtDW.obj_dw.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      rtDW.obj_dw.TunablePropsChanged = true;
      rtDW.obj_dw.tunablePropertyChanged = true;
    }

    rtDW.obj_dw.isInitialized = true;
    rtDW.obj_dw.TunablePropsChanged = false;

    /* End of Start for MATLABSystem: '<S10>/Mavling Message Sender' */
    /* End of Start for SubSystem: '<S3>/Send Throttle Oout-of-range message' */

    /* Start for Triggered SubSystem: '<S4>/Send Throttle Oout-of-range message3' */
    /* Start for MATLABSystem: '<S12>/Mavling Message Sender' */
    rtDW.obj_nl.isInitialized = false;
    rtDW.obj_nl.isReleased = false;
    rtDW.obj_nl.tunablePropertyChanged = false;
    rtDW.objisempty_m = true;
    if (rtDW.obj_nl.isInitialized && (!rtDW.obj_nl.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      rtDW.obj_nl.TunablePropsChanged = true;
    }

    for (i = 0; i < 9; i++) {
      rtDW.obj_nl.Message[i] = tmp_0[i];
    }

    if (rtDW.obj_nl.isInitialized && (!rtDW.obj_nl.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      rtDW.obj_nl.TunablePropsChanged = true;
      rtDW.obj_nl.tunablePropertyChanged = true;
    }

    rtDW.obj_nl.isInitialized = true;
    rtDW.obj_nl.TunablePropsChanged = false;

    /* End of Start for MATLABSystem: '<S12>/Mavling Message Sender' */
    /* End of Start for SubSystem: '<S4>/Send Throttle Oout-of-range message3' */

    /* Start for Triggered SubSystem: '<S5>/Send Throttle Oout-of-range message3' */
    /* Start for MATLABSystem: '<S16>/Mavling Message Sender' */
    rtDW.obj_n.isInitialized = false;
    rtDW.obj_n.isReleased = false;
    rtDW.obj_n.tunablePropertyChanged = false;
    rtDW.objisempty_i = true;
    if (rtDW.obj_n.isInitialized && (!rtDW.obj_n.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      rtDW.obj_n.TunablePropsChanged = true;
    }

    for (i = 0; i < 17; i++) {
      rtDW.obj_n.Message[i] = tmp_1[i];
    }

    if (rtDW.obj_n.isInitialized && (!rtDW.obj_n.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      rtDW.obj_n.TunablePropsChanged = true;
      rtDW.obj_n.tunablePropertyChanged = true;
    }

    rtDW.obj_n.isInitialized = true;
    rtDW.obj_n.TunablePropsChanged = false;

    /* End of Start for MATLABSystem: '<S16>/Mavling Message Sender' */
    /* End of Start for SubSystem: '<S5>/Send Throttle Oout-of-range message3' */

    /* Start for Triggered SubSystem: '<S6>/Send Throttle Oout-of-range message3' */
    /* Start for MATLABSystem: '<S20>/Mavling Message Sender' */
    rtDW.obj_d.isInitialized = false;
    rtDW.obj_d.isReleased = false;
    rtDW.obj_d.tunablePropertyChanged = false;
    rtDW.objisempty_k = true;
    if (rtDW.obj_d.isInitialized && (!rtDW.obj_d.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      rtDW.obj_d.TunablePropsChanged = true;
    }

    for (i = 0; i < 9; i++) {
      rtDW.obj_d.Message[i] = tmp_2[i];
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

    /* End of Start for MATLABSystem: '<S20>/Mavling Message Sender' */
    /* End of Start for SubSystem: '<S6>/Send Throttle Oout-of-range message3' */

    /* Start for Triggered SubSystem: '<S7>/Send Throttle Oout-of-range message3' */
    /* Start for MATLABSystem: '<S24>/Mavling Message Sender' */
    rtDW.obj_m.isInitialized = false;
    rtDW.obj_m.isReleased = false;
    rtDW.obj_m.tunablePropertyChanged = false;
    rtDW.objisempty_h = true;
    if (rtDW.obj_m.isInitialized && (!rtDW.obj_m.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      rtDW.obj_m.TunablePropsChanged = true;
    }

    for (i = 0; i < 10; i++) {
      rtDW.obj_m.Message[i] = tmp_3[i];
    }

    if (rtDW.obj_m.isInitialized && (!rtDW.obj_m.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      rtDW.obj_m.TunablePropsChanged = true;
      rtDW.obj_m.tunablePropertyChanged = true;
    }

    rtDW.obj_m.isInitialized = true;
    rtDW.obj_m.TunablePropsChanged = false;

    /* End of Start for MATLABSystem: '<S24>/Mavling Message Sender' */
    /* End of Start for SubSystem: '<S7>/Send Throttle Oout-of-range message3' */

    /* Start for Triggered SubSystem: '<S8>/Send Throttle Oout-of-range message3' */
    /* Start for MATLABSystem: '<S28>/Mavling Message Sender' */
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

    for (i = 0; i < 11; i++) {
      rtDW.obj.Message[i] = tmp_4[i];
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

    /* End of Start for MATLABSystem: '<S28>/Mavling Message Sender' */
    /* End of Start for SubSystem: '<S8>/Send Throttle Oout-of-range message3' */
  }

  rtPrevZCX.SendThrottleOoutofrangemessage3 = POS_ZCSIG;
  rtPrevZCX.SendThrottleOoutofrangemessag_j = POS_ZCSIG;
  rtPrevZCX.SendThrottleOoutofrangemessag_n = POS_ZCSIG;
  rtPrevZCX.SendThrottleOoutofrangemessag_p = POS_ZCSIG;
  rtPrevZCX.SendThrottleOoutofrangemessag_b = POS_ZCSIG;
  rtPrevZCX.SendThrottleOoutofrangemessage_ = POS_ZCSIG;
}

/* Model terminate function */
void ModelD_terminate(void)
{
  boolean_T flag;
  static const char_T tmp[29] = { 't', 'h', 'r', 'o', 't', 't', 'l', 'e', ' ',
    'n', 'o', 't', ' ', 'b', 'e', 't', 'w', 'e', 'e', 'n', ' ', '0', ' ', 't',
    'o', ' ', '1', ':', ' ' };

  static const char_T tmp_0[9] = { 'r', 'c', ' ', 'p', 'i', 't', 'c', 'h', ':' };

  static const char_T tmp_1[17] = { 'r', 'a', 't', 'e', ' ', 'c', 'o', 'n', 't',
    '.', ' ', 'p', 'i', 't', 'c', 'h', ':' };

  static const char_T tmp_2[9] = { 'A', 'c', 'c', 'e', 'l', '.', ' ', 'x', ':' };

  static const char_T tmp_3[10] = { 'b', 'e', 'f', 'o', 'r', ' ', 'P', 'I', 'D',
    ':' };

  static const char_T tmp_4[11] = { 'A', 'f', 't', 'e', 'r', ' ', 'P', 'I', 'D',
    ':', ' ' };

  int32_T i;

  /* Start for MATLABSystem: '<Root>/  ' incorporates:
   *  Terminate for MATLABSystem: '<Root>/  '
   */
  rtDW.obj_l.isInitialized = false;
  rtDW.obj_l.isReleased = false;
  rtDW.objisempty_d = true;
  if (rtDW.obj_l.isInitialized) {
    rtDW.obj_l.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/  ' */

  /* Start for MATLABSystem: '<Root>/   1' incorporates:
   *  Terminate for MATLABSystem: '<Root>/   1'
   */
  rtDW.obj_j.isInitialized = false;
  rtDW.obj_j.isReleased = false;
  rtDW.objisempty_b = true;
  if (rtDW.obj_j.isInitialized) {
    rtDW.obj_j.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/   1' */

  /* Start for MATLABSystem: '<Root>/   ' incorporates:
   *  Terminate for MATLABSystem: '<Root>/   '
   */
  rtDW.obj_no.isInitialized = false;
  rtDW.obj_no.isReleased = false;
  rtDW.objisempty_bi = true;
  if (rtDW.obj_no.isInitialized) {
    rtDW.obj_no.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/   ' */

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

  /* Start for MATLABSystem: '<Root>/   3' incorporates:
   *  Terminate for MATLABSystem: '<Root>/   3'
   */
  rtDW.obj_k.isInitialized = false;
  rtDW.obj_k.isReleased = false;
  rtDW.objisempty_du = true;
  if (rtDW.obj_k.isInitialized) {
    rtDW.obj_k.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/   3' */

  /* Terminate for Triggered SubSystem: '<S3>/Send Throttle Oout-of-range message' */
  /* Start for MATLABSystem: '<S10>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S10>/Mavling Message Sender'
   */
  rtDW.obj_dw.isInitialized = false;
  rtDW.obj_dw.isReleased = false;
  rtDW.obj_dw.tunablePropertyChanged = false;
  rtDW.objisempty_a = true;
  if (rtDW.obj_dw.isInitialized && (!rtDW.obj_dw.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    rtDW.obj_dw.TunablePropsChanged = true;
  }

  /* Terminate for MATLABSystem: '<S10>/Mavling Message Sender' incorporates:
   *  Start for MATLABSystem: '<S10>/Mavling Message Sender'
   */
  for (i = 0; i < 29; i++) {
    rtDW.obj_dw.Message[i] = tmp[i];
  }

  /* Start for MATLABSystem: '<S10>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S10>/Mavling Message Sender'
   */
  if (rtDW.obj_dw.isInitialized && (!rtDW.obj_dw.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    rtDW.obj_dw.TunablePropsChanged = true;
    rtDW.obj_dw.tunablePropertyChanged = true;
  }

  if (rtDW.obj_dw.isInitialized) {
    rtDW.obj_dw.isReleased = true;
  }

  /* End of Terminate for SubSystem: '<S3>/Send Throttle Oout-of-range message' */

  /* Terminate for Triggered SubSystem: '<S4>/Send Throttle Oout-of-range message3' */
  /* Start for MATLABSystem: '<S12>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S12>/Mavling Message Sender'
   */
  rtDW.obj_nl.isInitialized = false;
  rtDW.obj_nl.isReleased = false;
  rtDW.obj_nl.tunablePropertyChanged = false;
  rtDW.objisempty_m = true;
  if (rtDW.obj_nl.isInitialized && (!rtDW.obj_nl.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    rtDW.obj_nl.TunablePropsChanged = true;
  }

  /* Terminate for MATLABSystem: '<S12>/Mavling Message Sender' incorporates:
   *  Start for MATLABSystem: '<S12>/Mavling Message Sender'
   */
  for (i = 0; i < 9; i++) {
    rtDW.obj_nl.Message[i] = tmp_0[i];
  }

  /* Start for MATLABSystem: '<S12>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S12>/Mavling Message Sender'
   */
  if (rtDW.obj_nl.isInitialized && (!rtDW.obj_nl.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    rtDW.obj_nl.TunablePropsChanged = true;
    rtDW.obj_nl.tunablePropertyChanged = true;
  }

  if (rtDW.obj_nl.isInitialized) {
    rtDW.obj_nl.isReleased = true;
  }

  /* End of Terminate for SubSystem: '<S4>/Send Throttle Oout-of-range message3' */

  /* Terminate for Triggered SubSystem: '<S5>/Send Throttle Oout-of-range message3' */
  /* Start for MATLABSystem: '<S16>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S16>/Mavling Message Sender'
   */
  rtDW.obj_n.isInitialized = false;
  rtDW.obj_n.isReleased = false;
  rtDW.obj_n.tunablePropertyChanged = false;
  rtDW.objisempty_i = true;
  if (rtDW.obj_n.isInitialized && (!rtDW.obj_n.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    rtDW.obj_n.TunablePropsChanged = true;
  }

  /* Terminate for MATLABSystem: '<S16>/Mavling Message Sender' incorporates:
   *  Start for MATLABSystem: '<S16>/Mavling Message Sender'
   */
  for (i = 0; i < 17; i++) {
    rtDW.obj_n.Message[i] = tmp_1[i];
  }

  /* Start for MATLABSystem: '<S16>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S16>/Mavling Message Sender'
   */
  if (rtDW.obj_n.isInitialized && (!rtDW.obj_n.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    rtDW.obj_n.TunablePropsChanged = true;
    rtDW.obj_n.tunablePropertyChanged = true;
  }

  if (rtDW.obj_n.isInitialized) {
    rtDW.obj_n.isReleased = true;
  }

  /* End of Terminate for SubSystem: '<S5>/Send Throttle Oout-of-range message3' */

  /* Terminate for Triggered SubSystem: '<S6>/Send Throttle Oout-of-range message3' */
  /* Start for MATLABSystem: '<S20>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S20>/Mavling Message Sender'
   */
  rtDW.obj_d.isInitialized = false;
  rtDW.obj_d.isReleased = false;
  rtDW.obj_d.tunablePropertyChanged = false;
  rtDW.objisempty_k = true;
  if (rtDW.obj_d.isInitialized && (!rtDW.obj_d.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    rtDW.obj_d.TunablePropsChanged = true;
  }

  /* Terminate for MATLABSystem: '<S20>/Mavling Message Sender' incorporates:
   *  Start for MATLABSystem: '<S20>/Mavling Message Sender'
   */
  for (i = 0; i < 9; i++) {
    rtDW.obj_d.Message[i] = tmp_2[i];
  }

  /* Start for MATLABSystem: '<S20>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S20>/Mavling Message Sender'
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

  /* End of Terminate for SubSystem: '<S6>/Send Throttle Oout-of-range message3' */

  /* Terminate for Triggered SubSystem: '<S7>/Send Throttle Oout-of-range message3' */
  /* Start for MATLABSystem: '<S24>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S24>/Mavling Message Sender'
   */
  rtDW.obj_m.isInitialized = false;
  rtDW.obj_m.isReleased = false;
  rtDW.obj_m.tunablePropertyChanged = false;
  rtDW.objisempty_h = true;
  if (rtDW.obj_m.isInitialized && (!rtDW.obj_m.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    rtDW.obj_m.TunablePropsChanged = true;
  }

  /* Terminate for MATLABSystem: '<S24>/Mavling Message Sender' incorporates:
   *  Start for MATLABSystem: '<S24>/Mavling Message Sender'
   */
  for (i = 0; i < 10; i++) {
    rtDW.obj_m.Message[i] = tmp_3[i];
  }

  /* Start for MATLABSystem: '<S24>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S24>/Mavling Message Sender'
   */
  if (rtDW.obj_m.isInitialized && (!rtDW.obj_m.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    rtDW.obj_m.TunablePropsChanged = true;
    rtDW.obj_m.tunablePropertyChanged = true;
  }

  if (rtDW.obj_m.isInitialized) {
    rtDW.obj_m.isReleased = true;
  }

  /* End of Terminate for SubSystem: '<S7>/Send Throttle Oout-of-range message3' */

  /* Terminate for Triggered SubSystem: '<S8>/Send Throttle Oout-of-range message3' */
  /* Start for MATLABSystem: '<S28>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S28>/Mavling Message Sender'
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

  /* Terminate for MATLABSystem: '<S28>/Mavling Message Sender' incorporates:
   *  Start for MATLABSystem: '<S28>/Mavling Message Sender'
   */
  for (i = 0; i < 11; i++) {
    rtDW.obj.Message[i] = tmp_4[i];
  }

  /* Start for MATLABSystem: '<S28>/Mavling Message Sender' incorporates:
   *  Terminate for MATLABSystem: '<S28>/Mavling Message Sender'
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

  /* End of Terminate for SubSystem: '<S8>/Send Throttle Oout-of-range message3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
