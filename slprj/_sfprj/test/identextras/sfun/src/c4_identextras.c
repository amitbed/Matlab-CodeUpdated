/* Include files */

#include <stddef.h>
#include "blas.h"
#include "identextras_sfun.h"
#include "c4_identextras.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "identextras_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[18] = { "algorithmParams", "nargin",
  "nargout", "uMeas", "yMeas", "isEnabled", "adg", "theta", "P", "phiMemory",
  "psiMemory", "A", "B", "estimationError", "thetaNew", "PNew", "phiMemoryNew",
  "psiMemoryNew" };

/* Function Declarations */
static void initialize_c4_identextras(SFc4_identextrasInstanceStruct
  *chartInstance);
static void initialize_params_c4_identextras(SFc4_identextrasInstanceStruct
  *chartInstance);
static void enable_c4_identextras(SFc4_identextrasInstanceStruct *chartInstance);
static void disable_c4_identextras(SFc4_identextrasInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_identextras
  (SFc4_identextrasInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_identextras
  (SFc4_identextrasInstanceStruct *chartInstance);
static void set_sim_state_c4_identextras(SFc4_identextrasInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_identextras(SFc4_identextrasInstanceStruct
  *chartInstance);
static void sf_gateway_c4_identextras(SFc4_identextrasInstanceStruct
  *chartInstance);
static void initSimStructsc4_identextras(SFc4_identextrasInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_emlrt_marshallOut(SFc4_identextrasInstanceStruct
  *chartInstance, const c4_s8I6VPw2Ssn0flwgyUaioQ c4_u);
static void c4_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_A, const char_T *c4_identifier, real_T c4_y[4]);
static void c4_b_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[4]);
static real_T c4_c_emlrt_marshallIn(SFc4_identextrasInstanceStruct
  *chartInstance, const mxArray *c4_estimationError, const char_T *c4_identifier);
static real_T c4_d_emlrt_marshallIn(SFc4_identextrasInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_PNew, const char_T *c4_identifier, real_T c4_y[16]);
static void c4_f_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[16]);
static void c4_g_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_phiMemoryNew, const char_T *c4_identifier, real_T c4_y[7]);
static void c4_h_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[7]);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_i_emlrt_marshallIn(SFc4_identextrasInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static c4_s8I6VPw2Ssn0flwgyUaioQ c4_j_emlrt_marshallIn
  (SFc4_identextrasInstanceStruct *chartInstance, const mxArray *c4_u, const
   emlrtMsgIdentifier *c4_parentId);
static uint8_T c4_k_emlrt_marshallIn(SFc4_identextrasInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static uint16_T c4_l_emlrt_marshallIn(SFc4_identextrasInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_m_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, uint16_T c4_y[4]);
static void c4_n_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, uint16_T c4_y[2]);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_o_emlrt_marshallIn(SFc4_identextrasInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_identextras, const char_T
  *c4_identifier);
static void init_dsm_address_info(SFc4_identextrasInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_identextras(SFc4_identextrasInstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_identextras = 0U;
}

static void initialize_params_c4_identextras(SFc4_identextrasInstanceStruct
  *chartInstance)
{
  const mxArray *c4_m0 = NULL;
  const mxArray *c4_mxField;
  c4_s8I6VPw2Ssn0flwgyUaioQ c4_r0;
  c4_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c4_mxField = sf_mex_getfield(c4_m0, "estimationMethod", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c4_mxField),
                      &c4_r0.estimationMethod, 1, 3, 0U, 0, 0U, 0);
  c4_mxField = sf_mex_getfield(c4_m0, "na", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c4_mxField), &c4_r0.na, 1, 5,
                      0U, 0, 0U, 0);
  c4_mxField = sf_mex_getfield(c4_m0, "nb", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c4_mxField), &c4_r0.nb, 1, 5,
                      0U, 0, 0U, 0);
  c4_mxField = sf_mex_getfield(c4_m0, "nk", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c4_mxField), &c4_r0.nk, 1, 5,
                      0U, 0, 0U, 0);
  c4_mxField = sf_mex_getfield(c4_m0, "nInputs", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c4_mxField), &c4_r0.nInputs,
                      1, 5, 0U, 0, 0U, 0);
  c4_mxField = sf_mex_getfield(c4_m0, "nParameters", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c4_mxField),
                      &c4_r0.nParameters, 1, 5, 0U, 0, 0U, 0);
  c4_mxField = sf_mex_getfield(c4_m0, "necessaryDataForPhi", "algorithmParams",
    0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c4_mxField),
                      c4_r0.necessaryDataForPhi, 1, 5, 0U, 1, 0U, 1, 4);
  c4_mxField = sf_mex_getfield(c4_m0, "b0CoeffPos", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c4_mxField),
                      c4_r0.b0CoeffPos, 1, 5, 0U, 1, 0U, 1, 2);
  c4_mxField = sf_mex_getfield(c4_m0, "finalInputPos", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c4_mxField),
                      &c4_r0.finalInputPos, 1, 5, 0U, 0, 0U, 0);
  c4_mxField = sf_mex_getfield(c4_m0, "bPolyMaxLength", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c4_mxField),
                      &c4_r0.bPolyMaxLength, 1, 5, 0U, 0, 0U, 0);
  sf_mex_destroy(&c4_m0);
  chartInstance->c4_algorithmParams = c4_r0;
}

