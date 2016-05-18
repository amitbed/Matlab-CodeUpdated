/* Include files */

#include <stddef.h>
#include "blas.h"
#include "identextras_sfun.h"
#include "c5_identextras.h"
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
static const char * c5_debug_family_names[19] = { "algorithmParams", "nargin",
  "nargout", "uMeas", "yMeas", "isEnabled", "adg", "theta", "P", "phiMemory",
  "psiMemory", "A", "B", "C", "estimationError", "thetaNew", "PNew",
  "phiMemoryNew", "psiMemoryNew" };

/* Function Declarations */
static void initialize_c5_identextras(SFc5_identextrasInstanceStruct
  *chartInstance);
static void initialize_params_c5_identextras(SFc5_identextrasInstanceStruct
  *chartInstance);
static void enable_c5_identextras(SFc5_identextrasInstanceStruct *chartInstance);
static void disable_c5_identextras(SFc5_identextrasInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_identextras
  (SFc5_identextrasInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_identextras
  (SFc5_identextrasInstanceStruct *chartInstance);
static void set_sim_state_c5_identextras(SFc5_identextrasInstanceStruct
  *chartInstance, const mxArray *c5_st);
static void finalize_c5_identextras(SFc5_identextrasInstanceStruct
  *chartInstance);
static void sf_gateway_c5_identextras(SFc5_identextrasInstanceStruct
  *chartInstance);
static void initSimStructsc5_identextras(SFc5_identextrasInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_emlrt_marshallOut(SFc5_identextrasInstanceStruct
  *chartInstance, const c5_szWfN9fHfXTSMrK3Q1hTVMH c5_u);
static void c5_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_A, const char_T *c5_identifier, real_T c5_y[4]);
static void c5_b_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[4]);
static void c5_c_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_C, const char_T *c5_identifier, real_T c5_y[2]);
static void c5_d_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[2]);
static real_T c5_e_emlrt_marshallIn(SFc5_identextrasInstanceStruct
  *chartInstance, const mxArray *c5_estimationError, const char_T *c5_identifier);
static real_T c5_f_emlrt_marshallIn(SFc5_identextrasInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_g_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_thetaNew, const char_T *c5_identifier, real_T c5_y[5]);
static void c5_h_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[5]);
static void c5_i_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_PNew, const char_T *c5_identifier, real_T c5_y[25]);
static void c5_j_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[25]);
static void c5_k_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_phiMemoryNew, const char_T *c5_identifier, real_T c5_y[7]);
static void c5_l_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[7]);
static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_m_emlrt_marshallIn(SFc5_identextrasInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static c5_szWfN9fHfXTSMrK3Q1hTVMH c5_n_emlrt_marshallIn
  (SFc5_identextrasInstanceStruct *chartInstance, const mxArray *c5_u, const
   emlrtMsgIdentifier *c5_parentId);
static uint8_T c5_o_emlrt_marshallIn(SFc5_identextrasInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static uint16_T c5_p_emlrt_marshallIn(SFc5_identextrasInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_q_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, uint16_T c5_y[5]);
static void c5_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_r_emlrt_marshallIn(SFc5_identextrasInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_identextras, const char_T
  *c5_identifier);
static void init_dsm_address_info(SFc5_identextrasInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_identextras(SFc5_identextrasInstanceStruct
  *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_identextras = 0U;
}

static void initialize_params_c5_identextras(SFc5_identextrasInstanceStruct
  *chartInstance)
{
  const mxArray *c5_m0 = NULL;
  const mxArray *c5_mxField;
  c5_szWfN9fHfXTSMrK3Q1hTVMH c5_r0;
  c5_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c5_mxField = sf_mex_getfield(c5_m0, "estimationMethod", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField),
                      &c5_r0.estimationMethod, 1, 3, 0U, 0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "na", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField), &c5_r0.na, 1, 5,
                      0U, 0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "nb", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField), &c5_r0.nb, 1, 5,
                      0U, 0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "nc", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField), &c5_r0.nc, 1, 5,
                      0U, 0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "nk", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField), &c5_r0.nk, 1, 5,
                      0U, 0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "nInputs", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField), &c5_r0.nInputs,
                      1, 5, 0U, 0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "nParameters", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField),
                      &c5_r0.nParameters, 1, 5, 0U, 0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "necessaryDataForPhi", "algorithmParams",
    0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField),
                      c5_r0.necessaryDataForPhi, 1, 5, 0U, 1, 0U, 1, 5);
  c5_mxField = sf_mex_getfield(c5_m0, "necessaryDataForPsi", "algorithmParams",
    0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField),
                      c5_r0.necessaryDataForPsi, 1, 5, 0U, 1, 0U, 1, 5);
  c5_mxField = sf_mex_getfield(c5_m0, "b0PosInTheta", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField),
                      &c5_r0.b0PosInTheta, 1, 5, 0U, 0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "b0PosInPsi", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField),
                      &c5_r0.b0PosInPsi, 1, 5, 0U, 0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "c1PosInTheta", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField),
                      &c5_r0.c1PosInTheta, 1, 5, 0U, 0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "cncPosInTheta", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField),
                      &c5_r0.cncPosInTheta, 1, 5, 0U, 0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "c1PosInPhi", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField),
                      &c5_r0.c1PosInPhi, 1, 5, 0U, 0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "c1PosInPsi", "algorithmParams", 0);
  sf_mex_import_named("algorithmParams", sf_mex_dup(c5_mxField),
                      &c5_r0.c1PosInPsi, 1, 5, 0U, 0, 0U, 0);
  sf_mex_destroy(&c5_m0);
  chartInstance->c5_algorithmParams = c5_r0;
}

