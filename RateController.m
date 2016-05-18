classdef RateController < matlab.System
    methods (Access = protected)
        function stepImpl(obj,yaw, pitch, roll)
            if coder.target('Rtw')
                coder.cinclude('MyCopter.h');
                
                coder.ceval('SET_YAW_RATE_TARGET',  yaw);                
                coder.ceval('SET_PITCH_RATE_TARGET',pitch);
                coder.ceval('SET_ROLL_RATE_TARGET', roll);
            end
        end
    end
end
 