static void enable_c4_identextras(SFc4_identextrasInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_identextras(SFc4_identextrasInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_identextras
  (SFc4_identextrasInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_identextras
  (SFc4_identextrasInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[4];
  const mxArray *c4_b_y = NULL;
  int32_T c4_i1;
  real_T c4_b_u[4];
  const mxArray *c4_c_y = NULL;
  int32_T c4_i2;
  real_T c4_c_u[16];
  const mxArray *c4_d_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  int32_T c4_i3;
  real_T c4_e_u[7];
  const mxArray *c4_f_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_f_u;
  const mxArray *c4_g_y = NULL;
  int32_T c4_i4;
  real_T c4_g_u[4];
  const mxArray *c4_h_y = NULL;
  uint8_T c4_c_hoistedGlobal;
  uint8_T c4_h_u;
  const mxArray *c4_i_y = NULL;
  real_T *c4_estimationError;
  real_T *c4_psiMemoryNew;
  real_T (*c4_thetaNew)[4];
  real_T (*c4_phiMemoryNew)[7];
  real_T (*c4_PNew)[16];
  real_T (*c4_B)[4];
  real_T (*c4_A)[4];
  c4_psiMemoryNew = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_phiMemoryNew = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 6);
  c4_PNew = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 5);
  c4_thetaNew = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 4);
  c4_estimationError = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_B = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_A = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(8, 1), false);
  for (c4_i0 = 0; c4_i0 < 4; c4_i0++) {
    c4_u[c4_i0] = (*c4_A)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  for (c4_i1 = 0; c4_i1 < 4; c4_i1++) {
    c4_b_u[c4_i1] = (*c4_B)[c4_i1];
  }

  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  for (c4_i2 = 0; c4_i2 < 16; c4_i2++) {
    c4_c_u[c4_i2] = (*c4_PNew)[c4_i2];
  }

  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_c_u, 0, 0U, 1U, 0U, 2, 4, 4),
                false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_hoistedGlobal = *c4_estimationError;
  c4_d_u = c4_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  for (c4_i3 = 0; c4_i3 < 7; c4_i3++) {
    c4_e_u[c4_i3] = (*c4_phiMemoryNew)[c4_i3];
  }

  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_e_u, 0, 0U, 1U, 0U, 1, 7), false);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_b_hoistedGlobal = *c4_psiMemoryNew;
  c4_f_u = c4_b_hoistedGlobal;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 5, c4_g_y);
  for (c4_i4 = 0; c4_i4 < 4; c4_i4++) {
    c4_g_u[c4_i4] = (*c4_thetaNew)[c4_i4];
  }

  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_g_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c4_y, 6, c4_h_y);
  c4_c_hoistedGlobal = chartInstance->c4_is_active_c4_identextras;
  c4_h_u = c4_c_hoistedGlobal;
  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create("y", &c4_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 7, c4_i_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_identextras(SFc4_identextrasInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[4];
  int32_T c4_i5;
  real_T c4_dv1[4];
  int32_T c4_i6;
  real_T c4_dv2[16];
  int32_T c4_i7;
  real_T c4_dv3[7];
  int32_T c4_i8;
  real_T c4_dv4[4];
  int32_T c4_i9;
  real_T *c4_estimationError;
  real_T *c4_psiMemoryNew;
  real_T (*c4_A)[4];
  real_T (*c4_B)[4];
  real_T (*c4_PNew)[16];
  real_T (*c4_phiMemoryNew)[7];
  real_T (*c4_thetaNew)[4];
  c4_psiMemoryNew = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_phiMemoryNew = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 6);
  c4_PNew = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 5);
  c4_thetaNew = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 4);
  c4_estimationError = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_B = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_A = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "A",
                      c4_dv0);
  for (c4_i5 = 0; c4_i5 < 4; c4_i5++) {
    (*c4_A)[c4_i5] = c4_dv0[c4_i5];
  }

  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)), "B",
                      c4_dv1);
  for (c4_i6 = 0; c4_i6 < 4; c4_i6++) {
    (*c4_B)[c4_i6] = c4_dv1[c4_i6];
  }

  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)),
                        "PNew", c4_dv2);
  for (c4_i7 = 0; c4_i7 < 16; c4_i7++) {
    (*c4_PNew)[c4_i7] = c4_dv2[c4_i7];
  }

  *c4_estimationError = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 3)), "estimationError");
  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 4)),
                        "phiMemoryNew", c4_dv3);
  for (c4_i8 = 0; c4_i8 < 7; c4_i8++) {
    (*c4_phiMemoryNew)[c4_i8] = c4_dv3[c4_i8];
  }

  *c4_psiMemoryNew = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 5)), "psiMemoryNew");
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 6)),
                      "thetaNew", c4_dv4);
  for (c4_i9 = 0; c4_i9 < 4; c4_i9++) {
    (*c4_thetaNew)[c4_i9] = c4_dv4[c4_i9];
  }

  chartInstance->c4_is_active_c4_identextras = c4_o_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 7)),
     "is_active_c4_identextras");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_identextras(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_identextras(SFc4_identextrasInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_identextras(SFc4_identextrasInstanceStruct
  *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_d_hoistedGlobal;
  real_T c4_e_hoistedGlobal;
  real_T c4_uMeas;
  real_T c4_yMeas;
  real_T c4_isEnabled;
  real_T c4_adg;
  int32_T c4_i10;
  real_T c4_theta[4];
  int32_T c4_i11;
  real_T c4_P[16];
  int32_T c4_i12;
  real_T c4_phiMemory[7];
  real_T c4_psiMemory;
  uint32_T c4_debug_family_var_map[18];
  c4_s8I6VPw2Ssn0flwgyUaioQ c4_b_algorithmParams;
  real_T c4_nargin = 9.0;
  real_T c4_nargout = 7.0;
  real_T c4_A[4];
  real_T c4_B[4];
  real_T c4_estimationError;
  real_T c4_thetaNew[4];
  real_T c4_PNew[16];
  real_T c4_phiMemoryNew[7];
  real_T c4_psiMemoryNew;
  static c4_s8I6VPw2Ssn0flwgyUaioQ c4_r1 = { 1U, 3U, 1U, 3U, 1U, 4U, { 1U, 2U,
      3U, 7U }, { 4U, 5U }, 4U, 4U };

  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_c_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_d_u;
  const mxArray *c4_d_y = NULL;
  int32_T c4_i18;
  real_T c4_e_u[4];
  const mxArray *c4_e_y = NULL;
  int32_T c4_i19;
  real_T c4_f_u[16];
  const mxArray *c4_f_y = NULL;
  int32_T c4_i20;
  real_T c4_g_u[7];
  const mxArray *c4_g_y = NULL;
  real_T c4_h_u;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_b_psiMemoryNew = NULL;
  const mxArray *c4_b_phiMemoryNew = NULL;
  const mxArray *c4_b_PNew = NULL;
  const mxArray *c4_b_thetaNew = NULL;
  const mxArray *c4_b_estimationError = NULL;
  const mxArray *c4_b_B = NULL;
  const mxArray *c4_b_A = NULL;
  real_T c4_dv5[4];
  int32_T c4_i21;
  real_T c4_dv6[4];
  int32_T c4_i22;
  real_T c4_dv7[4];
  int32_T c4_i23;
  real_T c4_dv8[16];
  int32_T c4_i24;
  real_T c4_dv9[7];
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  real_T *c4_c_estimationError;
  real_T *c4_b_uMeas;
  real_T *c4_b_yMeas;
  real_T *c4_b_isEnabled;
  real_T *c4_b_adg;
  real_T *c4_b_psiMemory;
  real_T *c4_c_psiMemoryNew;
  real_T (*c4_c_A)[4];
  real_T (*c4_c_B)[4];
  real_T (*c4_c_thetaNew)[4];
  real_T (*c4_c_PNew)[16];
  real_T (*c4_c_phiMemoryNew)[7];
  real_T (*c4_b_phiMemory)[7];
  real_T (*c4_b_P)[16];
  real_T (*c4_b_theta)[4];
  c4_c_psiMemoryNew = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_c_phiMemoryNew = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 6);
  c4_b_psiMemory = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c4_b_phiMemory = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 6);
  c4_b_P = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 5);
  c4_b_theta = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c4_b_adg = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_b_isEnabled = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_yMeas = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_c_PNew = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 5);
  c4_b_uMeas = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c4_c_thetaNew = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 4);
  c4_c_estimationError = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_c_B = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_c_A = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_uMeas;
  c4_b_hoistedGlobal = *c4_b_yMeas;
  c4_c_hoistedGlobal = *c4_b_isEnabled;
  c4_d_hoistedGlobal = *c4_b_adg;
  c4_e_hoistedGlobal = *c4_b_psiMemory;
  c4_uMeas = c4_hoistedGlobal;
  c4_yMeas = c4_b_hoistedGlobal;
  c4_isEnabled = c4_c_hoistedGlobal;
  c4_adg = c4_d_hoistedGlobal;
  for (c4_i10 = 0; c4_i10 < 4; c4_i10++) {
    c4_theta[c4_i10] = (*c4_b_theta)[c4_i10];
  }

  for (c4_i11 = 0; c4_i11 < 16; c4_i11++) {
    c4_P[c4_i11] = (*c4_b_P)[c4_i11];
  }

  for (c4_i12 = 0; c4_i12 < 7; c4_i12++) {
    c4_phiMemory[c4_i12] = (*c4_b_phiMemory)[c4_i12];
  }

  c4_psiMemory = c4_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_algorithmParams, 0U, c4_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 2U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_uMeas, 3U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_yMeas, 4U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_isEnabled, 5U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_adg, 6U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_theta, 7U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_P, 8U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_phiMemory, 9U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_psiMemory, 10U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_A, 11U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_B, 12U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_estimationError, 13U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_thetaNew, 14U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_PNew, 15U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_phiMemoryNew, 16U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_psiMemoryNew, 17U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  c4_b_algorithmParams = c4_r1;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  CV_EML_COND(0, 1, 0, true);
  CV_EML_COND(0, 1, 1, false);
  CV_EML_COND(0, 1, 2, false);
  CV_EML_MCDC(0, 1, 0, true);
  CV_EML_IF(0, 1, 0, true);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
  for (c4_i13 = 0; c4_i13 < 4; c4_i13++) {
    c4_A[c4_i13] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  for (c4_i14 = 0; c4_i14 < 4; c4_i14++) {
    c4_B[c4_i14] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  c4_estimationError = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
  for (c4_i15 = 0; c4_i15 < 4; c4_i15++) {
    c4_thetaNew[c4_i15] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
  for (c4_i16 = 0; c4_i16 < 16; c4_i16++) {
    c4_PNew[c4_i16] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
  for (c4_i17 = 0; c4_i17 < 7; c4_i17++) {
    c4_phiMemoryNew[c4_i17] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
  c4_psiMemoryNew = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
  CV_EML_IF(0, 1, 1, true);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
  c4_u = c4_uMeas;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  c4_b_u = c4_yMeas;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
  c4_c_u = c4_isEnabled;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), false);
  c4_d_u = c4_adg;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), false);
  for (c4_i18 = 0; c4_i18 < 4; c4_i18++) {
    c4_e_u[c4_i18] = c4_theta[c4_i18];
  }

  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_e_u, 0, 0U, 1U, 0U, 1, 4), false);
  for (c4_i19 = 0; c4_i19 < 16; c4_i19++) {
    c4_f_u[c4_i19] = c4_P[c4_i19];
  }

  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_f_u, 0, 0U, 1U, 0U, 2, 4, 4),
                false);
  for (c4_i20 = 0; c4_i20 < 7; c4_i20++) {
    c4_g_u[c4_i20] = c4_phiMemory[c4_i20];
  }

  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_g_u, 0, 0U, 1U, 0U, 1, 7), false);
  c4_h_u = c4_psiMemory;
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "idrarxstep_double_mex", 7U, 9U,
                    14, c4_y, 14, c4_b_y, 14, c4_c_y, 14, c4_d_y, 14, c4_e_y, 14,
                    c4_f_y, 14, c4_g_y, 14, c4_h_y, 14, c4_emlrt_marshallOut
                    (chartInstance, c4_r1), &c4_b_A, &c4_b_B,
                    &c4_b_estimationError, &c4_b_thetaNew, &c4_b_PNew,
                    &c4_b_phiMemoryNew, &c4_b_psiMemoryNew);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_A), "A", c4_dv5);
  for (c4_i21 = 0; c4_i21 < 4; c4_i21++) {
    c4_A[c4_i21] = c4_dv5[c4_i21];
  }

  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_B), "B", c4_dv6);
  for (c4_i22 = 0; c4_i22 < 4; c4_i22++) {
    c4_B[c4_i22] = c4_dv6[c4_i22];
  }

  c4_estimationError = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_estimationError), "estimationError");
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_thetaNew), "thetaNew",
                      c4_dv7);
  for (c4_i23 = 0; c4_i23 < 4; c4_i23++) {
    c4_thetaNew[c4_i23] = c4_dv7[c4_i23];
  }

  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_PNew), "PNew", c4_dv8);
  for (c4_i24 = 0; c4_i24 < 16; c4_i24++) {
    c4_PNew[c4_i24] = c4_dv8[c4_i24];
  }

  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_phiMemoryNew),
                        "phiMemoryNew", c4_dv9);
  for (c4_i25 = 0; c4_i25 < 7; c4_i25++) {
    c4_phiMemoryNew[c4_i25] = c4_dv9[c4_i25];
  }

  c4_psiMemoryNew = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_psiMemoryNew), "psiMemoryNew");
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -31);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c4_b_A);
  sf_mex_destroy(&c4_b_B);
  sf_mex_destroy(&c4_b_estimationError);
  sf_mex_destroy(&c4_b_thetaNew);
  sf_mex_destroy(&c4_b_PNew);
  sf_mex_destroy(&c4_b_phiMemoryNew);
  sf_mex_destroy(&c4_b_psiMemoryNew);
  for (c4_i26 = 0; c4_i26 < 4; c4_i26++) {
    (*c4_c_A)[c4_i26] = c4_A[c4_i26];
  }

  for (c4_i27 = 0; c4_i27 < 4; c4_i27++) {
    (*c4_c_B)[c4_i27] = c4_B[c4_i27];
  }

  *c4_c_estimationError = c4_estimationError;
  for (c4_i28 = 0; c4_i28 < 4; c4_i28++) {
    (*c4_c_thetaNew)[c4_i28] = c4_thetaNew[c4_i28];
  }

  for (c4_i29 = 0; c4_i29 < 16; c4_i29++) {
    (*c4_c_PNew)[c4_i29] = c4_PNew[c4_i29];
  }

  for (c4_i30 = 0; c4_i30 < 7; c4_i30++) {
    (*c4_c_phiMemoryNew)[c4_i30] = c4_phiMemoryNew[c4_i30];
  }

  *c4_c_psiMemoryNew = c4_psiMemoryNew;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_identextrasMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c4_i31 = 0; c4_i31 < 4; c4_i31++) {
    _SFD_DATA_RANGE_CHECK((*c4_c_A)[c4_i31], 0U);
  }

  for (c4_i32 = 0; c4_i32 < 4; c4_i32++) {
    _SFD_DATA_RANGE_CHECK((*c4_c_B)[c4_i32], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_c_estimationError, 2U);
  for (c4_i33 = 0; c4_i33 < 4; c4_i33++) {
    _SFD_DATA_RANGE_CHECK((*c4_c_thetaNew)[c4_i33], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_b_uMeas, 4U);
  for (c4_i34 = 0; c4_i34 < 16; c4_i34++) {
    _SFD_DATA_RANGE_CHECK((*c4_c_PNew)[c4_i34], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_b_yMeas, 6U);
  _SFD_DATA_RANGE_CHECK(*c4_b_isEnabled, 7U);
  _SFD_DATA_RANGE_CHECK(*c4_b_adg, 8U);
  for (c4_i35 = 0; c4_i35 < 4; c4_i35++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_theta)[c4_i35], 9U);
  }

  for (c4_i36 = 0; c4_i36 < 16; c4_i36++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_P)[c4_i36], 10U);
  }

  for (c4_i37 = 0; c4_i37 < 7; c4_i37++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_phiMemory)[c4_i37], 11U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_b_psiMemory, 12U);
  for (c4_i38 = 0; c4_i38 < 7; c4_i38++) {
    _SFD_DATA_RANGE_CHECK((*c4_c_phiMemoryNew)[c4_i38], 14U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_c_psiMemoryNew, 15U);
}