static void enable_c5_identextras(SFc5_identextrasInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_identextras(SFc5_identextrasInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_identextras
  (SFc5_identextrasInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_identextras
  (SFc5_identextrasInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_u[4];
  const mxArray *c5_b_y = NULL;
  int32_T c5_i1;
  real_T c5_b_u[4];
  const mxArray *c5_c_y = NULL;
  int32_T c5_i2;
  real_T c5_c_u[2];
  const mxArray *c5_d_y = NULL;
  int32_T c5_i3;
  real_T c5_d_u[25];
  const mxArray *c5_e_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_e_u;
  const mxArray *c5_f_y = NULL;
  int32_T c5_i4;
  real_T c5_f_u[7];
  const mxArray *c5_g_y = NULL;
  int32_T c5_i5;
  real_T c5_g_u[7];
  const mxArray *c5_h_y = NULL;
  int32_T c5_i6;
  real_T c5_h_u[5];
  const mxArray *c5_i_y = NULL;
  uint8_T c5_b_hoistedGlobal;
  uint8_T c5_i_u;
  const mxArray *c5_j_y = NULL;
  real_T *c5_estimationError;
  real_T (*c5_thetaNew)[5];
  real_T (*c5_psiMemoryNew)[7];
  real_T (*c5_phiMemoryNew)[7];
  real_T (*c5_PNew)[25];
  real_T (*c5_C)[2];
  real_T (*c5_B)[4];
  real_T (*c5_A)[4];
  c5_psiMemoryNew = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 8);
  c5_phiMemoryNew = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 7);
  c5_PNew = (real_T (*)[25])ssGetOutputPortSignal(chartInstance->S, 6);
  c5_thetaNew = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 5);
  c5_estimationError = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_C = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c5_B = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_A = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(9, 1), false);
  for (c5_i0 = 0; c5_i0 < 4; c5_i0++) {
    c5_u[c5_i0] = (*c5_A)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  for (c5_i1 = 0; c5_i1 < 4; c5_i1++) {
    c5_b_u[c5_i1] = (*c5_B)[c5_i1];
  }

  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
    c5_c_u[c5_i2] = (*c5_C)[c5_i2];
  }

  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c5_y, 2, c5_d_y);
  for (c5_i3 = 0; c5_i3 < 25; c5_i3++) {
    c5_d_u[c5_i3] = (*c5_PNew)[c5_i3];
  }

  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_d_u, 0, 0U, 1U, 0U, 2, 5, 5),
                false);
  sf_mex_setcell(c5_y, 3, c5_e_y);
  c5_hoistedGlobal = *c5_estimationError;
  c5_e_u = c5_hoistedGlobal;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 4, c5_f_y);
  for (c5_i4 = 0; c5_i4 < 7; c5_i4++) {
    c5_f_u[c5_i4] = (*c5_phiMemoryNew)[c5_i4];
  }

  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_f_u, 0, 0U, 1U, 0U, 1, 7), false);
  sf_mex_setcell(c5_y, 5, c5_g_y);
  for (c5_i5 = 0; c5_i5 < 7; c5_i5++) {
    c5_g_u[c5_i5] = (*c5_psiMemoryNew)[c5_i5];
  }

  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_g_u, 0, 0U, 1U, 0U, 1, 7), false);
  sf_mex_setcell(c5_y, 6, c5_h_y);
  for (c5_i6 = 0; c5_i6 < 5; c5_i6++) {
    c5_h_u[c5_i6] = (*c5_thetaNew)[c5_i6];
  }

  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_h_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_setcell(c5_y, 7, c5_i_y);
  c5_b_hoistedGlobal = chartInstance->c5_is_active_c5_identextras;
  c5_i_u = c5_b_hoistedGlobal;
  c5_j_y = NULL;
  sf_mex_assign(&c5_j_y, sf_mex_create("y", &c5_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 8, c5_j_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_identextras(SFc5_identextrasInstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[4];
  int32_T c5_i7;
  real_T c5_dv1[4];
  int32_T c5_i8;
  real_T c5_dv2[2];
  int32_T c5_i9;
  real_T c5_dv3[25];
  int32_T c5_i10;
  real_T c5_dv4[7];
  int32_T c5_i11;
  real_T c5_dv5[7];
  int32_T c5_i12;
  real_T c5_dv6[5];
  int32_T c5_i13;
  real_T *c5_estimationError;
  real_T (*c5_A)[4];
  real_T (*c5_B)[4];
  real_T (*c5_C)[2];
  real_T (*c5_PNew)[25];
  real_T (*c5_phiMemoryNew)[7];
  real_T (*c5_psiMemoryNew)[7];
  real_T (*c5_thetaNew)[5];
  c5_psiMemoryNew = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 8);
  c5_phiMemoryNew = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 7);
  c5_PNew = (real_T (*)[25])ssGetOutputPortSignal(chartInstance->S, 6);
  c5_thetaNew = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 5);
  c5_estimationError = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_C = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c5_B = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_A = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)), "A",
                      c5_dv0);
  for (c5_i7 = 0; c5_i7 < 4; c5_i7++) {
    (*c5_A)[c5_i7] = c5_dv0[c5_i7];
  }

  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)), "B",
                      c5_dv1);
  for (c5_i8 = 0; c5_i8 < 4; c5_i8++) {
    (*c5_B)[c5_i8] = c5_dv1[c5_i8];
  }

  c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 2)), "C",
                        c5_dv2);
  for (c5_i9 = 0; c5_i9 < 2; c5_i9++) {
    (*c5_C)[c5_i9] = c5_dv2[c5_i9];
  }

  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 3)),
                        "PNew", c5_dv3);
  for (c5_i10 = 0; c5_i10 < 25; c5_i10++) {
    (*c5_PNew)[c5_i10] = c5_dv3[c5_i10];
  }

  *c5_estimationError = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 4)), "estimationError");
  c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 5)),
                        "phiMemoryNew", c5_dv4);
  for (c5_i11 = 0; c5_i11 < 7; c5_i11++) {
    (*c5_phiMemoryNew)[c5_i11] = c5_dv4[c5_i11];
  }

  c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 6)),
                        "psiMemoryNew", c5_dv5);
  for (c5_i12 = 0; c5_i12 < 7; c5_i12++) {
    (*c5_psiMemoryNew)[c5_i12] = c5_dv5[c5_i12];
  }

  c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 7)),
                        "thetaNew", c5_dv6);
  for (c5_i13 = 0; c5_i13 < 5; c5_i13++) {
    (*c5_thetaNew)[c5_i13] = c5_dv6[c5_i13];
  }

  chartInstance->c5_is_active_c5_identextras = c5_r_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 8)),
     "is_active_c5_identextras");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_identextras(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_identextras(SFc5_identextrasInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c5_identextras(SFc5_identextrasInstanceStruct
  *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_d_hoistedGlobal;
  real_T c5_uMeas;
  real_T c5_yMeas;
  real_T c5_isEnabled;
  real_T c5_adg;
  int32_T c5_i14;
  real_T c5_theta[5];
  int32_T c5_i15;
  real_T c5_P[25];
  int32_T c5_i16;
  real_T c5_phiMemory[7];
  int32_T c5_i17;
  real_T c5_psiMemory[7];
  uint32_T c5_debug_family_var_map[19];
  c5_szWfN9fHfXTSMrK3Q1hTVMH c5_b_algorithmParams;
  real_T c5_nargin = 9.0;
  real_T c5_nargout = 8.0;
  real_T c5_A[4];
  real_T c5_B[4];
  real_T c5_C[2];
  real_T c5_estimationError;
  real_T c5_thetaNew[5];
  real_T c5_PNew[25];
  real_T c5_phiMemoryNew[7];
  real_T c5_psiMemoryNew[7];
  static c5_szWfN9fHfXTSMrK3Q1hTVMH c5_r1 = { 1U, 3U, 1U, 1U, 3U, 1U, 5U, { 1U,
      2U, 3U, 6U, 7U }, { 1U, 2U, 3U, 6U, 7U }, 4U, 4U, 5U, 5U, 7U, 7U };

  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  int32_T c5_i25;
  real_T c5_e_u[5];
  const mxArray *c5_e_y = NULL;
  int32_T c5_i26;
  real_T c5_f_u[25];
  const mxArray *c5_f_y = NULL;
  int32_T c5_i27;
  real_T c5_g_u[7];
  const mxArray *c5_g_y = NULL;
  int32_T c5_i28;
  real_T c5_h_u[7];
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_b_psiMemoryNew = NULL;
  const mxArray *c5_b_phiMemoryNew = NULL;
  const mxArray *c5_b_PNew = NULL;
  const mxArray *c5_b_thetaNew = NULL;
  const mxArray *c5_b_estimationError = NULL;
  const mxArray *c5_b_C = NULL;
  const mxArray *c5_b_B = NULL;
  const mxArray *c5_b_A = NULL;
  real_T c5_dv7[4];
  int32_T c5_i29;
  real_T c5_dv8[4];
  int32_T c5_i30;
  real_T c5_dv9[2];
  int32_T c5_i31;
  real_T c5_dv10[5];
  int32_T c5_i32;
  real_T c5_dv11[25];
  int32_T c5_i33;
  real_T c5_dv12[7];
  int32_T c5_i34;
  real_T c5_dv13[7];
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  real_T *c5_b_uMeas;
  real_T *c5_c_estimationError;
  real_T *c5_b_yMeas;
  real_T *c5_b_isEnabled;
  real_T *c5_b_adg;
  real_T (*c5_c_A)[4];
  real_T (*c5_c_B)[4];
  real_T (*c5_c_C)[2];
  real_T (*c5_c_thetaNew)[5];
  real_T (*c5_c_PNew)[25];
  real_T (*c5_c_phiMemoryNew)[7];
  real_T (*c5_c_psiMemoryNew)[7];
  real_T (*c5_b_psiMemory)[7];
  real_T (*c5_b_phiMemory)[7];
  real_T (*c5_b_P)[25];
  real_T (*c5_b_theta)[5];
  c5_b_psiMemory = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 7);
  c5_b_phiMemory = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 6);
  c5_b_P = (real_T (*)[25])ssGetInputPortSignal(chartInstance->S, 5);
  c5_b_theta = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 4);
  c5_b_adg = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_b_isEnabled = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_yMeas = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_c_psiMemoryNew = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 8);
  c5_c_phiMemoryNew = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 7);
  c5_c_PNew = (real_T (*)[25])ssGetOutputPortSignal(chartInstance->S, 6);
  c5_c_thetaNew = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 5);
  c5_c_estimationError = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_c_C = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c5_c_B = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_c_A = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_uMeas = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_b_uMeas, 0U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_uMeas;
  c5_b_hoistedGlobal = *c5_b_yMeas;
  c5_c_hoistedGlobal = *c5_b_isEnabled;
  c5_d_hoistedGlobal = *c5_b_adg;
  c5_uMeas = c5_hoistedGlobal;
  c5_yMeas = c5_b_hoistedGlobal;
  c5_isEnabled = c5_c_hoistedGlobal;
  c5_adg = c5_d_hoistedGlobal;
  for (c5_i14 = 0; c5_i14 < 5; c5_i14++) {
    c5_theta[c5_i14] = (*c5_b_theta)[c5_i14];
  }

  for (c5_i15 = 0; c5_i15 < 25; c5_i15++) {
    c5_P[c5_i15] = (*c5_b_P)[c5_i15];
  }

  for (c5_i16 = 0; c5_i16 < 7; c5_i16++) {
    c5_phiMemory[c5_i16] = (*c5_b_phiMemory)[c5_i16];
  }

  for (c5_i17 = 0; c5_i17 < 7; c5_i17++) {
    c5_psiMemory[c5_i17] = (*c5_b_psiMemory)[c5_i17];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_algorithmParams, 0U, c5_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 1U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 2U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_uMeas, 3U, c5_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_yMeas, 4U, c5_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_isEnabled, 5U, c5_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_adg, 6U, c5_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_theta, 7U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_P, 8U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_phiMemory, 9U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_psiMemory, 10U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_A, 11U, c5_f_sf_marshallOut,
    c5_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_B, 12U, c5_f_sf_marshallOut,
    c5_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_C, 13U, c5_e_sf_marshallOut,
    c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_estimationError, 14U,
    c5_d_sf_marshallOut, c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_thetaNew, 15U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_PNew, 16U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_phiMemoryNew, 17U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_psiMemoryNew, 18U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  c5_b_algorithmParams = c5_r1;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  CV_EML_COND(0, 1, 0, true);
  CV_EML_COND(0, 1, 1, false);
  CV_EML_COND(0, 1, 2, false);
  CV_EML_MCDC(0, 1, 0, true);
  CV_EML_IF(0, 1, 0, true);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 14);
  for (c5_i18 = 0; c5_i18 < 4; c5_i18++) {
    c5_A[c5_i18] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 15);
  for (c5_i19 = 0; c5_i19 < 4; c5_i19++) {
    c5_B[c5_i19] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 16);
  for (c5_i20 = 0; c5_i20 < 2; c5_i20++) {
    c5_C[c5_i20] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 17);
  c5_estimationError = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
  for (c5_i21 = 0; c5_i21 < 5; c5_i21++) {
    c5_thetaNew[c5_i21] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 19);
  for (c5_i22 = 0; c5_i22 < 25; c5_i22++) {
    c5_PNew[c5_i22] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 20);
  for (c5_i23 = 0; c5_i23 < 7; c5_i23++) {
    c5_phiMemoryNew[c5_i23] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 21);
  for (c5_i24 = 0; c5_i24 < 7; c5_i24++) {
    c5_psiMemoryNew[c5_i24] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 22);
  CV_EML_IF(0, 1, 1, true);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 23);
  c5_u = c5_uMeas;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  c5_b_u = c5_yMeas;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  c5_c_u = c5_isEnabled;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), false);
  c5_d_u = c5_adg;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), false);
  for (c5_i25 = 0; c5_i25 < 5; c5_i25++) {
    c5_e_u[c5_i25] = c5_theta[c5_i25];
  }

  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_e_u, 0, 0U, 1U, 0U, 1, 5), false);
  for (c5_i26 = 0; c5_i26 < 25; c5_i26++) {
    c5_f_u[c5_i26] = c5_P[c5_i26];
  }

  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_f_u, 0, 0U, 1U, 0U, 2, 5, 5),
                false);
  for (c5_i27 = 0; c5_i27 < 7; c5_i27++) {
    c5_g_u[c5_i27] = c5_phiMemory[c5_i27];
  }

  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_g_u, 0, 0U, 1U, 0U, 1, 7), false);
  for (c5_i28 = 0; c5_i28 < 7; c5_i28++) {
    c5_h_u[c5_i28] = c5_psiMemory[c5_i28];
  }

  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_h_u, 0, 0U, 1U, 0U, 1, 7), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "idrarmaxstep_double_mex", 8U,
                    9U, 14, c5_y, 14, c5_b_y, 14, c5_c_y, 14, c5_d_y, 14, c5_e_y,
                    14, c5_f_y, 14, c5_g_y, 14, c5_h_y, 14, c5_emlrt_marshallOut
                    (chartInstance, c5_r1), &c5_b_A, &c5_b_B, &c5_b_C,
                    &c5_b_estimationError, &c5_b_thetaNew, &c5_b_PNew,
                    &c5_b_phiMemoryNew, &c5_b_psiMemoryNew);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_A), "A", c5_dv7);
  for (c5_i29 = 0; c5_i29 < 4; c5_i29++) {
    c5_A[c5_i29] = c5_dv7[c5_i29];
  }

  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_B), "B", c5_dv8);
  for (c5_i30 = 0; c5_i30 < 4; c5_i30++) {
    c5_B[c5_i30] = c5_dv8[c5_i30];
  }

  c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_C), "C", c5_dv9);
  for (c5_i31 = 0; c5_i31 < 2; c5_i31++) {
    c5_C[c5_i31] = c5_dv9[c5_i31];
  }

  c5_estimationError = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_estimationError), "estimationError");
  c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_thetaNew), "thetaNew",
                        c5_dv10);
  for (c5_i32 = 0; c5_i32 < 5; c5_i32++) {
    c5_thetaNew[c5_i32] = c5_dv10[c5_i32];
  }

  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_PNew), "PNew", c5_dv11);
  for (c5_i33 = 0; c5_i33 < 25; c5_i33++) {
    c5_PNew[c5_i33] = c5_dv11[c5_i33];
  }

  c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_phiMemoryNew),
                        "phiMemoryNew", c5_dv12);
  for (c5_i34 = 0; c5_i34 < 7; c5_i34++) {
    c5_phiMemoryNew[c5_i34] = c5_dv12[c5_i34];
  }

  c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_psiMemoryNew),
                        "psiMemoryNew", c5_dv13);
  for (c5_i35 = 0; c5_i35 < 7; c5_i35++) {
    c5_psiMemoryNew[c5_i35] = c5_dv13[c5_i35];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -35);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c5_b_A);
  sf_mex_destroy(&c5_b_B);
  sf_mex_destroy(&c5_b_C);
  sf_mex_destroy(&c5_b_estimationError);
  sf_mex_destroy(&c5_b_thetaNew);
  sf_mex_destroy(&c5_b_PNew);
  sf_mex_destroy(&c5_b_phiMemoryNew);
  sf_mex_destroy(&c5_b_psiMemoryNew);
  for (c5_i36 = 0; c5_i36 < 4; c5_i36++) {
    (*c5_c_A)[c5_i36] = c5_A[c5_i36];
  }

  for (c5_i37 = 0; c5_i37 < 4; c5_i37++) {
    (*c5_c_B)[c5_i37] = c5_B[c5_i37];
  }

  for (c5_i38 = 0; c5_i38 < 2; c5_i38++) {
    (*c5_c_C)[c5_i38] = c5_C[c5_i38];
  }

  *c5_c_estimationError = c5_estimationError;
  for (c5_i39 = 0; c5_i39 < 5; c5_i39++) {
    (*c5_c_thetaNew)[c5_i39] = c5_thetaNew[c5_i39];
  }

  for (c5_i40 = 0; c5_i40 < 25; c5_i40++) {
    (*c5_c_PNew)[c5_i40] = c5_PNew[c5_i40];
  }

  for (c5_i41 = 0; c5_i41 < 7; c5_i41++) {
    (*c5_c_phiMemoryNew)[c5_i41] = c5_phiMemoryNew[c5_i41];
  }

  for (c5_i42 = 0; c5_i42 < 7; c5_i42++) {
    (*c5_c_psiMemoryNew)[c5_i42] = c5_psiMemoryNew[c5_i42];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_identextrasMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c5_i43 = 0; c5_i43 < 4; c5_i43++) {
    _SFD_DATA_RANGE_CHECK((*c5_c_A)[c5_i43], 1U);
  }

  for (c5_i44 = 0; c5_i44 < 4; c5_i44++) {
    _SFD_DATA_RANGE_CHECK((*c5_c_B)[c5_i44], 2U);
  }

  for (c5_i45 = 0; c5_i45 < 2; c5_i45++) {
    _SFD_DATA_RANGE_CHECK((*c5_c_C)[c5_i45], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c5_c_estimationError, 4U);
  for (c5_i46 = 0; c5_i46 < 5; c5_i46++) {
    _SFD_DATA_RANGE_CHECK((*c5_c_thetaNew)[c5_i46], 5U);
  }

  for (c5_i47 = 0; c5_i47 < 25; c5_i47++) {
    _SFD_DATA_RANGE_CHECK((*c5_c_PNew)[c5_i47], 6U);
  }

  for (c5_i48 = 0; c5_i48 < 7; c5_i48++) {
    _SFD_DATA_RANGE_CHECK((*c5_c_phiMemoryNew)[c5_i48], 7U);
  }

  for (c5_i49 = 0; c5_i49 < 7; c5_i49++) {
    _SFD_DATA_RANGE_CHECK((*c5_c_psiMemoryNew)[c5_i49], 8U);
  }

  _SFD_DATA_RANGE_CHECK(*c5_b_yMeas, 9U);
  _SFD_DATA_RANGE_CHECK(*c5_b_isEnabled, 10U);
  _SFD_DATA_RANGE_CHECK(*c5_b_adg, 11U);
  for (c5_i50 = 0; c5_i50 < 5; c5_i50++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_theta)[c5_i50], 12U);
  }

  for (c5_i51 = 0; c5_i51 < 25; c5_i51++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_P)[c5_i51], 13U);
  }

  for (c5_i52 = 0; c5_i52 < 7; c5_i52++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_phiMemory)[c5_i52], 14U);
  }

  for (c5_i53 = 0; c5_i53 < 7; c5_i53++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_psiMemory)[c5_i53], 15U);
  }
}

