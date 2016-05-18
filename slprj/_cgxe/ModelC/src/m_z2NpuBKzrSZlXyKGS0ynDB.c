/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ModelC_cgxe.h"
#include "m_z2NpuBKzrSZlXyKGS0ynDB.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 24, 5, "repmat",
  "C:\\Program Files\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"
};

static emlrtMCInfo b_emlrtMCI = { 1, 1, "SystemCore",
  "C:\\Program Files\\MATLAB\\R2014a\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"
};

/* Function Declarations */
static void mw__internal__start___fcn(InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB
  *moduleInstance);
static void mw__internal__initialize__fcn(InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *
  moduleInstance);
static void mw__internal__outputs__fcn(InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB
  *moduleInstance);
static void mw__internal__update__fcn(InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB
  *moduleInstance);
static void mw__internal__terminate__fcn(InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB
  *moduleInstance);
static const mxArray *mw__internal__name__resolution__fcn(void);
static void info_helper(const mxArray **info);
static const mxArray *emlrt_marshallOut(const char * u);
static const mxArray *b_emlrt_marshallOut(const uint32_T u);
static const mxArray *mw__internal__autoInference__fcn(void);
static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *moduleInstance);
static MavlinkMsg emlrt_marshallIn(const mxArray *b_sysobj, const char_T
  *identifier);
static MavlinkMsg b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *
  parentId);
static boolean_T c_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static boolean_T d_emlrt_marshallIn(const mxArray *b_sysobj_not_empty, const
  char_T *identifier);
static void mw__internal__setSimState__fcn(InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB
  *moduleInstance, const mxArray *st);
static void error(const mxArray *b, emlrtMCInfo *location);
static const mxArray *message(const mxArray *b, const mxArray *c, emlrtMCInfo
  *location);
static boolean_T e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);

/* Function Definitions */
static void mw__internal__start___fcn(InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB
  *moduleInstance)
{
  MavlinkMsg *obj;
  boolean_T flag;
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 51 };

  const mxArray *m0;
  char_T cv0[51];
  int32_T i0;
  static char_T cv1[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv1[2] = { 1, 5 };

  char_T cv2[5];
  static char_T cv3[5] = { 's', 'e', 't', 'u', 'p' };

  if (!moduleInstance->sysobj_not_empty) {
    obj = &moduleInstance->sysobj;
    obj->isInitialized = false;
    obj->isReleased = false;
    obj->tunablePropertyChanged = false;
    moduleInstance->sysobj_not_empty = true;
    obj = &moduleInstance->sysobj;
    if (obj->isInitialized && !obj->isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      obj->TunablePropsChanged = true;
    }

    obj = &moduleInstance->sysobj;
    if (obj->isInitialized && !obj->isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      obj->TunablePropsChanged = true;
      obj->tunablePropertyChanged = true;
    }
  }

  obj = &moduleInstance->sysobj;
  if (obj->isInitialized) {
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    for (i0 = 0; i0 < 51; i0++) {
      cv0[i0] = cv1[i0];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 51, m0, cv0);
    emlrtAssign(&y, m0);
    b_y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    for (i0 = 0; i0 < 5; i0++) {
      cv2[i0] = cv3[i0];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 5, m0, cv2);
    emlrtAssign(&b_y, m0);
    error(message(y, b_y, &b_emlrtMCI), &b_emlrtMCI);
  }

  obj->isInitialized = true;
  obj->TunablePropsChanged = false;
}