static void initSimStructsc4_identextras(SFc4_identextrasInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  (void)c4_chartNumber;
  (void)c4_instanceNumber;
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc4_identextrasInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_estimationError;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc4_identextrasInstanceStruct *)chartInstanceVoid;
  c4_estimationError = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_estimationError),
    &c4_thisId);
  sf_mex_destroy(&c4_estimationError);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i39;
  real_T c4_b_inData[7];
  int32_T c4_i40;
  real_T c4_u[7];
  const mxArray *c4_y = NULL;
  SFc4_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc4_identextrasInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i39 = 0; c4_i39 < 7; c4_i39++) {
    c4_b_inData[c4_i39] = (*(real_T (*)[7])c4_inData)[c4_i39];
  }

  for (c4_i40 = 0; c4_i40 < 7; c4_i40++) {
    c4_u[c4_i40] = c4_b_inData[c4_i40];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 7), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_phiMemoryNew;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[7];
  int32_T c4_i41;
  SFc4_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc4_identextrasInstanceStruct *)chartInstanceVoid;
  c4_phiMemoryNew = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_phiMemoryNew), &c4_thisId,
                        c4_y);
  sf_mex_destroy(&c4_phiMemoryNew);
  for (c4_i41 = 0; c4_i41 < 7; c4_i41++) {
    (*(real_T (*)[7])c4_outData)[c4_i41] = c4_y[c4_i41];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  real_T c4_b_inData[16];
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  real_T c4_u[16];
  const mxArray *c4_y = NULL;
  SFc4_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc4_identextrasInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i42 = 0;
  for (c4_i43 = 0; c4_i43 < 4; c4_i43++) {
    for (c4_i44 = 0; c4_i44 < 4; c4_i44++) {
      c4_b_inData[c4_i44 + c4_i42] = (*(real_T (*)[16])c4_inData)[c4_i44 +
        c4_i42];
    }

    c4_i42 += 4;
  }

  c4_i45 = 0;
  for (c4_i46 = 0; c4_i46 < 4; c4_i46++) {
    for (c4_i47 = 0; c4_i47 < 4; c4_i47++) {
      c4_u[c4_i47 + c4_i45] = c4_b_inData[c4_i47 + c4_i45];
    }

    c4_i45 += 4;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 4, 4), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_PNew;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[16];
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i50;
  SFc4_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc4_identextrasInstanceStruct *)chartInstanceVoid;
  c4_PNew = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_PNew), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_PNew);
  c4_i48 = 0;
  for (c4_i49 = 0; c4_i49 < 4; c4_i49++) {
    for (c4_i50 = 0; c4_i50 < 4; c4_i50++) {
      (*(real_T (*)[16])c4_outData)[c4_i50 + c4_i48] = c4_y[c4_i50 + c4_i48];
    }

    c4_i48 += 4;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i51;
  real_T c4_b_inData[4];
  int32_T c4_i52;
  real_T c4_u[4];
  const mxArray *c4_y = NULL;
  SFc4_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc4_identextrasInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i51 = 0; c4_i51 < 4; c4_i51++) {
    c4_b_inData[c4_i51] = (*(real_T (*)[4])c4_inData)[c4_i51];
  }

  for (c4_i52 = 0; c4_i52 < 4; c4_i52++) {
    c4_u[c4_i52] = c4_b_inData[c4_i52];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_A;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[4];
  int32_T c4_i53;
  SFc4_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc4_identextrasInstanceStruct *)chartInstanceVoid;
  c4_A = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_A), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_A);
  for (c4_i53 = 0; c4_i53 < 4; c4_i53++) {
    (*(real_T (*)[4])c4_outData)[c4_i53] = c4_y[c4_i53];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  SFc4_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc4_identextrasInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  sf_mex_assign(&c4_mxArrayOutData, c4_emlrt_marshallOut(chartInstance,
    *(c4_s8I6VPw2Ssn0flwgyUaioQ *)c4_inData), false);
  return c4_mxArrayOutData;
}

