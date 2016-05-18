/* Include files */

#include "ModelD_cgxe.h"
#include "m_jGJeUnXowSnrBTmm3TGSwB.h"
#include "m_JxMy01r8DjVbsfi8ofMJEB.h"
#include "m_I2qdc3gRUXffgupHtEi3LB.h"
#include "m_Ppe0kcJTWAFj083kyKBRqF.h"
#include "m_t0r9JzKNkkWY1vKyCq46gE.h"
#include "m_NEQWUV6xi4bxN5U0gajE8B.h"

static unsigned int cgxeModelInitialized = 0;
emlrtContext emlrtContextGlobal = { true, true, EMLRT_VERSION_INFO, NULL, "",
  NULL, false, { 0, 0, 0, 0 }, NULL };

void *emlrtRootTLSGlobal = NULL;
char cgxeRtErrBuf[4096];

/* CGXE Glue Code */
void cgxe_ModelD_initializer(void)
{
  if (cgxeModelInitialized == 0) {
    cgxeModelInitialized = 1;
    emlrtRootTLSGlobal = NULL;
    emlrtCreateSimulinkRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  }
}

void cgxe_ModelD_terminator(void)
{
  if (cgxeModelInitialized != 0) {
    cgxeModelInitialized = 0;
    emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
    emlrtRootTLSGlobal = NULL;
  }
}

unsigned int cgxe_ModelD_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 422767618 &&
      ssGetChecksum1(S) == 2039901938 &&
      ssGetChecksum2(S) == 2881736823 &&
      ssGetChecksum3(S) == 2235349202) {
    method_dispatcher_jGJeUnXowSnrBTmm3TGSwB(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1577825174 &&
      ssGetChecksum1(S) == 479541923 &&
      ssGetChecksum2(S) == 2526003561 &&
      ssGetChecksum3(S) == 4279520987) {
    method_dispatcher_JxMy01r8DjVbsfi8ofMJEB(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2123709983 &&
      ssGetChecksum1(S) == 3165116183 &&
      ssGetChecksum2(S) == 2966475493 &&
      ssGetChecksum3(S) == 1493217462) {
    method_dispatcher_I2qdc3gRUXffgupHtEi3LB(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2331273809 &&
      ssGetChecksum1(S) == 853821471 &&
      ssGetChecksum2(S) == 3218367319 &&
      ssGetChecksum3(S) == 1688128191) {
    method_dispatcher_Ppe0kcJTWAFj083kyKBRqF(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3293317654 &&
      ssGetChecksum1(S) == 1965091921 &&
      ssGetChecksum2(S) == 2437599121 &&
      ssGetChecksum3(S) == 3060787271) {
    method_dispatcher_t0r9JzKNkkWY1vKyCq46gE(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3950256316 &&
      ssGetChecksum1(S) == 3609674402 &&
      ssGetChecksum2(S) == 2718372105 &&
      ssGetChecksum3(S) == 2590603628) {
    method_dispatcher_NEQWUV6xi4bxN5U0gajE8B(S, method, data);
    return 1;
  }

  return 0;
}

int cgxe_ModelD_autoInfer_dispatcher(const mxArray* prhs, mxArray* lhs[], const
  char* commandName)
{
  char sid[64];
  mxGetString(prhs,sid, sizeof(sid)/sizeof(char));
  sid[(sizeof(sid)/sizeof(char)-1)] = '\0';
  if (strcmp(sid, "ModelD:37") == 0 ) {
    return autoInfer_dispatcher_jGJeUnXowSnrBTmm3TGSwB(lhs, commandName);
  }

  mxGetString(prhs,sid, sizeof(sid)/sizeof(char));
  sid[(sizeof(sid)/sizeof(char)-1)] = '\0';
  if (strcmp(sid, "ModelD:125") == 0 ) {
    return autoInfer_dispatcher_JxMy01r8DjVbsfi8ofMJEB(lhs, commandName);
  }

  mxGetString(prhs,sid, sizeof(sid)/sizeof(char));
  sid[(sizeof(sid)/sizeof(char)-1)] = '\0';
  if (strcmp(sid, "ModelD:153") == 0 ) {
    return autoInfer_dispatcher_I2qdc3gRUXffgupHtEi3LB(lhs, commandName);
  }

  mxGetString(prhs,sid, sizeof(sid)/sizeof(char));
  sid[(sizeof(sid)/sizeof(char)-1)] = '\0';
  if (strcmp(sid, "ModelD:146") == 0 ) {
    return autoInfer_dispatcher_Ppe0kcJTWAFj083kyKBRqF(lhs, commandName);
  }

  mxGetString(prhs,sid, sizeof(sid)/sizeof(char));
  sid[(sizeof(sid)/sizeof(char)-1)] = '\0';
  if (strcmp(sid, "ModelD:160") == 0 ) {
    return autoInfer_dispatcher_t0r9JzKNkkWY1vKyCq46gE(lhs, commandName);
  }

  mxGetString(prhs,sid, sizeof(sid)/sizeof(char));
  sid[(sizeof(sid)/sizeof(char)-1)] = '\0';
  if (strcmp(sid, "ModelD:106") == 0 ) {
    return autoInfer_dispatcher_NEQWUV6xi4bxN5U0gajE8B(lhs, commandName);
  }

  return 0;
}

int *ssGetCurrentInputPortDimensions_wrapper(SimStruct *S,int portNumber)
{
  return((int *)(&(ssGetCurrentInputPortDimensions(S, portNumber, 0))));
}

int *ssGetCurrentOutputPortDimensions_wrapper(SimStruct *S,int portNumber)
{
  return(&(ssGetCurrentOutputPortDimensions(S, portNumber, 0)));
}

static unsigned int cgxe_listen_for_ctrl_c_force(SimStruct *S, emlrtCTX aCtx)
{
  mxArray *plhs[1]= { NULL };

  mxArray *prhs[2];
  emlrtBreakCheckR2012b(aCtx);
  prhs[0] = mxCreateString("listen_for_ctrlc");
  prhs[1] = mxCreateString("ModelD");
  mexCallMATLAB(1,plhs,2,prhs,"cgxeprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  if (plhs[0]!=NULL) {
    unsigned int simStatus = (unsigned int)mxGetScalar(plhs[0]);
    mxDestroyArray(plhs[0]);
    if (simStatus==CGXE_SIM_STOPPED) {
      emlrtBreakSimulation(aCtx);
    }

    return(simStatus);
  }

  return(0);
}

#ifdef WATCOM
#define CONTROL_C_THRESHOLD            1000

unsigned int cgxe_listen_for_ctrl_c(SimStruct *S, emlrtCTX aCtx)
{
  static unsigned int sControlCCount = 0;
  sControlCCount++;
  if (sControlCCount>=CONTROL_C_THRESHOLD) {
    unsigned int result;
    sControlCCount = 0;
    result = cgxe_listen_for_ctrl_c_force(S,aCtx);
  }

  return(0);
}

#else                                  /* #ifdef WATCOM */

unsigned int cgxe_listen_for_ctrl_c(SimStruct *S, emlrtCTX aCtx)
{
  static double lastCpuTime = 0;
  double cpuTime = utCPUtime();
  if (cpuTime - lastCpuTime > 0.3) {
    unsigned int result;
    lastCpuTime = cpuTime;
    result = cgxe_listen_for_ctrl_c_force(S,aCtx);
  }

  return(0);
}

#endif