static void mw__internal__initialize__fcn(InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *
  moduleInstance)
{
  MavlinkMsg *obj;
  boolean_T flag;
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 45 };

  const mxArray *m1;
  char_T cv4[45];
  int32_T i1;
  static char_T cv5[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 8 };

  char_T cv6[8];
  static char_T cv7[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  const mxArray *c_y;
  static const int32_T iv4[2] = { 1, 45 };

  const mxArray *d_y;
  static const int32_T iv5[2] = { 1, 5 };

  char_T cv8[5];
  static char_T cv9[5] = { 'r', 'e', 's', 'e', 't' };

  if (!moduleInstance->sysobj_not_empty) {
    obj = &moduleInstance->sysobj;
    obj->isInitialized = false;
    obj->isReleased = false;
    obj->tunablePropertyChanged = false;
    moduleInstance->sysobj_not_empty = true;
    obj = &moduleInstance->sysobj;
    if (obj->isInitialized && !obj->isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      obj->TunablePropsChanged = true;
    }

    obj = &moduleInstance->sysobj;
    if (obj->isInitialized && !obj->isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      obj->TunablePropsChanged = true;
      obj->tunablePropertyChanged = true;
    }
  }

  obj = &moduleInstance->sysobj;
  if (obj->isReleased) {
    y = NULL;
    m1 = emlrtCreateCharArray(2, iv2);
    for (i1 = 0; i1 < 45; i1++) {
      cv4[i1] = cv5[i1];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m1, cv4);
    emlrtAssign(&y, m1);
    b_y = NULL;
    m1 = emlrtCreateCharArray(2, iv3);
    for (i1 = 0; i1 < 8; i1++) {
      cv6[i1] = cv7[i1];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m1, cv6);
    emlrtAssign(&b_y, m1);
    error(message(y, b_y, &b_emlrtMCI), &b_emlrtMCI);
  }

  flag = obj->isInitialized;
  if (flag && moduleInstance->sysobj.isReleased) {
    c_y = NULL;
    m1 = emlrtCreateCharArray(2, iv4);
    for (i1 = 0; i1 < 45; i1++) {
      cv4[i1] = cv5[i1];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m1, cv4);
    emlrtAssign(&c_y, m1);
    d_y = NULL;
    m1 = emlrtCreateCharArray(2, iv5);
    for (i1 = 0; i1 < 5; i1++) {
      cv8[i1] = cv9[i1];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 5, m1, cv8);
    emlrtAssign(&d_y, m1);
    error(message(c_y, d_y, &b_emlrtMCI), &b_emlrtMCI);
  }
}