static void initSimStructsc5_identextras(SFc5_identextrasInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  (void)c5_chartNumber;
  (void)c5_instanceNumber;
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i54;
  real_T c5_b_inData[7];
  int32_T c5_i55;
  real_T c5_u[7];
  const mxArray *c5_y = NULL;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i54 = 0; c5_i54 < 7; c5_i54++) {
    c5_b_inData[c5_i54] = (*(real_T (*)[7])c5_inData)[c5_i54];
  }

  for (c5_i55 = 0; c5_i55 < 7; c5_i55++) {
    c5_u[c5_i55] = c5_b_inData[c5_i55];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 7), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_phiMemoryNew;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[7];
  int32_T c5_i56;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_phiMemoryNew = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_phiMemoryNew), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_phiMemoryNew);
  for (c5_i56 = 0; c5_i56 < 7; c5_i56++) {
    (*(real_T (*)[7])c5_outData)[c5_i56] = c5_y[c5_i56];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  real_T c5_b_inData[25];
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  real_T c5_u[25];
  const mxArray *c5_y = NULL;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i57 = 0;
  for (c5_i58 = 0; c5_i58 < 5; c5_i58++) {
    for (c5_i59 = 0; c5_i59 < 5; c5_i59++) {
      c5_b_inData[c5_i59 + c5_i57] = (*(real_T (*)[25])c5_inData)[c5_i59 +
        c5_i57];
    }

    c5_i57 += 5;
  }

  c5_i60 = 0;
  for (c5_i61 = 0; c5_i61 < 5; c5_i61++) {
    for (c5_i62 = 0; c5_i62 < 5; c5_i62++) {
      c5_u[c5_i62 + c5_i60] = c5_b_inData[c5_i62 + c5_i60];
    }

    c5_i60 += 5;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 5, 5), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_PNew;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[25];
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_PNew = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_PNew), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_PNew);
  c5_i63 = 0;
  for (c5_i64 = 0; c5_i64 < 5; c5_i64++) {
    for (c5_i65 = 0; c5_i65 < 5; c5_i65++) {
      (*(real_T (*)[25])c5_outData)[c5_i65 + c5_i63] = c5_y[c5_i65 + c5_i63];
    }

    c5_i63 += 5;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i66;
  real_T c5_b_inData[5];
  int32_T c5_i67;
  real_T c5_u[5];
  const mxArray *c5_y = NULL;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i66 = 0; c5_i66 < 5; c5_i66++) {
    c5_b_inData[c5_i66] = (*(real_T (*)[5])c5_inData)[c5_i66];
  }

  for (c5_i67 = 0; c5_i67 < 5; c5_i67++) {
    c5_u[c5_i67] = c5_b_inData[c5_i67];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_thetaNew;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[5];
  int32_T c5_i68;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_thetaNew = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_thetaNew), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_thetaNew);
  for (c5_i68 = 0; c5_i68 < 5; c5_i68++) {
    (*(real_T (*)[5])c5_outData)[c5_i68] = c5_y[c5_i68];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_estimationError;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_estimationError = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_estimationError),
    &c5_thisId);
  sf_mex_destroy(&c5_estimationError);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i69;
  real_T c5_b_inData[2];
  int32_T c5_i70;
  real_T c5_u[2];
  const mxArray *c5_y = NULL;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i69 = 0; c5_i69 < 2; c5_i69++) {
    c5_b_inData[c5_i69] = (*(real_T (*)[2])c5_inData)[c5_i69];
  }

  for (c5_i70 = 0; c5_i70 < 2; c5_i70++) {
    c5_u[c5_i70] = c5_b_inData[c5_i70];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_C;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[2];
  int32_T c5_i71;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_C = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_C), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_C);
  for (c5_i71 = 0; c5_i71 < 2; c5_i71++) {
    (*(real_T (*)[2])c5_outData)[c5_i71] = c5_y[c5_i71];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i72;
  real_T c5_b_inData[4];
  int32_T c5_i73;
  real_T c5_u[4];
  const mxArray *c5_y = NULL;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i72 = 0; c5_i72 < 4; c5_i72++) {
    c5_b_inData[c5_i72] = (*(real_T (*)[4])c5_inData)[c5_i72];
  }

  for (c5_i73 = 0; c5_i73 < 4; c5_i73++) {
    c5_u[c5_i73] = c5_b_inData[c5_i73];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_A;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[4];
  int32_T c5_i74;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_A = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_A), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_A);
  for (c5_i74 = 0; c5_i74 < 4; c5_i74++) {
    (*(real_T (*)[4])c5_outData)[c5_i74] = c5_y[c5_i74];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  sf_mex_assign(&c5_mxArrayOutData, c5_emlrt_marshallOut(chartInstance,
    *(c5_szWfN9fHfXTSMrK3Q1hTVMH *)c5_inData), false);
  return c5_mxArrayOutData;
}

