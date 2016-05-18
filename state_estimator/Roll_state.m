classdef Roll_state < matlab.System 

   methods (Access = protected)
       function roll = stepImpl(~)
         roll = 0.0;
         roll = coder.ceval('GET_ROLL_STATE');
      end
   end
end 

#define GET_ROLL_STATE copter.ahrs.roll