const mxArray *sf_c4_identextras_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_emlrt_marshallOut(SFc4_identextrasInstanceStruct
  *chartInstance, const c4_s8I6VPw2Ssn0flwgyUaioQ c4_u)
{
  const mxArray *c4_y = NULL;
  uint8_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  uint16_T c4_c_u;
  const mxArray *c4_c_y = NULL;
  uint16_T c4_d_u;
  const mxArray *c4_d_y = NULL;
  uint16_T c4_e_u;
  const mxArray *c4_e_y = NULL;
  uint16_T c4_f_u;
  const mxArray *c4_f_y = NULL;
  uint16_T c4_g_u;
  const mxArray *c4_g_y = NULL;
  int32_T c4_i54;
  uint16_T c4_h_u[4];
  const mxArray *c4_h_y = NULL;
  int32_T c4_i55;
  uint16_T c4_i_u[2];
  const mxArray *c4_i_y = NULL;
  uint16_T c4_j_u;
  const mxArray *c4_j_y = NULL;
  uint16_T c4_k_u;
  const mxArray *c4_k_y = NULL;
  (void)chartInstance;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c4_b_u = c4_u.estimationMethod;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_y, c4_b_y, "estimationMethod", "estimationMethod", 0);
  c4_c_u = c4_u.na;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_c_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_y, c4_c_y, "na", "na", 0);
  c4_d_u = c4_u.nb;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_d_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_y, c4_d_y, "nb", "nb", 0);
  c4_e_u = c4_u.nk;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_e_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_y, c4_e_y, "nk", "nk", 0);
  c4_f_u = c4_u.nInputs;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_f_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_y, c4_f_y, "nInputs", "nInputs", 0);
  c4_g_u = c4_u.nParameters;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_g_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_y, c4_g_y, "nParameters", "nParameters", 0);
  for (c4_i54 = 0; c4_i54 < 4; c4_i54++) {
    c4_h_u[c4_i54] = c4_u.necessaryDataForPhi[c4_i54];
  }

  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_h_u, 5, 0U, 1U, 0U, 1, 4), false);
  sf_mex_addfield(c4_y, c4_h_y, "necessaryDataForPhi", "necessaryDataForPhi", 0);
  for (c4_i55 = 0; c4_i55 < 2; c4_i55++) {
    c4_i_u[c4_i55] = c4_u.b0CoeffPos[c4_i55];
  }

  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_i_u, 5, 0U, 1U, 0U, 1, 2), false);
  sf_mex_addfield(c4_y, c4_i_y, "b0CoeffPos", "b0CoeffPos", 0);
  c4_j_u = c4_u.finalInputPos;
  c4_j_y = NULL;
  sf_mex_assign(&c4_j_y, sf_mex_create("y", &c4_j_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_y, c4_j_y, "finalInputPos", "finalInputPos", 0);
  c4_k_u = c4_u.bPolyMaxLength;
  c4_k_y = NULL;
  sf_mex_assign(&c4_k_y, sf_mex_create("y", &c4_k_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c4_y, c4_k_y, "bPolyMaxLength", "bPolyMaxLength", 0);
  return c4_y;
}

static void c4_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_A, const char_T *c4_identifier, real_T c4_y[4])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_A), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_A);
}