static void mw__internal__outputs__fcn(InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB
  *moduleInstance)
{
  MavlinkMsg *obj;
  boolean_T flag;
  const mxArray *y;
  static const int32_T iv6[2] = { 1, 45 };

  const mxArray *m2;
  char_T cv10[45];
  int32_T i2;
  static char_T cv11[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv7[2] = { 1, 4 };

  char_T cv12[4];
  static char_T cv13[4] = { 's', 't', 'e', 'p' };

  const mxArray *c_y;
  static const int32_T iv8[2] = { 1, 51 };

  char_T cv14[51];
  static char_T cv15[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  const mxArray *d_y;
  static const int32_T iv9[2] = { 1, 5 };

  char_T cv16[5];
  static char_T cv17[5] = { 's', 'e', 't', 'u', 'p' };

  if (!moduleInstance->sysobj_not_empty) {
    obj = &moduleInstance->sysobj;
    obj->isInitialized = false;
    obj->isReleased = false;
    obj->tunablePropertyChanged = false;
    moduleInstance->sysobj_not_empty = true;
    obj = &moduleInstance->sysobj;
    if (obj->isInitialized && !obj->isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      obj->TunablePropsChanged = true;
    }

    obj = &moduleInstance->sysobj;
    if (obj->isInitialized && !obj->isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      obj->TunablePropsChanged = true;
      obj->tunablePropertyChanged = true;
    }
  }

  obj = &moduleInstance->sysobj;
  if (obj->isReleased) {
    y = NULL;
    m2 = emlrtCreateCharArray(2, iv6);
    for (i2 = 0; i2 < 45; i2++) {
      cv10[i2] = cv11[i2];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m2, cv10);
    emlrtAssign(&y, m2);
    b_y = NULL;
    m2 = emlrtCreateCharArray(2, iv7);
    for (i2 = 0; i2 < 4; i2++) {
      cv12[i2] = cv13[i2];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 4, m2, cv12);
    emlrtAssign(&b_y, m2);
    error(message(y, b_y, &b_emlrtMCI), &b_emlrtMCI);
  }

  if (!obj->isInitialized) {
    if (obj->isInitialized) {
      c_y = NULL;
      m2 = emlrtCreateCharArray(2, iv8);
      for (i2 = 0; i2 < 51; i2++) {
        cv14[i2] = cv15[i2];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 51, m2, cv14);
      emlrtAssign(&c_y, m2);
      d_y = NULL;
      m2 = emlrtCreateCharArray(2, iv9);
      for (i2 = 0; i2 < 5; i2++) {
        cv16[i2] = cv17[i2];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 5, m2, cv16);
      emlrtAssign(&d_y, m2);
      error(message(c_y, d_y, &b_emlrtMCI), &b_emlrtMCI);
    }

    obj->isInitialized = true;
    obj->TunablePropsChanged = false;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    obj->tunablePropertyChanged = false;
  }

  /* function setupImpl(~) */
  /*  Implement tasks that need to be performed only once,  */
  /*  such as pre-computed constants. */
  /* end */
}

static void mw__internal__update__fcn(InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void mw__internal__terminate__fcn(InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB
  *moduleInstance)
{
  MavlinkMsg *obj;
  boolean_T flag;
  const mxArray *y;
  static const int32_T iv10[2] = { 1, 45 };

  const mxArray *m3;
  char_T cv18[45];
  int32_T i3;
  static char_T cv19[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv11[2] = { 1, 8 };

  char_T cv20[8];
  static char_T cv21[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  const mxArray *c_y;
  static const int32_T iv12[2] = { 1, 45 };

  const mxArray *d_y;
  static const int32_T iv13[2] = { 1, 7 };

  char_T cv22[7];
  static char_T cv23[7] = { 'r', 'e', 'l', 'e', 'a', 's', 'e' };

  if (!moduleInstance->sysobj_not_empty) {
    obj = &moduleInstance->sysobj;
    obj->isInitialized = false;
    obj->isReleased = false;
    obj->tunablePropertyChanged = false;
    moduleInstance->sysobj_not_empty = true;
    obj = &moduleInstance->sysobj;
    if (obj->isInitialized && !obj->isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      obj->TunablePropsChanged = true;
    }

    obj = &moduleInstance->sysobj;
    if (obj->isInitialized && !obj->isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      obj->TunablePropsChanged = true;
      obj->tunablePropertyChanged = true;
    }
  }

  obj = &moduleInstance->sysobj;
  if (obj->isReleased) {
    y = NULL;
    m3 = emlrtCreateCharArray(2, iv10);
    for (i3 = 0; i3 < 45; i3++) {
      cv18[i3] = cv19[i3];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m3, cv18);
    emlrtAssign(&y, m3);
    b_y = NULL;
    m3 = emlrtCreateCharArray(2, iv11);
    for (i3 = 0; i3 < 8; i3++) {
      cv20[i3] = cv21[i3];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m3, cv20);
    emlrtAssign(&b_y, m3);
    error(message(y, b_y, &b_emlrtMCI), &b_emlrtMCI);
  }

  flag = obj->isInitialized;
  if (flag) {
    obj = &moduleInstance->sysobj;
    if (obj->isReleased) {
      c_y = NULL;
      m3 = emlrtCreateCharArray(2, iv12);
      for (i3 = 0; i3 < 45; i3++) {
        cv18[i3] = cv19[i3];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m3, cv18);
      emlrtAssign(&c_y, m3);
      d_y = NULL;
      m3 = emlrtCreateCharArray(2, iv13);
      for (i3 = 0; i3 < 7; i3++) {
        cv22[i3] = cv23[i3];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 7, m3, cv22);
      emlrtAssign(&d_y, m3);
      error(message(c_y, d_y, &b_emlrtMCI), &b_emlrtMCI);
    }

    if (obj->isInitialized) {
      obj->isReleased = true;
    }
  }
}

static const mxArray *mw__internal__name__resolution__fcn(void)
{
  const mxArray *nameCaptureInfo;
  nameCaptureInfo = NULL;
  emlrtAssign(&nameCaptureInfo, emlrtCreateStructMatrix(35, 1, 0, NULL));
  info_helper(&nameCaptureInfo);
  emlrtNameCapturePostProcessR2013b(&nameCaptureInfo);
  return nameCaptureInfo;
}

static void info_helper(const mxArray **info)
{
  emlrtAddField(*info, emlrt_marshallOut(""), "context", 0);
  emlrtAddField(*info, emlrt_marshallOut("repmat"), "name", 0);
  emlrtAddField(*info, emlrt_marshallOut("struct"), "dominantType", 0);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "resolved", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(1372578814U), "fileTimeLo", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 0);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 1);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assert"), "name", 1);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 1);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                "resolved", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(1363710956U), "fileTimeLo", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 1);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 2);
  emlrtAddField(*info, emlrt_marshallOut("eml_assert_valid_size_arg"), "name", 2);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 2);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "resolved", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(1368179430U), "fileTimeLo", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 2);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 3);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 3);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 3);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(1363710956U), "fileTimeLo", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 3);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                "context", 4);
  emlrtAddField(*info, emlrt_marshallOut("isinf"), "name", 4);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 4);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(1363710256U), "fileTimeLo", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 4);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context", 5);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 5);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 5);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(1363710956U), "fileTimeLo", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 5);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 6);
  emlrtAddField(*info, emlrt_marshallOut("eml_is_integer_class"), "name", 6);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 6);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                "resolved", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(1286818782U), "fileTimeLo", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 6);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 7);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 7);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 7);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(1362258282U), "fileTimeLo", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 7);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context", 8);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 8);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 8);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(1381850300U), "fileTimeLo", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 8);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 9);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 9);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 9);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(1362258282U), "fileTimeLo", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 9);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context", 10);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 10);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 10);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(1381850300U), "fileTimeLo", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 10);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 11);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexIntRelop"), "name",
                11);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 11);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                "resolved", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(1326724722U), "fileTimeLo", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 11);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                "context", 12);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 12);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 12);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(1381850300U), "fileTimeLo", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 12);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                "context", 13);
  emlrtAddField(*info, emlrt_marshallOut("eml_float_model"), "name", 13);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 13);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                "resolved", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(1326724396U), "fileTimeLo", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 13);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                "context", 14);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 14);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 14);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(1362258282U), "fileTimeLo", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 14);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 15);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 15);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 15);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(1323166978U), "fileTimeLo", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 15);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 16);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 16);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 16);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(1362258282U), "fileTimeLo", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 16);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 17);
  emlrtAddField(*info, emlrt_marshallOut("max"), "name", 17);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 17);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(1311251716U), "fileTimeLo", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 17);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context", 18);
  emlrtAddField(*info, emlrt_marshallOut("eml_min_or_max"), "name", 18);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 18);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                "resolved", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(1378292384U), "fileTimeLo", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 18);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 19);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 19);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 19);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                19);
  emlrtAddField(*info, b_emlrt_marshallOut(1375977088U), "fileTimeLo", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 19);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                20);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalarEg"), "name", 20);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 20);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                "resolved", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(1389304320U), "fileTimeLo", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 20);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 21);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_alloc"), "name", 21);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 21);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "resolved", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(1375977088U), "fileTimeLo", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 21);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "context", 22);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalexpAlloc"), "name",
                22);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 22);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                "resolved", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(1389304320U), "fileTimeLo", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 22);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 23);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 23);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 23);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(1323166978U), "fileTimeLo", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 23);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                "context", 24);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 24);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 24);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                24);
  emlrtAddField(*info, b_emlrt_marshallOut(1375977088U), "fileTimeLo", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 24);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                "context", 25);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 25);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 25);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(1363710956U), "fileTimeLo", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 25);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 26);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 26);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 26);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(1389304322U), "fileTimeLo", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 26);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "context", 27);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemProp"),
                "name", 27);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 27);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "resolved", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(1388455090U), "fileTimeLo", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 27);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "context", 28);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 28);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 28);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(1389304322U), "fileTimeLo", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 28);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "context", 29);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemCore"),
                "name", 29);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 29);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "resolved", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(1388455090U), "fileTimeLo", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 29);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/admin/Documents/MATLAB/MavlinkMsg.m"), "context", 30);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.System"), "name",
                30);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 30);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "resolved", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(1388455088U), "fileTimeLo", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 30);
  emlrtAddField(*info, emlrt_marshallOut(""), "context", 31);
  emlrtAddField(*info, emlrt_marshallOut("MavlinkMsg"), "name", 31);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 31);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/admin/Documents/MATLAB/MavlinkMsg.m"), "resolved", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(1458860685U), "fileTimeLo", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 31);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 32);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemProp"),
                "name", 32);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 32);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "resolved", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(1388455090U), "fileTimeLo", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 32);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 33);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 33);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 33);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(1381850300U), "fileTimeLo", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 33);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "context", 34);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemCore"),
                "name", 34);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 34);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "resolved", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(1388455090U), "fileTimeLo", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 34);
}

