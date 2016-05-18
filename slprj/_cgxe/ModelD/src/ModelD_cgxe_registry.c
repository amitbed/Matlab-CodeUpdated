#define S_FUNCTION_LEVEL               2
#define S_FUNCTION_NAME                ModelD_cgxe
#include "simstruc.h"
#include "ModelD_cgxe.h"
#define MDL_START

static void mdlStart(SimStruct* S)
{
  unsigned int success;
  success = cgxe_ModelD_method_dispatcher(S, SS_CALL_MDL_START, NULL);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }
}

#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  /*sf_mex_error_direct_call(S, "mdlInitializeConditions", "sf_sfun");*/
  mexPrintf("ERROR: Calling model mdlInitializeConditions method directly.\n");
}

#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  /*sf_mex_error_direct_call(S, "mdlUpdate", "sf_sfun");*/
  mexPrintf("ERROR: Calling model mdlUpdate method directly.\n");
}

static void mdlOutputs(SimStruct* S, int_T tid)
{
  /*sf_mex_error_direct_call(S, "mdlOutputs", "sf_sfun");*/
  mexPrintf("ERROR: Calling model mdlOUtputs method directly.\n");
}

static void mdlTerminate(SimStruct *S)
{
  /*sf_mex_error_direct_call(S, "mdlOutputs", "sf_sfun");*/
  mexPrintf("ERROR: Calling model mdlTerminate method directly.\n");
}

static void mdlInitializeSizes(SimStruct *S)
{
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
}

