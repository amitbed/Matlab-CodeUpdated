classdef Pitch_state < matlab.System 

   methods (Access = protected)
       function pitch = stepImpl(~)
         pitch = 0.0;
         pitch = coder.ceval('GET_PITCH_STATE');
      end
   end
end 

#define GET_PITCH_STATE copter.ahrs.pitch