static const mxArray *emlrt_marshallOut(const char * u)
{
  const mxArray *y;
  const mxArray *m4;
  y = NULL;
  m4 = emlrtCreateString(u);
  emlrtAssign(&y, m4);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const uint32_T u)
{
  const mxArray *y;
  const mxArray *m5;
  y = NULL;
  m5 = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)mxGetData(m5) = u;
  emlrtAssign(&y, m5);
  return y;
}

static const mxArray *mw__internal__autoInference__fcn(void)
{
  const mxArray *infoCache;
  s7UBIGHSehQY1gCsIQWwr5C expl_temp;
  s7UBIGHSehQY1gCsIQWwr5C b_expl_temp;
  s7UBIGHSehQY1gCsIQWwr5C c_expl_temp;
  s7UBIGHSehQY1gCsIQWwr5C d_expl_temp;
  int32_T i4;
  static uint32_T t1_chksum[4] = { 3076484946U, 2803738438U, 589589609U,
    2105992559U };

  s7UBIGHSehQY1gCsIQWwr5C checksums[4];
  char_T u_RestoreInfo_DispatcherInfo_objTypeName[10];
  static char_T t2_DispatcherInfo_objTypeName[10] = { 'M', 'a', 'v', 'l', 'i',
    'n', 'k', 'M', 's', 'g' };

  char_T u_RestoreInfo_DispatcherInfo_sysObjChksum[22];
  static char_T t2_DispatcherInfo_sysObjChksum[22] = { 'y', 'e', 'H', '6', 'B',
    'U', 'T', 'm', 'z', 'I', 'T', 'J', 'q', 'b', 'x', 'w', 's', 'G', 'T', 'K',
    'L', 'E' };

  uint32_T b_t1_chksum[4];
  static uint32_T t2_cgxeChksum[4] = { 1146116233U, 3082269321U, 3915340638U,
    443046735U };

  char_T u_slVer[3];
  static char_T cv24[3] = { '8', '.', '3' };

  const mxArray *y;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  int32_T iv14[2];
  const mxArray *e_y;
  const mxArray *f_y;
  static const int32_T iv15[2] = { 1, 10 };

  const mxArray *m6;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  static const int32_T iv16[2] = { 1, 22 };

  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  static const int32_T iv17[2] = { 0, 0 };

  const mxArray *p_y;
  static const int32_T iv18[2] = { 1, 4 };

  real_T *pData;
  int32_T i;
  const mxArray *q_y;
  s7UBIGHSehQY1gCsIQWwr5C u[4];
  const mxArray *r_y;
  const s7UBIGHSehQY1gCsIQWwr5C *r0;
  real_T b_u[4];
  const mxArray *s_y;
  static const int32_T iv19[2] = { 1, 4 };

  const mxArray *t_y;
  static const int32_T iv20[2] = { 1, 3 };

  infoCache = NULL;
  for (i4 = 0; i4 < 4; i4++) {
    expl_temp.chksum[i4] = 0.0;
    b_expl_temp.chksum[i4] = 0.0;
    c_expl_temp.chksum[i4] = 0.0;
    d_expl_temp.chksum[i4] = (real_T)t1_chksum[i4];
  }

  checksums[0] = expl_temp;
  checksums[1] = b_expl_temp;
  checksums[2] = c_expl_temp;
  checksums[3] = d_expl_temp;
  for (i4 = 0; i4 < 10; i4++) {
    u_RestoreInfo_DispatcherInfo_objTypeName[i4] =
      t2_DispatcherInfo_objTypeName[i4];
  }

  for (i4 = 0; i4 < 22; i4++) {
    u_RestoreInfo_DispatcherInfo_sysObjChksum[i4] =
      t2_DispatcherInfo_sysObjChksum[i4];
  }

  for (i4 = 0; i4 < 4; i4++) {
    b_t1_chksum[i4] = t2_cgxeChksum[i4];
  }

  for (i4 = 0; i4 < 3; i4++) {
    u_slVer[i4] = cv24[i4];
  }

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  c_y = NULL;
  emlrtAssign(&c_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  d_y = NULL;
  for (i4 = 0; i4 < 2; i4++) {
    iv14[i4] = 1 - i4;
  }

  emlrtAssign(&d_y, emlrtCreateStructArray(2, iv14, 0, NULL));
  emlrtAddField(d_y, NULL, "dimModes", 0);
  emlrtAddField(d_y, NULL, "dims", 0);
  emlrtAddField(d_y, NULL, "dType", 0);
  emlrtAddField(d_y, NULL, "complexity", 0);
  emlrtAddField(d_y, NULL, "outputBuiltInDTEqUsed", 0);
  emlrtAddField(c_y, d_y, "Ports", 0);
  e_y = NULL;
  for (i4 = 0; i4 < 2; i4++) {
    iv14[i4] = 1 - i4;
  }

  emlrtAssign(&e_y, emlrtCreateStructArray(2, iv14, 0, NULL));
  emlrtAddField(e_y, NULL, "names", 0);
  emlrtAddField(e_y, NULL, "dims", 0);
  emlrtAddField(e_y, NULL, "dType", 0);
  emlrtAddField(e_y, NULL, "complexity", 0);
  emlrtAddField(c_y, e_y, "dWork", 0);
  f_y = NULL;
  m6 = emlrtCreateCharArray(2, iv15);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 10, m6,
    u_RestoreInfo_DispatcherInfo_objTypeName);
  emlrtAssign(&f_y, m6);
  emlrtAddField(c_y, f_y, "objTypeName", 0);
  g_y = NULL;
  m6 = emlrtCreateDoubleScalar(4.0);
  emlrtAssign(&g_y, m6);
  emlrtAddField(c_y, g_y, "objTypeSize", 0);
  h_y = NULL;
  for (i4 = 0; i4 < 2; i4++) {
    iv14[i4] = 1 - i4;
  }

  emlrtAssign(&h_y, emlrtCreateStructArray(2, iv14, 0, NULL));
  emlrtAddField(h_y, NULL, "names", 0);
  emlrtAddField(h_y, NULL, "dims", 0);
  emlrtAddField(h_y, NULL, "dType", 0);
  emlrtAddField(h_y, NULL, "dTypeSize", 0);
  emlrtAddField(h_y, NULL, "dTypeName", 0);
  emlrtAddField(h_y, NULL, "dTypeChksum", 0);
  emlrtAddField(h_y, NULL, "complexity", 0);
  emlrtAddField(c_y, h_y, "persisVarDWork", 0);
  i_y = NULL;
  m6 = emlrtCreateCharArray(2, iv16);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 22, m6,
    u_RestoreInfo_DispatcherInfo_sysObjChksum);
  emlrtAssign(&i_y, m6);
  emlrtAddField(c_y, i_y, "sysObjChksum", 0);
  j_y = NULL;
  emlrtAssign(&j_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  k_y = NULL;
  for (i4 = 0; i4 < 2; i4++) {
    iv14[i4] = 1 - i4;
  }

  emlrtAssign(&k_y, emlrtCreateStructArray(2, iv14, 0, NULL));
  emlrtAddField(k_y, NULL, "Index", 0);
  emlrtAddField(k_y, NULL, "DataType", 0);
  emlrtAddField(k_y, NULL, "IsSigned", 0);
  emlrtAddField(k_y, NULL, "MantBits", 0);
  emlrtAddField(k_y, NULL, "FixExp", 0);
  emlrtAddField(k_y, NULL, "Slope", 0);
  emlrtAddField(k_y, NULL, "Bias", 0);
  emlrtAddField(j_y, k_y, "Out", 0);
  l_y = NULL;
  for (i4 = 0; i4 < 2; i4++) {
    iv14[i4] = 1 - i4;
  }

  emlrtAssign(&l_y, emlrtCreateStructArray(2, iv14, 0, NULL));
  emlrtAddField(l_y, NULL, "Index", 0);
  emlrtAddField(l_y, NULL, "DataType", 0);
  emlrtAddField(l_y, NULL, "IsSigned", 0);
  emlrtAddField(l_y, NULL, "MantBits", 0);
  emlrtAddField(l_y, NULL, "FixExp", 0);
  emlrtAddField(l_y, NULL, "Slope", 0);
  emlrtAddField(l_y, NULL, "Bias", 0);
  emlrtAddField(j_y, l_y, "DW", 0);
  m_y = NULL;
  for (i4 = 0; i4 < 2; i4++) {
    iv14[i4] = 1 - i4;
  }

  emlrtAssign(&m_y, emlrtCreateStructArray(2, iv14, 0, NULL));
  emlrtAddField(m_y, NULL, "Index", 0);
  emlrtAddField(m_y, NULL, "DataType", 0);
  emlrtAddField(m_y, NULL, "IsSigned", 0);
  emlrtAddField(m_y, NULL, "MantBits", 0);
  emlrtAddField(m_y, NULL, "FixExp", 0);
  emlrtAddField(m_y, NULL, "Slope", 0);
  emlrtAddField(m_y, NULL, "Bias", 0);
  emlrtAddField(j_y, m_y, "PersisDW", 0);
  emlrtAddField(c_y, j_y, "mapsInfo", 0);
  n_y = NULL;
  m6 = emlrtCreateDoubleScalar(2.0);
  emlrtAssign(&n_y, m6);
  emlrtAddField(c_y, n_y, "objDWorkTypeNameIndex", 0);
  o_y = NULL;
  m6 = emlrtCreateNumericArray(2, iv17, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&o_y, m6);
  emlrtAddField(c_y, o_y, "inputDFFlagsIndexField", 0);
  emlrtAddField(b_y, c_y, "DispatcherInfo", 0);
  p_y = NULL;
  m6 = emlrtCreateNumericArray(2, iv18, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  for (i = 0; i < 4; i++) {
    pData[i] = (real_T)b_t1_chksum[i];
  }

  emlrtAssign(&p_y, m6);
  emlrtAddField(b_y, p_y, "cgxeChksum", 0);
  emlrtAddField(y, b_y, "RestoreInfo", 0);
  q_y = NULL;
  emlrtAssign(&q_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  for (i4 = 0; i4 < 4; i4++) {
    u[i4] = checksums[i4];
  }

  r_y = NULL;
  for (i4 = 0; i4 < 2; i4++) {
    iv14[i4] = 1 + 3 * i4;
  }

  emlrtAssign(&r_y, emlrtCreateStructArray(2, iv14, 0, NULL));
  for (i4 = 0; i4 < 4; i4++) {
    r0 = &u[i4];
    for (i = 0; i < 4; i++) {
      b_u[i] = r0->chksum[i];
    }

    s_y = NULL;
    m6 = emlrtCreateNumericArray(2, iv19, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T *)mxGetPr(m6);
    for (i = 0; i < 4; i++) {
      pData[i] = b_u[i];
    }

    emlrtAssign(&s_y, m6);
    emlrtAddField(r_y, s_y, "chksum", i4);
  }

  emlrtAddField(q_y, r_y, "checksums", 0);
  emlrtAddField(y, q_y, "VerificationInfo", 0);
  t_y = NULL;
  m6 = emlrtCreateCharArray(2, iv20);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 3, m6, u_slVer);
  emlrtAssign(&t_y, m6);
  emlrtAddField(y, t_y, "slVer", 0);
  emlrtAssign(&infoCache, y);
  return infoCache;
}

static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *moduleInstance)
{
  const mxArray *st;
  const mxArray *y;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m7;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  st = NULL;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(2, 1));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  c_y = NULL;
  m7 = emlrtCreateLogicalScalar(moduleInstance->sysobj.tunablePropertyChanged);
  emlrtAssign(&c_y, m7);
  emlrtAddField(b_y, c_y, "tunablePropertyChanged", 0);
  d_y = NULL;
  m7 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isInitialized);
  emlrtAssign(&d_y, m7);
  emlrtAddField(b_y, d_y, "isInitialized", 0);
  e_y = NULL;
  m7 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isReleased);
  emlrtAssign(&e_y, m7);
  emlrtAddField(b_y, e_y, "isReleased", 0);
  f_y = NULL;
  m7 = emlrtCreateLogicalScalar(moduleInstance->sysobj.TunablePropsChanged);
  emlrtAssign(&f_y, m7);
  emlrtAddField(b_y, f_y, "TunablePropsChanged", 0);
  emlrtSetCell(y, 0, b_y);
  g_y = NULL;
  m7 = emlrtCreateLogicalScalar(moduleInstance->sysobj_not_empty);
  emlrtAssign(&g_y, m7);
  emlrtSetCell(y, 1, g_y);
  emlrtAssign(&st, y);
  return st;
}

