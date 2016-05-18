/*
 * File: ModelC.c
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

#include "ModelC.h"
#include "ModelC_private.h"

/* Block states (auto storage) */
DW_ModelC_T ModelC_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ModelC_T ModelC_PrevZCX;

/* Real-time model */
RT_MODEL_ModelC_T ModelC_M_;
RT_MODEL_ModelC_T *const ModelC_M = &ModelC_M_;

/* Model output function */
void ModelC_output(void)
{
  real_T varargout_4;
  real_T varargout_3;
  real_T varargout_2;
  real_T varargout_1;
  MAV_SEVERITY f;
  char_T str[100];
  boolean_T rtb_LogicalOperator;
  char_T tmp[34];
  int32_T i;

  /* Start for MATLABSystem: '<Root>/  ' incorporates:
   *  MATLABSystem: '<Root>/  '
   */
  GET_GYRO_X();
  GET_GYRO_Y();
  GET_GYRO_Z();

  /* Start for MATLABSystem: '<Root>/   ' incorporates:
   *  MATLABSystem: '<Root>/   '
   */
  GET_ACCEL_X();
  GET_ACCEL_Y();
  GET_ACCEL_Z();

  /* Start for MATLABSystem: '<Root>/   1' incorporates:
   *  MATLABSystem: '<Root>/   1'
   */
  varargout_2 = GET_DESIRED_YAW_RATE();
  varargout_1 = GET_DESIRED_THROTLE();
  varargout_4 = GET_DESIRED_ROLL();
  varargout_3 = GET_DESIRED_PITCH();

  /* Start for MATLABSystem: '<Root>/   2' incorporates:
   *  MATLABSystem: '<Root>/   1'
   *  Start for MATLABSystem: '<Root>/   1'
   *  MATLABSystem: '<Root>/   2'
   */
  SET_YAW_RATE_TARGET(varargout_2);
  SET_PITCH_RATE_TARGET(varargout_3);
  SET_ROLL_RATE_TARGET(varargout_4);

  /* Start for MATLABSystem: '<Root>/   3' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLABSystem: '<Root>/   1'
   *  Start for MATLABSystem: '<Root>/   1'
   *  MATLABSystem: '<Root>/   3'
   */
  varargout_2 = ModelC_P.Constant_Value;
  varargout_4 = ModelC_P.Constant_Value;
  if ((ModelC_P.Constant_Value >= -1.0) && (ModelC_P.Constant_Value <= 1.0)) {
    copter.motors.set_roll(ModelC_P.Constant_Value);
  }

  if ((varargout_2 >= -1.0) && (varargout_2 <= 1.0)) {
    copter.motors.set_pitch(varargout_2);
  }

  if ((varargout_4 >= -1.0) && (varargout_4 <= 1.0)) {
    copter.motors.set_yaw(varargout_4);
  }

  if ((varargout_1 >= 0.0) && (varargout_4 <= 1.0)) {
    copter.motors.set_throttle(varargout_1);
  }

  /* End of Start for MATLABSystem: '<Root>/   3' */

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S2>/Lower Limit'
   *  Constant: '<S2>/Upper Limit'
   *  Logic: '<S2>/AND'
   *  MATLABSystem: '<Root>/   1'
   *  Start for MATLABSystem: '<Root>/   1'
   *  RelationalOperator: '<S2>/Lower Test'
   *  RelationalOperator: '<S2>/Upper Test'
   */
  rtb_LogicalOperator = !((ModelC_P.IntervalTest_lowlimit <= varargout_1) &&
    (varargout_1 <= ModelC_P.IntervalTest_uplimit));

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  if (rtb_LogicalOperator && (ModelC_PrevZCX.TriggeredSubsystem_Trig_ZCE !=
       POS_ZCSIG)) {
    /* Start for MATLABSystem: '<S3>/MATLAB System' incorporates:
     *  MATLABSystem: '<Root>/   1'
     *  Start for MATLABSystem: '<Root>/   1'
     *  MATLABSystem: '<S3>/MATLAB System'
     */
    if (ModelC_DW.obj.TunablePropsChanged) {
      ModelC_DW.obj.TunablePropsChanged = false;
      ModelC_DW.obj.tunablePropertyChanged = false;
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
      tmp[i] = ModelC_DW.obj.Message[i];
    }

    tmp[29] = ':';
    tmp[30] = ' ';
    tmp[31] = '%';
    tmp[32] = 'f';
    tmp[33] = '\x00';
    sprintf(str, tmp, varargout_1);
    copter.gcs_send_text(f, str);

    /* End of Start for MATLABSystem: '<S3>/MATLAB System' */
  }

  ModelC_PrevZCX.TriggeredSubsystem_Trig_ZCE = (uint8_T)(rtb_LogicalOperator ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem' */
}

/* Model update function */
void ModelC_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void ModelC_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  ModelC_P.Constant_Value = rtMinusInf;

  /* initialize error status */
  rtmSetErrorStatus(ModelC_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&ModelC_DW, 0,
                sizeof(DW_ModelC_T));

  {
    boolean_T flag;
    static const char_T tmp[29] = { 't', 'h', 'r', 'o', 't', 't', 'l', 'e', ' ',
      'n', 'o', 't', ' ', 'b', 'e', 't', 'w', 'e', 'e', 'n', ' ', '0', ' ', 't',
      'o', ' ', '1', ':', ' ' };

    int32_T i;

    /* Start for MATLABSystem: '<Root>/  ' */
    ModelC_DW.obj_l.isInitialized = false;
    ModelC_DW.obj_l.isReleased = false;
    ModelC_DW.objisempty_d = true;
    ModelC_DW.obj_l.isInitialized = true;

    /* Start for MATLABSystem: '<Root>/   ' */
    ModelC_DW.obj_n.isInitialized = false;
    ModelC_DW.obj_n.isReleased = false;
    ModelC_DW.objisempty_b = true;
    ModelC_DW.obj_n.isInitialized = true;

    /* Start for MATLABSystem: '<Root>/   1' */
    ModelC_DW.obj_j.isInitialized = false;
    ModelC_DW.obj_j.isReleased = false;
    ModelC_DW.objisempty_bp = true;
    ModelC_DW.obj_j.isInitialized = true;

    /* Start for MATLABSystem: '<Root>/   2' */
    ModelC_DW.obj_h.isInitialized = false;
    ModelC_DW.obj_h.isReleased = false;
    ModelC_DW.objisempty_e = true;
    ModelC_DW.obj_h.isInitialized = true;

    /* Start for MATLABSystem: '<Root>/   3' */
    ModelC_DW.obj_k.isInitialized = false;
    ModelC_DW.obj_k.isReleased = false;
    ModelC_DW.objisempty_du = true;
    ModelC_DW.obj_k.isInitialized = true;

    /* Start for Triggered SubSystem: '<S1>/Triggered Subsystem' */
    /* Start for MATLABSystem: '<S3>/MATLAB System' */
    ModelC_DW.obj.isInitialized = false;
    ModelC_DW.obj.isReleased = false;
    ModelC_DW.obj.tunablePropertyChanged = false;
    ModelC_DW.objisempty = true;
    if (ModelC_DW.obj.isInitialized && (!ModelC_DW.obj.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      ModelC_DW.obj.TunablePropsChanged = true;
    }

    for (i = 0; i < 29; i++) {
      ModelC_DW.obj.Message[i] = tmp[i];
    }

    if (ModelC_DW.obj.isInitialized && (!ModelC_DW.obj.isReleased)) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      ModelC_DW.obj.TunablePropsChanged = true;
      ModelC_DW.obj.tunablePropertyChanged = true;
    }

    ModelC_DW.obj.isInitialized = true;
    ModelC_DW.obj.TunablePropsChanged = false;

    /* End of Start for MATLABSystem: '<S3>/MATLAB System' */
    /* End of Start for SubSystem: '<S1>/Triggered Subsystem' */
  }

  ModelC_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;
}

