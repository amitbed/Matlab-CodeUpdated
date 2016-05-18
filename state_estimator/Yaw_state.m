classdef Yaw_state < matlab.System 

   methods (Access = protected)
       function yaw = stepImpl(~)
         yaw = 0.0;
         yaw = coder.ceval('GET_YAW_STATE');
      end
   end
end 

#define GET_YAW_STATE copter.ahrs.yaw