static MavlinkMsg emlrt_marshallIn(const mxArray *b_sysobj, const char_T
  *identifier)
{
  MavlinkMsg y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(emlrtAlias(b_sysobj), &thisId);
  emlrtDestroyArray(&b_sysobj);
  return y;
}

static MavlinkMsg b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *
  parentId)
{
  MavlinkMsg y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[4] = { "tunablePropertyChanged",
    "isInitialized", "isReleased", "TunablePropsChanged" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 4, fieldNames, 0U, 0);
  thisId.fIdentifier = "tunablePropertyChanged";
  y.tunablePropertyChanged = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "tunablePropertyChanged")), &thisId);
  thisId.fIdentifier = "isInitialized";
  y.isInitialized = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isInitialized")), &thisId);
  thisId.fIdentifier = "isReleased";
  y.isReleased = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isReleased")), &thisId);
  thisId.fIdentifier = "TunablePropsChanged";
  y.TunablePropsChanged = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "TunablePropsChanged")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T c_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  boolean_T y;
  y = e_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T d_emlrt_marshallIn(const mxArray *b_sysobj_not_empty, const
  char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = c_emlrt_marshallIn(emlrtAlias(b_sysobj_not_empty), &thisId);
  emlrtDestroyArray(&b_sysobj_not_empty);
  return y;
}

