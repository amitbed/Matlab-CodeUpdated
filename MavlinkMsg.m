classdef MavlinkMsg < matlab.System
    properties
      Message='Type a message to send';
   end
    
    methods (Access = protected)
        %function setupImpl(~)
            % Implement tasks that need to be performed only once, 
            % such as pre-computed constants.
        %end

        function stepImpl(obj,u)
            coder.extrinsic('properties')
            coder.extrinsic('num2str')
            if coder.target('Rtw')
                coder.cinclude('MyCopter.h'); 
                f = coder.opaque('MAV_SEVERITY', 'MAV_SEVERITY_INFO');
                %coder.ceval('copter.gcs_send_text',f, [obj.Message char(0)]);
                
                str = char(zeros(1,100));
                coder.ceval('sprintf', coder.ref(str), [obj.Message ': %f' char(0)], u);
                coder.ceval('copter.gcs_send_text',f, str);
            end
        end
    end
end