const mxArray *sf_c5_identextras_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_emlrt_marshallOut(SFc5_identextrasInstanceStruct
  *chartInstance, const c5_szWfN9fHfXTSMrK3Q1hTVMH c5_u)
{
  const mxArray *c5_y = NULL;
  uint8_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  uint16_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  uint16_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  uint16_T c5_e_u;
  const mxArray *c5_e_y = NULL;
  uint16_T c5_f_u;
  const mxArray *c5_f_y = NULL;
  uint16_T c5_g_u;
  const mxArray *c5_g_y = NULL;
  uint16_T c5_h_u;
  const mxArray *c5_h_y = NULL;
  int32_T c5_i75;
  uint16_T c5_i_u[5];
  const mxArray *c5_i_y = NULL;
  int32_T c5_i76;
  uint16_T c5_j_u[5];
  const mxArray *c5_j_y = NULL;
  uint16_T c5_k_u;
  const mxArray *c5_k_y = NULL;
  uint16_T c5_l_u;
  const mxArray *c5_l_y = NULL;
  uint16_T c5_m_u;
  const mxArray *c5_m_y = NULL;
  uint16_T c5_n_u;
  const mxArray *c5_n_y = NULL;
  uint16_T c5_o_u;
  const mxArray *c5_o_y = NULL;
  uint16_T c5_p_u;
  const mxArray *c5_p_y = NULL;
  (void)chartInstance;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_b_u = c5_u.estimationMethod;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_b_y, "estimationMethod", "estimationMethod", 0);
  c5_c_u = c5_u.na;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_c_y, "na", "na", 0);
  c5_d_u = c5_u.nb;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_d_y, "nb", "nb", 0);
  c5_e_u = c5_u.nc;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_e_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_e_y, "nc", "nc", 0);
  c5_f_u = c5_u.nk;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_f_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_f_y, "nk", "nk", 0);
  c5_g_u = c5_u.nInputs;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_g_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_g_y, "nInputs", "nInputs", 0);
  c5_h_u = c5_u.nParameters;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_h_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_h_y, "nParameters", "nParameters", 0);
  for (c5_i75 = 0; c5_i75 < 5; c5_i75++) {
    c5_i_u[c5_i75] = c5_u.necessaryDataForPhi[c5_i75];
  }

  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_i_u, 5, 0U, 1U, 0U, 1, 5), false);
  sf_mex_addfield(c5_y, c5_i_y, "necessaryDataForPhi", "necessaryDataForPhi", 0);
  for (c5_i76 = 0; c5_i76 < 5; c5_i76++) {
    c5_j_u[c5_i76] = c5_u.necessaryDataForPsi[c5_i76];
  }

  c5_j_y = NULL;
  sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_j_u, 5, 0U, 1U, 0U, 1, 5), false);
  sf_mex_addfield(c5_y, c5_j_y, "necessaryDataForPsi", "necessaryDataForPsi", 0);
  c5_k_u = c5_u.b0PosInTheta;
  c5_k_y = NULL;
  sf_mex_assign(&c5_k_y, sf_mex_create("y", &c5_k_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_k_y, "b0PosInTheta", "b0PosInTheta", 0);
  c5_l_u = c5_u.b0PosInPsi;
  c5_l_y = NULL;
  sf_mex_assign(&c5_l_y, sf_mex_create("y", &c5_l_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_l_y, "b0PosInPsi", "b0PosInPsi", 0);
  c5_m_u = c5_u.c1PosInTheta;
  c5_m_y = NULL;
  sf_mex_assign(&c5_m_y, sf_mex_create("y", &c5_m_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_m_y, "c1PosInTheta", "c1PosInTheta", 0);
  c5_n_u = c5_u.cncPosInTheta;
  c5_n_y = NULL;
  sf_mex_assign(&c5_n_y, sf_mex_create("y", &c5_n_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_n_y, "cncPosInTheta", "cncPosInTheta", 0);
  c5_o_u = c5_u.c1PosInPhi;
  c5_o_y = NULL;
  sf_mex_assign(&c5_o_y, sf_mex_create("y", &c5_o_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_o_y, "c1PosInPhi", "c1PosInPhi", 0);
  c5_p_u = c5_u.c1PosInPsi;
  c5_p_y = NULL;
  sf_mex_assign(&c5_p_y, sf_mex_create("y", &c5_p_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_y, c5_p_y, "c1PosInPsi", "c1PosInPsi", 0);
  return c5_y;
}

static void c5_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_A, const char_T *c5_identifier, real_T c5_y[4])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_A), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_A);
}

static void c5_b_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[4])
{
  real_T c5_dv14[4];
  int32_T c5_i77;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv14, 1, 0, 0U, 1, 0U, 1, 4);
  for (c5_i77 = 0; c5_i77 < 4; c5_i77++) {
    c5_y[c5_i77] = c5_dv14[c5_i77];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_c_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_C, const char_T *c5_identifier, real_T c5_y[2])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_C), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_C);
}

