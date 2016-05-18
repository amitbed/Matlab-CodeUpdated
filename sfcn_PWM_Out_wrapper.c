

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
# ifndef MATLAB_MEX_FILE
#include </home/pi/wiringPi/wiringPi/gertboard.h>
#include </home/pi/wiringPi/wiringPi/piNes.h>
#include </home/pi/wiringPi/wiringPi/softServo.h>
#include </home/pi/wiringPi/wiringPi/wiringSerial.h>
#include </home/pi/wiringPi/wiringPi/softTone.h>
#include </home/pi/wiringPi/wiringPi/wiringPiI2C.h>
#include </home/pi/wiringPi/wiringPi/wiringShift.h>
#include </home/pi/wiringPi/wiringPi/softPwm.h>
#include </home/pi/wiringPi/wiringPi/wiringPi.h>
#include </home/pi/wiringPi/wiringPi/wiringPiSPI.h>

// for digital out:
#include </home/pi/wiringPi/wiringPi/wiringPi.c>
#include </home/pi/wiringPi/wiringPi/piHiPri.c>
// for pwm:
#include </home/pi/wiringPi/wiringPi/softPwm.c>
#include </home/pi/wiringPi/wiringPi/piThread.c>

# endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void sfcn_PWM_Out_Outputs_wrapper(const uint8_T *in,
			const real_T *xD,
			const uint8_T  *pin, const int_T  p_width0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* wait until after initialization is done */
if (xD[0]==1) {
    
    /* don't do anything for mex file generation */
    # ifndef MATLAB_MEX_FILE
    // Update Output:
    softPwmWrite (pin[0],in[0]) ;
    # endif
    
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void sfcn_PWM_Out_Update_wrapper(const uint8_T *in,
			real_T *xD,
			const uint8_T  *pin,  const int_T  p_width0)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1) {
    
    /* don't do anything for MEX-file generation */
    # ifndef MATLAB_MEX_FILE
    // Initialize WiringPi
    wiringPiSetup ();
    // Initialize pin as output
    // In WiringPi pins are not GPIO pins see "WiringPi GPIO Pins"
    softPwmCreate (pin[0], 0, 255) ;
    # endif
    
    /* initialization done */ 
    xD[0]=1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