static void c4_b_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[4])
{
  real_T c4_dv10[4];
  int32_T c4_i56;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv10, 1, 0, 0U, 1, 0U, 1, 4);
  for (c4_i56 = 0; c4_i56 < 4; c4_i56++) {
    c4_y[c4_i56] = c4_dv10[c4_i56];
  }

  sf_mex_destroy(&c4_u);
}

static real_T c4_c_emlrt_marshallIn(SFc4_identextrasInstanceStruct
  *chartInstance, const mxArray *c4_estimationError, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_estimationError),
    &c4_thisId);
  sf_mex_destroy(&c4_estimationError);
  return c4_y;
}

static real_T c4_d_emlrt_marshallIn(SFc4_identextrasInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_PNew, const char_T *c4_identifier, real_T c4_y[16])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_PNew), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_PNew);
}

static void c4_f_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[16])
{
  real_T c4_dv11[16];
  int32_T c4_i57;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv11, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c4_i57 = 0; c4_i57 < 16; c4_i57++) {
    c4_y[c4_i57] = c4_dv11[c4_i57];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_g_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_phiMemoryNew, const char_T *c4_identifier, real_T c4_y[7])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_phiMemoryNew), &c4_thisId,
                        c4_y);
  sf_mex_destroy(&c4_phiMemoryNew);
}