static void c5_d_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[2])
{
  real_T c5_dv15[2];
  int32_T c5_i78;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv15, 1, 0, 0U, 1, 0U, 1, 2);
  for (c5_i78 = 0; c5_i78 < 2; c5_i78++) {
    c5_y[c5_i78] = c5_dv15[c5_i78];
  }

  sf_mex_destroy(&c5_u);
}

static real_T c5_e_emlrt_marshallIn(SFc5_identextrasInstanceStruct
  *chartInstance, const mxArray *c5_estimationError, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_estimationError),
    &c5_thisId);
  sf_mex_destroy(&c5_estimationError);
  return c5_y;
}

static real_T c5_f_emlrt_marshallIn(SFc5_identextrasInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_g_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_thetaNew, const char_T *c5_identifier, real_T c5_y[5])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_thetaNew), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_thetaNew);
}

static void c5_h_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[5])
{
  real_T c5_dv16[5];
  int32_T c5_i79;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv16, 1, 0, 0U, 1, 0U, 1, 5);
  for (c5_i79 = 0; c5_i79 < 5; c5_i79++) {
    c5_y[c5_i79] = c5_dv16[c5_i79];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_i_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_PNew, const char_T *c5_identifier, real_T c5_y[25])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_PNew), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_PNew);
}