static void mw__internal__setSimState__fcn(InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB
  *moduleInstance, const mxArray *st)
{
  const mxArray *u;
  u = emlrtAlias(st);
  moduleInstance->sysobj = emlrt_marshallIn(emlrtAlias(emlrtGetCell
    (emlrtRootTLSGlobal, u, 0)), "sysobj");
  moduleInstance->sysobj_not_empty = d_emlrt_marshallIn(emlrtAlias(emlrtGetCell
    (emlrtRootTLSGlobal, u, 1)), "sysobj_not_empty");
  emlrtDestroyArray(&u);
  emlrtDestroyArray(&st);
}

static void error(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "error", true,
                        location);
}

static const mxArray *message(const mxArray *b, const mxArray *c, emlrtMCInfo
  *location)
{
  const mxArray *pArrays[2];
  const mxArray *m8;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m8, 2, pArrays, "message",
    true, location);
}

static boolean_T e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  boolean_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "logical", false, 0U,
    0);
  ret = *mxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

/* CGXE Glue Code */
static void mdlOutputs_z2NpuBKzrSZlXyKGS0ynDB(SimStruct *S, int_T tid)
{
  InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *moduleInstance;
  moduleInstance = (InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mw__internal__outputs__fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static void mdlInitialize_z2NpuBKzrSZlXyKGS0ynDB(SimStruct *S)
{
  InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *moduleInstance;
  moduleInstance = (InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mw__internal__initialize__fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static void mdlUpdate_z2NpuBKzrSZlXyKGS0ynDB(SimStruct *S, int_T tid)
{
  InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *moduleInstance;
  moduleInstance = (InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mw__internal__update__fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static mxArray* getSimState_z2NpuBKzrSZlXyKGS0ynDB(SimStruct *S)
{
  InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *moduleInstance;
  mxArray* mxSS;
  moduleInstance = (InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mxSS = (mxArray *) mw__internal__getSimState__fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();
  return mxSS;
}

static void setSimState_z2NpuBKzrSZlXyKGS0ynDB(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *moduleInstance;
  moduleInstance = (InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mw__internal__setSimState__fcn(moduleInstance, emlrtAlias(ss));
  CGXERT_LEAVE_CHECK();
}

static void mdlTerminate_z2NpuBKzrSZlXyKGS0ynDB(SimStruct *S)
{
  InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *moduleInstance;
  moduleInstance = (InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mw__internal__terminate__fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();
  free((void *)moduleInstance);
  ssSetUserData(S, NULL);
}

static void mdlStart_z2NpuBKzrSZlXyKGS0ynDB(SimStruct *S)
{
  InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *moduleInstance;
  moduleInstance = (InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB *)calloc(1, sizeof
    (InstanceStruct_z2NpuBKzrSZlXyKGS0ynDB));
  moduleInstance->S = S;
  ssSetUserData(S, (void *)moduleInstance);
  CGXERT_ENTER_CHECK();
  mw__internal__start___fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }

  ssSetmdlOutputs(S, mdlOutputs_z2NpuBKzrSZlXyKGS0ynDB);
  ssSetmdlInitializeConditions(S, mdlInitialize_z2NpuBKzrSZlXyKGS0ynDB);
  ssSetmdlUpdate(S, mdlUpdate_z2NpuBKzrSZlXyKGS0ynDB);
  ssSetmdlTerminate(S, mdlTerminate_z2NpuBKzrSZlXyKGS0ynDB);
}

static void mdlProcessParameters_z2NpuBKzrSZlXyKGS0ynDB(SimStruct *S)
{
}

void method_dispatcher_z2NpuBKzrSZlXyKGS0ynDB(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_z2NpuBKzrSZlXyKGS0ynDB(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_z2NpuBKzrSZlXyKGS0ynDB(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_z2NpuBKzrSZlXyKGS0ynDB(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_z2NpuBKzrSZlXyKGS0ynDB(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: z2NpuBKzrSZlXyKGS0ynDB.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

int autoInfer_dispatcher_z2NpuBKzrSZlXyKGS0ynDB(mxArray* plhs[], const char
  * commandName)
{
  if (strcmp(commandName, "NameResolution") == 0) {
    plhs[0] = (mxArray*) mw__internal__name__resolution__fcn();
    return 1;
  }

  if (strcmp(commandName, "AutoInfer") == 0) {
    plhs[0] = (mxArray*) mw__internal__autoInference__fcn();
    return 1;
  }

  return 0;
}

mxArray *cgxe_z2NpuBKzrSZlXyKGS0ynDB_BuildInfoUpdate(void)
{
  mxArray * mxBIArgs;
  mxArray * elem_1;
  mxArray * elem_2;
  mxArray * elem_3;
  mxArray * elem_4;
  mxArray * elem_5;
  mxArray * elem_6;
  mxArray * elem_7;
  mxArray * elem_8;
  mxArray * elem_9;
  double * pointer;
  mxBIArgs = mxCreateCellMatrix(1,3);
  elem_1 = mxCreateCellMatrix(1,6);
  elem_2 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,0,elem_2);
  elem_3 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,1,elem_3);
  elem_4 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,2,elem_4);
  elem_5 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,3,elem_5);
  elem_6 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,4,elem_6);
  elem_7 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,5,elem_7);
  mxSetCell(mxBIArgs,0,elem_1);
  elem_8 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,1,elem_8);
  elem_9 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,2,elem_9);
  return mxBIArgs;
}