static void c4_h_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[7])
{
  real_T c4_dv12[7];
  int32_T c4_i58;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv12, 1, 0, 0U, 1, 0U, 1, 7);
  for (c4_i58 = 0; c4_i58 < 7; c4_i58++) {
    c4_y[c4_i58] = c4_dv12[c4_i58];
  }

  sf_mex_destroy(&c4_u);
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc4_identextrasInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_i_emlrt_marshallIn(SFc4_identextrasInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i59;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i59, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i59;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc4_identextrasInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static c4_s8I6VPw2Ssn0flwgyUaioQ c4_j_emlrt_marshallIn
  (SFc4_identextrasInstanceStruct *chartInstance, const mxArray *c4_u, const
   emlrtMsgIdentifier *c4_parentId)
{
  c4_s8I6VPw2Ssn0flwgyUaioQ c4_y;
  emlrtMsgIdentifier c4_thisId;
  static const char * c4_fieldNames[10] = { "estimationMethod", "na", "nb", "nk",
    "nInputs", "nParameters", "necessaryDataForPhi", "b0CoeffPos",
    "finalInputPos", "bPolyMaxLength" };

  c4_thisId.fParent = c4_parentId;
  sf_mex_check_struct(c4_parentId, c4_u, 10, c4_fieldNames, 0U, NULL);
  c4_thisId.fIdentifier = "estimationMethod";
  c4_y.estimationMethod = c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c4_u, "estimationMethod", "estimationMethod", 0)),
    &c4_thisId);
  c4_thisId.fIdentifier = "na";
  c4_y.na = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "na", "na", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "nb";
  c4_y.nb = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "nb", "nb", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "nk";
  c4_y.nk = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "nk", "nk", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "nInputs";
  c4_y.nInputs = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c4_u, "nInputs", "nInputs", 0)),
    &c4_thisId);
  c4_thisId.fIdentifier = "nParameters";
  c4_y.nParameters = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c4_u, "nParameters", "nParameters", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "necessaryDataForPhi";
  c4_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "necessaryDataForPhi", "necessaryDataForPhi", 0)), &c4_thisId,
                        c4_y.necessaryDataForPhi);
  c4_thisId.fIdentifier = "b0CoeffPos";
  c4_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c4_u,
    "b0CoeffPos", "b0CoeffPos", 0)), &c4_thisId, c4_y.b0CoeffPos);
  c4_thisId.fIdentifier = "finalInputPos";
  c4_y.finalInputPos = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c4_u, "finalInputPos", "finalInputPos", 0)), &c4_thisId);
  c4_thisId.fIdentifier = "bPolyMaxLength";
  c4_y.bPolyMaxLength = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c4_u, "bPolyMaxLength", "bPolyMaxLength", 0)), &c4_thisId);
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static uint8_T c4_k_emlrt_marshallIn(SFc4_identextrasInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static uint16_T c4_l_emlrt_marshallIn(SFc4_identextrasInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint16_T c4_y;
  uint16_T c4_u1;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u1, 1, 5, 0U, 0, 0U, 0);
  c4_y = c4_u1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_m_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, uint16_T c4_y[4])
{
  uint16_T c4_uv0[4];
  int32_T c4_i60;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv0, 1, 5, 0U, 1, 0U, 1, 4);
  for (c4_i60 = 0; c4_i60 < 4; c4_i60++) {
    c4_y[c4_i60] = c4_uv0[c4_i60];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_n_emlrt_marshallIn(SFc4_identextrasInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, uint16_T c4_y[2])
{
  uint16_T c4_uv1[2];
  int32_T c4_i61;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv1, 1, 5, 0U, 1, 0U, 1, 2);
  for (c4_i61 = 0; c4_i61 < 2; c4_i61++) {
    c4_y[c4_i61] = c4_uv1[c4_i61];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_algorithmParams;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  c4_s8I6VPw2Ssn0flwgyUaioQ c4_y;
  SFc4_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc4_identextrasInstanceStruct *)chartInstanceVoid;
  c4_b_algorithmParams = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_algorithmParams),
    &c4_thisId);
  sf_mex_destroy(&c4_b_algorithmParams);
  *(c4_s8I6VPw2Ssn0flwgyUaioQ *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_o_emlrt_marshallIn(SFc4_identextrasInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_identextras, const char_T
  *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_identextras), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_identextras);
  return c4_y;
}