/* Model terminate function */
void ModelC_terminate(void)
{
  boolean_T flag;
  static const char_T tmp[29] = { 't', 'h', 'r', 'o', 't', 't', 'l', 'e', ' ',
    'n', 'o', 't', ' ', 'b', 'e', 't', 'w', 'e', 'e', 'n', ' ', '0', ' ', 't',
    'o', ' ', '1', ':', ' ' };

  int32_T i;

  /* Start for MATLABSystem: '<Root>/  ' incorporates:
   *  Terminate for MATLABSystem: '<Root>/  '
   */
  ModelC_DW.obj_l.isInitialized = false;
  ModelC_DW.obj_l.isReleased = false;
  ModelC_DW.objisempty_d = true;
  if (ModelC_DW.obj_l.isInitialized) {
    ModelC_DW.obj_l.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/  ' */

  /* Start for MATLABSystem: '<Root>/   ' incorporates:
   *  Terminate for MATLABSystem: '<Root>/   '
   */
  ModelC_DW.obj_n.isInitialized = false;
  ModelC_DW.obj_n.isReleased = false;
  ModelC_DW.objisempty_b = true;
  if (ModelC_DW.obj_n.isInitialized) {
    ModelC_DW.obj_n.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/   ' */

  /* Start for MATLABSystem: '<Root>/   1' incorporates:
   *  Terminate for MATLABSystem: '<Root>/   1'
   */
  ModelC_DW.obj_j.isInitialized = false;
  ModelC_DW.obj_j.isReleased = false;
  ModelC_DW.objisempty_bp = true;
  if (ModelC_DW.obj_j.isInitialized) {
    ModelC_DW.obj_j.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/   1' */

  /* Start for MATLABSystem: '<Root>/   2' incorporates:
   *  Terminate for MATLABSystem: '<Root>/   2'
   */
  ModelC_DW.obj_h.isInitialized = false;
  ModelC_DW.obj_h.isReleased = false;
  ModelC_DW.objisempty_e = true;
  if (ModelC_DW.obj_h.isInitialized) {
    ModelC_DW.obj_h.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/   2' */

  /* Start for MATLABSystem: '<Root>/   3' incorporates:
   *  Terminate for MATLABSystem: '<Root>/   3'
   */
  ModelC_DW.obj_k.isInitialized = false;
  ModelC_DW.obj_k.isReleased = false;
  ModelC_DW.objisempty_du = true;
  if (ModelC_DW.obj_k.isInitialized) {
    ModelC_DW.obj_k.isReleased = true;
  }

  /* End of Start for MATLABSystem: '<Root>/   3' */

  /* Terminate for Triggered SubSystem: '<S1>/Triggered Subsystem' */
  /* Start for MATLABSystem: '<S3>/MATLAB System' incorporates:
   *  Terminate for MATLABSystem: '<S3>/MATLAB System'
   */
  ModelC_DW.obj.isInitialized = false;
  ModelC_DW.obj.isReleased = false;
  ModelC_DW.obj.tunablePropertyChanged = false;
  ModelC_DW.objisempty = true;
  if (ModelC_DW.obj.isInitialized && (!ModelC_DW.obj.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    ModelC_DW.obj.TunablePropsChanged = true;
  }

  /* Terminate for MATLABSystem: '<S3>/MATLAB System' incorporates:
   *  Start for MATLABSystem: '<S3>/MATLAB System'
   */
  for (i = 0; i < 29; i++) {
    ModelC_DW.obj.Message[i] = tmp[i];
  }

  /* Start for MATLABSystem: '<S3>/MATLAB System' incorporates:
   *  Terminate for MATLABSystem: '<S3>/MATLAB System'
   */
  if (ModelC_DW.obj.isInitialized && (!ModelC_DW.obj.isReleased)) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    ModelC_DW.obj.TunablePropsChanged = true;
    ModelC_DW.obj.tunablePropertyChanged = true;
  }

  if (ModelC_DW.obj.isInitialized) {
    ModelC_DW.obj.isReleased = true;
  }

  /* End of Terminate for SubSystem: '<S1>/Triggered Subsystem' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