static void c5_j_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[25])
{
  real_T c5_dv17[25];
  int32_T c5_i80;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv17, 1, 0, 0U, 1, 0U, 2, 5, 5);
  for (c5_i80 = 0; c5_i80 < 25; c5_i80++) {
    c5_y[c5_i80] = c5_dv17[c5_i80];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_k_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_phiMemoryNew, const char_T *c5_identifier, real_T c5_y[7])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_phiMemoryNew), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_phiMemoryNew);
}

static void c5_l_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[7])
{
  real_T c5_dv18[7];
  int32_T c5_i81;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv18, 1, 0, 0U, 1, 0U, 1, 7);
  for (c5_i81 = 0; c5_i81 < 7; c5_i81++) {
    c5_y[c5_i81] = c5_dv18[c5_i81];
  }

  sf_mex_destroy(&c5_u);
}

static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_m_emlrt_marshallIn(SFc5_identextrasInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i82;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i82, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i82;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static c5_szWfN9fHfXTSMrK3Q1hTVMH c5_n_emlrt_marshallIn
  (SFc5_identextrasInstanceStruct *chartInstance, const mxArray *c5_u, const
   emlrtMsgIdentifier *c5_parentId)
{
  c5_szWfN9fHfXTSMrK3Q1hTVMH c5_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[15] = { "estimationMethod", "na", "nb", "nc",
    "nk", "nInputs", "nParameters", "necessaryDataForPhi", "necessaryDataForPsi",
    "b0PosInTheta", "b0PosInPsi", "c1PosInTheta", "cncPosInTheta", "c1PosInPhi",
    "c1PosInPsi" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_u, 15, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "estimationMethod";
  c5_y.estimationMethod = c5_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "estimationMethod", "estimationMethod", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "na";
  c5_y.na = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "na", "na", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "nb";
  c5_y.nb = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "nb", "nb", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "nc";
  c5_y.nc = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "nc", "nc", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "nk";
  c5_y.nk = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "nk", "nk", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "nInputs";
  c5_y.nInputs = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c5_u, "nInputs", "nInputs", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "nParameters";
  c5_y.nParameters = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "nParameters", "nParameters", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "necessaryDataForPhi";
  c5_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "necessaryDataForPhi", "necessaryDataForPhi", 0)), &c5_thisId,
                        c5_y.necessaryDataForPhi);
  c5_thisId.fIdentifier = "necessaryDataForPsi";
  c5_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_u,
    "necessaryDataForPsi", "necessaryDataForPsi", 0)), &c5_thisId,
                        c5_y.necessaryDataForPsi);
  c5_thisId.fIdentifier = "b0PosInTheta";
  c5_y.b0PosInTheta = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "b0PosInTheta", "b0PosInTheta", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "b0PosInPsi";
  c5_y.b0PosInPsi = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "b0PosInPsi", "b0PosInPsi", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "c1PosInTheta";
  c5_y.c1PosInTheta = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "c1PosInTheta", "c1PosInTheta", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "cncPosInTheta";
  c5_y.cncPosInTheta = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "cncPosInTheta", "cncPosInTheta", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "c1PosInPhi";
  c5_y.c1PosInPhi = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "c1PosInPhi", "c1PosInPhi", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "c1PosInPsi";
  c5_y.c1PosInPsi = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "c1PosInPsi", "c1PosInPsi", 0)), &c5_thisId);
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static uint8_T c5_o_emlrt_marshallIn(SFc5_identextrasInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static uint16_T c5_p_emlrt_marshallIn(SFc5_identextrasInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint16_T c5_y;
  uint16_T c5_u1;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u1, 1, 5, 0U, 0, 0U, 0);
  c5_y = c5_u1;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_q_emlrt_marshallIn(SFc5_identextrasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, uint16_T c5_y[5])
{
  uint16_T c5_uv0[5];
  int32_T c5_i83;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_uv0, 1, 5, 0U, 1, 0U, 1, 5);
  for (c5_i83 = 0; c5_i83 < 5; c5_i83++) {
    c5_y[c5_i83] = c5_uv0[c5_i83];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_algorithmParams;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  c5_szWfN9fHfXTSMrK3Q1hTVMH c5_y;
  SFc5_identextrasInstanceStruct *chartInstance;
  chartInstance = (SFc5_identextrasInstanceStruct *)chartInstanceVoid;
  c5_b_algorithmParams = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_algorithmParams),
    &c5_thisId);
  sf_mex_destroy(&c5_b_algorithmParams);
  *(c5_szWfN9fHfXTSMrK3Q1hTVMH *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_r_emlrt_marshallIn(SFc5_identextrasInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_identextras, const char_T
  *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_identextras), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_identextras);
  return c5_y;
}