static void init_dsm_address_info(SFc4_identextrasInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c4_identextras_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(795271360U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4048143004U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1588849777U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1856636396U);
}

mxArray *sf_c4_identextras_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("yUYkUiAiaFqkeQuCmFDdf");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(4);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(7);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(4);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(7);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_identextras_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_identextras_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_identextras(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[57],T\"A\",},{M[1],M[58],T\"B\",},{M[1],M[17],T\"PNew\",},{M[1],M[10],T\"estimationError\",},{M[1],M[59],T\"phiMemoryNew\",},{M[1],M[60],T\"psiMemoryNew\",},{M[1],M[29],T\"thetaNew\",},{M[8],M[0],T\"is_active_c4_identextras\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_identextras_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_identextrasInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_identextrasInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _identextrasMachineNumber_,
           4,
           1,
           1,
           0,
           16,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_identextrasMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_identextrasMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _identextrasMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"A");
          _SFD_SET_DATA_PROPS(1,2,0,1,"B");
          _SFD_SET_DATA_PROPS(2,2,0,1,"estimationError");
          _SFD_SET_DATA_PROPS(3,2,0,1,"thetaNew");
          _SFD_SET_DATA_PROPS(4,1,1,0,"uMeas");
          _SFD_SET_DATA_PROPS(5,2,0,1,"PNew");
          _SFD_SET_DATA_PROPS(6,1,1,0,"yMeas");
          _SFD_SET_DATA_PROPS(7,1,1,0,"isEnabled");
          _SFD_SET_DATA_PROPS(8,1,1,0,"adg");
          _SFD_SET_DATA_PROPS(9,1,1,0,"theta");
          _SFD_SET_DATA_PROPS(10,1,1,0,"P");
          _SFD_SET_DATA_PROPS(11,1,1,0,"phiMemory");
          _SFD_SET_DATA_PROPS(12,1,1,0,"psiMemory");
          _SFD_SET_DATA_PROPS(13,10,0,0,"algorithmParams");
          _SFD_SET_DATA_PROPS(14,2,0,1,"phiMemoryNew");
          _SFD_SET_DATA_PROPS(15,2,0,1,"psiMemoryNew");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1676);
        _SFD_CV_INIT_EML_IF(0,1,0,309,394,1452,1672);
        _SFD_CV_INIT_EML_IF(0,1,1,1016,1038,1241,1451);

        {
          static int condStart[] = { 312, 337, 369 };

          static int condEnd[] = { 332, 364, 394 };

          static int pfixExpr[] = { 0, 1, -1, -3, 2, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,312,394,3,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)
            c4_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)
            c4_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)
            c4_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)
            c4_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_e_sf_marshallOut,(MexInFcnForType)c4_f_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          real_T *c4_estimationError;
          real_T *c4_uMeas;
          real_T *c4_yMeas;
          real_T *c4_isEnabled;
          real_T *c4_adg;
          real_T *c4_psiMemory;
          real_T *c4_psiMemoryNew;
          real_T (*c4_A)[4];
          real_T (*c4_B)[4];
          real_T (*c4_thetaNew)[4];
          real_T (*c4_PNew)[16];
          real_T (*c4_theta)[4];
          real_T (*c4_P)[16];
          real_T (*c4_phiMemory)[7];
          real_T (*c4_phiMemoryNew)[7];
          c4_psiMemoryNew = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c4_phiMemoryNew = (real_T (*)[7])ssGetOutputPortSignal
            (chartInstance->S, 6);
          c4_psiMemory = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c4_phiMemory = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 6);
          c4_P = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 5);
          c4_theta = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
          c4_adg = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c4_isEnabled = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_yMeas = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_PNew = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 5);
          c4_uMeas = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c4_thetaNew = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 4);
          c4_estimationError = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            3);
          c4_B = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
          c4_A = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_A);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_B);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_estimationError);
          _SFD_SET_DATA_VALUE_PTR(3U, *c4_thetaNew);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_uMeas);
          _SFD_SET_DATA_VALUE_PTR(5U, *c4_PNew);
          _SFD_SET_DATA_VALUE_PTR(6U, c4_yMeas);
          _SFD_SET_DATA_VALUE_PTR(7U, c4_isEnabled);
          _SFD_SET_DATA_VALUE_PTR(8U, c4_adg);
          _SFD_SET_DATA_VALUE_PTR(9U, *c4_theta);
          _SFD_SET_DATA_VALUE_PTR(10U, *c4_P);
          _SFD_SET_DATA_VALUE_PTR(11U, *c4_phiMemory);
          _SFD_SET_DATA_VALUE_PTR(12U, c4_psiMemory);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c4_algorithmParams);
          _SFD_SET_DATA_VALUE_PTR(14U, *c4_phiMemoryNew);
          _SFD_SET_DATA_VALUE_PTR(15U, c4_psiMemoryNew);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _identextrasMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "ywC5TFp1mP9SP1vBsJh0kH";
}