static mxArray* cgxe_get_supported_modules(void)
{
  mxArray* mxModules = mxCreateCellMatrix(6, 1);
  mxArray* mxChksum = NULL;
  uint32_T* checksumData = NULL;
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 422767618;
  checksumData[1] = 2039901938;
  checksumData[2] = 2881736823;
  checksumData[3] = 2235349202;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1577825174;
  checksumData[1] = 479541923;
  checksumData[2] = 2526003561;
  checksumData[3] = 4279520987;
  mxSetCell(mxModules, 1, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2123709983;
  checksumData[1] = 3165116183;
  checksumData[2] = 2966475493;
  checksumData[3] = 1493217462;
  mxSetCell(mxModules, 2, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2331273809;
  checksumData[1] = 853821471;
  checksumData[2] = 3218367319;
  checksumData[3] = 1688128191;
  mxSetCell(mxModules, 3, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3293317654;
  checksumData[1] = 1965091921;
  checksumData[2] = 2437599121;
  checksumData[3] = 3060787271;
  mxSetCell(mxModules, 4, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3950256316;
  checksumData[1] = 3609674402;
  checksumData[2] = 2718372105;
  checksumData[3] = 2590603628;
  mxSetCell(mxModules, 5, mxChksum);
  return mxModules;
}

static int cgxe_process_get_checksums(int nlhs, mxArray* plhs[], int nrhs, const
  mxArray* prhs[])
{
  const char* checksumFields[] = { "modules", "model", "makefile", "target",
    "overall" };

  mxArray* mxChecksum = mxCreateStructMatrix(1, 1, 5, checksumFields);
  mxSetField(mxChecksum, 0, "modules", cgxe_get_supported_modules());

  {
    mxArray* mxModelChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxModelChksum);
    checksumData[0] = 267898686;
    checksumData[1] = 1321967189;
    checksumData[2] = 709776591;
    checksumData[3] = 2060915697;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 4232055401;
    checksumData[1] = 4229590544;
    checksumData[2] = 1360672252;
    checksumData[3] = 3334659291;
    mxSetField(mxChecksum, 0, "makefile", mxMakefileChksum);
  }

  {
    mxArray* mxTargetChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxTargetChksum);
    checksumData[0] = 1635109058;
    checksumData[1] = 2120455702;
    checksumData[2] = 12658520;
    checksumData[3] = 3454939730;
    mxSetField(mxChecksum, 0, "target", mxTargetChksum);
  }

  {
    mxArray* mxOverallChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxOverallChksum);
    checksumData[0] = 4059435905;
    checksumData[1] = 3258906853;
    checksumData[2] = 3437202854;
    checksumData[3] = 1599305411;
    mxSetField(mxChecksum, 0, "overall", mxOverallChksum);
  }

  plhs[0] = mxChecksum;
  return 1;
}

static int cgxe_mex_unlock_call(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  while (mexIsLocked()) {
    mexUnlock();
  }

  return 1;
}

static SimStruct* cgxe_unpack_simstruct(const mxArray *mxS)
{
  int *intPtr = (int*)malloc(sizeof(SimStruct*));
  int nEl = sizeof(SimStruct*)/sizeof(int);
  double *dblPtr = mxGetPr(mxS);
  int el;
  SimStruct *S;
  for (el=0; el < nEl; el++) {
    intPtr[el] = (int)(dblPtr[el]);
  }

  S = *((SimStruct**)intPtr);
  free(intPtr);
  return S;
}

static int cgxe_get_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_ModelD_method_dispatcher(S, SS_CALL_MDL_GET_SIM_STATE, (void *)
    (plhs));
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_set_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_ModelD_method_dispatcher(S, SS_CALL_MDL_SET_SIM_STATE, (void *)
    prhs[2]);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_get_BuildInfoUpdate(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(tpChksum, "jGJeUnXowSnrBTmm3TGSwB") == 0) {
    extern mxArray *cgxe_jGJeUnXowSnrBTmm3TGSwB_BuildInfoUpdate(void);
    plhs[0] = cgxe_jGJeUnXowSnrBTmm3TGSwB_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "JxMy01r8DjVbsfi8ofMJEB") == 0) {
    extern mxArray *cgxe_JxMy01r8DjVbsfi8ofMJEB_BuildInfoUpdate(void);
    plhs[0] = cgxe_JxMy01r8DjVbsfi8ofMJEB_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "I2qdc3gRUXffgupHtEi3LB") == 0) {
    extern mxArray *cgxe_I2qdc3gRUXffgupHtEi3LB_BuildInfoUpdate(void);
    plhs[0] = cgxe_I2qdc3gRUXffgupHtEi3LB_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "Ppe0kcJTWAFj083kyKBRqF") == 0) {
    extern mxArray *cgxe_Ppe0kcJTWAFj083kyKBRqF_BuildInfoUpdate(void);
    plhs[0] = cgxe_Ppe0kcJTWAFj083kyKBRqF_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "t0r9JzKNkkWY1vKyCq46gE") == 0) {
    extern mxArray *cgxe_t0r9JzKNkkWY1vKyCq46gE_BuildInfoUpdate(void);
    plhs[0] = cgxe_t0r9JzKNkkWY1vKyCq46gE_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "NEQWUV6xi4bxN5U0gajE8B") == 0) {
    extern mxArray *cgxe_NEQWUV6xi4bxN5U0gajE8B_BuildInfoUpdate(void);
    plhs[0] = cgxe_NEQWUV6xi4bxN5U0gajE8B_BuildInfoUpdate();
    return 1;
  }

  return 0;
}

#define PROCESS_MEX_SFUNCTION_CMD_LINE_CALL

static int ProcessMexSfunctionCmdLineCall(int nlhs, mxArray* plhs[], int nrhs,
  const mxArray* prhs[])
{
  char commandName[64];
  if (nrhs < 1 || !mxIsChar(prhs[0]))
    return 0;
  mxGetString(prhs[0], commandName, sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName, "get_checksums") == 0) {
    return cgxe_process_get_checksums(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "mex_unlock") == 0) {
    return cgxe_mex_unlock_call(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_sim_state") == 0) {
    return cgxe_get_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if ((strcmp(commandName, "NameResolution") == 0)||
      (strcmp(commandName, "AutoInfer") == 0)) {
    if (nrhs < 2 || !mxIsChar(prhs[1]))
      return 0;
    return cgxe_ModelD_autoInfer_dispatcher(prhs[1], plhs, commandName);
  }

  if (strcmp(commandName, "set_sim_state") == 0) {
    return cgxe_set_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_BuildInfoUpdate") == 0) {
    return cgxe_get_BuildInfoUpdate(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "mex_initialize") == 0) {
    cgxe_ModelD_initializer();
    return 1;
  }

  if (strcmp(commandName, "mex_terminate") == 0) {
    cgxe_ModelD_terminator();
    return 1;
  }

  return 0;
}

#include "simulink.c"
