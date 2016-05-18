classdef Copter_Self_State < matlab.System 

   methods (Access = protected)
       function [yaw roll pitch] = stepImpl(~)
         yaw = 0.0;
         yaw = coder.ceval('GET_YAW_STATE');

         roll = 0.0;
         roll = coder.ceval('GET_ROLL_STATE');

         pitch = 0.0;
         pitch = coder.ceval('GET_PITCH_STATE');
      end
   end
end 