static void sf_opaque_initialize_c4_identextras(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_identextrasInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c4_identextras((SFc4_identextrasInstanceStruct*)
    chartInstanceVar);
  initialize_c4_identextras((SFc4_identextrasInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_identextras(void *chartInstanceVar)
{
  enable_c4_identextras((SFc4_identextrasInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_identextras(void *chartInstanceVar)
{
  disable_c4_identextras((SFc4_identextrasInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_identextras(void *chartInstanceVar)
{
  sf_gateway_c4_identextras((SFc4_identextrasInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_identextras(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_identextras
    ((SFc4_identextrasInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_identextras();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c4_identextras(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c4_identextras();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_identextras((SFc4_identextrasInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_identextras(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_identextras(S);
}

static void sf_opaque_set_sim_state_c4_identextras(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c4_identextras(S, st);
}

static void sf_opaque_terminate_c4_identextras(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_identextrasInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_identextras_optimization_info();
    }

    finalize_c4_identextras((SFc4_identextrasInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_identextras((SFc4_identextrasInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_identextras(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c4_identextras((SFc4_identextrasInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_identextras(SimStruct *S)
{
  /* Actual parameters from chart:
     algorithmParams
   */
  const char_T *rtParamNames[] = { "algorithmParams" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_identextras_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,7);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=7; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3772761430U));
  ssSetChecksum1(S,(2056882010U));
  ssSetChecksum2(S,(2336205111U));
  ssSetChecksum3(S,(2451789600U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_identextras(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_identextras(SimStruct *S)
{
  SFc4_identextrasInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_identextrasInstanceStruct *)utMalloc(sizeof
    (SFc4_identextrasInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_identextrasInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_identextras;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_identextras;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_identextras;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_identextras;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_identextras;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_identextras;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_identextras;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_identextras;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_identextras;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_identextras;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_identextras;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c4_identextras_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_identextras(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_identextras(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_identextras(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_identextras_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
