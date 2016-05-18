#ifndef __JxMy01r8DjVbsfi8ofMJEB_h__
#define __JxMy01r8DjVbsfi8ofMJEB_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_slE07I4lDg6FknjQ3k8Q9CG
#define struct_slE07I4lDg6FknjQ3k8Q9CG

struct slE07I4lDg6FknjQ3k8Q9CG
{
  real_T Index;
  real_T DataType;
  real_T IsSigned;
  real_T MantBits;
  real_T FixExp;
  real_T Slope;
  real_T Bias;
};

#endif                                 /*struct_slE07I4lDg6FknjQ3k8Q9CG*/

#ifndef typedef_slE07I4lDg6FknjQ3k8Q9CG
#define typedef_slE07I4lDg6FknjQ3k8Q9CG

typedef struct slE07I4lDg6FknjQ3k8Q9CG slE07I4lDg6FknjQ3k8Q9CG;

#endif                                 /*typedef_slE07I4lDg6FknjQ3k8Q9CG*/

#ifndef struct_sd9l5MLXsdIpquS6M3bJviG
#define struct_sd9l5MLXsdIpquS6M3bJviG

struct sd9l5MLXsdIpquS6M3bJviG
{
  boolean_T tunablePropertyChanged;
  boolean_T isInitialized;
  boolean_T isReleased;
  boolean_T TunablePropsChanged;
};

#endif                                 /*struct_sd9l5MLXsdIpquS6M3bJviG*/

#ifndef typedef_MavlinkMsg
#define typedef_MavlinkMsg

typedef struct sd9l5MLXsdIpquS6M3bJviG MavlinkMsg;

#endif                                 /*typedef_MavlinkMsg*/

#ifndef struct_sfOd2wElE6un66xmZCZog7F
#define struct_sfOd2wElE6un66xmZCZog7F

struct sfOd2wElE6un66xmZCZog7F
{
  real_T dimModes;
  real_T dims[3];
  real_T dType;
  real_T complexity;
  real_T outputBuiltInDTEqUsed;
};

#endif                                 /*struct_sfOd2wElE6un66xmZCZog7F*/

#ifndef typedef_sfOd2wElE6un66xmZCZog7F
#define typedef_sfOd2wElE6un66xmZCZog7F

typedef struct sfOd2wElE6un66xmZCZog7F sfOd2wElE6un66xmZCZog7F;

#endif                                 /*typedef_sfOd2wElE6un66xmZCZog7F*/

#ifndef struct_sZVQz5WVraeIWEljxFvLe8
#define struct_sZVQz5WVraeIWEljxFvLe8

struct sZVQz5WVraeIWEljxFvLe8
{
  char_T names;
  real_T dims[3];
  real_T dType;
  real_T complexity;
};

#endif                                 /*struct_sZVQz5WVraeIWEljxFvLe8*/

#ifndef typedef_sZVQz5WVraeIWEljxFvLe8
#define typedef_sZVQz5WVraeIWEljxFvLe8

typedef struct sZVQz5WVraeIWEljxFvLe8 sZVQz5WVraeIWEljxFvLe8;

#endif                                 /*typedef_sZVQz5WVraeIWEljxFvLe8*/

#ifndef struct_svX6IjOBvErUqADtenqb2BE
#define struct_svX6IjOBvErUqADtenqb2BE

struct svX6IjOBvErUqADtenqb2BE
{
  char_T names;
  real_T dims[3];
  real_T dType;
  real_T dTypeSize;
  char_T dTypeName;
  char_T dTypeChksum;
  real_T complexity;
};

#endif                                 /*struct_svX6IjOBvErUqADtenqb2BE*/

#ifndef typedef_svX6IjOBvErUqADtenqb2BE
#define typedef_svX6IjOBvErUqADtenqb2BE

typedef struct svX6IjOBvErUqADtenqb2BE svX6IjOBvErUqADtenqb2BE;

#endif                                 /*typedef_svX6IjOBvErUqADtenqb2BE*/

#ifndef struct_s7UBIGHSehQY1gCsIQWwr5C
#define struct_s7UBIGHSehQY1gCsIQWwr5C

struct s7UBIGHSehQY1gCsIQWwr5C
{
  real_T chksum[4];
};

#endif                                 /*struct_s7UBIGHSehQY1gCsIQWwr5C*/

#ifndef typedef_s7UBIGHSehQY1gCsIQWwr5C
#define typedef_s7UBIGHSehQY1gCsIQWwr5C

typedef struct s7UBIGHSehQY1gCsIQWwr5C s7UBIGHSehQY1gCsIQWwr5C;

#endif                                 /*typedef_s7UBIGHSehQY1gCsIQWwr5C*/

#ifndef typedef_InstanceStruct_JxMy01r8DjVbsfi8ofMJEB
#define typedef_InstanceStruct_JxMy01r8DjVbsfi8ofMJEB

typedef struct {
  SimStruct *S;
  covrtInstance covInst;
  MavlinkMsg sysobj;
  boolean_T sysobj_not_empty;
} InstanceStruct_JxMy01r8DjVbsfi8ofMJEB;

#endif                                 /*typedef_InstanceStruct_JxMy01r8DjVbsfi8ofMJEB*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_JxMy01r8DjVbsfi8ofMJEB(SimStruct *S, int_T method,
  void* data);
extern int autoInfer_dispatcher_JxMy01r8DjVbsfi8ofMJEB(mxArray *lhs[], const
  char* commandName);

#endif