static void init_dsm_address_info(SFc5_identextrasInstanceStruct *chartInstance)
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

void sf_c5_identextras_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3905699143U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(661193310U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(534528816U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2619890128U);
}

mxArray *sf_c5_identextras_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("9vY3pa2cbBXfYAZtKP8dND");
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
      pr[0] = (double)(5);
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
      pr[0] = (double)(5);
      pr[1] = (double)(5);
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
      pr[0] = (double)(7);
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

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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
      pr[0] = (double)(2);
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
      pr[0] = (double)(5);
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
      pr[0] = (double)(5);
      pr[1] = (double)(5);
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
      pr[0] = (double)(7);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_identextras_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_identextras_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_identextras(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[31],T\"A\",},{M[1],M[32],T\"B\",},{M[1],M[33],T\"C\",},{M[1],M[17],T\"PNew\",},{M[1],M[10],T\"estimationError\",},{M[1],M[25],T\"phiMemoryNew\",},{M[1],M[26],T\"psiMemoryNew\",},{M[1],M[29],T\"thetaNew\",},{M[8],M[0],T\"is_active_c5_identextras\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_identextras_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_identextrasInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_identextrasInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _identextrasMachineNumber_,
           5,
           1,
           1,
           0,
           17,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"uMeas");
          _SFD_SET_DATA_PROPS(1,2,0,1,"A");
          _SFD_SET_DATA_PROPS(2,2,0,1,"B");
          _SFD_SET_DATA_PROPS(3,2,0,1,"C");
          _SFD_SET_DATA_PROPS(4,2,0,1,"estimationError");
          _SFD_SET_DATA_PROPS(5,2,0,1,"thetaNew");
          _SFD_SET_DATA_PROPS(6,2,0,1,"PNew");
          _SFD_SET_DATA_PROPS(7,2,0,1,"phiMemoryNew");
          _SFD_SET_DATA_PROPS(8,2,0,1,"psiMemoryNew");
          _SFD_SET_DATA_PROPS(9,1,1,0,"yMeas");
          _SFD_SET_DATA_PROPS(10,1,1,0,"isEnabled");
          _SFD_SET_DATA_PROPS(11,1,1,0,"adg");
          _SFD_SET_DATA_PROPS(12,1,1,0,"theta");
          _SFD_SET_DATA_PROPS(13,1,1,0,"P");
          _SFD_SET_DATA_PROPS(14,1,1,0,"phiMemory");
          _SFD_SET_DATA_PROPS(15,1,1,0,"psiMemory");
          _SFD_SET_DATA_PROPS(16,10,0,0,"algorithmParams");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1800);
        _SFD_CV_INIT_EML_IF(0,1,0,327,412,1560,1796);
        _SFD_CV_INIT_EML_IF(0,1,1,1084,1106,1329,1559);

        {
          static int condStart[] = { 330, 355, 387 };

          static int condEnd[] = { 350, 382, 412 };

          static int pfixExpr[] = { 0, 1, -1, -3, 2, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,330,412,3,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_f_sf_marshallOut,(MexInFcnForType)
            c5_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_f_sf_marshallOut,(MexInFcnForType)
            c5_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)
            c5_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_d_sf_marshallOut,(MexInFcnForType)c5_d_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)
            c5_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 5;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 5;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(16,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_g_sf_marshallOut,(MexInFcnForType)c5_h_sf_marshallIn);

        {
          real_T *c5_uMeas;
          real_T *c5_estimationError;
          real_T *c5_yMeas;
          real_T *c5_isEnabled;
          real_T *c5_adg;
          real_T (*c5_A)[4];
          real_T (*c5_B)[4];
          real_T (*c5_C)[2];
          real_T (*c5_thetaNew)[5];
          real_T (*c5_PNew)[25];
          real_T (*c5_phiMemoryNew)[7];
          real_T (*c5_psiMemoryNew)[7];
          real_T (*c5_theta)[5];
          real_T (*c5_P)[25];
          real_T (*c5_phiMemory)[7];
          real_T (*c5_psiMemory)[7];
          c5_psiMemory = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 7);
          c5_phiMemory = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 6);
          c5_P = (real_T (*)[25])ssGetInputPortSignal(chartInstance->S, 5);
          c5_theta = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 4);
          c5_adg = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c5_isEnabled = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_yMeas = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_psiMemoryNew = (real_T (*)[7])ssGetOutputPortSignal
            (chartInstance->S, 8);
          c5_phiMemoryNew = (real_T (*)[7])ssGetOutputPortSignal
            (chartInstance->S, 7);
          c5_PNew = (real_T (*)[25])ssGetOutputPortSignal(chartInstance->S, 6);
          c5_thetaNew = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 5);
          c5_estimationError = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            4);
          c5_C = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
          c5_B = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
          c5_A = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_uMeas = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_uMeas);
          _SFD_SET_DATA_VALUE_PTR(1U, *c5_A);
          _SFD_SET_DATA_VALUE_PTR(2U, *c5_B);
          _SFD_SET_DATA_VALUE_PTR(3U, *c5_C);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_estimationError);
          _SFD_SET_DATA_VALUE_PTR(5U, *c5_thetaNew);
          _SFD_SET_DATA_VALUE_PTR(6U, *c5_PNew);
          _SFD_SET_DATA_VALUE_PTR(7U, *c5_phiMemoryNew);
          _SFD_SET_DATA_VALUE_PTR(8U, *c5_psiMemoryNew);
          _SFD_SET_DATA_VALUE_PTR(9U, c5_yMeas);
          _SFD_SET_DATA_VALUE_PTR(10U, c5_isEnabled);
          _SFD_SET_DATA_VALUE_PTR(11U, c5_adg);
          _SFD_SET_DATA_VALUE_PTR(12U, *c5_theta);
          _SFD_SET_DATA_VALUE_PTR(13U, *c5_P);
          _SFD_SET_DATA_VALUE_PTR(14U, *c5_phiMemory);
          _SFD_SET_DATA_VALUE_PTR(15U, *c5_psiMemory);
          _SFD_SET_DATA_VALUE_PTR(16U, &chartInstance->c5_algorithmParams);
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
  return "qFRQ5IIDUSBOLgeBLu1TIG";
}

