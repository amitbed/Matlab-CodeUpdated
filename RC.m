classdef RC < matlab.System 

   methods (Access = protected)
       function [thort,yawR,pitch,roll] = stepImpl(~)
         yawR = 0.0;
         yawR = coder.ceval('GET_DESIRED_YAW_RATE'); 
         
         thort = 0.0;
         thort = coder.ceval('GET_DESIRED_THROTLE'); 
         
         roll = 0.0;
         roll = coder.ceval('GET_DESIRED_ROLL'); 

         pitch = 0.0;
         pitch = coder.ceval('GET_DESIRED_PITCH'); 
         
      end
   end
end 

