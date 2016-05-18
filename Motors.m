classdef Motors < matlab.System 
    
    methods (Access = protected)
 

        function stepImpl(obj,roll,pitch,yaw,throttle)
            if coder.target('Rtw')
                coder.cinclude('MyCopter.h'); 
                
                if(roll>=-1 && roll <= 1)
                    coder.ceval('copter.motors.set_roll',roll);
                end
                
                if(pitch>=-1 && pitch <= 1)
                    coder.ceval('copter.motors.set_pitch',pitch);
                end
                
                if(yaw>=-1 && yaw <= 1)
                    coder.ceval('copter.motors.set_yaw',yaw);
                end
                
                if(throttle>=0 && yaw <= 1)
                    coder.ceval('copter.motors.set_throttle',throttle);
                end
            end
        end
        
        
        
        
    end
end