static void sf_opaque_initialize_c5_identextras(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_identextrasInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c5_identextras((SFc5_identextrasInstanceStruct*)
    chartInstanceVar);
  initialize_c5_identextras((SFc5_identextrasInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_identextras(void *chartInstanceVar)
{
  enable_c5_identextras((SFc5_identextrasInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_identextras(void *chartInstanceVar)
{
  disable_c5_identextras((SFc5_identextrasInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_identextras(void *chartInstanceVar)
{
  sf_gateway_c5_identextras((SFc5_identextrasInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_identextras(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_identextras
    ((SFc5_identextrasInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_identextras();/* state var info */
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

extern void sf_internal_set_sim_state_c5_identextras(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c5_identextras();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_identextras((SFc5_identextrasInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_identextras(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_identextras(S);
}

static void sf_opaque_set_sim_state_c5_identextras(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c5_identextras(S, st);
}

static void sf_opaque_terminate_c5_identextras(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_identextrasInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_identextras_optimization_info();
    }

    finalize_c5_identextras((SFc5_identextrasInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_identextras((SFc5_identextrasInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_identextras(SimStruct *S)
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
    initialize_params_c5_identextras((SFc5_identextrasInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_identextras(SimStruct *S)
{
  /* Actual parameters from chart:
     algorithmParams
   */
  const char_T *rtParamNames[] = { "algorithmParams" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_identextras_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,5);
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
        infoStruct,5,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,8);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=8; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1576483556U));
  ssSetChecksum1(S,(359809751U));
  ssSetChecksum2(S,(2720506634U));
  ssSetChecksum3(S,(805911119U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_identextras(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_identextras(SimStruct *S)
{
  SFc5_identextrasInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_identextrasInstanceStruct *)utMalloc(sizeof
    (SFc5_identextrasInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_identextrasInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_identextras;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_identextras;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_identextras;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_identextras;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_identextras;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_identextras;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_identextras;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_identextras;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_identextras;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_identextras;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_identextras;
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

void c5_identextras_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_identextras(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_identextras(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_identextras(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_identextras_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
