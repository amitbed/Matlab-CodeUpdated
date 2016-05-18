/*
 * test.h
 *
 * Code generation for model "test".
 *
 * Model version              : 1.12
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Sun Apr 17 22:43:35 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_test_h_
#define RTW_HEADER_test_h_
#include <string.h>
#include <math.h>
#include <float.h>
#include <stddef.h>
#ifndef test_COMMON_INCLUDES_
# define test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* test_COMMON_INCLUDES_ */

#include "test_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteStateSpace_DSTATE[2]; /* '<Root>/Discrete State-Space' */
  real_T estimatedParameters[4];       /* '<S4>/delayTheta' */
  real_T P[16];                        /* '<S4>/delayP' */
  real_T ioMemory[4];                  /* '<S4>/delayPhi' */
  real_T errorSensitivity[4];          /* '<S4>/delayPsi' */
  real_T NextOutput;                   /* '<S1>/White Noise' */
  uint32_T RandSeed;                   /* '<S1>/White Noise' */
  uint8_T icLoad;                      /* '<S4>/delayTheta' */
  uint8_T icLoad_e;                    /* '<S4>/delayP' */
  uint8_T icLoad_k;                    /* '<S4>/delayPhi' */
  uint8_T icLoad_kn;                   /* '<S4>/delayPsi' */
} DW_test_T;

/* Parameters (auto storage) */
struct P_test_T_ {
  real_T AdaptationParameter_Value;    /* Expression: initializationParams.adg
                                        * Referenced by: '<S4>/AdaptationParameter'
                                        */
  real_T Enable_Value;                 /* Expression: 1
                                        * Referenced by: '<S4>/Enable'
                                        */
  real_T InitialParameters_Value[4];   /* Expression: initializationParams.theta0
                                        * Referenced by: '<S4>/InitialParameters'
                                        */
  real_T InitialCovariance_Value;      /* Expression: initializationParams.P0
                                        * Referenced by: '<S4>/InitialCovariance'
                                        */
  real_T InitialPhiMemory_Value[4];    /* Expression: initializationParams.phiMemory0
                                        * Referenced by: '<S4>/InitialPhiMemory'
                                        */
  real_T InitialPsiMemory_Value[4];    /* Expression: initializationParams.psiMemory0
                                        * Referenced by: '<S4>/InitialPsiMemory'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T WhiteNoise_Seed;              /* Expression: seed
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T Output_Gain;                  /* Expression: [sqrt(Cov)]/[sqrt(Ts)]
                                        * Referenced by: '<S1>/Output'
                                        */
  real_T DiscreteStateSpace_A[3];      /* Computed Parameter: DiscreteStateSpace_A
                                        * Referenced by: '<Root>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B;         /* Computed Parameter: DiscreteStateSpace_B
                                        * Referenced by: '<Root>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C;         /* Computed Parameter: DiscreteStateSpace_C
                                        * Referenced by: '<Root>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0;        /* Expression: 0
                                        * Referenced by: '<Root>/Discrete State-Space'
                                        */
  uint32_T delayTheta_DelayLength;     /* Computed Parameter: delayTheta_DelayLength
                                        * Referenced by: '<S4>/delayTheta'
                                        */
  uint32_T delayP_DelayLength;         /* Computed Parameter: delayP_DelayLength
                                        * Referenced by: '<S4>/delayP'
                                        */
  uint32_T delayPhi_DelayLength;       /* Computed Parameter: delayPhi_DelayLength
                                        * Referenced by: '<S4>/delayPhi'
                                        */
  uint32_T delayPsi_DelayLength;       /* Computed Parameter: delayPsi_DelayLength
                                        * Referenced by: '<S4>/delayPsi'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_test_T test_P;

/* Block states (auto storage) */
extern DW_test_T test_DW;

/* Model entry point functions */
extern void test_initialize(void);
extern void test_step(void);
extern void test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test_T *const test_M;

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
 * '<Root>' : 'test'
 * '<S1>'   : 'test/Band-Limited White Noise'
 * '<S2>'   : 'test/Subsystem'
 * '<S3>'   : 'test/Subsystem/Model Type Converter'
 * '<S4>'   : 'test/Subsystem/Recursive Polynomial Model Estimator'
 * '<S5>'   : 'test/Subsystem/Recursive Polynomial Model Estimator/Check Enable Signal'
 * '<S6>'   : 'test/Subsystem/Recursive Polynomial Model Estimator/Check Initial Covariance'
 * '<S7>'   : 'test/Subsystem/Recursive Polynomial Model Estimator/Check Initial Parameters'
 * '<S8>'   : 'test/Subsystem/Recursive Polynomial Model Estimator/Check Reset Signal'
 * '<S9>'   : 'test/Subsystem/Recursive Polynomial Model Estimator/Check Signals'
 * '<S10>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/Data Type Conversion Inherited'
 * '<S11>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/Data Type Conversion Inherited1'
 * '<S12>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/Data Type Conversion Inherited2'
 * '<S13>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/Data Type Conversion Inherited3'
 * '<S14>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/Data Type Conversion Inherited4'
 * '<S15>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/Data Type Conversion Inherited5'
 * '<S16>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/Data Type Conversion Inherited7'
 * '<S17>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/Data Type Conversion Inherited8'
 * '<S18>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/Data Type Conversion Inherited9'
 * '<S19>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/Estimator'
 * '<S20>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/InitialParameterDataTypeConverter'
 * '<S21>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/ProcessInitialCovariance'
 * '<S22>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/ProcessInitialParameters'
 * '<S23>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/Estimator/Data Type Conversion Inherited'
 * '<S24>'  : 'test/Subsystem/Recursive Polynomial Model Estimator/Estimator/rarmax - MATLAB Function'
 */
#endif                                 /* RTW_HEADER_test_h_ */
