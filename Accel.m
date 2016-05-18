classdef Accel < matlab.System 

   methods (Access = protected)
       function [x y z] = stepImpl(~)
         x = 0.0;
         x = coder.ceval('GET_ACCEL_X');

         y = 0.0;
         y = coder.ceval('GET_ACCEL_Y');

         z = 0.0;
         z = coder.ceval('GET_ACCEL_Z');
      end
   end
end 

